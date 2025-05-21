
#include "Dashboard.h"
#include "../Models/UserModel.h"
#include "../Models/PharmacyModel.h"
#include "../Controllers/CategoryController.h"
#include "../Controllers/SuppliersController.h"
#include "../Controllers/ProductsController.h"
#include "../Controllers/SalesController.h"
#include "../Helpers/UIHelper.h"

using namespace PMST;
//Constructor
Dashboard::Dashboard(UserModel^ user, PharmacyModel^ pharmacy)
{
	

	if (user == nullptr || pharmacy == nullptr) {
		throw gcnew ArgumentNullException("User or Pharmacy cannot be null");
	}
	currentUser = user;
	currentPharmacy = pharmacy;


	InitializeComponent();

	
	InitializeChart();

	//Charts 
	/*auto chartData = SaleController::GetSalesByProductName(currentPharmacy->Id);
	this->HomePanel->Controls->Add(PieChartPanel::Create(chartData));*/
	LoadCategories(currentPharmacy->Id);

	LoadSuppliers(currentPharmacy->Id);
	InitHeavyLogic();
	
}

void Dashboard::InitializeChart()
{
	// Initialize controller
	productController = gcnew PMST::ProductController();

	// Create and add pie chart
	pieChart = gcnew PieChartPanel();
	pieChart->BackColor = System::Drawing::Color::FromArgb(50 ,50,50);
	pieChart->ForeColor = System::Drawing::Color::White;
	pieChart->Dock = DockStyle::Fill;
	this->ChartPanel->Controls->Add(pieChart);

	// Load initial data (example for pharmacy ID 1)
	LoadChartData(1);
}

void Dashboard::LoadChartData(int pharmacyId)
{
	try
	{
		// Choose which data to show (quantity or value)
		Dictionary<String^, float>^ chartData =
			productController->GetProductValueByCategory(pharmacyId);
		// or: productController->GetProductQuantityByCategory(pharmacyId);

		pieChart->SetData(chartData);
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error loading chart data: " + ex->Message,
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	}
}
void Dashboard::InitHeavyLogic() {
	if (this->userBtn == nullptr) {
		throw gcnew Exception("userBtn control not found");
	}
	UpdateUserInfoDisplay();

	resources = gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid);



	// Save the user original image and create resized versions
	originalUserImage = this->userBtn->Image; // Original from resources
	collapsedUserImage = ResizeImage(originalUserImage, 48, 48); // Smaller size
	expandedUserImage = ResizeImage(originalUserImage, 65, 65);  // Larger size
	this->maximizeIcon = (resources->GetObject(L"max2") != nullptr) ?
		cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"max2")) :
		nullptr;

	this->minimizeIcon = (resources->GetObject(L"min2") != nullptr) ?
		cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"min2")) :
		nullptr;

	// Set initial image for the collapsed state btn
	if (this->maximizeIcon != nullptr) {
		this->minMax->Image = this->maximizeIcon;
	}
}


//HOME SCREEN
void Dashboard::UpdateUserInfoDisplay() {
	try {

		this->userBtn->Text = currentUser->Username;
		this->pharmacyName->Text = currentPharmacy->Name;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error updating user info: " + ex->Message);
	}
}
void Dashboard::LoadProfitSummaries() {
	auto sales = saleController->GetByPharmacy(currentPharmacy->Id);
	DateTime now = DateTime::Now;

	double todayTotal = 0.0;
	double monthTotal = 0.0;
	double yearTotal = 0.0;

	for each (auto s in sales) {
		auto createdAt = s->Created_At;

		if (createdAt.Date == now.Date)
			todayTotal += Convert::ToDouble(s->Total_Price);

		if (createdAt.Year == now.Year && createdAt.Month == now.Month)
			monthTotal += Convert::ToDouble(s->Total_Price);

		if (createdAt.Year == now.Year)
			yearTotal += Convert::ToDouble(s->Total_Price);
	}

	TotalProfitsListBox->Items->Clear();
	TotalProfitsListBox->Items->Add(String::Format("Today’s Sales: ${0:F2}", todayTotal));
	TotalProfitsListBox->Items->Add(String::Format("This Month’s Sales: ${0:F2}", monthTotal));
	TotalProfitsListBox->Items->Add(String::Format("This Year’s Sales: ${0:F2}", yearTotal));
}
//loading all the data to he application
System::Void Dashboard::Dashboard_Load(Object^ sender, EventArgs^ e) {
	//MessageBox::Show("Size: " + ManageProductContainer->Width + " x " + ManageProductContainer->Height + "\nLocation: " + ManageProductContainer->Location.ToString() + "\nDock: " + ManageProductContainer->Dock.ToString(), "Runtime Info");

	// First, clear all tables
	this->CategoryTable->Rows->Clear();
	this->ProductTable->Rows->Clear();
	this->SupplierTable->Rows->Clear();
	//this->recentSalesTable->Rows->Clear();
	this->CashierTable->Rows->Clear();


	// 1. Load categories and store them in a list
	auto categoryList = CategoryController::GetByPharmacy(currentPharmacy->Id);
	for each (CategoryModel ^ category in categoryList) {
		this->CategoryTable->Rows->Add(
			category->Id,
			category->Name,
			category->Description,
			FormatCustomDate(category->Created_At),
			FormatCustomDate(category->Updated_At)
		);
	}

	// 2. Load suppliers and store them in a list
	auto supplierList = SupplierController::GetByPharmacy(currentPharmacy->Id);
	for each (SupplierModel ^ supplier in supplierList) {
		this->SupplierTable->Rows->Add(
			supplier->Id,
			supplier->Name,
			supplier->Contact_Info,
			FormatCustomDate(supplier->Created_At),
			FormatCustomDate(supplier->Updated_At)
		);
	}

	// 3. Set up comboboxes for categories and suppliers first
	LoadCategories(currentPharmacy->Id);
	LoadSuppliers(currentPharmacy->Id);
	LoadInvoiceHeaders();
	LoadProfitSummaries();


	// 4. Load products
	auto productList = ProductController::GetByPharmacy(currentPharmacy->Id);

	// 5. Create lookup dictionaries for faster access
	Dictionary<int, String^>^ categoryNames = gcnew Dictionary<int, String^>();
	Dictionary<int, String^>^ supplierNames = gcnew Dictionary<int, String^>();

	// Populate category lookup dictionary
	for each (CategoryModel ^ category in categoryList) {
		// Add debugging output if needed
		// Console::WriteLine("Adding category ID {0} with name {1}", category->Id, category->Name);
		categoryNames[category->Id] = category->Name;
	}

	// Populate supplier lookup dictionary
	for each (SupplierModel ^ supplier in supplierList) {
		// Add debugging output if needed
		// Console::WriteLine("Adding supplier ID {0} with name {1}", supplier->Id, supplier->Name);
		supplierNames[supplier->Id] = supplier->Name;
	}

	// 6. Add products to the table with proper category and supplier names
	for each (ProductModel ^ product in productList) {
		// Debug output to check values
		// Console::WriteLine("Product: {0}, CategoryID: {1}, SupplierID: {2}", 
		//     product->Name, product->Category_Id, product->Supplier_Id);

		// Get category name using lookup with safety checks
		String^ categoryName = "Unknown";
		if (product->Category_Id > 0 && categoryNames->ContainsKey(product->Category_Id)) {
			categoryName = categoryNames[product->Category_Id];
		}

		// Get supplier name using lookup with safety checks
		String^ supplierName = "Unknown";
		if (product->Supplier_Id > 0 && supplierNames->ContainsKey(product->Supplier_Id)) {
			supplierName = supplierNames[product->Supplier_Id];
		}

		// Add row to product table
		this->ProductTable->Rows->Add(
			product->Id,
			product->Name,
			product->Price,
			product->Quantity,
			categoryName,  // Category name
			supplierName,  // Supplier name
			FormatCustomDate(product->Created_At),
			FormatCustomDate(product->Updated_At)
		);

	}
}

