#include "ProductsController.h"
#include "../Database/DBConnection.h"
#include "../Models/ProductModel.h"
#include "../Helpers/UIHelper.h"
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
    List<ProductModel^>^ ProductController::SearchProducts(String^ searchText, int pharmacyId) {
        auto list = gcnew List<ProductModel^>();
        if (String::IsNullOrWhiteSpace(searchText) || pharmacyId <= 0) return list;

        auto conn = DBConnection::GetConnection();
        conn->Open();
        SQLiteDataReader^ rd = nullptr;

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT id,pharmacy_id,category_id,supplier_id,name,price,quantity,created_at,updated_at "
                "FROM products WHERE pharmacy_id=@pharmId AND name LIKE @search;", conn);

            cmd->Parameters->AddWithValue("@pharmId", pharmacyId);
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
        }
        finally {
            if (rd != nullptr && !rd->IsClosed)
                rd->Close();
            conn->Close();
        }

        return list;
    }

    ProductModel^ ProductController::Create(ProductModel^ m) {
        try {
            Validate(m, false);
            m->Created_At = DateTime::Now;
            m->Updated_At = DateTime::Now;

            auto conn = DBConnection::GetConnection();
            conn->Open();

            // Check if product already exists
            auto checkCmd = gcnew SQLiteCommand(
                "SELECT COUNT(*) FROM Products WHERE Pharmacy_Id = @p AND Name = @n", conn);
            checkCmd->Parameters->AddWithValue("@p", m->Pharmacy_Id);
            checkCmd->Parameters->AddWithValue("@n", m->Name);
            int count = Convert::ToInt32(checkCmd->ExecuteScalar());

            if (count > 0) {
                MessageBox::Show("Product with this name already exists in this pharmacy.", "Duplicate Product", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                conn->Close();
                return nullptr;
            }

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
        catch (Exception^ ex) {
            UIHelper::ShowUserFriendlyError(ex, "Create Product");
            return nullptr;
        }
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
        try {
            Validate(m, true);
            m->Updated_At = DateTime::Now;

            auto conn = DBConnection::GetConnection();
            conn->Open();

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
        catch (Exception^ ex) {
            UIHelper::ShowUserFriendlyError(ex, "Update Product");
            return false;
        }
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


    // Add to ProductController.cpp
        Dictionary<String^, float>^ ProductController::GetProductQuantityByCategory(int pharmacyId)
        {
            auto result = gcnew Dictionary<String^, float>();
            if (pharmacyId <= 0) return result;

            auto conn = DBConnection::GetConnection();
            conn->Open();
            SQLiteDataReader^ rd = nullptr;

            try {
                auto cmd = gcnew SQLiteCommand(
                    "SELECT c.name, SUM(p.quantity) as TotalQuantity "
                    "FROM products p "
                    "JOIN categories c ON p.category_id = c.id "
                    "WHERE p.pharmacy_id = @pharmId "
                    "GROUP BY c.name;", conn);
                cmd->Parameters->AddWithValue("@pharmId", pharmacyId);
                rd = cmd->ExecuteReader();

                while (rd->Read()) {
                    String^ categoryName = rd->GetString(0);
                    float totalQuantity = static_cast<float>(rd->GetInt32(1));
                    result->Add(categoryName, totalQuantity);
                }
            }
            finally {
                if (rd != nullptr && !rd->IsClosed)
                    rd->Close();
                conn->Close();
            }

            return result;
        }

        Dictionary<String^, float>^ ProductController::GetProductValueByCategory(int pharmacyId)
        {
            auto result = gcnew Dictionary<String^, float>();
            if (pharmacyId <= 0) return result;

            auto conn = DBConnection::GetConnection();
            conn->Open();
            SQLiteDataReader^ rd = nullptr;

            try {
                auto cmd = gcnew SQLiteCommand(
                    "SELECT c.name, SUM(p.price * p.quantity) as TotalValue "
                    "FROM products p "
                    "JOIN categories c ON p.category_id = c.id "
                    "WHERE p.pharmacy_id = @pharmId "
                    "GROUP BY c.name;", conn);
                cmd->Parameters->AddWithValue("@pharmId", pharmacyId);
                rd = cmd->ExecuteReader();

                while (rd->Read()) {
                    String^ categoryName = rd->GetString(0);
                    float totalValue = static_cast<float>(Convert::ToDouble(rd->GetValue(1)));
                    result->Add(categoryName, totalValue);
                }
            }
            finally {
                if (rd != nullptr && !rd->IsClosed)
                    rd->Close();
                conn->Close();
            }

            return result;
        }

}
