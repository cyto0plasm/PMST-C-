#include "DBConnection.h"
using namespace System::Data::SQLite;
using namespace System;
using namespace System::Windows::Forms;
SQLiteConnection^ DBConnection::GetConnection()
{
	SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);
	return conn;
}


SQLiteConnection^ DBConnection::GetOpenConnection()
{
	SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);
	conn->Open();

	auto pragmaCmd = gcnew SQLiteCommand("PRAGMA foreign_keys = ON;", conn);
	pragmaCmd->ExecuteNonQuery();

	return conn; // Leave it open
}

bool DBConnection::IsConnectionOpen(SQLiteConnection^ conn)
{
	return conn != nullptr && conn->State == System::Data::ConnectionState::Open;
}



void DBConnection::ResetDatabase()
{
	SQLiteConnection^ conn = GetOpenConnection();
	try {
		if (!IsConnectionOpen(conn)) {
			MessageBox::Show("Failed to open database connection.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Use transaction to maintain data integrity
		SQLiteTransaction^ transaction = conn->BeginTransaction();

		// List your tables here
		array<String^>^ tables = gcnew array<String^> {
			"categories", // child
				"suppliers",          
				"invoice_Header",
				"sales",
				"products",        
				"users"  ,   
				"pharmacies"
		};
		for each (String ^ table in tables) {
			// Delete data
			auto deleteCmd = gcnew SQLiteCommand("DELETE FROM " + table + ";", conn, transaction);
			deleteCmd->ExecuteNonQuery();

			// Reset auto-increment (SQLite keeps this in sqlite_sequence table)
			auto resetCmd = gcnew SQLiteCommand("DELETE FROM sqlite_sequence WHERE name = '" + table + "';", conn, transaction);
			resetCmd->ExecuteNonQuery();
		}

		transaction->Commit();

		MessageBox::Show("All data deleted and IDs reset successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Reset failed: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		conn->Close();
	}
}