//  event handlers for the shortcut buttons In Home Screen
System::Void Dashboard::SCAddCategory_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create a small dialog form for adding a category
	Form^ categoryDialog = gcnew Form();
	categoryDialog->Text = "Add New Category";
	categoryDialog->Width = 400;
	categoryDialog->Height = 250;
	categoryDialog->StartPosition = FormStartPosition::CenterParent;
	categoryDialog->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	categoryDialog->MaximizeBox = false;
	categoryDialog->MinimizeBox = false;

	// Create controls for the form
	Label^ nameLabel = gcnew Label();
	nameLabel->Text = "Category Name:";
	nameLabel->Location = Point(20, 20);
	nameLabel->AutoSize = true;

	TextBox^ nameTextBox = gcnew TextBox();
	nameTextBox->Location = Point(20, 40);
	nameTextBox->Width = 340;

	Label^ descLabel = gcnew Label();
	descLabel->Text = "Description:";
	descLabel->Location = Point(20, 80);
	descLabel->AutoSize = true;

	TextBox^ descTextBox = gcnew TextBox();
	descTextBox->Location = Point(20, 100);
	descTextBox->Width = 340;
	descTextBox->Multiline = true;
	descTextBox->Height = 60;

	Button^ submitButton = gcnew Button();
	submitButton->Text = "Add Category";
	submitButton->Location = Point(230, 170);
	submitButton->DialogResult = System::Windows::Forms::DialogResult::OK;

	Button^ cancelButton = gcnew Button();
	cancelButton->Text = "Cancel";
	cancelButton->Location = Point(140, 170);
	cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;

	// Add controls to form
	categoryDialog->Controls->Add(nameLabel);
	categoryDialog->Controls->Add(nameTextBox);
	categoryDialog->Controls->Add(descLabel);
	categoryDialog->Controls->Add(descTextBox);
	categoryDialog->Controls->Add(submitButton);
	categoryDialog->Controls->Add(cancelButton);

	// Set the AcceptButton property
	categoryDialog->AcceptButton = submitButton;
	categoryDialog->CancelButton = cancelButton;

	// Show dialog and process result
	if (categoryDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// Temporarily store form data in Dashboard controls for processing
		this->CatName->Text = nameTextBox->Text;
		this->Catdesc->Text = descTextBox->Text;

		// Call the existing add method
		this->addCat_Click(nullptr, nullptr);
		LoadCategories(currentPharmacy->Id);

	}
}

System::Void Dashboard::SCAddSupplier_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create a small dialog form for adding a supplier
	Form^ supplierDialog = gcnew Form();
	supplierDialog->Text = "Add New Supplier";
	supplierDialog->Width = 400;
	supplierDialog->Height = 250;
	supplierDialog->StartPosition = FormStartPosition::CenterParent;
	supplierDialog->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	supplierDialog->MaximizeBox = false;
	supplierDialog->MinimizeBox = false;

	// Create controls for the form
	Label^ nameLabel = gcnew Label();
	nameLabel->Text = "Supplier Name:";
	nameLabel->Location = Point(20, 20);
	nameLabel->AutoSize = true;

	TextBox^ nameTextBox = gcnew TextBox();
	nameTextBox->Location = Point(20, 40);
	nameTextBox->Width = 340;

	Label^ contactLabel = gcnew Label();
	contactLabel->Text = "Contact Information:";
	contactLabel->Location = Point(20, 80);
	contactLabel->AutoSize = true;

	TextBox^ contactTextBox = gcnew TextBox();
	contactTextBox->Location = Point(20, 100);
	contactTextBox->Width = 340;
	contactTextBox->Multiline = true;
	contactTextBox->Height = 60;

	Button^ submitButton = gcnew Button();
	submitButton->Text = "Add Supplier";
	submitButton->Location = Point(230, 170);
	submitButton->DialogResult = System::Windows::Forms::DialogResult::OK;

	Button^ cancelButton = gcnew Button();
	cancelButton->Text = "Cancel";
	cancelButton->Location = Point(140, 170);
	cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;

	// Add controls to form
	supplierDialog->Controls->Add(nameLabel);
	supplierDialog->Controls->Add(nameTextBox);
	supplierDialog->Controls->Add(contactLabel);
	supplierDialog->Controls->Add(contactTextBox);
	supplierDialog->Controls->Add(submitButton);
	supplierDialog->Controls->Add(cancelButton);

	// Set the AcceptButton property
	supplierDialog->AcceptButton = submitButton;
	supplierDialog->CancelButton = cancelButton;

	// Show dialog and process result
	if (supplierDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// Temporarily store form data in Dashboard controls for processing
		this->SupplierName->Text = nameTextBox->Text;
		this->SupplierContact_Info->Text = contactTextBox->Text;

		// Call the existing add method
		this->AddSupplier_Btn_Click(nullptr, nullptr);

		LoadSuppliers(currentPharmacy->Id);
	}
}

System::Void Dashboard::SCAddProduct_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create a small dialog form for adding a product
	Form^ productDialog = gcnew Form();
	productDialog->Text = "Add New Product";
	productDialog->Width = 400;
	productDialog->Height = 400;
	productDialog->StartPosition = FormStartPosition::CenterParent;
	productDialog->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	productDialog->MaximizeBox = false;
	productDialog->MinimizeBox = false;

	// Create controls for the form
	int yPos = 20;
	int spacing = 40;

	Label^ nameLabel = gcnew Label();
	nameLabel->Text = "Product Name:";
	nameLabel->Location = Point(20, yPos);
	nameLabel->AutoSize = true;

	yPos += 20;
	TextBox^ nameTextBox = gcnew TextBox();
	nameTextBox->Location = Point(20, yPos);
	nameTextBox->Width = 340;

	yPos += spacing;
	Label^ priceLabel = gcnew Label();
	priceLabel->Text = "Price:";
	priceLabel->Location = Point(20, yPos);
	priceLabel->AutoSize = true;

	yPos += 20;
	TextBox^ priceTextBox = gcnew TextBox();
	priceTextBox->Location = Point(20, yPos);
	priceTextBox->Width = 150;

	yPos += spacing;
	Label^ quantityLabel = gcnew Label();
	quantityLabel->Text = "Quantity:";
	quantityLabel->Location = Point(20, yPos);
	quantityLabel->AutoSize = true;

	yPos += 20;
	TextBox^ quantityTextBox = gcnew TextBox();
	quantityTextBox->Location = Point(20, yPos);
	quantityTextBox->Width = 150;

	yPos += spacing;
	Label^ categoryLabel = gcnew Label();
	categoryLabel->Text = "Category:";
	categoryLabel->Location = Point(20, yPos);
	categoryLabel->AutoSize = true;

	yPos += 20;
	ComboBox^ categoryComboBox = gcnew ComboBox();
	categoryComboBox->Location = Point(20, yPos);
	categoryComboBox->Width = 340;
	categoryComboBox->DropDownStyle = ComboBoxStyle::DropDownList;

	// Duplicate the data source from the main form's combo box
	categoryComboBox->DataSource = this->CategoryComboBox->DataSource;
	categoryComboBox->DisplayMember = this->CategoryComboBox->DisplayMember;
	categoryComboBox->ValueMember = this->CategoryComboBox->ValueMember;

	yPos += spacing;
	Label^ supplierLabel = gcnew Label();
	supplierLabel->Text = "Supplier:";
	supplierLabel->Location = Point(20, yPos);
	supplierLabel->AutoSize = true;

	yPos += 20;
	ComboBox^ supplierComboBox = gcnew ComboBox();
	supplierComboBox->Location = Point(20, yPos);
	supplierComboBox->Width = 340;
	supplierComboBox->DropDownStyle = ComboBoxStyle::DropDownList;

	// Duplicate the data source from the main form's combo box
	supplierComboBox->DataSource = this->SupplierComboBox->DataSource;
	supplierComboBox->DisplayMember = this->SupplierComboBox->DisplayMember;
	supplierComboBox->ValueMember = this->SupplierComboBox->ValueMember;

	yPos += spacing;
	Button^ submitButton = gcnew Button();
	submitButton->Text = "Add Product";
	submitButton->Location = Point(230, yPos);
	submitButton->DialogResult = System::Windows::Forms::DialogResult::OK;

	Button^ cancelButton = gcnew Button();
	cancelButton->Text = "Cancel";
	cancelButton->Location = Point(140, yPos);
	cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;

	// Add controls to form
	productDialog->Controls->Add(nameLabel);
	productDialog->Controls->Add(nameTextBox);
	productDialog->Controls->Add(priceLabel);
	productDialog->Controls->Add(priceTextBox);
	productDialog->Controls->Add(quantityLabel);
	productDialog->Controls->Add(quantityTextBox);
	productDialog->Controls->Add(categoryLabel);
	productDialog->Controls->Add(categoryComboBox);
	productDialog->Controls->Add(supplierLabel);
	productDialog->Controls->Add(supplierComboBox);
	productDialog->Controls->Add(submitButton);
	productDialog->Controls->Add(cancelButton);

	// Set the AcceptButton property
	productDialog->AcceptButton = submitButton;
	productDialog->CancelButton = cancelButton;

	// Show dialog and process result
	if (productDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// Temporarily store form data in Dashboard controls for processing
		this->productName->Text = nameTextBox->Text;
		this->productPrice->Text = priceTextBox->Text;
		this->productQuantity->Text = quantityTextBox->Text;

		// Set the selected values in the main form's combo boxes
		this->CategoryComboBox->SelectedValue = categoryComboBox->SelectedValue;
		this->SupplierComboBox->SelectedValue = supplierComboBox->SelectedValue;

		// Call the existing add method
		this->addProduct_Click(nullptr, nullptr);
	}
}

