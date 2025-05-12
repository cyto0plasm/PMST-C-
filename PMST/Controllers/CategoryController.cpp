#include "CategoryController.h"
#include "../Database/DBConnection.h"

namespace PMST {

    void CategoryController::Validate(CategoryModel^ m, bool requireId) {
        if (requireId && m->Id <= 0)
            throw gcnew ArgumentException("Invalid Category Id.");
        if (m->Pharmacy_Id <= 0 || !PharmacyExists(m->Pharmacy_Id))
            throw gcnew ArgumentException("Pharmacy_Id must refer to an existing pharmacy.");
        if (String::IsNullOrWhiteSpace(m->Name))
            throw gcnew ArgumentException("Category name required.");
    }

    bool CategoryController::PharmacyExists(int pharmacyId) {
        auto conn = DBConnection::GetConnection();
        conn->Open();
        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT COUNT(1) FROM Pharmacies WHERE Id = @id;", conn);
            cmd->Parameters->AddWithValue("@id", pharmacyId);
            return (Int64)cmd->ExecuteScalar() > 0;
        }
        finally {
            conn->Close();
        }
    }

    CategoryModel^ CategoryController::Create(CategoryModel^ m) {
        Validate(m, false);
        m->Created_At = DateTime::Now;
        m->Updated_At = DateTime::Now;

        auto conn = DBConnection::GetConnection();
        conn->Open();
        try {
            auto cmd = gcnew SQLiteCommand(
                "INSERT INTO Categories "
                "(Pharmacy_Id, Name, Description, Created_At, Updated_At) "
                "VALUES (@p,@n,@d,@cA,@uA); "
                "SELECT last_insert_rowid();",
                conn);
            cmd->Parameters->AddWithValue("@p", m->Pharmacy_Id);
            cmd->Parameters->AddWithValue("@n", m->Name);
            cmd->Parameters->AddWithValue("@d", m->Description);
            cmd->Parameters->AddWithValue("@cA", m->Created_At);
            cmd->Parameters->AddWithValue("@uA", m->Updated_At);

            m->Id = safe_cast<int>((Int64)cmd->ExecuteScalar());
            return m;
        }
        finally {
            conn->Close();
        }
    }

    CategoryModel^ CategoryController::GetById(int id) {
        if (id <= 0) return nullptr;

        auto conn = DBConnection::GetConnection();
        conn->Open();

        SQLiteDataReader^ rd = nullptr;
        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT Id,Pharmacy_Id,Name,Description,Created_At,Updated_At "
                "FROM Categories WHERE Id = @id;",
                conn);
            cmd->Parameters->AddWithValue("@id", id);

            rd = cmd->ExecuteReader();
            if (!rd->Read())
                return nullptr;

            auto m = gcnew CategoryModel();
            m->Id = rd->GetInt32(0);
            m->Pharmacy_Id = rd->GetInt32(1);
            m->Name = rd->GetString(2);
            m->Description = rd->GetString(3);
            m->Created_At = rd->GetDateTime(4);
            m->Updated_At = rd->GetDateTime(5);
            return m;
        }
        finally {
            if (rd != nullptr && !rd->IsClosed) rd->Close();
            conn->Close();
        }
    }

    List<CategoryModel^>^ CategoryController::GetAll() {
        auto list = gcnew List<CategoryModel^>();
        auto conn = DBConnection::GetConnection();
        conn->Open();

        SQLiteDataReader^ rd = nullptr;
        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT Id,Pharmacy_Id,Name,Description,Created_At,Updated_At "
                "FROM Categories;", conn);

            rd = cmd->ExecuteReader();
            while (rd->Read()) {
                auto m = gcnew CategoryModel();
                m->Id = rd->GetInt32(0);
                m->Pharmacy_Id = rd->GetInt32(1);
                m->Name = rd->GetString(2);
                m->Description = rd->GetString(3);
                m->Created_At = rd->GetDateTime(4);
                m->Updated_At = rd->GetDateTime(5);
                list->Add(m);
            }
            return list;
        }
        finally {
            if (rd != nullptr && !rd->IsClosed) rd->Close();
            conn->Close();
        }
    }

    List<CategoryModel^>^ CategoryController::GetByPharmacy(int pharmacyId) {
        auto list = gcnew List<CategoryModel^>();
        auto conn = DBConnection::GetConnection();
        conn->Open();

        SQLiteDataReader^ rd = nullptr;
        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT Id,Pharmacy_Id,Name,Description,Created_At,Updated_At "
                "FROM Categories WHERE Pharmacy_Id = @p;",
                conn);
            cmd->Parameters->AddWithValue("@p", pharmacyId);

            rd = cmd->ExecuteReader();
            while (rd->Read()) {
                auto m = gcnew CategoryModel();
                m->Id = rd->GetInt32(0);
                m->Pharmacy_Id = rd->GetInt32(1);
                m->Name = rd->GetString(2);
                m->Description = rd->GetString(3);
                m->Created_At = rd->GetDateTime(4);
                m->Updated_At = rd->GetDateTime(5);
                list->Add(m);
            }
            return list;
        }
        finally {
            if (rd != nullptr && !rd->IsClosed) rd->Close();
            conn->Close();
        }
    }

    bool CategoryController::Update(CategoryModel^ m) {
        Validate(m, true);
        m->Updated_At = DateTime::Now;

        auto conn = DBConnection::GetConnection();
        conn->Open();
        try {
            auto cmd = gcnew SQLiteCommand(
                "UPDATE Categories "
                "SET Name=@n, Description=@d, Updated_At=@u "
                "WHERE Id=@id;",
                conn);
            cmd->Parameters->AddWithValue("@n", m->Name);
            cmd->Parameters->AddWithValue("@d", m->Description);
            cmd->Parameters->AddWithValue("@u", m->Updated_At);
            cmd->Parameters->AddWithValue("@id", m->Id);

            return cmd->ExecuteNonQuery() > 0;
        }
        finally {
            conn->Close();
        }
    }

    bool CategoryController::Delete(int id) {
        if (id <= 0) return false;

        auto conn = DBConnection::GetConnection();
        conn->Open();
        try {
            auto cmd = gcnew SQLiteCommand(
                "DELETE FROM Categories WHERE Id=@id;",
                conn);
            cmd->Parameters->AddWithValue("@id", id);
            return cmd->ExecuteNonQuery() > 0;
        }
        finally {
            conn->Close();
        }
    }

}  // namespace PMST
