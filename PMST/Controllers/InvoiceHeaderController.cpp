#include "InvoiceHeaderController.h"

namespace PMST {

    void InvoiceHeaderController::Validate(InvoiceHeaderModel^ m, bool requireId) {
        if (requireId && m->Id <= 0) throw gcnew ArgumentException("Invalid Invoice Header Id.");

        if (m->Pharmacy_Id <= 0 || !PharmacyExists(m->Pharmacy_Id))
            throw gcnew ArgumentException("Pharmacy_Id must refer to an existing pharmacy.");

        if (m->User_Id <= 0 || !UserExists(m->User_Id))
            throw gcnew ArgumentException("User_Id must refer to an existing user.");

        if (m->Total_Price < 0)
            throw gcnew ArgumentException("Total_Price cannot be negative.");
    }

    bool InvoiceHeaderController::PharmacyExists(int pharmacyId) {
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand("SELECT COUNT(1) FROM Pharmacies WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@id", pharmacyId);
        bool ok = (Int64)cmd->ExecuteScalar() > 0;
        conn->Close();
        return ok;
    }

    bool InvoiceHeaderController::UserExists(int userId) {
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand("SELECT COUNT(1) FROM Users WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@id", userId);
        bool ok = (Int64)cmd->ExecuteScalar() > 0;
        conn->Close();
        return ok;
    }

    InvoiceHeaderModel^ InvoiceHeaderController::Create(InvoiceHeaderModel^ m) {
        Validate(m, false);
        m->Created_At = DateTime::Now;
        m->Updated_At = DateTime::Now;

        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "INSERT INTO invoice_Header (Pharmacy_Id, User_Id, Total_Price, Created_At, Updated_At) "
            "VALUES (@p, @u, @tp, @cA, @uA); SELECT last_insert_rowid();", conn);
        cmd->Parameters->AddWithValue("@p", m->Pharmacy_Id);
        cmd->Parameters->AddWithValue("@u", m->User_Id);
        cmd->Parameters->AddWithValue("@tp", m->Total_Price);
        cmd->Parameters->AddWithValue("@cA", m->Created_At);
        cmd->Parameters->AddWithValue("@uA", m->Updated_At);
        m->Id = safe_cast<int>((Int64)cmd->ExecuteScalar());
        conn->Close();
        return m;
    }

    InvoiceHeaderModel^ InvoiceHeaderController::GetById(int id) {
        if (id <= 0) return nullptr;

        auto conn = DBConnection::GetConnection();
        conn->Open();
        SQLiteDataReader^ rd = nullptr;

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT Id, Pharmacy_Id, User_Id, Total_Price, Created_At, Updated_At "
                "FROM invoice_Header WHERE Id=@id;", conn);
            cmd->Parameters->AddWithValue("@id", id);

            rd = cmd->ExecuteReader();
            if (!rd->Read()) return nullptr;

            auto m = gcnew InvoiceHeaderModel();
            m->Id = rd->GetInt32(0);
            m->Pharmacy_Id = rd->GetInt32(1);
            m->User_Id = rd->GetInt32(2);
            m->Total_Price = rd->GetDecimal(3);
            m->Created_At = rd->GetDateTime(4);
            m->Updated_At = rd->GetDateTime(5);
            return m;
        }
        finally {
            if (rd != nullptr && !rd->IsClosed)
                rd->Close();
            conn->Close();
        }
    }

    System::Collections::Generic::List<InvoiceHeaderModel^>^ InvoiceHeaderController::GetAll() {
        auto list = gcnew System::Collections::Generic::List<InvoiceHeaderModel^>();
        auto conn = DBConnection::GetConnection();
        conn->Open();
        SQLiteDataReader^ rd = nullptr;

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT Id, Pharmacy_Id, User_Id, Total_Price, Created_At, Updated_At FROM invoice_Header;", conn);
            rd = cmd->ExecuteReader();

            while (rd->Read()) {
                auto m = gcnew InvoiceHeaderModel();
                m->Id = rd->GetInt32(0);
                m->Pharmacy_Id = rd->GetInt32(1);
                m->User_Id = rd->GetInt32(2);
                m->Total_Price = rd->GetDecimal(3);
                m->Created_At = rd->GetDateTime(4);
                m->Updated_At = rd->GetDateTime(5);
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

    bool InvoiceHeaderController::Update(InvoiceHeaderModel^ m) {
        Validate(m, true);
        m->Updated_At = DateTime::Now;
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand(
            "UPDATE invoice_Header SET Total_Price=@tp, Updated_At=@u WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@tp", m->Total_Price);
        cmd->Parameters->AddWithValue("@u", m->Updated_At);
        cmd->Parameters->AddWithValue("@id", m->Id);
        int rows = cmd->ExecuteNonQuery();
        conn->Close();
        return rows > 0;
    }

    bool InvoiceHeaderController::Delete(int id) {
        if (id <= 0) return false;
        auto conn = DBConnection::GetConnection(); conn->Open();
        auto cmd = gcnew SQLiteCommand("DELETE FROM invoice_Header WHERE Id=@id;", conn);
        cmd->Parameters->AddWithValue("@id", id);
        int rows = cmd->ExecuteNonQuery();
        conn->Close();
        return rows > 0;
    }
}