// HOME SCREEEN END



//CASHIER SCREEN

//Search Products From Cashier 
System::Void Dashboard::CashierSearchProduct_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ searchText = CashierSearchProduct->Text->Trim();
	SearchSuggestionsList->Items->Clear();

	if (String::IsNullOrEmpty(searchText)) return;

	auto products = productController->SearchProducts(searchText, currentPharmacy->Id);

	for each (auto product in products) {
		String^ displayText = String::Format("{0}|{1}|{2}", product->Id, product->Name, product->Price);
		SearchSuggestionsList->Items->Add(displayText);
	}
}
System::Void Dashboard::SearchSuggestionsList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (SearchSuggestionsList->SelectedItem != nullptr) {
		String^ selectedText = safe_cast<String^>(SearchSuggestionsList->SelectedItem);
		array<String^>^ parts = selectedText->Split('|');
		if (parts->Length == 3) {
			CashierSearchProduct->Text = parts[1]; // Set the product name in the search box
			CashierSearchProduct->SelectionStart = CashierSearchProduct->Text->Length; // Move cursor to end

			// Extract product details
			String^ productId = parts[0];
			String^ productName = parts[1];
			double productPrice = Convert::ToDouble(parts[2]);

			// Check if product already exists in the table
			bool productExists = false;
			for (int i = 0; i < CashierTable->Rows->Count; ++i) {
				auto cellValue = CashierTable->Rows[i]->Cells["CashProductName"]->Value;
				if (cellValue != nullptr && safe_cast<String^>(cellValue) == productName) {
					MessageBox::Show("Product already added to cashier.");
					productExists = true;
					break;
				}
			}

			// If product doesn't exist in the table, add it
			if (!productExists) {
				int rowIndex = CashierTable->Rows->Add();
				CashierTable->Rows[rowIndex]->Cells["CashProductId"]->Value = nextCashRowId;
				CashierTable->Rows[rowIndex]->Cells["CashProductName"]->Value = productName;
				CashierTable->Rows[rowIndex]->Cells["CashProductPrice"]->Value = productPrice;
				CashierTable->Rows[rowIndex]->Cells["CashProductQuantity"]->Value = 1; // Set default quantity to 1
				CashierTable->Rows[rowIndex]->Cells["CashTotalProductPrice"]->Value = productPrice; // Initial total is just the price

				nextCashRowId++; // Increment ID for next row

				// Recalculate the overall total
				UpdateTotalAmount();
			}
		}
	}
}
//update the total amount Label
double Dashboard::UpdateTotalAmount() {
	double totalAmount = 0.0;
	for (int i = 0; i < CashierTable->Rows->Count; ++i) {
		if (CashierTable->Rows[i]->Cells["CashTotalProductPrice"]->Value != nullptr) {
			totalAmount += Convert::ToDouble(CashierTable->Rows[i]->Cells["CashTotalProductPrice"]->Value);
		}
	}

	// Assuming you have a label to display the total
	TotalInvoiceLab->Text = String::Format("Total: ${0:F2}", totalAmount);
	return totalAmount;
}
//cashier Table
// Handle cell edit completion
System::Void Dashboard::CashierTable_CellEndEdit(System::Object^ sender, DataGridViewCellEventArgs^ e) {
	// Check if the edited cell is in the quantity column
	if (e->ColumnIndex == CashierTable->Columns["CashProductQuantity"]->Index) {
		// Get the new quantity value
		int newQuantity = Convert::ToInt32(CashierTable->Rows[e->RowIndex]->Cells["CashProductQuantity"]->Value);
		double productPrice = Convert::ToDouble(CashierTable->Rows[e->RowIndex]->Cells["CashProductPrice"]->Value);
		// Update the total price for that row
		double totalPrice = newQuantity * productPrice;
		CashierTable->Rows[e->RowIndex]->Cells["CashTotalProductPrice"]->Value = totalPrice;
		// Update the overall total amount
		UpdateTotalAmount();
	}
}
// Handle cell value changes
System::Void Dashboard::CashierTable_CellValueChanged(System::Object^ sender, DataGridViewCellEventArgs^ e) {
	// Ensure the column exists
	if (CashierTable->Columns["CashProductQuantity"] == nullptr) {
		MessageBox::Show("Column 'CashProductQuantity' does not exist.");
		return;
	}

	// Ensure the row index is valid
	if (e->RowIndex < 0) {
		return; // Ignore invalid rows
	}

	// Check if the changed cell is in the quantity column
	if (e->ColumnIndex == CashierTable->Columns["CashProductQuantity"]->Index) {
		int newQuantity = Convert::ToInt32(CashierTable->Rows[e->RowIndex]->Cells["CashProductQuantity"]->Value);
		double productPrice = Convert::ToDouble(CashierTable->Rows[e->RowIndex]->Cells["CashProductPrice"]->Value);
		double totalPrice = newQuantity * productPrice;
		CashierTable->Rows[e->RowIndex]->Cells["CashTotalProductPrice"]->Value = totalPrice;
		UpdateTotalAmount();
	}
}
// Handle Enter key in the grid to commit changes and move focus
System::Void Dashboard::CashierTable_KeyDown(System::Object^ sender, KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter) {
		// Commit the edit
		CashierTable->EndEdit();
		// Optionally, you can move to the next cell or row
		int currentRow = CashierTable->CurrentCell->RowIndex;
		int currentColumn = CashierTable->CurrentCell->ColumnIndex;
		if (currentColumn < CashierTable->Columns->Count - 1) {
			CashierTable->CurrentCell = CashierTable->Rows[currentRow]->Cells[currentColumn + 1];
		}
		else if (currentRow < CashierTable->Rows->Count - 1) {
			CashierTable->CurrentCell = CashierTable->Rows[currentRow + 1]->Cells[0];
		}
		else {
			// Move focus to another control if needed
			// For example, you can move focus to the TotalInvoiceLab
			TotalInvoiceLab->Focus();
		}
	}




}
System::Void Dashboard::CashierTable_CellValueChanged_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->ColumnIndex == CashierTable->Columns["CashProductQuantity"]->Index) {
		// Get the new quantity value
		if (e->RowIndex < 0) {
			return; // Ignore invalid rows
		}
		int newQuantity = Convert::ToInt32(CashierTable->Rows[e->RowIndex]->Cells["CashProductQuantity"]->Value);
		double productPrice = Convert::ToDouble(CashierTable->Rows[e->RowIndex]->Cells["CashProductPrice"]->Value);
		// Update the total price for that row
		double totalPrice = newQuantity * productPrice;
		CashierTable->Rows[e->RowIndex]->Cells["CashTotalProductPrice"]->Value = totalPrice;
		// Update the overall total amount
		UpdateTotalAmount();
	}
}
System::Void Dashboard::AddProductToCashierTable(System::Object^ sender, System::EventArgs^ e) {
	if (SearchSuggestionsList->SelectedItem == nullptr) return;

	String^ selectedText = safe_cast<String^>(SearchSuggestionsList->SelectedItem);
	array<String^>^ parts = selectedText->Split('|');

	if (parts->Length != 3) return;

	String^ productName = parts[1];
	double productPrice = Convert::ToDouble(parts[2]);

	// Check if product already added
	for (int i = 0; i < CashierTable->Rows->Count; ++i) {
		auto cellValue = CashierTable->Rows[i]->Cells["CashProductName"]->Value;
		if (cellValue != nullptr && safe_cast<String^>(cellValue) == productName) {
			MessageBox::Show("Product already added to cashier.");
			return;
		}
	}

	// Add new row
	int rowIndex = CashierTable->Rows->Add();
	CashierTable->Rows[rowIndex]->Cells["CashProductId"]->Value = nextCashRowId;  // auto id
	CashierTable->Rows[rowIndex]->Cells["CashProductName"]->Value = productName;
	CashierTable->Rows[rowIndex]->Cells["CashProductPrice"]->Value = productPrice;

	nextCashRowId++;  // increment id for next row
}
System::Void Dashboard::PayInvoice_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(payFeild->Text)) {
		MessageBox::Show("Enter payment amount."); return;
	}

	double paidAmount;
	if (!Double::TryParse(payFeild->Text, paidAmount) || paidAmount <= 0) {
		MessageBox::Show("Invalid payment amount."); return;
	}

	if (CashierTable->Rows->Count == 0) {
		MessageBox::Show("No products to process."); return;
	}

	double totalAmount = UpdateTotalAmount();
	if (paidAmount != totalAmount) {
		MessageBox::Show("Paid amount must exactly match total."); return;
	}

	auto result = MessageBox::Show(
		String::Format("Total: ${0:F2}\nProceed with payment?", totalAmount),
		"Confirm Payment", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

	if (result != System::Windows::Forms::DialogResult::Yes) return;

	// 1. Save invoice header first
	auto invoiceHeader = gcnew InvoiceHeaderModel();
	invoiceHeader->Pharmacy_Id = currentPharmacy->Id;
	invoiceHeader->Total_Price = Convert::ToDecimal(totalAmount);
	invoiceHeader->User_Id = currentUser->Id;
	invoiceHeader->Created_At = DateTime::Now;
	invoiceHeader->Updated_At = DateTime::Now;

	invoiceHeader = invoiceHeaderController->Create(invoiceHeader);
	int invoiceId = invoiceHeader->Id;

	// 2. Save each sale and link to invoiceId
	for (int i = 0; i < CashierTable->Rows->Count; ++i) {
		auto sale = gcnew PMST::SaleModel();
		sale->Pharmacy_Id = currentPharmacy->Id;
		sale->Product_Id = Convert::ToInt32(CashierTable->Rows[i]->Cells["CashProductId"]->Value);
		sale->Quantity = Convert::ToInt32(CashierTable->Rows[i]->Cells["CashProductQuantity"]->Value);
		sale->Total_Price = Convert::ToDecimal(
			Convert::ToDouble(CashierTable->Rows[i]->Cells["CashProductPrice"]->Value) * sale->Quantity);
		sale->User_Id = Nullable<int>(currentUser->Id);
		sale->Invoice_Id = invoiceId; // link to invoice
		saleController->Create(sale);
	}
	//load invoice headers
	LoadInvoiceHeaders();
	// 3. Reset UI
	MessageBox::Show("Payment successful!");
	CashierTable->Rows->Clear();
	TotalInvoiceLab->Text = "Total: $0.00";
	payFeild->Text = "";
	CashierSearchProduct->Focus();
	SearchSuggestionsList->Items->Clear();
}
//END CASHIER SCREEEN

