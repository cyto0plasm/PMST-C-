#include "ProductsController.h"
#include "../Database/DBConnection.h"
#include "../Models/ProductModel.h"

namespace PMST {

    void ProductController::Validate(ProductModel^ m, bool requireId) {
        if (requireId && m->Id <= 0) throw gcnew ArgumentException("Invalid Product Id.");

        if (m->Pharmacy_Id <= 0 || !PharmacyExists(m->Pharmacy_Id))
            throw gcnew ArgumentException("Pharmacy_Id must refer to existing pharmacy.");

        if (m->Category_Id <= 0 || !CategoryExistsForPharmacy(m->Category_Id, m->Pharmacy_Id))
            throw gcnew ArgumentException("Category_Id must refer to existing category in the same pharmacy.");

        if (m->Supplier_Id <= 0 || !SupplierExists(m->Supplier_Id))
            throw gcnew ArgumentException("Supplier_Id must refer to existing supplier.");

        if (String::IsNullOrWhiteSpace(m->Name))
            throw gcnew ArgumentException("Product name required.");
    }

    bool ProductController::PharmacyExists(int pharmacyId) {
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand("SELECT COUNT(1) FROM Pharmacies WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@id", pharmacyId);
        bool ok = (Int64)cmd->ExecuteScalar() > 0;
        conn->Close(); return ok;
    }

