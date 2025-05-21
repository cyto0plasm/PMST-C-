#pragma once

namespace PMST {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SQLite;
	using namespace System::Collections::Generic; 

	/// <summary>
	/// Summary for UIHelper
	/// </summary>
	public ref class UIHelper abstract sealed {

	public:
		 static void ShowUserFriendlyError(Exception^ ex, String^ context);
	
		 static void FillControlsFromSelectedRow(
			 DataGridView^ table,
			 Dictionary<String^, TextBox^>^ columnToControlMap);
		 static void PrintTable(DataGridView^ table);
		 static void UIHelper::ExportTableToCsv(DataGridView^ table);
		 static void PrintRow(DataGridViewCellMouseEventArgs^ e, DataGridView^ table);
		 static void FilterDataGridView(DataGridView^ table, String^ searchText);
	
		 //Table Cell Hover
		 static void HandleCellMouseEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		 static void HandleCellMouseLeave(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

};
}