//INVOICE HEADER Screen

System::Void Dashboard::LoadInvoiceHeaders() {
	// Clear existing rows
	InvoiceHeaderTable->Rows->Clear();

	// Fetch all invoices from DB
	auto invoices = invoiceHeaderController->GetByPharmacy(currentPharmacy->Id); // You'll need to make this method (I'll show)

	for each (InvoiceHeaderModel ^ inv in invoices) {
		InvoiceHeaderTable->Rows->Add(
			inv->Id,
			inv->Total_Price.ToString("F2"),
			FormatCustomDate(inv->Created_At),
			FormatCustomDate(inv->Updated_At)
		);
	}
}
System::Void Dashboard::InvoiceHeaderTable_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex < 0) return; // ignore header clicks

	InvoiceDetailsPanel->Controls->Clear();
	InvoiceDetailsPanel->AutoScroll = true;

	int invoiceId = Convert::ToInt32(InvoiceHeaderTable->Rows[e->RowIndex]->Cells["InvoiceHeaderId"]->Value);
	currentInvoiceId = invoiceId;

	// Create mainPanel and dock it fully inside InvoiceDetailsPanel
	Panel^ mainPanel = gcnew Panel();
	mainPanel->Dock = DockStyle::Fill;
	mainPanel->AutoScroll = true;  // if content exceeds size, scrollbar appears
	mainPanel->BackColor = Color::White;
	mainPanel->Padding = System::Windows::Forms::Padding(15);
	InvoiceDetailsPanel->Controls->Add(mainPanel);

	// Fetch invoice header
	auto invoice = invoiceHeaderController->GetById(invoiceId);
	if (invoice == nullptr) {
		AddHeading("Invoice not found", mainPanel, 10);
		return;
	}

	// Fetch sales linked to invoice
	auto salesList = saleController->GetByInvoiceId(invoiceId);
	if (salesList == nullptr || salesList->Count == 0) {
		AddHeading("Invoice #" + invoiceId.ToString(), mainPanel, 10);
		AddNormalText("No products found for this invoice.", mainPanel, 10, 40);
		return;
	}

	int y = 10;

	// Print button with anchoring (top right)
	Button^ printButton = gcnew Button();
	printButton->Text = "Print";
	printButton->Width = 100;
	printButton->Height = 35;
	printButton->BackColor = Color::FromArgb(70, 130, 180);
	printButton->ForeColor = Color::White;
	printButton->Font = gcnew Drawing::Font("Segoe UI", 9.5F, FontStyle::Bold);
	printButton->FlatStyle = FlatStyle::Flat;
	printButton->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Right);
	printButton->Location = Point(mainPanel->Width - printButton->Width - 15, y);
	printButton->Click += gcnew EventHandler(this, &Dashboard::PrintButton_Click);
	mainPanel->Controls->Add(printButton);

	// Heading
	AddHeading("Invoice #" + invoiceId.ToString(), mainPanel, y);
	y += 40;

	// Metadata panel
	Panel^ metadataPanel = gcnew Panel();
	metadataPanel->Location = Point(15, y);
	metadataPanel->Width = mainPanel->ClientSize.Width - 30;
	metadataPanel->Height = 80;
	metadataPanel->BackColor = Color::FromArgb(245, 245, 250);
	metadataPanel->BorderStyle = BorderStyle::FixedSingle;
	metadataPanel->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right);
	mainPanel->Controls->Add(metadataPanel);

	AddBoldText("Date:", metadataPanel, 15, 15);
	AddNormalText(FormatCustomDate(invoice->Created_At), metadataPanel, 120, 15);
	AddBoldText("Invoice Total:", metadataPanel, 15, 45);
	AddHighlightedText("$" + invoice->Total_Price.ToString("F2"), metadataPanel, 120, 45);

	y += metadataPanel->Height + 20;

	// Products subheading
	AddSubheading("Products", mainPanel, y);
	y += 35;

	int colWidth = (mainPanel->ClientSize.Width - 60) / 4;
	int col1 = 10;
	int col2 = col1 + colWidth;
	int col3 = col2 + (colWidth / 2);
	int col4 = col3 + colWidth;

	// Table headers
	AddColumnHeader("Product", col1, mainPanel, y);
	AddColumnHeader("Qty", col2, mainPanel, y);
	AddColumnHeader("Unit Price", col3, mainPanel, y);
	AddColumnHeader("Total", col4, mainPanel, y);
	y += 25;

	AddSeparator(mainPanel, y);
	y += 15;

	double calculatedTotal = 0;
	bool isAlternateRow = false;

	for each (PMST::SaleModel ^ sale in salesList) {
		auto product = productController->GetById(sale->Product_Id);
		String^ productName = product != nullptr ? product->Name : "Unknown Product";
		Decimal unitPrice = sale->Total_Price / sale->Quantity;

		Panel^ rowPanel = gcnew Panel();
		rowPanel->Location = Point(0, y);
		rowPanel->Width = mainPanel->ClientSize.Width - 40;
		rowPanel->Height = 30;
		rowPanel->BackColor = isAlternateRow ? Color::FromArgb(245, 245, 250) : Color::White;
		rowPanel->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right);
		mainPanel->Controls->Add(rowPanel);

		AddNormalText(productName, rowPanel, col1, 5);
		AddNormalText(sale->Quantity.ToString(), rowPanel, col2, 5);
		AddNormalText("$" + unitPrice.ToString("F2"), rowPanel, col3, 5);
		AddNormalText("$" + sale->Total_Price.ToString("F2"), rowPanel, col4, 5);

		y += rowPanel->Height;
		isAlternateRow = !isAlternateRow;
		calculatedTotal += Convert::ToDouble(sale->Total_Price);
	}

	y += 15;
	AddSeparator(mainPanel, y);
	y += 20;

	// Total panel
	Panel^ totalPanel = gcnew Panel();
	totalPanel->Location = Point(mainPanel->ClientSize.Width - 230, y);
	totalPanel->Width = 200;
	totalPanel->Height = 35;
	totalPanel->BackColor = Color::FromArgb(230, 230, 250);
	totalPanel->BorderStyle = BorderStyle::FixedSingle;
	totalPanel->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Right);
	mainPanel->Controls->Add(totalPanel);

	AddBoldText("TOTAL:", totalPanel, 10, 8);
	AddHighlightedText("$" + calculatedTotal.ToString("F2"), totalPanel, 80, 8);

	// Adjust mainPanel height if needed (optional)
	// mainPanel->Height = Math::Min(y + totalPanel->Height + 20, 770);

	// Refresh UI to ensure updates show
	InvoiceDetailsPanel->ResumeLayout();
	InvoiceDetailsPanel->PerformLayout();
	InvoiceDetailsPanel->Refresh();
}
// Print button click handler
System::Void Dashboard::PrintButton_Click(System::Object^ sender, System::EventArgs^ e) {
	PrintInvoice(currentInvoiceId);
}	   // Helper methods for UI components with improved styling
System::Void Dashboard::AddHeading(String^ text, Control^ parent, int y) {
	Label^ lbl = gcnew Label();
	lbl->Text = text;
	lbl->AutoSize = false;
	lbl->Width = parent->Width - 30;
	lbl->Height = 30;
	lbl->TextAlign = ContentAlignment::MiddleLeft;
	lbl->Location = Point(0, y);
	lbl->Font = gcnew Drawing::Font("Segoe UI", 14, FontStyle::Bold);
	lbl->ForeColor = Color::FromArgb(50, 50, 80);
	parent->Controls->Add(lbl);
}
//Invoice UI INIT
System::Void Dashboard::AddSubheading(String^ text, Control^ parent, int y) {
	Label^ lbl = gcnew Label();
	lbl->Text = text;
	lbl->AutoSize = false;
	lbl->Width = parent->Width - 30;
	lbl->Height = 25;
	lbl->TextAlign = ContentAlignment::MiddleLeft;
	lbl->Location = Point(0, y);
	lbl->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
	lbl->ForeColor = Color::FromArgb(70, 70, 100);
	parent->Controls->Add(lbl);
}
System::Void Dashboard::AddColumnHeader(String^ text, int x, Control^ parent, int y) {
	Label^ lbl = gcnew Label();
	lbl->Text = text;
	lbl->AutoSize = true;
	lbl->Location = Point(x, y);
	lbl->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
	lbl->ForeColor = Color::FromArgb(60, 60, 90);
	parent->Controls->Add(lbl);
}
System::Void Dashboard::AddNormalText(String^ text, Control^ parent, int x, int y) {
	Label^ lbl = gcnew Label();
	lbl->Text = text;
	lbl->AutoSize = true;
	lbl->Location = Point(x, y);
	lbl->Font = gcnew Drawing::Font("Segoe UI", 9.5F);
	lbl->ForeColor = Color::FromArgb(60, 60, 60);
	parent->Controls->Add(lbl);
}
System::Void Dashboard::AddBoldText(String^ text, Control^ parent, int x, int y) {
	Label^ lbl = gcnew Label();
	lbl->Text = text;
	lbl->AutoSize = true;
	lbl->Location = Point(x, y);
	lbl->Font = gcnew Drawing::Font("Segoe UI", 9.5F, FontStyle::Bold);
	lbl->ForeColor = Color::FromArgb(50, 50, 80);
	parent->Controls->Add(lbl);
}
System::Void Dashboard::AddHighlightedText(String^ text, Control^ parent, int x, int y) {
	Label^ lbl = gcnew Label();
	lbl->Text = text;
	lbl->AutoSize = true;
	lbl->Location = Point(x, y);
	lbl->Font = gcnew Drawing::Font("Segoe UI", 11, FontStyle::Bold);
	lbl->ForeColor = Color::FromArgb(20, 100, 120);
	parent->Controls->Add(lbl);
}
System::Void Dashboard::AddSeparator(Control^ parent, int y) {
	Panel^ separator = gcnew Panel();
	separator->Location = Point(0, y);
	separator->Width = parent->Width - 30;
	separator->Height = 1;
	separator->BackColor = Color::FromArgb(200, 200, 220);
	parent->Controls->Add(separator);
}
System::Void Dashboard::PrintInvoice(int invoiceId) {
	try {
		// Set up print document if not already created
		if (printDocument == nullptr) {
			printDocument = gcnew System::Drawing::Printing::PrintDocument();
			printDocument->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &Dashboard::PrintDocument_PrintPage);
		}

		// Show print dialog
		PrintDialog^ printDialog = gcnew PrintDialog();
		printDialog->Document = printDocument;

		if (printDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
			printDocument->Print();
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error printing invoice: " + ex->Message, "Print Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
// Print page handler
System::Void Dashboard::PrintDocument_PrintPage(System::Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e) {
	try {
		// Get invoice data
		auto invoice = invoiceHeaderController->GetById(currentInvoiceId);
		auto salesList = saleController->GetByInvoiceId(currentInvoiceId);

		if (invoice == nullptr || salesList == nullptr) {
			MessageBox::Show("Invoice data not found", "Print Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Font settings
		Drawing::Font^ headerFont = gcnew Drawing::Font("Arial", 12, FontStyle::Bold);
		Drawing::Font^ normalFont = gcnew Drawing::Font("Arial", 10, FontStyle::Regular);
		Drawing::Font^ boldFont = gcnew Drawing::Font("Arial", 10, FontStyle::Bold);
		SolidBrush^ brush = gcnew SolidBrush(Color::Black);

		// Set up coordinates - ALL float
		float startX = static_cast<float>(e->MarginBounds.Left);
		float startY = static_cast<float>(e->MarginBounds.Top);
		float offset = 25.0f; // Line spacing
		float currentY = startY;
		float width = static_cast<float>(e->MarginBounds.Width);

		// Print header
		String^ storeName = "PMS Pharmacy";
		e->Graphics->DrawString(storeName, headerFont, brush, startX + (width / 2.0f) - 60.0f, currentY);
		currentY += offset;

		e->Graphics->DrawLine(gcnew Pen(Color::Black), startX, currentY, startX + width, currentY);
		currentY += offset / 2.0f;

		// Invoice info
		e->Graphics->DrawString("Invoice #" + currentInvoiceId, headerFont, brush, startX, currentY);
		currentY += offset;

		e->Graphics->DrawString("Date: " + FormatCustomDate(invoice->Created_At), normalFont, brush, startX, currentY);
		currentY += offset * 1.5f;

		// Column headers
		float col1 = startX;
		float col2 = startX + 250.0f;
		float col3 = startX + 350.0f;
		float col4 = startX + 450.0f;

		e->Graphics->DrawString("Product", boldFont, brush, col1, currentY);
		e->Graphics->DrawString("Qty", boldFont, brush, col2, currentY);
		e->Graphics->DrawString("Unit Price", boldFont, brush, col3, currentY);
		e->Graphics->DrawString("Total", boldFont, brush, col4, currentY);
		currentY += offset;

		e->Graphics->DrawLine(gcnew Pen(Color::Black), startX, currentY, startX + width, currentY);
		currentY += offset / 2.0f;

		// Print products
		double totalAmount = 0;
		for each (PMST::SaleModel ^ sale in salesList) {
			auto product = productController->GetById(sale->Product_Id);
			String^ productName = product != nullptr ? product->Name : "Unknown Product";
			Decimal unitPrice = sale->Total_Price / sale->Quantity;

			// Truncate long product names
			if (productName->Length > 30) {
				productName = productName->Substring(0, 27) + "...";
			}

			e->Graphics->DrawString(productName, normalFont, brush, col1, currentY);
			e->Graphics->DrawString(sale->Quantity.ToString(), normalFont, brush, col2, currentY);
			e->Graphics->DrawString("$" + unitPrice.ToString("F2"), normalFont, brush, col3, currentY);
			e->Graphics->DrawString("$" + sale->Total_Price.ToString("F2"), normalFont, brush, col4, currentY);

			currentY += offset;
			totalAmount += Convert::ToDouble(sale->Total_Price);
		}

		// Draw total
		e->Graphics->DrawLine(gcnew Pen(Color::Black), startX, currentY, startX + width, currentY);
		currentY += offset;

		e->Graphics->DrawString("TOTAL:", boldFont, brush, col3, currentY);
		e->Graphics->DrawString("$" + totalAmount.ToString("F2"), boldFont, brush, col4, currentY);
		currentY += offset * 2.0f;

		// Footer
		e->Graphics->DrawString("Thank you for your purchase!", normalFont, brush, startX + (width / 2.0f) - 80.0f, currentY);

		// No more pages
		e->HasMorePages = false;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error printing page: " + ex->Message, "Print Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
//END INVOICE HEADER SCREEN



// PRODUCT SCREEN
// 
// category loading function for product combobox
void Dashboard::LoadCategories(int pharmacyId) {
	try {
		// Get the categories for this pharmacy
		auto categories = CategoryController::GetByPharmacy(pharmacyId);

		if (categories == nullptr || categories->Count == 0) {
			// Handle empty case
			this->CategoryComboBox->DataSource = nullptr;
			this->CategoryComboBox->Items->Clear();
			return;
		}

		// First clear the existing data source
		this->CategoryComboBox->DataSource = nullptr;

		// Then set the new data source
		this->CategoryComboBox->DataSource = categories;
		this->CategoryComboBox->DisplayMember = "Name";
		this->CategoryComboBox->ValueMember = "Id";

		// Make sure no item is initially selected
		if (categories->Count > 0) {
			this->CategoryComboBox->SelectedIndex = -1;
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show(
			"Error loading categories: " + ex->Message,
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);
	}
}
//  supplier loading function for product combobox
void Dashboard::LoadSuppliers(int pharmacyId) {
	try {
		// Get the suppliers for this pharmacy
		auto suppliers = SupplierController::GetByPharmacy(pharmacyId);

		if (suppliers == nullptr || suppliers->Count == 0) {
			// Handle empty case
			this->SupplierComboBox->DataSource = nullptr;
			this->SupplierComboBox->Items->Clear();
			return;
		}

		// First clear the existing data source
		this->SupplierComboBox->DataSource = nullptr;

		// Then set the new data source
		this->SupplierComboBox->DataSource = suppliers;
		this->SupplierComboBox->DisplayMember = "Name";
		this->SupplierComboBox->ValueMember = "Id";

		// Make sure no item is initially selected
		if (suppliers->Count > 0) {
			this->SupplierComboBox->SelectedIndex = -1;
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show(
			"Error loading suppliers: " + ex->Message,
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);
	}
}
// refresh the product table and its data with category and supplier
void Dashboard::RefreshProductTable() {
	try {
		// Clear the table
		this->ProductTable->Rows->Clear();

		// Get fresh data
		auto productList = ProductController::GetByPharmacy(currentPharmacy->Id);
		auto categoryList = CategoryController::GetByPharmacy(currentPharmacy->Id);
		auto supplierList = SupplierController::GetByPharmacy(currentPharmacy->Id);

		// Create lookup dictionaries
		Dictionary<int, String^>^ categoryNames = gcnew Dictionary<int, String^>();
		Dictionary<int, String^>^ supplierNames = gcnew Dictionary<int, String^>();

		// Populate dictionaries
		for each (CategoryModel ^ category in categoryList) {
			categoryNames[category->Id] = category->Name;
		}

		for each (SupplierModel ^ supplier in supplierList) {
			supplierNames[supplier->Id] = supplier->Name;
		}

		// Populate the table
		for each (ProductModel ^ product in productList) {
			String^ categoryName = "Unknown";
			if (product->Category_Id > 0 && categoryNames->ContainsKey(product->Category_Id)) {
				categoryName = categoryNames[product->Category_Id];
			}

			String^ supplierName = "Unknown";
			if (product->Supplier_Id > 0 && supplierNames->ContainsKey(product->Supplier_Id)) {
				supplierName = supplierNames[product->Supplier_Id];
			}

			this->ProductTable->Rows->Add(
				product->Id,
				product->Name,
				product->Price,
				product->Quantity,
				categoryName,
				supplierName,
				FormatCustomDate(product->Created_At),
				FormatCustomDate(product->Updated_At)
			);
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show(
			"Error refreshing product table: " + ex->Message,
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);
	}
}
//Product Database Button Handling
System::Void Dashboard::addProduct_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Input validation
		if (String::IsNullOrWhiteSpace(this->productName->Text))
			throw gcnew Exception("Product name cannot be empty");

		if (String::IsNullOrWhiteSpace(this->productPrice->Text))
			throw gcnew Exception("Product price cannot be empty");

		if (String::IsNullOrWhiteSpace(this->productQuantity->Text))
			throw gcnew Exception("Product quantity cannot be empty");

		if (this->CategoryComboBox->SelectedValue == nullptr)
			throw gcnew Exception("Please select a category");

		if (this->SupplierComboBox->SelectedValue == nullptr)
			throw gcnew Exception("Please select a supplier");

		auto m = gcnew ProductModel();
		m->Pharmacy_Id = currentPharmacy->Id;
		m->Name = this->productName->Text->Trim();
		m->Price = Convert::ToDecimal(this->productPrice->Text->Trim());
		m->Quantity = Convert::ToInt32(this->productQuantity->Text->Trim());

		// Get selected IDs directly from bound ComboBoxes
		m->Category_Id = Convert::ToInt32(this->CategoryComboBox->SelectedValue);
		m->Supplier_Id = Convert::ToInt32(this->SupplierComboBox->SelectedValue);

		// Create product in database
		m = ProductController::Create(m);
		if (m == nullptr) {
			MessageBox::Show("Product could not be added. It may already exist or something went wrong.",
				"Add Product Failed",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning);
			return;
		}
		// Get the actual selected objects from the ComboBoxes
		CategoryModel^ selectedCategory = nullptr;
		SupplierModel^ selectedSupplier = nullptr;

		auto categoryList = safe_cast<List<CategoryModel^>^>(this->CategoryComboBox->DataSource);
		auto supplierList = safe_cast<List<SupplierModel^>^>(this->SupplierComboBox->DataSource);

		for each (CategoryModel ^ cat in categoryList) {
			if (cat->Id == m->Category_Id) {
				selectedCategory = cat;
				break;
			}
		}

		for each (SupplierModel ^ sup in supplierList) {
			if (sup->Id == m->Supplier_Id) {
				selectedSupplier = sup;
				break;
			}
		}

		// Add new product row with the correct category and supplier names
		this->ProductTable->Rows->Add(
			m->Id,
			m->Name,
			m->Price,
			m->Quantity,
			selectedCategory ? selectedCategory->Name : "Unknown",
			selectedSupplier ? selectedSupplier->Name : "Unknown",
			FormatCustomDate(m->Created_At),
			FormatCustomDate(m->Updated_At)
		);
		this->LatestProductsListBox->Items->Add(m->Name);

		// Clear inputs
		this->productName->Clear();
		this->productPrice->Clear();
		this->productQuantity->Clear();
		this->CategoryComboBox->SelectedIndex = -1;
		this->SupplierComboBox->SelectedIndex = -1;

		MessageBox::Show("Product added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (Exception^ ex) {
		MessageBox::Show(
			"Error Adding Product: " + ex->Message,
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);
	}
}
System::Void Dashboard::updateProduct_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// 1) Ensure a row is selected
		if (this->ProductTable->SelectedRows->Count == 0)
			throw gcnew InvalidOperationException("Please select a product to update.");

		auto row = this->ProductTable->SelectedRows[0];
		int id = safe_cast<int>(row->Cells["productColId"]->Value);

		// 2) Build/update model
		auto m = ProductController::GetById(id);
		if (m == nullptr)
			throw gcnew InvalidOperationException("Selected product not found in database.");

		m->Name = this->productName->Text->Trim();
		m->Price = Convert::ToDecimal(this->productPrice->Text->Trim());
		m->Quantity = Convert::ToInt32(this->productQuantity->Text->Trim());

		// 3) Get selected IDs directly from bound ComboBoxes
		m->Category_Id = Convert::ToInt32(this->CategoryComboBox->SelectedValue);
		m->Supplier_Id = Convert::ToInt32(this->SupplierComboBox->SelectedValue);

		// 4) Resolve Category name from selected Category_Id
		String^ selectedCategoryName = "";
		auto categoryList = safe_cast<List<CategoryModel^>^>(this->CategoryComboBox->DataSource);
		for each (CategoryModel ^ cat in categoryList) {
			if (cat->Id == m->Category_Id) {
				selectedCategoryName = cat->Name;
				break;
			}
		}

		// 5) Resolve Supplier name from selected Supplier_Id
		String^ selectedSupplierName = "";
		auto supplierList = safe_cast<List<SupplierModel^>^>(this->SupplierComboBox->DataSource);
		for each (SupplierModel ^ sup in supplierList) {
			if (sup->Id == m->Supplier_Id) {
				selectedSupplierName = sup->Name;
				break;
			}
		}

		// 6) Call controller to persist
		bool ok = ProductController::Update(m);
		if (!ok)
			throw gcnew Exception("Database update failed.");

		// 7) Reflect changes in the grid
		row->Cells["productColName"]->Value = m->Name;
		row->Cells["productColPrice"]->Value = m->Price;
		row->Cells["productColQuantity"]->Value = m->Quantity;
		row->Cells["productColCategory"]->Value = selectedCategoryName;
		row->Cells["productColSupplier"]->Value = selectedSupplierName;
		row->Cells["productColUpdated_At"]->Value = FormatCustomDate(m->Updated_At);
		row->Cells["productColCreated_At"]->Value = FormatCustomDate(m->Created_At);

		// 8) Clear inputs
		this->productName->Clear();
		this->productPrice->Clear();
		this->productQuantity->Clear();
		this->CategoryComboBox->SelectedIndex = -1;
		this->SupplierComboBox->SelectedIndex = -1;
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message, "Error Updating Product", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
System::Void Dashboard::delProduct_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// 1) Ensure a row is selected
		if (this->ProductTable->SelectedRows->Count == 0)
			throw gcnew InvalidOperationException("Please select a product to delete.");

		auto row = this->ProductTable->SelectedRows[0];
		int id = safe_cast<int>(row->Cells["productColId"]->Value);

		// 2) Confirm deletion
		auto dlg = MessageBox::Show(
			"Are you sure you want to delete this product?",
			"Confirm Delete",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);
		if (dlg != ::DialogResult::Yes)
			return;

		// 3) Call controller to delete from DB
		bool ok = ProductController::Delete(id);
		if (!ok)
			throw gcnew Exception("Database delete failed.");

		// 4) Remove row from grid
		this->ProductTable->Rows->Remove(row);

		// 5) Clear inputs
		this->productName->Clear();
		this->productPrice->Clear();
		this->productQuantity->Clear();
		this->CategoryComboBox->SelectedIndex = -1;
		this->SupplierComboBox->SelectedIndex = -1;
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message, "Error Deleting Product", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
System::Void Dashboard::RefreshProductData_Click(System::Object^ sender, System::EventArgs^ e) {
	LoadCategories(currentPharmacy->Id);

	LoadSuppliers(currentPharmacy->Id);
}
//PRODUCT SCREEN END
// CATEGORY SCREEN
//Category Database Button Handling
System::Void Dashboard::addCat_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// 1) Build a model from form inputs
		auto m = gcnew CategoryModel();
		m->Pharmacy_Id = currentPharmacy->Id;      // or however you track current pharmacy
		m->Name = this->CatName->Text->Trim();
		m->Description = this->Catdesc->Text->Trim();

		// 2) Call controller to insert & get back the new Id/timestamps
		m = CategoryController::Create(m);

		// 3) Add new row to DataGridView
		this->CategoryTable->Rows->Add(
			m->Id,
			m->Name,
			m->Description,
			FormatCustomDate(m->Created_At),
			FormatCustomDate(m->Updated_At)
		);
		this->LatestCategoriesListBox->Items->Add(m->Name);

		// 4) Clear inputs
		this->CatName->Clear();
		this->Catdesc->Clear();
		LoadCategories(currentPharmacy->Id);
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message, "Error Adding Category", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
System::Void Dashboard::updateCat_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// 1) Ensure a row is selected
		if (this->CategoryTable->SelectedRows->Count == 0)
			throw gcnew InvalidOperationException("Please select a category to update.");

		auto row = this->CategoryTable->SelectedRows[0];
		int id = safe_cast<int>(row->Cells["categoryColId"]->Value);

		// 2) Build/update model
		auto m = CategoryController::GetById(id);
		if (m == nullptr)
			throw gcnew InvalidOperationException("Selected category not found in database.");

		m->Name = this->CatName->Text->Trim();
		m->Description = this->Catdesc->Text->Trim();

		// 3) Call controller to persist
		bool ok = CategoryController::Update(m);
		if (!ok)
			throw gcnew Exception("Database update failed.");

		// 4) Reflect changes in the grid
		row->Cells["categoryColName"]->Value = m->Name;
		row->Cells["categoryColDescription"]->Value = m->Description;
		row->Cells["categoryColUpdated_At"]->Value = FormatCustomDate(m->Updated_At);
		row->Cells["categoryColCreated_At"]->Value = FormatCustomDate(m->Created_At);

		// 5) Clear inputs
		this->CatName->Clear();
		this->Catdesc->Clear();
		LoadCategories(currentPharmacy->Id);

	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message, "Error Updating Category", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
System::Void Dashboard::delCat_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// 1) Ensure a row is selected
		if (this->CategoryTable->SelectedRows->Count == 0)
			throw gcnew InvalidOperationException("Please select a category to delete.");

		auto row = this->CategoryTable->SelectedRows[0];
		int id = safe_cast<int>(row->Cells["CategoryColId"]->Value);

		// 2) Confirm deletion
		auto dlg = MessageBox::Show(
			"Are you sure you want to delete this category?",
			"Confirm Delete",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);
		if (dlg != ::DialogResult::Yes)
			return;

		// 3) Call controller to delete from DB
		bool ok = CategoryController::Delete(id);
		if (!ok)
			throw gcnew Exception("Database delete failed.");

		// 4) Remove row from grid
		this->CategoryTable->Rows->Remove(row);

		// 5) Clear inputs
		this->CatName->Clear();
		this->Catdesc->Clear();
		LoadCategories(currentPharmacy->Id);

	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message, "Error Deleting Category", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
// CATEGORY SCREEN END
//SUPPLIER SCREEN
// 
//Supplier Database Button Handling
System::Void Dashboard::AddSupplier_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// 1) Build a model from form inputs
		auto m = gcnew SupplierModel();
		m->Pharmacy_Id = currentPharmacy->Id;      // or however you track current pharmacy
		m->Name = this->SupplierName->Text->Trim();
		m->Contact_Info = this->SupplierContact_Info->Text->Trim();

		// 2) Call controller to insert & get back the new Id/timestamps
		m = SupplierController::Create(m);

		// 3) Add new row to DataGridView
		this->SupplierTable->Rows->Add(
			m->Id,
			m->Name,
			m->Contact_Info,
			FormatCustomDate(m->Created_At),
			FormatCustomDate(m->Updated_At)
		);
		this->LatestSuppliersListBox->Items->Add(m->Name);

		// 4) Clear inputs
		this->SupplierName->Clear();
		this->SupplierContact_Info->Clear();

		LoadSuppliers(currentPharmacy->Id);
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message, "Error Adding Supplier", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
System::Void Dashboard::EditSupplier_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// 1) Ensure a row is selected in the supplier table
		if (this->SupplierTable->SelectedRows->Count == 0)
			throw gcnew InvalidOperationException("Please select a supplier to update.");

		auto row = this->SupplierTable->SelectedRows[0];
		int id = safe_cast<int>(row->Cells["SupplierColId"]->Value);

		// 2) Build/update the model from the controller
		auto m = SupplierController::GetById(id);
		if (m == nullptr)
			throw gcnew InvalidOperationException("Selected supplier not found in database.");

		// Update the supplier's information with the input values
		m->Name = this->SupplierName->Text->Trim();
		m->Contact_Info = this->SupplierContact_Info->Text->Trim();

		// 3) Call controller to persist the changes in the database
		bool ok = SupplierController::Update(m);
		if (!ok)
			throw gcnew Exception("Database update failed.");

		// 4) Reflect changes in the grid
		row->Cells["SupplierColName"]->Value = m->Name;
		row->Cells["SupplierColContactInfo"]->Value = m->Contact_Info;
		row->Cells["SupplierColUpdated_At"]->Value = FormatCustomDate(m->Updated_At);
		row->Cells["SupplierColCreated_At"]->Value = FormatCustomDate(m->Created_At);

		// 5) Clear the input fields after successful update
		this->SupplierName->Clear();
		this->SupplierContact_Info->Clear();
		LoadSuppliers(currentPharmacy->Id);

	}
	catch (Exception^ ex) {
		// Show an error message if something goes wrong
		MessageBox::Show(ex->Message, "Error Updating Supplier", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
System::Void Dashboard::DelSupplier_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// 1) Ensure a row is selected in the supplier table
		if (this->SupplierTable->SelectedRows->Count == 0)
			throw gcnew InvalidOperationException("Please select a supplier to delete.");

		auto row = this->SupplierTable->SelectedRows[0];
		int id = safe_cast<int>(row->Cells["SupplierColId"]->Value);

		// 2) Confirm deletion
		auto dlg = MessageBox::Show(
			"Are you sure you want to delete this supplier?",
			"Confirm Delete",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);
		if (dlg != ::DialogResult::Yes)
			return;

		// 3) Call controller to delete from DB
		bool ok = SupplierController::Delete(id);
		if (!ok)
			throw gcnew Exception("Database delete failed.");

		// 4) Remove the row from the supplier table
		this->SupplierTable->Rows->Remove(row);

		// 5) Clear the input fields (if needed)
		this->SupplierName->Clear();
		this->SupplierContact_Info->Clear();
		LoadSuppliers(currentPharmacy->Id);

	}
	catch (Exception^ ex) {
		// Show error message if something goes wrong
		MessageBox::Show(ex->Message, "Error Deleting Supplier", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
//SUPPLIER SCREEN End

//SCREENS SEARCH LOGIC
System::Void Dashboard::CategorySearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	// Get the search text
	String^ searchText = CategorySearch->Text->Trim();
	// Filter the DataGridView based on the search text
	for (int i = 0; i < CategoryTable->Rows->Count; i++) {
		DataGridViewRow^ row = CategoryTable->Rows[i];
		if (row->Cells["CategoryColName"]->Value != nullptr && row->Cells["CategoryColName"]->Value->ToString()->Contains(searchText)) {
			row->Visible = true;
		}
		else {
			row->Visible = false;
		}
	}
}
System::Void Dashboard::ProductSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	// Get the search text
	String^ searchText = ProductSearch->Text->Trim();
	// Filter the DataGridView based on the search text
	for (int i = 0; i < ProductTable->Rows->Count; i++) {
		DataGridViewRow^ row = ProductTable->Rows[i];
		if (row->Cells["ProductColName"]->Value != nullptr && row->Cells["ProductColName"]->Value->ToString()->Contains(searchText)) {
			row->Visible = true;
		}
		else {
			row->Visible = false;
		}
	}
}
System::Void Dashboard::SupplierSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	// Get the search text
	String^ searchText = SupplierSearch->Text->Trim();
	// Filter the DataGridView based on the search text
	for (int i = 0; i < SupplierTable->Rows->Count; i++) {
		DataGridViewRow^ row = SupplierTable->Rows[i];
		if (row->Cells["SupplierColName"]->Value != nullptr && row->Cells["SupplierColName"]->Value->ToString()->Contains(searchText)) {
			row->Visible = true;
		}
		else {
			row->Visible = false;
		}
	}
}
//SCREENS SEARCH LOGIC END


//SCREENS NAVIGATION BUTTONS
System::Void Dashboard::homeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	HomePanel->BringToFront();
}
System::Void Dashboard::cashierBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	cashierPanel->BringToFront();
}
System::Void Dashboard::productBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	productPanel->BringToFront();
}
System::Void Dashboard::categoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	categoryPanel->BringToFront();
}
System::Void Dashboard::supplierBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	supplierPanel->BringToFront();
}
System::Void Dashboard::stockBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	stockPanel->BringToFront();
}
//SCREENS NAVIGATION BUTTONS END

//WINDOW CONTROL BUTTONS
System::Void Dashboard::closeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// Close the application
	//this->Close();
	//Environment::Exit(0);
	Application::Exit();
}
System::Void Dashboard::button5_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (this->WindowState == FormWindowState::Normal) {
		this->WindowState = FormWindowState::Maximized;
		ManageProductContainer->Dock = DockStyle::Right;
	}
	else {
		this->WindowState = FormWindowState::Normal;
		this->Size = System::Drawing::Size(1245, 707);

		// Center the form on screen
		System::Drawing::Rectangle screen = Screen::PrimaryScreen->WorkingArea;
		this->Location = System::Drawing::Point(
			(screen.Width - this->Width) / 2,
			(screen.Height - this->Height) / 2
		);

		ManageProductContainer->Dock = DockStyle::Right;
	}

	this->minMax->Refresh();
}