     bool ProductController::CategoryExistsForPharmacy(int categoryId, int pharmacyId) {
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "SELECT COUNT(1) FROM Categories WHERE Id=@catId AND Pharmacy_Id=@pharmId;", conn);
        cmd->Parameters->AddWithValue("@catId", categoryId);
        cmd->Parameters->AddWithValue("@pharmId", pharmacyId);
        bool ok = (Int64)cmd->ExecuteScalar() > 0;
        conn->Close(); return ok;
    }

    bool ProductController::SupplierExists(int supplierId) {
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand("SELECT COUNT(1) FROM Suppliers WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@id", supplierId);
        bool ok = (Int64)cmd->ExecuteScalar() > 0;
        conn->Close(); return ok;
    }

    ProductModel^ ProductController::Create(ProductModel^ m) {
        Validate(m, false);
        m->Created_At = DateTime::Now;
        m->Updated_At = DateTime::Now;

        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "INSERT INTO Products (Pharmacy_Id,Category_Id,Supplier_Id,Name,Price,Quantity,Created_At,Updated_At) "
            "VALUES (@p,@c,@s,@n,@pr,@q,@cA,@uA); SELECT last_insert_rowid();", conn);
        cmd->Parameters->AddWithValue("@p", m->Pharmacy_Id);
        cmd->Parameters->AddWithValue("@c", m->Category_Id);
        cmd->Parameters->AddWithValue("@s", m->Supplier_Id);
        cmd->Parameters->AddWithValue("@n", m->Name);
        cmd->Parameters->AddWithValue("@pr", m->Price);
        cmd->Parameters->AddWithValue("@q", m->Quantity);
        cmd->Parameters->AddWithValue("@cA", m->Created_At);
        cmd->Parameters->AddWithValue("@uA", m->Updated_At);
        m->Id = safe_cast<int>((Int64)cmd->ExecuteScalar());
        conn->Close();
        return m;
    }

    ProductModel^ ProductController::GetById(int id) {
        if (id <= 0) return nullptr;

        auto conn = DBConnection::GetConnection();
        conn->Open();
        SQLiteDataReader^ rd = nullptr;

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT Id,Pharmacy_Id,Category_Id,Supplier_Id,Name,Price,Quantity,Created_At,Updated_At "
                "FROM Products WHERE Id=@id;", conn);
            cmd->Parameters->AddWithValue("@id", id);

            rd = cmd->ExecuteReader();
            if (!rd->Read()) return nullptr;

            auto m = gcnew ProductModel();
            m->Id = rd->GetInt32(0);
            m->Pharmacy_Id = rd->GetInt32(1);
            m->Category_Id = rd->GetInt32(2);
            m->Supplier_Id = rd->GetInt32(3);
            m->Name = rd->GetString(4);
            m->Price = rd->GetDecimal(5);
            m->Quantity = rd->GetInt32(6);
            m->Created_At = rd->GetDateTime(7);
            m->Updated_At = rd->GetDateTime(8);
            return m;
        }
        finally {
            if (rd != nullptr && !rd->IsClosed)
                rd->Close();
            conn->Close();
        }
    }

    List<ProductModel^>^ ProductController::GetAll() {
        auto list = gcnew List<ProductModel^>();
        auto conn = DBConnection::GetConnection();
        conn->Open();
        SQLiteDataReader^ rd = nullptr;

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT Id,Pharmacy_Id,Category_Id,Supplier_Id,Name,Price,Quantity,Created_At,Updated_At FROM Products;", conn);
            rd = cmd->ExecuteReader();

            while (rd->Read()) {
                auto m = gcnew ProductModel();
                m->Id = rd->GetInt32(0);
                m->Pharmacy_Id = rd->GetInt32(1);
                m->Category_Id = rd->GetInt32(2);
                m->Supplier_Id = rd->GetInt32(3);
                m->Name = rd->GetString(4);
                m->Price = rd->GetDecimal(5);
                m->Quantity = rd->GetInt32(6);
                m->Created_At = rd->GetDateTime(7);
                m->Updated_At = rd->GetDateTime(8);
                list->Add(m);
            }
            return list;
        }
        finally {
            if (rd != nullptr && !rd->IsClosed)
                rd->Close();
            conn->Close();
        }
    }

    List<ProductModel^>^ ProductController::GetByPharmacy(int pharmacyId) {
        auto list = gcnew List<ProductModel^>();
        if (pharmacyId <= 0) return list;

        auto conn = DBConnection::GetConnection();
        conn->Open();
        SQLiteDataReader^ rd = nullptr;

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT Id,Pharmacy_Id,Category_Id,Supplier_Id,Name,Price,Quantity,Created_At,Updated_At "
                "FROM Products WHERE Pharmacy_Id=@p;", conn);
            cmd->Parameters->AddWithValue("@p", pharmacyId);
            rd = cmd->ExecuteReader();

            while (rd->Read()) {
                auto m = gcnew ProductModel();
                m->Id = rd->GetInt32(0);
                m->Pharmacy_Id = rd->GetInt32(1);
                m->Category_Id = rd->GetInt32(2);
                m->Supplier_Id = rd->GetInt32(3);
                m->Name = rd->GetString(4);
                m->Price = rd->GetDecimal(5);
                m->Quantity = rd->GetInt32(6);
                m->Created_At = rd->GetDateTime(7);
                m->Updated_At = rd->GetDateTime(8);
                list->Add(m);
            }
            return list;
        }
        finally {
            if (rd != nullptr && !rd->IsClosed)
                rd->Close();
            conn->Close();
        }
    }

    bool ProductController::Update(ProductModel^ m) {
        Validate(m, true);
        m->Updated_At = DateTime::Now;
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "UPDATE Products SET Name=@n,Price=@pr,Quantity=@q,Updated_At=@u WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@n", m->Name);
        cmd->Parameters->AddWithValue("@pr", m->Price);
        cmd->Parameters->AddWithValue("@q", m->Quantity);
        cmd->Parameters->AddWithValue("@u", m->Updated_At);
        cmd->Parameters->AddWithValue("@id", m->Id);
        int rows = cmd->ExecuteNonQuery();
        conn->Close();
        return rows > 0;
    }

    bool ProductController::Delete(int id) {
        if (id <= 0) return false;
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand("DELETE FROM Products WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@id", id);
        int rows = cmd->ExecuteNonQuery();
        conn->Close();
        return rows > 0;
    }

    List<ProductModel^>^ ProductController::SearchProducts(String^ searchText, int pharmacyId) {
        auto list = gcnew List<ProductModel^>();
        if (String::IsNullOrEmpty(searchText) || pharmacyId <= 0) return list;

        auto conn = DBConnection::GetConnection();
        conn->Open();
        SQLiteDataReader^ rd = nullptr;

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT Id,Pharmacy_Id,Category_Id,Supplier_Id,Name,Price,Quantity,Created_At,Updated_At "
                "FROM Products WHERE Pharmacy_Id=@p AND (Name LIKE @search OR Id LIKE @search) LIMIT 20;", conn);
            cmd->Parameters->AddWithValue("@p", pharmacyId);
            cmd->Parameters->AddWithValue("@search", "%" + searchText + "%");

            rd = cmd->ExecuteReader();

            while (rd->Read()) {
                auto m = gcnew ProductModel();
                m->Id = rd->GetInt32(0);
                m->Pharmacy_Id = rd->GetInt32(1);
                m->Category_Id = rd->GetInt32(2);
                m->Supplier_Id = rd->GetInt32(3);
                m->Name = rd->GetString(4);
                m->Price = rd->GetDecimal(5);
                m->Quantity = rd->GetInt32(6);
                m->Created_At = rd->GetDateTime(7);
                m->Updated_At = rd->GetDateTime(8);
                list->Add(m);
            }
            return list;
        }
        finally {
            if (rd != nullptr && !rd->IsClosed)
                rd->Close();
            conn->Close();
        }
    }
}