System::Void Dashboard::minimize_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->WindowState == FormWindowState::Maximized) {
		this->WindowState = FormWindowState::Minimized;
	}
	else {
		this->WindowState = FormWindowState::Maximized;
	}
	this->minMax->Refresh();
}
System::Void Dashboard::collaps_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->RightPanel->Width > 200) {
		this->RightPanel->Width = 70;
		array<Button^>^ navButtons = {
		   homeBtn, cashierBtn, productBtn,
		   categoryBtn, supplierBtn, stockBtn
		};

		for each (Button ^ btn in navButtons) {
			btn->Text = "";
			btn->ImageAlign = ContentAlignment::MiddleCenter;
			btn->Padding = System::Windows::Forms::Padding(0);
			btn->Width = 45; // Set fixed width for collapsed state
		}
		userBtn->Image = collapsedUserImage;
		userBtn->ImageAlign = ContentAlignment::MiddleLeft; // Center image when collapsed
		userBtn->TextImageRelation = TextImageRelation::ImageBeforeText;
		userBtn->Text = "";

		collaps->SendToBack();

	}
	else {
		this->RightPanel->Width = 260;
		homeBtn->Text = L"الرئيسية";
		cashierBtn->Text = L"كاشير";
		productBtn->Text = L"المنتجات";
		categoryBtn->Text = L"الاصناف";
		supplierBtn->Text = L"الموردين";
		stockBtn->Text = L"المخزون";
		array<Button^>^ navButtons = {
		   homeBtn, cashierBtn, productBtn,
		   categoryBtn, supplierBtn, stockBtn
		};

		for each (Button ^ btn in navButtons) {
			btn->ImageAlign = ContentAlignment::MiddleRight;
			btn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			btn->Width = 280; // Restore original width
		}
		userBtn->Image = expandedUserImage;
		userBtn->ImageAlign = ContentAlignment::MiddleRight; // Align right when expanded
		userBtn->TextImageRelation = TextImageRelation::TextBeforeImage;
		//userBtn->Text = userName->IsNullOrEmpty?"اسم المستخدم": userName;
		userBtn->Text = L"اسم المستخدم";
		collaps->BringToFront();
	}
	this->RightPanel->Refresh();
}
//WINDOW CONTROL BUTTONS END


//Tables Cell Click
// Category row click → fill Category form fields
System::Void Dashboard::CategoryTable_CellClick(Object^ sender, DataGridViewCellEventArgs^ e) {
	auto map = gcnew Dictionary<String^, TextBox^>();
	map->Add("categoryColName", CatName);
	map->Add("categoryColDescription", Catdesc);
	UIHelper::FillControlsFromSelectedRow(CategoryTable,map);


}
// Supplier row click → fill Supplier form fields
System::Void Dashboard::SupplierTable_CellClick(Object^ sender, DataGridViewCellEventArgs^ e) {
	auto map = gcnew Dictionary<String^, TextBox^>();
	map->Add("SupplierColName", SupplierName);
	map->Add("SupplierColContactInfo", SupplierContact_Info);
	UIHelper::FillControlsFromSelectedRow(SupplierTable, map);
}
// Product row click → fill Product form fields + combo-boxes
System::Void Dashboard::ProductTable_CellClick(Object^ sender, DataGridViewCellEventArgs^ e) {
	if (e->RowIndex < 0) return;
	auto row = this->ProductTable->Rows[e->RowIndex];

	// Populate Product basic fields
	this->productName->Text = row->Cells["ProductColName"]->Value->ToString();
	this->productPrice->Text = row->Cells["ProductColPrice"]->Value->ToString();
	this->productQuantity->Text = row->Cells["ProductColQuantity"]->Value->ToString();

	// Now get category name and supplier name from table
	String^ categoryName = row->Cells["ProductColCategory"]->Value->ToString();  // Column with category name
	String^ supplierName = row->Cells["ProductColSupplier"]->Value->ToString();  // Column with supplier name

	// Find matching Category ID by name
	auto categoryList = safe_cast<List<CategoryModel^>^>(this->CategoryComboBox->DataSource);
	auto supplierList = safe_cast<List<SupplierModel^>^>(this->SupplierComboBox->DataSource);

	for each (CategoryModel ^ cat in categoryList) {
		if (cat->Name == categoryName) {
			this->CategoryComboBox->SelectedValue = cat->Id;
			break;
		}
	}

	for each (SupplierModel ^ sup in supplierList) {
		if (sup->Name == supplierName) {
			this->SupplierComboBox->SelectedValue = sup->Id;
			break;
		}
	}
}

// Generic event handlers for all DataGridView controls - HOVER AND FOCUS EFFECTS
Void Dashboard::DataGridView_CellMouseEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	UIHelper::HandleCellMouseEnter(sender, e);

}
Void Dashboard::DataGridView_CellMouseLeave(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	UIHelper::HandleCellMouseLeave(sender, e);

}
//- HOVER AND FOCUS EFFECTS END

//Helper Methods
//Format the DataTime - Created...Updated At
String^ Dashboard::FormatCustomDate(DateTime dt) {
	return dt.ToString("MMM") + " " +
		(dt.Year % 10).ToString() + " at " +
		dt.ToString("h:mmtt")->ToLower();
}

// Resize the image to fit within the specified dimensions
Bitmap^ Dashboard::ResizeImage(Image^ image, int maxWidth, int maxHeight) {
	double ratioX = (double)maxWidth / image->Width;
	double ratioY = (double)maxHeight / image->Height;
	double ratio = Math::Min(ratioX, ratioY);

	int newWidth = (int)(image->Width * ratio);
	int newHeight = (int)(image->Height * ratio);

	Bitmap^ resizedImage = gcnew Bitmap(newWidth, newHeight);
	Graphics^ g = Graphics::FromImage(resizedImage);
	g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::HighQualityBicubic;
	g->DrawImage(image, 0, 0, newWidth, newHeight);
	delete g;
	return resizedImage;
}


