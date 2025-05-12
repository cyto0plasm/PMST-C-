#pragma once
#include "../Models/CategoryModel.h"
#include "../Controllers/CategoryController.h"
#include "../Database/DBConnection.h"
#include "../Models/UserModel.h"
#include "../Models/PharmacyModel.h"
#include "../Controllers/ProductsController.h"
#include "../Models/SaleModel.h"
#include "../Controllers/SalesController.h"
#include "../Models/InvoiceHeaderModel.h"
#include "../Controllers/InvoiceHeaderController.h"

namespace PMST {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{
		//Constructors
		Dashboard() {
			InitializeComponent();
		}
	public:PMST::Dashboard::Dashboard(UserModel^ user, PharmacyModel^ pharmacy);

	private:
		//DATABASE
		UserModel^ currentUser;
		PharmacyModel^ currentPharmacy;
		String^ categoryName;
		ProductController^ productController;
		SaleController^ saleController;
		InvoiceHeaderModel^ invoiceHeader;
		InvoiceHeaderController^ invoiceHeaderController;
		Dictionary<String^, ProductModel^>^ searchResultMap;
		int nextCashRowId = 1;
		int currentInvoiceId;
		String^ categoryDescription;

	private:System::Drawing::Printing::PrintDocument^ printDocument;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::FlowLayoutPanel^ CashierTablePanelContainer;
	private: System::Windows::Forms::Panel^ CashierTableTitlePanel;
	private: System::Windows::Forms::Label^ CashierTableTitle;
	private: System::Windows::Forms::FlowLayoutPanel^ CashierTablePanel;
	private: System::Windows::Forms::Panel^ CashierSearchProductPanel;
	private: System::Windows::Forms::FlowLayoutPanel^ CashierSearchProductContainer;
	private: System::Windows::Forms::TextBox^ CashierSearchProduct;
	private: System::Windows::Forms::Label^ CashierSearchLab;
	private: System::Windows::Forms::DataGridView^ CashierTable;
	private: System::Windows::Forms::Panel^ panel12;
	private: System::Windows::Forms::Panel^ panel14;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ RefreshInvoice;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Label^ payLab;
	private: System::Windows::Forms::FlowLayoutPanel^ payFeildContainer;
	private: System::Windows::Forms::TextBox^ payFeild;
	private: System::Windows::Forms::Label^ payMethodLab;
	private: System::Windows::Forms::Panel^ panel15;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::ComboBox^ payMethodComboBox;
	private: System::Windows::Forms::Label^ TotalInvoiceLab;
	private: System::Windows::Forms::Button^ PayInvoice;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ListBox^ SearchSuggestionsList;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CashProductId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CashProductName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CashProductPrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CashProductQuantity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CashTotalProductPrice;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel3;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::FlowLayoutPanel^ InvoiceHeaderContainer;
	private: System::Windows::Forms::Panel^ InvoiceHeaderTitlepanel;
	private: System::Windows::Forms::Label^ InvoiceHeaderTitleLab;
	private: System::Windows::Forms::FlowLayoutPanel^ InvoiceHeaderTableContainer;
	private: System::Windows::Forms::Panel^ SearchInvoiceHeaderPanel;
	private: System::Windows::Forms::FlowLayoutPanel^ SearchInvoiceHeaderContainer;
	private: System::Windows::Forms::TextBox^ SearchInvoiceHeaderFeild;
	private: System::Windows::Forms::Label^ SearchInvoiceHeaderLab;
	private: System::Windows::Forms::DataGridView^ InvoiceHeaderTable;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel6;
	private: System::Windows::Forms::Panel^ InvoiceDetailsContainer;
	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ InvoiceDetailsPanel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ InvoiceHeaderId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ InvoiceTotalPrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ InvoiceHeaderCreatedAt;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ InvoiceHeaderUpdatedAt;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SaleId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SaleDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SaleQuantity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SalePrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ categoryColId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ categoryColName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ categoryColDescription;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ categoryColCreated_At;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ categoryColUpdated_At;
	private: System::Windows::Forms::FlowLayoutPanel^ CategoryTablePanel;
	private: System::Windows::Forms::FlowLayoutPanel^ CategorySearchPanel;
	private: System::Windows::Forms::TextBox^ CategorySearch;
	private: System::Windows::Forms::Panel^ SearchPanelContainer;
	private: System::Windows::Forms::FlowLayoutPanel^ ProductTableContainer;
	private: System::Windows::Forms::Panel^ ProductTableTitlePanel;
	private: System::Windows::Forms::Label^ ProductTableTitle;
	private: System::Windows::Forms::FlowLayoutPanel^ ProductTablePanel;
	private: System::Windows::Forms::Panel^ ProductSearchContainer;
	private: System::Windows::Forms::FlowLayoutPanel^ ProductSearchPanel;
	private: System::Windows::Forms::TextBox^ ProductSearch;
	private: System::Windows::Forms::Label^ ProductSearchLab;
	private: System::Windows::Forms::DataGridView^ ProductTable;
	private: System::Windows::Forms::Panel^ ManageProductContainer;
	private: System::Windows::Forms::Panel^ ManageProductTitlePanel;
	private: System::Windows::Forms::Label^ ManageProductTitle;
	private: System::Windows::Forms::Panel^ ManageProductFormPanel;
	private: System::Windows::Forms::Panel^ ManageCategoryPanel;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ CategoryFormTitkePanel;
	private: System::Windows::Forms::Label^ catFormTitle;
	private: System::Windows::Forms::FlowLayoutPanel^ SupplierTableContainer;
	private: System::Windows::Forms::Panel^ SupplierTableTitlePanel;
	private: System::Windows::Forms::Label^ SupplierTableTitle;
	private: System::Windows::Forms::FlowLayoutPanel^ SupplierTablePanel;
	private: System::Windows::Forms::Panel^ SupplierSearchContainer;
	private: System::Windows::Forms::FlowLayoutPanel^ SupplierSearchPanel;
	private: System::Windows::Forms::TextBox^ SupplierSearch;
	private: System::Windows::Forms::Label^ SupplierSearchLab;
	private: System::Windows::Forms::DataGridView^ SupplierTable;
	private: System::Windows::Forms::Panel^ ManageSupplierContainer;
	private: System::Windows::Forms::Panel^ ManageSupplierFormsPanel;
	private: System::Windows::Forms::Panel^ panel13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SupplierColId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SupplierColName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SupplierColContactInfo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SupplierColCreated_At;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SupplierColUpdated_At;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductColId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductColName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductColPrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductColQuantity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductColCategory;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductColSupplier;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductColCreated_At;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductColUpdated_At;
	private: System::Windows::Forms::ComboBox^ SupplierComboBox;
	private: System::Windows::Forms::ComboBox^ CategoryComboBox;
	private: System::Windows::Forms::Label^ ProductNameLab;
	private: System::Windows::Forms::FlowLayoutPanel^ ContainerOfProductQuantity;
	private: System::Windows::Forms::TextBox^ productQuantity;
	private: System::Windows::Forms::FlowLayoutPanel^ ContainerOfProductPrice;
	private: System::Windows::Forms::TextBox^ productPrice;
	private: System::Windows::Forms::FlowLayoutPanel^ ContainerOfProductName;
	private: System::Windows::Forms::TextBox^ productName;
	private: System::Windows::Forms::Label^ SupplierComboBoxLab;
	private: System::Windows::Forms::Label^ CategoryComboBoxLab;
	private: System::Windows::Forms::Label^ ProductQuantityLab;
	private: System::Windows::Forms::Label^ ProductPriceLab;
	private: System::Windows::Forms::Label^ catNameLab;
	private: System::Windows::Forms::Button^ delCat;
	private: System::Windows::Forms::Button^ updateCat;
	private: System::Windows::Forms::Button^ addCat;
	private: System::Windows::Forms::Label^ catdescLab;
	private: System::Windows::Forms::FlowLayoutPanel^ ContainerOfCatDesc;
	private: System::Windows::Forms::TextBox^ Catdesc;
	private: System::Windows::Forms::FlowLayoutPanel^ ContainerOfCatName;
	private: System::Windows::Forms::TextBox^ CatName;
	private: System::Windows::Forms::Button^ delProduct_Btn;
	private: System::Windows::Forms::Button^ editProduct_Btn;
	private: System::Windows::Forms::Button^ RefreshProductData;
	private: System::Windows::Forms::Button^ addProduct_Btn;
	private: System::Windows::Forms::Label^ SupplierNameLab;
	private: System::Windows::Forms::FlowLayoutPanel^ ContainerOfSupplierContact_Info;
	private: System::Windows::Forms::TextBox^ SupplierContact_Info;
	private: System::Windows::Forms::FlowLayoutPanel^ ContainerOfSupplierName;
	private: System::Windows::Forms::TextBox^ SupplierName;
	private: System::Windows::Forms::Button^ DelSupplier_Btn;
	private: System::Windows::Forms::Button^ EditSupplier_Btn;
	private: System::Windows::Forms::Button^ AddSupplier_Btn;
	private: System::Windows::Forms::Label^ label11;
	protected:
	private:
		//panels user controls
		System::Windows::Forms::Panel^ infoPanel;
		System::Windows::Forms::Panel^ panel1;
		System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
		System::Windows::Forms::Panel^ panel2;
		System::Windows::Forms::FlowLayoutPanel^ flowMainPanel;
		System::Windows::Forms::Button^ category;
		System::Windows::Forms::Button^ supplier;
		System::Windows::Forms::Button^ product;
		System::Windows::Forms::Panel^ Header;
		System::Windows::Forms::Panel^ FooterPanel;
		System::Windows::Forms::Panel^ RightPanel;
		System::Windows::Forms::FlowLayoutPanel^ NavPanel;
		System::Windows::Forms::Panel^ UserPanel;
		System::Windows::Forms::Panel^ CenterPanel;
		System::Windows::Forms::Button^ homeBtn;
		System::Windows::Forms::Button^ cashierBtn;
		System::Windows::Forms::Button^ productBtn;
		System::Windows::Forms::Button^ categoryBtn;
		System::Windows::Forms::Button^ supplierBtn;
		System::Windows::Forms::Button^ stockBtn;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ logo;
		System::Windows::Forms::Button^ closeBtn;
		System::Windows::Forms::Button^ minMax;
		System::Windows::Forms::Button^ mimimizeBtn;
		System::Windows::Forms::Button^ collaps;
		System::Drawing::Image^ maximizeIcon;
		System::Drawing::Image^ minimizeIcon;
		System::ComponentModel::ComponentResourceManager^ resources;
		System::Windows::Forms::Button^ userBtn;
		System::Drawing::Image^ originalUserImage;
		System::Drawing::Image^ collapsedUserImage;
		System::Drawing::Image^ expandedUserImage;
		System::Windows::Forms::FlowLayoutPanel^ HomePanel;
		System::Windows::Forms::Panel^ cashierPanel;
		System::Windows::Forms::Panel^ stockPanel;
		System::Windows::Forms::Panel^ supplierPanel;
		System::Windows::Forms::Panel^ productPanel;
		System::Windows::Forms::Panel^ categoryPanel;
		System::Windows::Forms::Label^ pharmacyNameLabel;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ pharmacyName;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Button^ expandBtn;
		System::Windows::Forms::Button^ totalSales;
		System::Windows::Forms::FlowLayoutPanel^ fastNav;
private: System::Windows::Forms::Button^ SCAddSupplier;

private: System::Windows::Forms::Button^ SCAddCategory;

private: System::Windows::Forms::Button^ SCAddProduct;

		System::Windows::Forms::FlowLayoutPanel^ recentSalesPanel;
		System::Windows::Forms::DataGridView^ recentSalesTable;
		System::Windows::Forms::Panel^ panel3;
private: System::Windows::Forms::ListBox^ TotalProfitsListBox;


		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::FlowLayoutPanel^ Cards;
		System::Windows::Forms::Panel^ panel4;
private: System::Windows::Forms::ListBox^ LatestCategoriesListBox;
	   private: System::Windows::Forms::ListBox^ LatestProductsListBox;
			  private: System::Windows::Forms::ListBox^ LatestSuppliersListBox;

		System::Windows::Forms::Button^ button5;
		System::Windows::Forms::Panel^ panel5;

		System::Windows::Forms::Button^ button6;
		System::Windows::Forms::Panel^ panel6;

		System::Windows::Forms::Button^ button7;
		System::Windows::Forms::Panel^ panel7;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Panel^ CardPanelHead;
		System::Windows::Forms::Label^ CardPanelTitle;
		System::Windows::Forms::FlowLayoutPanel^ CategoryTableContainer;
		System::Windows::Forms::Panel^ CategoryTableTitlePanel;
		System::Windows::Forms::Label^ CategoryTableTitle;
		System::Windows::Forms::DataGridView^ CategoryTable;
		System::Windows::Forms::Label^ catSearchLab;
		System::Windows::Forms::Button^ button8;
		System::Windows::Forms::Button^ cashier;
		System::ComponentModel::Container^ components;


		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
			if (maximizeIcon) delete maximizeIcon;
			if (minimizeIcon) delete minimizeIcon;
		}

		//UTILS FUNCTIONS
		Void Dashboard_Load(System::Object^ sender, System::EventArgs^ e);
		void InitHeavyLogic();
		System::Void LoadProfitSummaries();
		Bitmap^ ResizeImage(Image^ image, int maxWidth, int maxHeight);

		// Generic event handlers for all DataGridView controls
		Void DataGridView_CellMouseEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		Void DataGridView_CellMouseLeave(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		Void DataGridView_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		void UpdateUserInfoDisplay(); // New method to update UI

		// Event handlers for Category Cruds buttons
		Void updateCat_Click(System::Object^ sender, System::EventArgs^ e);
		Void delCat_Click(System::Object^ sender, System::EventArgs^ e);
		Void addCat_Click(System::Object^ sender, System::EventArgs^ e);
		void LoadCategories(int pharmacyId);

		// Event handlers for Product Cruds buttons
		Void addProduct_Click(System::Object^ sender, System::EventArgs^ e);
		Void updateProduct_Click(System::Object^ sender, System::EventArgs^ e);
		Void delProduct_Click(System::Object^ sender, System::EventArgs^ e);
		void RefreshProductTable();

		// Event handlers for Supplier Cruds buttons
		Void AddSupplier_Btn_Click(System::Object^ sender, System::EventArgs^ e);
		Void EditSupplier_Btn_Click(System::Object^ sender, System::EventArgs^ e);
		Void DelSupplier_Btn_Click(System::Object^ sender, System::EventArgs^ e);
		void LoadSuppliers(int pharmacyId);

		// Event handlers for DataGridView cell clicks
		Void ProductTable_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		Void CategoryTable_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		Void SupplierTable_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		Void RefreshProductData_Click(System::Object^ sender, System::EventArgs^ e);

		//search Methods
		Void CategorySearch_TextChanged(System::Object^ sender, System::EventArgs^ e);
		Void ProductSearch_TextChanged(System::Object^ sender, System::EventArgs^ e);
		Void SupplierSearch_TextChanged(System::Object^ sender, System::EventArgs^ e);


		//navigation buttons methods
		System::Void homeBtn_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void cashierBtn_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void productBtn_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void categoryBtn_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void supplierBtn_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void stockBtn_Click(System::Object^ sender, System::EventArgs^ e);
		//windows control buttons methods
		System::Void closeBtn_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button5_Click_1(System::Object^ sender, System::EventArgs^ e);
		System::Void minimize_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void collaps_Click(System::Object^ sender, System::EventArgs^ e);

		//tables hover effect and styles
		System::Void recentSalesTable_CellMouseEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		System::Void recentSalesTable_CellMouseLeave(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		System::Void recentSalesTable_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e);
		//Cashier table 
		System::Void CashierTable_CellEndEdit(System::Object^ sender, DataGridViewCellEventArgs^ e);
		System::Void CashierTable_CellValueChanged(System::Object^ sender, DataGridViewCellEventArgs^ e);
		System::Void CashierTable_KeyDown(System::Object^ sender, KeyEventArgs^ e);
		System::Void CashierTable_CellValueChanged_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		System::Void CashierSearchProduct_TextChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void AddProductToCashierTable(System::Object^ sender, System::EventArgs^ e);
		System::Void SearchSuggestionsList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
		double UpdateTotalAmount();
		System::Void PayInvoice_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void LoadInvoiceHeaders();
		System::Void InvoiceHeaderTable_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		// Print button click handler
		System::Void PrintButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void AddHeading(String^ text, Control^ parent, int y);
		System::Void AddSubheading(String^ text, Control^ parent, int y);
		System::Void AddColumnHeader(String^ text, int x, Control^ parent, int y);
		System::Void AddNormalText(String^ text, Control^ parent, int x, int y);
		System::Void AddBoldText(String^ text, Control^ parent, int x, int y);
		System::Void AddHighlightedText(String^ text, Control^ parent, int x, int y);
		System::Void AddSeparator(Control^ parent, int y);
		System::Void PrintInvoice(int invoiceId);
		// Print page handler
		System::Void PrintDocument_PrintPage(System::Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e);
	protected:
	private:


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle31 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle32 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle34 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle35 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle33 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle36 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle37 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle39 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle40 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle38 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle41 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle42 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle44 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle45 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle43 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle46 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle47 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle49 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle50 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle48 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle51 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle52 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle54 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle55 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle53 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle56 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle57 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle59 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle60 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle58 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->Header = (gcnew System::Windows::Forms::Panel());
			this->minMax = (gcnew System::Windows::Forms::Button());
			this->mimimizeBtn = (gcnew System::Windows::Forms::Button());
			this->closeBtn = (gcnew System::Windows::Forms::Button());
			this->logo = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->FooterPanel = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pharmacyName = (gcnew System::Windows::Forms::Label());
			this->pharmacyNameLabel = (gcnew System::Windows::Forms::Label());
			this->RightPanel = (gcnew System::Windows::Forms::Panel());
			this->NavPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->homeBtn = (gcnew System::Windows::Forms::Button());
			this->cashierBtn = (gcnew System::Windows::Forms::Button());
			this->productBtn = (gcnew System::Windows::Forms::Button());
			this->categoryBtn = (gcnew System::Windows::Forms::Button());
			this->supplierBtn = (gcnew System::Windows::Forms::Button());
			this->stockBtn = (gcnew System::Windows::Forms::Button());
			this->UserPanel = (gcnew System::Windows::Forms::Panel());
			this->userBtn = (gcnew System::Windows::Forms::Button());
			this->collaps = (gcnew System::Windows::Forms::Button());
			this->expandBtn = (gcnew System::Windows::Forms::Button());
			this->CenterPanel = (gcnew System::Windows::Forms::Panel());
			this->HomePanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->fastNav = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->totalSales = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->SCAddSupplier = (gcnew System::Windows::Forms::Button());
			this->SCAddCategory = (gcnew System::Windows::Forms::Button());
			this->SCAddProduct = (gcnew System::Windows::Forms::Button());
			this->recentSalesPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->recentSalesTable = (gcnew System::Windows::Forms::DataGridView());
			this->SaleId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SaleDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SaleQuantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SalePrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Cards = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->CardPanelHead = (gcnew System::Windows::Forms::Panel());
			this->CardPanelTitle = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->LatestProductsListBox = (gcnew System::Windows::Forms::ListBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->TotalProfitsListBox = (gcnew System::Windows::Forms::ListBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->LatestCategoriesListBox = (gcnew System::Windows::Forms::ListBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->LatestSuppliersListBox = (gcnew System::Windows::Forms::ListBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->stockPanel = (gcnew System::Windows::Forms::Panel());
			this->InvoiceDetailsContainer = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->InvoiceDetailsPanel = (gcnew System::Windows::Forms::Panel());
			this->InvoiceHeaderContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->InvoiceHeaderTitlepanel = (gcnew System::Windows::Forms::Panel());
			this->InvoiceHeaderTitleLab = (gcnew System::Windows::Forms::Label());
			this->InvoiceHeaderTableContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SearchInvoiceHeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->SearchInvoiceHeaderContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SearchInvoiceHeaderFeild = (gcnew System::Windows::Forms::TextBox());
			this->SearchInvoiceHeaderLab = (gcnew System::Windows::Forms::Label());
			this->InvoiceHeaderTable = (gcnew System::Windows::Forms::DataGridView());
			this->InvoiceHeaderId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->InvoiceTotalPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->InvoiceHeaderCreatedAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->InvoiceHeaderUpdatedAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->flowLayoutPanel6 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->cashierPanel = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->CashierTablePanelContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->CashierTableTitlePanel = (gcnew System::Windows::Forms::Panel());
			this->CashierTableTitle = (gcnew System::Windows::Forms::Label());
			this->CashierTablePanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->CashierSearchProductPanel = (gcnew System::Windows::Forms::Panel());
			this->CashierSearchProductContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->CashierSearchProduct = (gcnew System::Windows::Forms::TextBox());
			this->CashierSearchLab = (gcnew System::Windows::Forms::Label());
			this->CashierTable = (gcnew System::Windows::Forms::DataGridView());
			this->CashProductId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CashProductName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CashProductPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CashProductQuantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CashTotalProductPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->SearchSuggestionsList = (gcnew System::Windows::Forms::ListBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->PayInvoice = (gcnew System::Windows::Forms::Button());
			this->RefreshInvoice = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->payMethodComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->TotalInvoiceLab = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->payLab = (gcnew System::Windows::Forms::Label());
			this->payFeildContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->payFeild = (gcnew System::Windows::Forms::TextBox());
			this->payMethodLab = (gcnew System::Windows::Forms::Label());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->productPanel = (gcnew System::Windows::Forms::Panel());
			this->ProductTableContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ProductTableTitlePanel = (gcnew System::Windows::Forms::Panel());
			this->ProductTableTitle = (gcnew System::Windows::Forms::Label());
			this->ProductTablePanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ProductSearchContainer = (gcnew System::Windows::Forms::Panel());
			this->ProductSearchPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ProductSearch = (gcnew System::Windows::Forms::TextBox());
			this->ProductSearchLab = (gcnew System::Windows::Forms::Label());
			this->ProductTable = (gcnew System::Windows::Forms::DataGridView());
			this->ProductColId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProductColName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProductColPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProductColQuantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProductColCategory = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProductColSupplier = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProductColCreated_At = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProductColUpdated_At = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ManageProductContainer = (gcnew System::Windows::Forms::Panel());
			this->ManageProductFormPanel = (gcnew System::Windows::Forms::Panel());
			this->delProduct_Btn = (gcnew System::Windows::Forms::Button());
			this->editProduct_Btn = (gcnew System::Windows::Forms::Button());
			this->RefreshProductData = (gcnew System::Windows::Forms::Button());
			this->addProduct_Btn = (gcnew System::Windows::Forms::Button());
			this->SupplierComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->CategoryComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ProductNameLab = (gcnew System::Windows::Forms::Label());
			this->ContainerOfProductQuantity = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->productQuantity = (gcnew System::Windows::Forms::TextBox());
			this->ContainerOfProductPrice = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->productPrice = (gcnew System::Windows::Forms::TextBox());
			this->ContainerOfProductName = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->productName = (gcnew System::Windows::Forms::TextBox());
			this->SupplierComboBoxLab = (gcnew System::Windows::Forms::Label());
			this->CategoryComboBoxLab = (gcnew System::Windows::Forms::Label());
			this->ProductQuantityLab = (gcnew System::Windows::Forms::Label());
			this->ProductPriceLab = (gcnew System::Windows::Forms::Label());
			this->ManageProductTitlePanel = (gcnew System::Windows::Forms::Panel());
			this->ManageProductTitle = (gcnew System::Windows::Forms::Label());
			this->categoryPanel = (gcnew System::Windows::Forms::Panel());
			this->CategoryTableContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->CategoryTableTitlePanel = (gcnew System::Windows::Forms::Panel());
			this->CategoryTableTitle = (gcnew System::Windows::Forms::Label());
			this->CategoryTablePanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SearchPanelContainer = (gcnew System::Windows::Forms::Panel());
			this->CategorySearchPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->CategorySearch = (gcnew System::Windows::Forms::TextBox());
			this->catSearchLab = (gcnew System::Windows::Forms::Label());
			this->CategoryTable = (gcnew System::Windows::Forms::DataGridView());
			this->categoryColId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->categoryColName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->categoryColDescription = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->categoryColCreated_At = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->categoryColUpdated_At = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ManageCategoryPanel = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->catNameLab = (gcnew System::Windows::Forms::Label());
			this->delCat = (gcnew System::Windows::Forms::Button());
			this->updateCat = (gcnew System::Windows::Forms::Button());
			this->addCat = (gcnew System::Windows::Forms::Button());
			this->catdescLab = (gcnew System::Windows::Forms::Label());
			this->ContainerOfCatDesc = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->Catdesc = (gcnew System::Windows::Forms::TextBox());
			this->ContainerOfCatName = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->CatName = (gcnew System::Windows::Forms::TextBox());
			this->CategoryFormTitkePanel = (gcnew System::Windows::Forms::Panel());
			this->catFormTitle = (gcnew System::Windows::Forms::Label());
			this->supplierPanel = (gcnew System::Windows::Forms::Panel());
			this->SupplierTableContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SupplierTableTitlePanel = (gcnew System::Windows::Forms::Panel());
			this->SupplierTableTitle = (gcnew System::Windows::Forms::Label());
			this->SupplierTablePanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SupplierSearchContainer = (gcnew System::Windows::Forms::Panel());
			this->SupplierSearchPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SupplierSearch = (gcnew System::Windows::Forms::TextBox());
			this->SupplierSearchLab = (gcnew System::Windows::Forms::Label());
			this->SupplierTable = (gcnew System::Windows::Forms::DataGridView());
			this->SupplierColId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SupplierColName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SupplierColContactInfo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SupplierColCreated_At = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SupplierColUpdated_At = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ManageSupplierContainer = (gcnew System::Windows::Forms::Panel());
			this->ManageSupplierFormsPanel = (gcnew System::Windows::Forms::Panel());
			this->SupplierNameLab = (gcnew System::Windows::Forms::Label());
			this->ContainerOfSupplierContact_Info = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SupplierContact_Info = (gcnew System::Windows::Forms::TextBox());
			this->ContainerOfSupplierName = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SupplierName = (gcnew System::Windows::Forms::TextBox());
			this->DelSupplier_Btn = (gcnew System::Windows::Forms::Button());
			this->EditSupplier_Btn = (gcnew System::Windows::Forms::Button());
			this->AddSupplier_Btn = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->Header->SuspendLayout();
			this->FooterPanel->SuspendLayout();
			this->RightPanel->SuspendLayout();
			this->NavPanel->SuspendLayout();
			this->UserPanel->SuspendLayout();
			this->CenterPanel->SuspendLayout();
			this->HomePanel->SuspendLayout();
			this->fastNav->SuspendLayout();
			this->recentSalesPanel->SuspendLayout();
			this->panel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->recentSalesTable))->BeginInit();
			this->Cards->SuspendLayout();
			this->CardPanelHead->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel6->SuspendLayout();
			this->stockPanel->SuspendLayout();
			this->InvoiceDetailsContainer->SuspendLayout();
			this->panel11->SuspendLayout();
			this->InvoiceHeaderContainer->SuspendLayout();
			this->InvoiceHeaderTitlepanel->SuspendLayout();
			this->InvoiceHeaderTableContainer->SuspendLayout();
			this->SearchInvoiceHeaderPanel->SuspendLayout();
			this->SearchInvoiceHeaderContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InvoiceHeaderTable))->BeginInit();
			this->cashierPanel->SuspendLayout();
			this->panel9->SuspendLayout();
			this->CashierTablePanelContainer->SuspendLayout();
			this->CashierTableTitlePanel->SuspendLayout();
			this->CashierTablePanel->SuspendLayout();
			this->CashierSearchProductPanel->SuspendLayout();
			this->CashierSearchProductContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CashierTable))->BeginInit();
			this->panel12->SuspendLayout();
			this->panel14->SuspendLayout();
			this->panel10->SuspendLayout();
			this->payFeildContainer->SuspendLayout();
			this->panel15->SuspendLayout();
			this->productPanel->SuspendLayout();
			this->ProductTableContainer->SuspendLayout();
			this->ProductTableTitlePanel->SuspendLayout();
			this->ProductTablePanel->SuspendLayout();
			this->ProductSearchContainer->SuspendLayout();
			this->ProductSearchPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProductTable))->BeginInit();
			this->ManageProductContainer->SuspendLayout();
			this->ManageProductFormPanel->SuspendLayout();
			this->ContainerOfProductQuantity->SuspendLayout();
			this->ContainerOfProductPrice->SuspendLayout();
			this->ContainerOfProductName->SuspendLayout();
			this->ManageProductTitlePanel->SuspendLayout();
			this->categoryPanel->SuspendLayout();
			this->CategoryTableContainer->SuspendLayout();
			this->CategoryTableTitlePanel->SuspendLayout();
			this->CategoryTablePanel->SuspendLayout();
			this->SearchPanelContainer->SuspendLayout();
			this->CategorySearchPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CategoryTable))->BeginInit();
			this->ManageCategoryPanel->SuspendLayout();
			this->panel8->SuspendLayout();
			this->ContainerOfCatDesc->SuspendLayout();
			this->ContainerOfCatName->SuspendLayout();
			this->CategoryFormTitkePanel->SuspendLayout();
			this->supplierPanel->SuspendLayout();
			this->SupplierTableContainer->SuspendLayout();
			this->SupplierTableTitlePanel->SuspendLayout();
			this->SupplierTablePanel->SuspendLayout();
			this->SupplierSearchContainer->SuspendLayout();
			this->SupplierSearchPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SupplierTable))->BeginInit();
			this->ManageSupplierContainer->SuspendLayout();
			this->ManageSupplierFormsPanel->SuspendLayout();
			this->ContainerOfSupplierContact_Info->SuspendLayout();
			this->ContainerOfSupplierName->SuspendLayout();
			this->panel13->SuspendLayout();
			this->SuspendLayout();
			// 
			// Header
			// 
			this->Header->AccessibleName = L"headerPanel";
			this->Header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Header->Controls->Add(this->minMax);
			this->Header->Controls->Add(this->mimimizeBtn);
			this->Header->Controls->Add(this->closeBtn);
			this->Header->Controls->Add(this->logo);
			this->Header->Controls->Add(this->label1);
			this->Header->Dock = System::Windows::Forms::DockStyle::Top;
			this->Header->Location = System::Drawing::Point(0, 0);
			this->Header->Name = L"Header";
			this->Header->Size = System::Drawing::Size(1536, 68);
			this->Header->TabIndex = 0;
			// 
			// minMax
			// 
			this->minMax->AccessibleName = L"minMax";
			this->minMax->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->minMax->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->minMax->FlatAppearance->BorderSize = 0;
			this->minMax->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->minMax->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->minMax->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"minMax.Image")));
			this->minMax->Location = System::Drawing::Point(1264, 9);
			this->minMax->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->minMax->Name = L"minMax";
			this->minMax->Size = System::Drawing::Size(57, 44);
			this->minMax->TabIndex = 3;
			this->minMax->UseVisualStyleBackColor = false;
			this->minMax->Visible = false;
			this->minMax->Click += gcnew System::EventHandler(this, &Dashboard::button5_Click_1);
			// 
			// mimimizeBtn
			// 
			this->mimimizeBtn->AccessibleName = L"mimimizeBtn";
			this->mimimizeBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->mimimizeBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->mimimizeBtn->FlatAppearance->BorderSize = 0;
			this->mimimizeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mimimizeBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->mimimizeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mimimizeBtn.Image")));
			this->mimimizeBtn->Location = System::Drawing::Point(1414, 16);
			this->mimimizeBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->mimimizeBtn->Name = L"mimimizeBtn";
			this->mimimizeBtn->Size = System::Drawing::Size(45, 34);
			this->mimimizeBtn->TabIndex = 3;
			this->mimimizeBtn->UseVisualStyleBackColor = false;
			this->mimimizeBtn->Click += gcnew System::EventHandler(this, &Dashboard::minimize_Click);
			// 
			// closeBtn
			// 
			this->closeBtn->AccessibleName = L"closeBtn";
			this->closeBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->closeBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->closeBtn->FlatAppearance->BorderSize = 0;
			this->closeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->closeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeBtn.Image")));
			this->closeBtn->Location = System::Drawing::Point(1465, 9);
			this->closeBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(60, 49);
			this->closeBtn->TabIndex = 3;
			this->closeBtn->UseVisualStyleBackColor = false;
			this->closeBtn->Click += gcnew System::EventHandler(this, &Dashboard::closeBtn_Click);
			// 
			// logo
			// 
			this->logo->AutoSize = true;
			this->logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logo.Image")));
			this->logo->Location = System::Drawing::Point(9, 4);
			this->logo->Margin = System::Windows::Forms::Padding(4, 4, 2, 0);
			this->logo->MaximumSize = System::Drawing::Size(0, 64);
			this->logo->MinimumSize = System::Drawing::Size(200, 16);
			this->logo->Name = L"logo";
			this->logo->Padding = System::Windows::Forms::Padding(32, 28, 56, 28);
			this->logo->Size = System::Drawing::Size(200, 64);
			this->logo->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AccessibleName = L"AppTitle";
			this->label1->AutoSize = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(673, 18);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L" ...مدير الصيدلية";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// FooterPanel
			// 
			this->FooterPanel->AccessibleName = L"FooterPanel";
			this->FooterPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->FooterPanel->Controls->Add(this->label4);
			this->FooterPanel->Controls->Add(this->label3);
			this->FooterPanel->Controls->Add(this->pharmacyName);
			this->FooterPanel->Controls->Add(this->pharmacyNameLabel);
			this->FooterPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->FooterPanel->Location = System::Drawing::Point(0, 762);
			this->FooterPanel->Name = L"FooterPanel";
			this->FooterPanel->Size = System::Drawing::Size(1536, 87);
			this->FooterPanel->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AccessibleName = L"pharmacyName";
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Silver;
			this->label4->Location = System::Drawing::Point(7, 38);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(158, 20);
			this->label4->TabIndex = 0;
			this->label4->Text = L"All rights reserved.";
			// 
			// label3
			// 
			this->label3->AccessibleName = L"pharmacyName";
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Silver;
			this->label3->Location = System::Drawing::Point(2, 15);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(255, 20);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Copyright © 2025 Cyto0plasm .";
			// 
			// pharmacyName
			// 
			this->pharmacyName->AccessibleName = L"pharmacyName";
			this->pharmacyName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->pharmacyName->AutoSize = true;
			this->pharmacyName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pharmacyName->ForeColor = System::Drawing::Color::Lime;
			this->pharmacyName->Location = System::Drawing::Point(1333, 28);
			this->pharmacyName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->pharmacyName->Name = L"pharmacyName";
			this->pharmacyName->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->pharmacyName->Size = System::Drawing::Size(0, 31);
			this->pharmacyName->TabIndex = 0;
			// 
			// pharmacyNameLabel
			// 
			this->pharmacyNameLabel->AccessibleName = L"pharmacyNameLabel";
			this->pharmacyNameLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->pharmacyNameLabel->AutoSize = true;
			this->pharmacyNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pharmacyNameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pharmacyNameLabel->Location = System::Drawing::Point(1366, 30);
			this->pharmacyNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->pharmacyNameLabel->Name = L"pharmacyNameLabel";
			this->pharmacyNameLabel->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->pharmacyNameLabel->Size = System::Drawing::Size(0, 31);
			this->pharmacyNameLabel->TabIndex = 0;
			// 
			// RightPanel
			// 
			this->RightPanel->AccessibleName = L"RightPanel";
			this->RightPanel->Controls->Add(this->NavPanel);
			this->RightPanel->Controls->Add(this->UserPanel);
			this->RightPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->RightPanel->Location = System::Drawing::Point(1328, 68);
			this->RightPanel->MaximumSize = System::Drawing::Size(208, 552);
			this->RightPanel->MinimumSize = System::Drawing::Size(56, 552);
			this->RightPanel->Name = L"RightPanel";
			this->RightPanel->Size = System::Drawing::Size(208, 552);
			this->RightPanel->TabIndex = 2;
			// 
			// NavPanel
			// 
			this->NavPanel->AccessibleName = L"NavPanel";
			this->NavPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->NavPanel->Controls->Add(this->homeBtn);
			this->NavPanel->Controls->Add(this->cashierBtn);
			this->NavPanel->Controls->Add(this->productBtn);
			this->NavPanel->Controls->Add(this->categoryBtn);
			this->NavPanel->Controls->Add(this->supplierBtn);
			this->NavPanel->Controls->Add(this->stockBtn);
			this->NavPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->NavPanel->Location = System::Drawing::Point(0, 117);
			this->NavPanel->MaximumSize = System::Drawing::Size(236, 569);
			this->NavPanel->Name = L"NavPanel";
			this->NavPanel->Size = System::Drawing::Size(208, 435);
			this->NavPanel->TabIndex = 1;
			// 
			// homeBtn
			// 
			this->homeBtn->AccessibleName = L"homeBtn";
			this->homeBtn->AutoEllipsis = true;
			this->homeBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->homeBtn->FlatAppearance->BorderSize = 0;
			this->homeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->homeBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->homeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"homeBtn.Image")));
			this->homeBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->homeBtn->Location = System::Drawing::Point(3, 5);
			this->homeBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->homeBtn->MaximumSize = System::Drawing::Size(200, 64);
			this->homeBtn->MinimumSize = System::Drawing::Size(64, 64);
			this->homeBtn->Name = L"homeBtn";
			this->homeBtn->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
			this->homeBtn->Size = System::Drawing::Size(200, 64);
			this->homeBtn->TabIndex = 1;
			this->homeBtn->Text = L"الرئيسية";
			this->homeBtn->UseVisualStyleBackColor = false;
			this->homeBtn->Click += gcnew System::EventHandler(this, &Dashboard::homeBtn_Click);
			// 
			// cashierBtn
			// 
			this->cashierBtn->AccessibleName = L"cashierBtn";
			this->cashierBtn->AutoEllipsis = true;
			this->cashierBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->cashierBtn->FlatAppearance->BorderSize = 0;
			this->cashierBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cashierBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->cashierBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cashierBtn.Image")));
			this->cashierBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->cashierBtn->Location = System::Drawing::Point(3, 77);
			this->cashierBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->cashierBtn->MaximumSize = System::Drawing::Size(200, 64);
			this->cashierBtn->MinimumSize = System::Drawing::Size(64, 64);
			this->cashierBtn->Name = L"cashierBtn";
			this->cashierBtn->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
			this->cashierBtn->Size = System::Drawing::Size(200, 64);
			this->cashierBtn->TabIndex = 2;
			this->cashierBtn->Text = L"كاشير";
			this->cashierBtn->UseVisualStyleBackColor = false;
			this->cashierBtn->Click += gcnew System::EventHandler(this, &Dashboard::cashierBtn_Click);
			// 
			// productBtn
			// 
			this->productBtn->AccessibleName = L"productBtn";
			this->productBtn->AutoEllipsis = true;
			this->productBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->productBtn->FlatAppearance->BorderSize = 0;
			this->productBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->productBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->productBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"productBtn.Image")));
			this->productBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->productBtn->Location = System::Drawing::Point(3, 149);
			this->productBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->productBtn->MaximumSize = System::Drawing::Size(200, 64);
			this->productBtn->MinimumSize = System::Drawing::Size(64, 64);
			this->productBtn->Name = L"productBtn";
			this->productBtn->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
			this->productBtn->Size = System::Drawing::Size(200, 64);
			this->productBtn->TabIndex = 3;
			this->productBtn->Text = L"المنتجات";
			this->productBtn->UseVisualStyleBackColor = false;
			this->productBtn->Click += gcnew System::EventHandler(this, &Dashboard::productBtn_Click);
			// 
			// categoryBtn
			// 
			this->categoryBtn->AccessibleName = L"categoryBtn";
			this->categoryBtn->AutoEllipsis = true;
			this->categoryBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->categoryBtn->FlatAppearance->BorderSize = 0;
			this->categoryBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->categoryBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->categoryBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"categoryBtn.Image")));
			this->categoryBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->categoryBtn->Location = System::Drawing::Point(3, 221);
			this->categoryBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->categoryBtn->MaximumSize = System::Drawing::Size(200, 64);
			this->categoryBtn->MinimumSize = System::Drawing::Size(64, 64);
			this->categoryBtn->Name = L"categoryBtn";
			this->categoryBtn->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
			this->categoryBtn->Size = System::Drawing::Size(200, 64);
			this->categoryBtn->TabIndex = 4;
			this->categoryBtn->Text = L"الاصناف";
			this->categoryBtn->UseVisualStyleBackColor = false;
			this->categoryBtn->Click += gcnew System::EventHandler(this, &Dashboard::categoryBtn_Click);
			// 
			// supplierBtn
			// 
			this->supplierBtn->AccessibleName = L"supplierBtn";
			this->supplierBtn->AutoEllipsis = true;
			this->supplierBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->supplierBtn->FlatAppearance->BorderSize = 0;
			this->supplierBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->supplierBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->supplierBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"supplierBtn.Image")));
			this->supplierBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->supplierBtn->Location = System::Drawing::Point(3, 293);
			this->supplierBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->supplierBtn->MaximumSize = System::Drawing::Size(200, 64);
			this->supplierBtn->MinimumSize = System::Drawing::Size(64, 64);
			this->supplierBtn->Name = L"supplierBtn";
			this->supplierBtn->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
			this->supplierBtn->Size = System::Drawing::Size(200, 64);
			this->supplierBtn->TabIndex = 5;
			this->supplierBtn->Text = L"الموردين";
			this->supplierBtn->UseVisualStyleBackColor = false;
			this->supplierBtn->Click += gcnew System::EventHandler(this, &Dashboard::supplierBtn_Click);
			// 
			// stockBtn
			// 
			this->stockBtn->AccessibleName = L"stockBtn";
			this->stockBtn->AutoEllipsis = true;
			this->stockBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->stockBtn->FlatAppearance->BorderSize = 0;
			this->stockBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->stockBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->stockBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"stockBtn.Image")));
			this->stockBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->stockBtn->Location = System::Drawing::Point(3, 365);
			this->stockBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->stockBtn->MaximumSize = System::Drawing::Size(200, 64);
			this->stockBtn->MinimumSize = System::Drawing::Size(64, 64);
			this->stockBtn->Name = L"stockBtn";
			this->stockBtn->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
			this->stockBtn->Size = System::Drawing::Size(200, 64);
			this->stockBtn->TabIndex = 6;
			this->stockBtn->Text = L"المخزون";
			this->stockBtn->UseVisualStyleBackColor = false;
			this->stockBtn->Click += gcnew System::EventHandler(this, &Dashboard::stockBtn_Click);
			// 
			// UserPanel
			// 
			this->UserPanel->AccessibleName = L"UserPanel";
			this->UserPanel->Controls->Add(this->userBtn);
			this->UserPanel->Controls->Add(this->collaps);
			this->UserPanel->Controls->Add(this->expandBtn);
			this->UserPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->UserPanel->Location = System::Drawing::Point(0, 0);
			this->UserPanel->Name = L"UserPanel";
			this->UserPanel->Size = System::Drawing::Size(208, 117);
			this->UserPanel->TabIndex = 0;
			// 
			// userBtn
			// 
			this->userBtn->AccessibleName = L"userBtn";
			this->userBtn->AutoEllipsis = true;
			this->userBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->userBtn->FlatAppearance->BorderSize = 0;
			this->userBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->userBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->userBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"userBtn.Image")));
			this->userBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->userBtn->Location = System::Drawing::Point(4, 34);
			this->userBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->userBtn->MaximumSize = System::Drawing::Size(200, 77);
			this->userBtn->MinimumSize = System::Drawing::Size(64, 77);
			this->userBtn->Name = L"userBtn";
			this->userBtn->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
			this->userBtn->Size = System::Drawing::Size(200, 77);
			this->userBtn->TabIndex = 5;
			this->userBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->userBtn->UseVisualStyleBackColor = false;
			// 
			// collaps
			// 
			this->collaps->AccessibleName = L"collapsBtn";
			this->collaps->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->collaps->FlatAppearance->BorderSize = 0;
			this->collaps->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->collaps->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->collaps->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"collaps.Image")));
			this->collaps->Location = System::Drawing::Point(15, 8);
			this->collaps->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->collaps->Name = L"collaps";
			this->collaps->Size = System::Drawing::Size(24, 24);
			this->collaps->TabIndex = 3;
			this->collaps->UseVisualStyleBackColor = false;
			this->collaps->Click += gcnew System::EventHandler(this, &Dashboard::collaps_Click);
			// 
			// expandBtn
			// 
			this->expandBtn->AccessibleName = L"expandBtn";
			this->expandBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->expandBtn->FlatAppearance->BorderSize = 0;
			this->expandBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->expandBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->expandBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"expandBtn.Image")));
			this->expandBtn->Location = System::Drawing::Point(15, 8);
			this->expandBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->expandBtn->Name = L"expandBtn";
			this->expandBtn->Size = System::Drawing::Size(24, 24);
			this->expandBtn->TabIndex = 3;
			this->expandBtn->UseVisualStyleBackColor = false;
			this->expandBtn->Click += gcnew System::EventHandler(this, &Dashboard::collaps_Click);
			// 
			// CenterPanel
			// 
			this->CenterPanel->AccessibleName = L"Home";
			this->CenterPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CenterPanel->Controls->Add(this->HomePanel);
			this->CenterPanel->Controls->Add(this->stockPanel);
			this->CenterPanel->Controls->Add(this->cashierPanel);
			this->CenterPanel->Controls->Add(this->productPanel);
			this->CenterPanel->Controls->Add(this->categoryPanel);
			this->CenterPanel->Controls->Add(this->supplierPanel);
			this->CenterPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CenterPanel->Location = System::Drawing::Point(0, 68);
			this->CenterPanel->Name = L"CenterPanel";
			this->CenterPanel->Size = System::Drawing::Size(1328, 694);
			this->CenterPanel->TabIndex = 3;
			// 
			// HomePanel
			// 
			this->HomePanel->Controls->Add(this->fastNav);
			this->HomePanel->Controls->Add(this->recentSalesPanel);
			this->HomePanel->Controls->Add(this->Cards);
			this->HomePanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->HomePanel->Location = System::Drawing::Point(0, 0);
			this->HomePanel->Margin = System::Windows::Forms::Padding(2);
			this->HomePanel->Name = L"HomePanel";
			this->HomePanel->Size = System::Drawing::Size(1326, 692);
			this->HomePanel->TabIndex = 0;
			// 
			// fastNav
			// 
			this->fastNav->AutoSize = true;
			this->fastNav->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->fastNav->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->fastNav->Controls->Add(this->totalSales);
			this->fastNav->Controls->Add(this->button8);
			this->fastNav->Controls->Add(this->SCAddSupplier);
			this->fastNav->Controls->Add(this->SCAddCategory);
			this->fastNav->Controls->Add(this->SCAddProduct);
			this->fastNav->Dock = System::Windows::Forms::DockStyle::Top;
			this->fastNav->Location = System::Drawing::Point(0, 0);
			this->fastNav->Margin = System::Windows::Forms::Padding(0);
			this->fastNav->MinimumSize = System::Drawing::Size(1520, 88);
			this->fastNav->Name = L"fastNav";
			this->fastNav->Size = System::Drawing::Size(1520, 89);
			this->fastNav->TabIndex = 1;
			// 
			// totalSales
			// 
			this->totalSales->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->totalSales->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->totalSales->FlatAppearance->BorderSize = 0;
			this->totalSales->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->totalSales->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totalSales->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->totalSales->Location = System::Drawing::Point(2, 2);
			this->totalSales->Margin = System::Windows::Forms::Padding(2);
			this->totalSales->Name = L"totalSales";
			this->totalSales->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->totalSales->Size = System::Drawing::Size(262, 83);
			this->totalSales->TabIndex = 0;
			this->totalSales->Text = L"الة حاسبة";
			this->totalSales->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button8->FlatAppearance->BorderSize = 0;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button8->Location = System::Drawing::Point(268, 2);
			this->button8->Margin = System::Windows::Forms::Padding(2);
			this->button8->Name = L"button8";
			this->button8->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button8->Size = System::Drawing::Size(262, 83);
			this->button8->TabIndex = 0;
			this->button8->Text = L"المورد المتميز";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// SCAddSupplier
			// 
			this->SCAddSupplier->AccessibleName = L"SCAddSupplier";
			this->SCAddSupplier->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->SCAddSupplier->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->SCAddSupplier->FlatAppearance->BorderSize = 0;
			this->SCAddSupplier->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SCAddSupplier->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SCAddSupplier->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->SCAddSupplier->Location = System::Drawing::Point(534, 2);
			this->SCAddSupplier->Margin = System::Windows::Forms::Padding(2);
			this->SCAddSupplier->Name = L"SCAddSupplier";
			this->SCAddSupplier->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SCAddSupplier->Size = System::Drawing::Size(262, 83);
			this->SCAddSupplier->TabIndex = 0;
			this->SCAddSupplier->Text = L"اضافة مورد";
			this->SCAddSupplier->UseVisualStyleBackColor = true;
			this->SCAddSupplier->Click += gcnew System::EventHandler(this, &Dashboard::SCAddSupplier_Click);
			// 
			// SCAddCategory
			// 
			this->SCAddCategory->AccessibleName = L"SCAddCategory";
			this->SCAddCategory->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->SCAddCategory->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->SCAddCategory->FlatAppearance->BorderSize = 0;
			this->SCAddCategory->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SCAddCategory->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SCAddCategory->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->SCAddCategory->Location = System::Drawing::Point(800, 2);
			this->SCAddCategory->Margin = System::Windows::Forms::Padding(2);
			this->SCAddCategory->Name = L"SCAddCategory";
			this->SCAddCategory->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SCAddCategory->Size = System::Drawing::Size(262, 83);
			this->SCAddCategory->TabIndex = 0;
			this->SCAddCategory->Text = L"اضافة صنف";
			this->SCAddCategory->UseVisualStyleBackColor = true;
			this->SCAddCategory->Click += gcnew System::EventHandler(this, &Dashboard::SCAddCategory_Click);
			// 
			// SCAddProduct
			// 
			this->SCAddProduct->AccessibleName = L"SCAddProduct";
			this->SCAddProduct->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->SCAddProduct->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->SCAddProduct->FlatAppearance->BorderSize = 0;
			this->SCAddProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SCAddProduct->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SCAddProduct->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->SCAddProduct->Location = System::Drawing::Point(1066, 2);
			this->SCAddProduct->Margin = System::Windows::Forms::Padding(2);
			this->SCAddProduct->Name = L"SCAddProduct";
			this->SCAddProduct->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SCAddProduct->Size = System::Drawing::Size(262, 83);
			this->SCAddProduct->TabIndex = 0;
			this->SCAddProduct->Text = L"اضافة منتج";
			this->SCAddProduct->UseVisualStyleBackColor = true;
			this->SCAddProduct->Click += gcnew System::EventHandler(this, &Dashboard::SCAddProduct_Click);
			// 
			// recentSalesPanel
			// 
			this->recentSalesPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->recentSalesPanel->Controls->Add(this->panel7);
			this->recentSalesPanel->Controls->Add(this->recentSalesTable);
			this->recentSalesPanel->FlowDirection = System::Windows::Forms::FlowDirection::RightToLeft;
			this->recentSalesPanel->Location = System::Drawing::Point(4, 97);
			this->recentSalesPanel->Margin = System::Windows::Forms::Padding(4, 8, 4, 8);
			this->recentSalesPanel->Name = L"recentSalesPanel";
			this->recentSalesPanel->Size = System::Drawing::Size(639, 593);
			this->recentSalesPanel->TabIndex = 2;
			// 
			// panel7
			// 
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel7->Controls->Add(this->label2);
			this->panel7->Location = System::Drawing::Point(5, 2);
			this->panel7->Margin = System::Windows::Forms::Padding(2);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(630, 64);
			this->panel7->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->AutoEllipsis = true;
			this->label2->AutoSize = true;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(230, 22);
			this->label2->Margin = System::Windows::Forms::Padding(80, 12, 40, 8);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 27);
			this->label2->TabIndex = 7;
			this->label2->Text = L"اخر الفواتير";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// recentSalesTable
			// 
			this->recentSalesTable->AccessibleName = L"recentSalesTable";
			this->recentSalesTable->AllowUserToAddRows = false;
			this->recentSalesTable->AllowUserToDeleteRows = false;
			dataGridViewCellStyle31->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			dataGridViewCellStyle31->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle31->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle31->Padding = System::Windows::Forms::Padding(4);
			dataGridViewCellStyle31->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle31->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle31->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->recentSalesTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle31;
			this->recentSalesTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->recentSalesTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->recentSalesTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->recentSalesTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle32->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(65)));
			dataGridViewCellStyle32->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle32->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle32->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle32->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			dataGridViewCellStyle32->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle32->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->recentSalesTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle32;
			this->recentSalesTable->ColumnHeadersHeight = 50;
			this->recentSalesTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->recentSalesTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->SaleId,
					this->SaleDate, this->SaleQuantity, this->SalePrice
			});
			dataGridViewCellStyle34->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle34->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle34->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle34->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle34->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle34->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle34->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->recentSalesTable->DefaultCellStyle = dataGridViewCellStyle34;
			this->recentSalesTable->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->recentSalesTable->EnableHeadersVisualStyles = false;
			this->recentSalesTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->recentSalesTable->Location = System::Drawing::Point(6, 76);
			this->recentSalesTable->Margin = System::Windows::Forms::Padding(8);
			this->recentSalesTable->Name = L"recentSalesTable";
			this->recentSalesTable->ReadOnly = true;
			this->recentSalesTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->recentSalesTable->RowHeadersVisible = false;
			this->recentSalesTable->RowHeadersWidth = 51;
			dataGridViewCellStyle35->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle35->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle35->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle35->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle35->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle35->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle35->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle35->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->recentSalesTable->RowsDefaultCellStyle = dataGridViewCellStyle35;
			this->recentSalesTable->RowTemplate->Height = 40;
			this->recentSalesTable->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->recentSalesTable->Size = System::Drawing::Size(623, 508);
			this->recentSalesTable->StandardTab = true;
			this->recentSalesTable->TabIndex = 0;
			this->recentSalesTable->CellMouseEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::recentSalesTable_CellMouseEnter);
			this->recentSalesTable->CellMouseLeave += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::recentSalesTable_CellMouseLeave);
			this->recentSalesTable->DataBindingComplete += gcnew System::Windows::Forms::DataGridViewBindingCompleteEventHandler(this, &Dashboard::recentSalesTable_DataBindingComplete);
			// 
			// SaleId
			// 
			this->SaleId->DataPropertyName = L"id";
			this->SaleId->HeaderText = L"رقم الفاتورة";
			this->SaleId->MaxInputLength = 10;
			this->SaleId->MinimumWidth = 80;
			this->SaleId->Name = L"SaleId";
			this->SaleId->ReadOnly = true;
			this->SaleId->ToolTipText = L"الرقم التعريفي للفاتورة";
			// 
			// SaleDate
			// 
			this->SaleDate->DataPropertyName = L"createdAt";
			this->SaleDate->HeaderText = L"التاريخ";
			this->SaleDate->MaxInputLength = 15;
			this->SaleDate->MinimumWidth = 100;
			this->SaleDate->Name = L"SaleDate";
			this->SaleDate->ReadOnly = true;
			this->SaleDate->ToolTipText = L"تاريخ دفع الفاتورة";
			// 
			// SaleQuantity
			// 
			this->SaleQuantity->DataPropertyName = L"quantity";
			this->SaleQuantity->HeaderText = L"الكمية";
			this->SaleQuantity->MaxInputLength = 20;
			this->SaleQuantity->MinimumWidth = 80;
			this->SaleQuantity->Name = L"SaleQuantity";
			this->SaleQuantity->ReadOnly = true;
			// 
			// SalePrice
			// 
			this->SalePrice->DataPropertyName = L"total_price";
			dataGridViewCellStyle33->Padding = System::Windows::Forms::Padding(8);
			this->SalePrice->DefaultCellStyle = dataGridViewCellStyle33;
			this->SalePrice->HeaderText = L"المبلغ ";
			this->SalePrice->MaxInputLength = 50;
			this->SalePrice->MinimumWidth = 80;
			this->SalePrice->Name = L"SalePrice";
			this->SalePrice->ReadOnly = true;
			// 
			// Cards
			// 
			this->Cards->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Cards->Controls->Add(this->CardPanelHead);
			this->Cards->Controls->Add(this->panel5);
			this->Cards->Controls->Add(this->panel3);
			this->Cards->Controls->Add(this->panel4);
			this->Cards->Controls->Add(this->panel6);
			this->Cards->Location = System::Drawing::Point(651, 97);
			this->Cards->Margin = System::Windows::Forms::Padding(4, 8, 4, 8);
			this->Cards->MaximumSize = System::Drawing::Size(672, 480);
			this->Cards->Name = L"Cards";
			this->Cards->Size = System::Drawing::Size(670, 352);
			this->Cards->TabIndex = 4;
			// 
			// CardPanelHead
			// 
			this->CardPanelHead->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CardPanelHead->Controls->Add(this->CardPanelTitle);
			this->CardPanelHead->Location = System::Drawing::Point(4, 2);
			this->CardPanelHead->Margin = System::Windows::Forms::Padding(4, 2, 2, 2);
			this->CardPanelHead->Name = L"CardPanelHead";
			this->CardPanelHead->Size = System::Drawing::Size(661, 64);
			this->CardPanelHead->TabIndex = 8;
			// 
			// CardPanelTitle
			// 
			this->CardPanelTitle->AutoEllipsis = true;
			this->CardPanelTitle->AutoSize = true;
			this->CardPanelTitle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CardPanelTitle->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CardPanelTitle->ForeColor = System::Drawing::Color::White;
			this->CardPanelTitle->Location = System::Drawing::Point(280, 18);
			this->CardPanelTitle->Margin = System::Windows::Forms::Padding(80, 12, 40, 8);
			this->CardPanelTitle->Name = L"CardPanelTitle";
			this->CardPanelTitle->Size = System::Drawing::Size(111, 27);
			this->CardPanelTitle->TabIndex = 7;
			this->CardPanelTitle->Text = L"احصائيات";
			this->CardPanelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->LatestProductsListBox);
			this->panel5->Controls->Add(this->button6);
			this->panel5->Location = System::Drawing::Point(8, 76);
			this->panel5->Margin = System::Windows::Forms::Padding(8);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(315, 126);
			this->panel5->TabIndex = 5;
			// 
			// LatestProductsListBox
			// 
			this->LatestProductsListBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->LatestProductsListBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->LatestProductsListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LatestProductsListBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LatestProductsListBox->ForeColor = System::Drawing::Color::White;
			this->LatestProductsListBox->FormattingEnabled = true;
			this->LatestProductsListBox->IntegralHeight = false;
			this->LatestProductsListBox->ItemHeight = 21;
			this->LatestProductsListBox->Location = System::Drawing::Point(0, 32);
			this->LatestProductsListBox->Margin = System::Windows::Forms::Padding(2);
			this->LatestProductsListBox->Name = L"LatestProductsListBox";
			this->LatestProductsListBox->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->LatestProductsListBox->Size = System::Drawing::Size(315, 94);
			this->LatestProductsListBox->TabIndex = 1;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->button6->Dock = System::Windows::Forms::DockStyle::Top;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button6->Location = System::Drawing::Point(0, 0);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button6->Size = System::Drawing::Size(315, 32);
			this->button6->TabIndex = 0;
			this->button6->Text = L"احدث المنتجات";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Dashboard::productBtn_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->TotalProfitsListBox);
			this->panel3->Controls->Add(this->button4);
			this->panel3->Location = System::Drawing::Point(339, 76);
			this->panel3->Margin = System::Windows::Forms::Padding(8);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(315, 126);
			this->panel3->TabIndex = 3;
			// 
			// TotalProfitsListBox
			// 
			this->TotalProfitsListBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->TotalProfitsListBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->TotalProfitsListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TotalProfitsListBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TotalProfitsListBox->ForeColor = System::Drawing::Color::White;
			this->TotalProfitsListBox->FormattingEnabled = true;
			this->TotalProfitsListBox->IntegralHeight = false;
			this->TotalProfitsListBox->ItemHeight = 21;
			this->TotalProfitsListBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"ارباح اليوم:", L"ارباح الشهر:", L"ارباح السنة:" });
			this->TotalProfitsListBox->Location = System::Drawing::Point(0, 32);
			this->TotalProfitsListBox->Margin = System::Windows::Forms::Padding(2);
			this->TotalProfitsListBox->Name = L"TotalProfitsListBox";
			this->TotalProfitsListBox->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->TotalProfitsListBox->Size = System::Drawing::Size(315, 94);
			this->TotalProfitsListBox->TabIndex = 1;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->button4->Dock = System::Windows::Forms::DockStyle::Top;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button4->Location = System::Drawing::Point(0, 0);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button4->Size = System::Drawing::Size(315, 32);
			this->button4->TabIndex = 0;
			this->button4->Text = L"الارباح";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Dashboard::stockBtn_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->LatestCategoriesListBox);
			this->panel4->Controls->Add(this->button5);
			this->panel4->Location = System::Drawing::Point(8, 218);
			this->panel4->Margin = System::Windows::Forms::Padding(8);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(315, 126);
			this->panel4->TabIndex = 4;
			// 
			// LatestCategoriesListBox
			// 
			this->LatestCategoriesListBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->LatestCategoriesListBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->LatestCategoriesListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LatestCategoriesListBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LatestCategoriesListBox->ForeColor = System::Drawing::Color::White;
			this->LatestCategoriesListBox->FormattingEnabled = true;
			this->LatestCategoriesListBox->IntegralHeight = false;
			this->LatestCategoriesListBox->ItemHeight = 21;
			this->LatestCategoriesListBox->Location = System::Drawing::Point(0, 32);
			this->LatestCategoriesListBox->Margin = System::Windows::Forms::Padding(2);
			this->LatestCategoriesListBox->Name = L"LatestCategoriesListBox";
			this->LatestCategoriesListBox->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->LatestCategoriesListBox->Size = System::Drawing::Size(315, 94);
			this->LatestCategoriesListBox->TabIndex = 1;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->button5->Dock = System::Windows::Forms::DockStyle::Top;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button5->Location = System::Drawing::Point(0, 0);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button5->Size = System::Drawing::Size(315, 32);
			this->button5->TabIndex = 0;
			this->button5->Text = L"احدث الاصناف";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Dashboard::categoryBtn_Click);
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->LatestSuppliersListBox);
			this->panel6->Controls->Add(this->button7);
			this->panel6->Location = System::Drawing::Point(339, 218);
			this->panel6->Margin = System::Windows::Forms::Padding(8);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(315, 126);
			this->panel6->TabIndex = 6;
			// 
			// LatestSuppliersListBox
			// 
			this->LatestSuppliersListBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->LatestSuppliersListBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->LatestSuppliersListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LatestSuppliersListBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LatestSuppliersListBox->ForeColor = System::Drawing::Color::White;
			this->LatestSuppliersListBox->FormattingEnabled = true;
			this->LatestSuppliersListBox->IntegralHeight = false;
			this->LatestSuppliersListBox->ItemHeight = 21;
			this->LatestSuppliersListBox->Location = System::Drawing::Point(0, 32);
			this->LatestSuppliersListBox->Margin = System::Windows::Forms::Padding(2);
			this->LatestSuppliersListBox->Name = L"LatestSuppliersListBox";
			this->LatestSuppliersListBox->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->LatestSuppliersListBox->Size = System::Drawing::Size(315, 94);
			this->LatestSuppliersListBox->TabIndex = 1;
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->button7->Dock = System::Windows::Forms::DockStyle::Top;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button7->Location = System::Drawing::Point(0, 0);
			this->button7->Margin = System::Windows::Forms::Padding(2);
			this->button7->Name = L"button7";
			this->button7->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button7->Size = System::Drawing::Size(315, 32);
			this->button7->TabIndex = 0;
			this->button7->Text = L"احدث الموردين";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Dashboard::supplierBtn_Click);
			// 
			// stockPanel
			// 
			this->stockPanel->Controls->Add(this->InvoiceDetailsContainer);
			this->stockPanel->Controls->Add(this->InvoiceHeaderContainer);
			this->stockPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->stockPanel->Location = System::Drawing::Point(0, 0);
			this->stockPanel->Margin = System::Windows::Forms::Padding(2);
			this->stockPanel->Name = L"stockPanel";
			this->stockPanel->Size = System::Drawing::Size(1326, 692);
			this->stockPanel->TabIndex = 5;
			// 
			// InvoiceDetailsContainer
			// 
			this->InvoiceDetailsContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->InvoiceDetailsContainer->Controls->Add(this->panel11);
			this->InvoiceDetailsContainer->Controls->Add(this->InvoiceDetailsPanel);
			this->InvoiceDetailsContainer->Location = System::Drawing::Point(823, 5);
			this->InvoiceDetailsContainer->Name = L"InvoiceDetailsContainer";
			this->InvoiceDetailsContainer->Size = System::Drawing::Size(500, 686);
			this->InvoiceDetailsContainer->TabIndex = 12;
			// 
			// panel11
			// 
			this->panel11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel11->Controls->Add(this->label6);
			this->panel11->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel11->Location = System::Drawing::Point(0, 0);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(498, 60);
			this->panel11->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->AccessibleName = L"InvoiceHeaderTitleLab";
			this->label6->AutoEllipsis = true;
			this->label6->AutoSize = true;
			this->label6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label6->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(161, 11);
			this->label6->Margin = System::Windows::Forms::Padding(80, 12, 40, 8);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(172, 27);
			this->label6->TabIndex = 7;
			this->label6->Text = L"تفاصيل الفاتورة";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// InvoiceDetailsPanel
			// 
			this->InvoiceDetailsPanel->AccessibleName = L"InvoiceDetailsPanel";
			this->InvoiceDetailsPanel->AutoScroll = true;
			this->InvoiceDetailsPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->InvoiceDetailsPanel->Location = System::Drawing::Point(0, 64);
			this->InvoiceDetailsPanel->Name = L"InvoiceDetailsPanel";
			this->InvoiceDetailsPanel->Size = System::Drawing::Size(495, 613);
			this->InvoiceDetailsPanel->TabIndex = 12;
			// 
			// InvoiceHeaderContainer
			// 
			this->InvoiceHeaderContainer->AutoSize = true;
			this->InvoiceHeaderContainer->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->InvoiceHeaderContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->InvoiceHeaderContainer->Controls->Add(this->InvoiceHeaderTitlepanel);
			this->InvoiceHeaderContainer->Controls->Add(this->InvoiceHeaderTableContainer);
			this->InvoiceHeaderContainer->Dock = System::Windows::Forms::DockStyle::Left;
			this->InvoiceHeaderContainer->FlowDirection = System::Windows::Forms::FlowDirection::RightToLeft;
			this->InvoiceHeaderContainer->Location = System::Drawing::Point(0, 0);
			this->InvoiceHeaderContainer->Margin = System::Windows::Forms::Padding(4, 8, 4, 8);
			this->InvoiceHeaderContainer->MaximumSize = System::Drawing::Size(820, 692);
			this->InvoiceHeaderContainer->MinimumSize = System::Drawing::Size(820, 692);
			this->InvoiceHeaderContainer->Name = L"InvoiceHeaderContainer";
			this->InvoiceHeaderContainer->Size = System::Drawing::Size(820, 692);
			this->InvoiceHeaderContainer->TabIndex = 9;
			// 
			// InvoiceHeaderTitlepanel
			// 
			this->InvoiceHeaderTitlepanel->AccessibleName = L"CashierTableTitlePanel";
			this->InvoiceHeaderTitlepanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->InvoiceHeaderTitlepanel->Controls->Add(this->InvoiceHeaderTitleLab);
			this->InvoiceHeaderTitlepanel->Location = System::Drawing::Point(14, 2);
			this->InvoiceHeaderTitlepanel->Margin = System::Windows::Forms::Padding(2);
			this->InvoiceHeaderTitlepanel->Name = L"InvoiceHeaderTitlepanel";
			this->InvoiceHeaderTitlepanel->Size = System::Drawing::Size(802, 63);
			this->InvoiceHeaderTitlepanel->TabIndex = 9;
			// 
			// InvoiceHeaderTitleLab
			// 
			this->InvoiceHeaderTitleLab->AccessibleName = L"InvoiceHeaderTitleLab";
			this->InvoiceHeaderTitleLab->AutoEllipsis = true;
			this->InvoiceHeaderTitleLab->AutoSize = true;
			this->InvoiceHeaderTitleLab->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->InvoiceHeaderTitleLab->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InvoiceHeaderTitleLab->ForeColor = System::Drawing::Color::White;
			this->InvoiceHeaderTitleLab->Location = System::Drawing::Point(343, 14);
			this->InvoiceHeaderTitleLab->Margin = System::Windows::Forms::Padding(80, 12, 40, 8);
			this->InvoiceHeaderTitleLab->Name = L"InvoiceHeaderTitleLab";
			this->InvoiceHeaderTitleLab->Size = System::Drawing::Size(90, 27);
			this->InvoiceHeaderTitleLab->TabIndex = 7;
			this->InvoiceHeaderTitleLab->Text = L"فواتيرك";
			this->InvoiceHeaderTitleLab->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// InvoiceHeaderTableContainer
			// 
			this->InvoiceHeaderTableContainer->AccessibleName = L"CashierTablePanel";
			this->InvoiceHeaderTableContainer->AutoSize = true;
			this->InvoiceHeaderTableContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->InvoiceHeaderTableContainer->Controls->Add(this->SearchInvoiceHeaderPanel);
			this->InvoiceHeaderTableContainer->Controls->Add(this->InvoiceHeaderTable);
			this->InvoiceHeaderTableContainer->Controls->Add(this->flowLayoutPanel6);
			this->InvoiceHeaderTableContainer->Location = System::Drawing::Point(16, 69);
			this->InvoiceHeaderTableContainer->Margin = System::Windows::Forms::Padding(2);
			this->InvoiceHeaderTableContainer->MaximumSize = System::Drawing::Size(800, 620);
			this->InvoiceHeaderTableContainer->Name = L"InvoiceHeaderTableContainer";
			this->InvoiceHeaderTableContainer->Size = System::Drawing::Size(800, 620);
			this->InvoiceHeaderTableContainer->TabIndex = 13;
			// 
			// SearchInvoiceHeaderPanel
			// 
			this->SearchInvoiceHeaderPanel->AccessibleName = L"CashierSearchProductPanel";
			this->SearchInvoiceHeaderPanel->Controls->Add(this->SearchInvoiceHeaderContainer);
			this->SearchInvoiceHeaderPanel->Controls->Add(this->SearchInvoiceHeaderLab);
			this->SearchInvoiceHeaderPanel->Location = System::Drawing::Point(2, 2);
			this->SearchInvoiceHeaderPanel->Margin = System::Windows::Forms::Padding(2);
			this->SearchInvoiceHeaderPanel->Name = L"SearchInvoiceHeaderPanel";
			this->SearchInvoiceHeaderPanel->Size = System::Drawing::Size(940, 67);
			this->SearchInvoiceHeaderPanel->TabIndex = 14;
			// 
			// SearchInvoiceHeaderContainer
			// 
			this->SearchInvoiceHeaderContainer->AccessibleName = L"CashierSearchProductContainer";
			this->SearchInvoiceHeaderContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SearchInvoiceHeaderContainer->Controls->Add(this->SearchInvoiceHeaderFeild);
			this->SearchInvoiceHeaderContainer->Location = System::Drawing::Point(6, 12);
			this->SearchInvoiceHeaderContainer->Name = L"SearchInvoiceHeaderContainer";
			this->SearchInvoiceHeaderContainer->Padding = System::Windows::Forms::Padding(8);
			this->SearchInvoiceHeaderContainer->Size = System::Drawing::Size(650, 40);
			this->SearchInvoiceHeaderContainer->TabIndex = 13;
			// 
			// SearchInvoiceHeaderFeild
			// 
			this->SearchInvoiceHeaderFeild->AccessibleName = L"CashierSearchProduct";
			this->SearchInvoiceHeaderFeild->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->SearchInvoiceHeaderFeild->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SearchInvoiceHeaderFeild->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchInvoiceHeaderFeild->ForeColor = System::Drawing::Color::White;
			this->SearchInvoiceHeaderFeild->Location = System::Drawing::Point(8, 8);
			this->SearchInvoiceHeaderFeild->Margin = System::Windows::Forms::Padding(0);
			this->SearchInvoiceHeaderFeild->MaxLength = 50;
			this->SearchInvoiceHeaderFeild->Multiline = true;
			this->SearchInvoiceHeaderFeild->Name = L"SearchInvoiceHeaderFeild";
			this->SearchInvoiceHeaderFeild->Size = System::Drawing::Size(630, 24);
			this->SearchInvoiceHeaderFeild->TabIndex = 5;
			this->SearchInvoiceHeaderFeild->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// SearchInvoiceHeaderLab
			// 
			this->SearchInvoiceHeaderLab->AccessibleName = L"CashierSearchLab";
			this->SearchInvoiceHeaderLab->AutoSize = true;
			this->SearchInvoiceHeaderLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchInvoiceHeaderLab->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SearchInvoiceHeaderLab.Image")));
			this->SearchInvoiceHeaderLab->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->SearchInvoiceHeaderLab->Location = System::Drawing::Point(682, 10);
			this->SearchInvoiceHeaderLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->SearchInvoiceHeaderLab->MinimumSize = System::Drawing::Size(96, 48);
			this->SearchInvoiceHeaderLab->Name = L"SearchInvoiceHeaderLab";
			this->SearchInvoiceHeaderLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SearchInvoiceHeaderLab->Size = System::Drawing::Size(96, 48);
			this->SearchInvoiceHeaderLab->TabIndex = 6;
			this->SearchInvoiceHeaderLab->Text = L"البحث";
			this->SearchInvoiceHeaderLab->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// InvoiceHeaderTable
			// 
			this->InvoiceHeaderTable->AccessibleName = L"InvoiceHeaderTable";
			this->InvoiceHeaderTable->AllowUserToAddRows = false;
			this->InvoiceHeaderTable->AllowUserToDeleteRows = false;
			dataGridViewCellStyle36->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle36->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			dataGridViewCellStyle36->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle36->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle36->Padding = System::Windows::Forms::Padding(4);
			dataGridViewCellStyle36->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle36->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle36->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->InvoiceHeaderTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle36;
			this->InvoiceHeaderTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->InvoiceHeaderTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->InvoiceHeaderTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->InvoiceHeaderTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle37->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle37->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(65)));
			dataGridViewCellStyle37->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle37->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle37->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle37->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			dataGridViewCellStyle37->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle37->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->InvoiceHeaderTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle37;
			this->InvoiceHeaderTable->ColumnHeadersHeight = 50;
			this->InvoiceHeaderTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->InvoiceHeaderTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->InvoiceHeaderId,
					this->InvoiceTotalPrice, this->InvoiceHeaderCreatedAt, this->InvoiceHeaderUpdatedAt
			});
			dataGridViewCellStyle39->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle39->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle39->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle39->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle39->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle39->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle39->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle39->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->InvoiceHeaderTable->DefaultCellStyle = dataGridViewCellStyle39;
			this->InvoiceHeaderTable->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->InvoiceHeaderTable->EnableHeadersVisualStyles = false;
			this->InvoiceHeaderTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->InvoiceHeaderTable->Location = System::Drawing::Point(8, 79);
			this->InvoiceHeaderTable->Margin = System::Windows::Forms::Padding(8);
			this->InvoiceHeaderTable->MultiSelect = false;
			this->InvoiceHeaderTable->Name = L"InvoiceHeaderTable";
			this->InvoiceHeaderTable->ReadOnly = true;
			this->InvoiceHeaderTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->InvoiceHeaderTable->RowHeadersVisible = false;
			this->InvoiceHeaderTable->RowHeadersWidth = 51;
			dataGridViewCellStyle40->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle40->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle40->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle40->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle40->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle40->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle40->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle40->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->InvoiceHeaderTable->RowsDefaultCellStyle = dataGridViewCellStyle40;
			this->InvoiceHeaderTable->RowTemplate->Height = 40;
			this->InvoiceHeaderTable->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->InvoiceHeaderTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->InvoiceHeaderTable->Size = System::Drawing::Size(786, 532);
			this->InvoiceHeaderTable->StandardTab = true;
			this->InvoiceHeaderTable->TabIndex = 0;
			this->InvoiceHeaderTable->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::InvoiceHeaderTable_CellClick);
			// 
			// InvoiceHeaderId
			// 
			this->InvoiceHeaderId->DataPropertyName = L"InvoiceHeaderId";
			this->InvoiceHeaderId->HeaderText = L"رقم الفاتورة";
			this->InvoiceHeaderId->MaxInputLength = 10;
			this->InvoiceHeaderId->MinimumWidth = 80;
			this->InvoiceHeaderId->Name = L"InvoiceHeaderId";
			this->InvoiceHeaderId->ReadOnly = true;
			this->InvoiceHeaderId->ToolTipText = L"الرقم التعريفي للفاتورة";
			// 
			// InvoiceTotalPrice
			// 
			this->InvoiceTotalPrice->DataPropertyName = L"InvoiceTotalPrice";
			dataGridViewCellStyle38->Padding = System::Windows::Forms::Padding(8);
			this->InvoiceTotalPrice->DefaultCellStyle = dataGridViewCellStyle38;
			this->InvoiceTotalPrice->HeaderText = L"سعر الفاتورة";
			this->InvoiceTotalPrice->MaxInputLength = 50;
			this->InvoiceTotalPrice->MinimumWidth = 80;
			this->InvoiceTotalPrice->Name = L"InvoiceTotalPrice";
			this->InvoiceTotalPrice->ReadOnly = true;
			this->InvoiceTotalPrice->ToolTipText = L"سعر الفاتورة";
			// 
			// InvoiceHeaderCreatedAt
			// 
			this->InvoiceHeaderCreatedAt->DataPropertyName = L"InvoiceHeaderCreatedAt";
			this->InvoiceHeaderCreatedAt->HeaderText = L"تاريخ الانتاج";
			this->InvoiceHeaderCreatedAt->MinimumWidth = 6;
			this->InvoiceHeaderCreatedAt->Name = L"InvoiceHeaderCreatedAt";
			this->InvoiceHeaderCreatedAt->ReadOnly = true;
			this->InvoiceHeaderCreatedAt->ToolTipText = L"تاريخ الانتاج";
			// 
			// InvoiceHeaderUpdatedAt
			// 
			this->InvoiceHeaderUpdatedAt->DataPropertyName = L"InvoiceHeaderUpdatedAt";
			this->InvoiceHeaderUpdatedAt->HeaderText = L"تاريخ التحديث";
			this->InvoiceHeaderUpdatedAt->Name = L"InvoiceHeaderUpdatedAt";
			this->InvoiceHeaderUpdatedAt->ReadOnly = true;
			// 
			// flowLayoutPanel6
			// 
			this->flowLayoutPanel6->Location = System::Drawing::Point(3, 622);
			this->flowLayoutPanel6->Name = L"flowLayoutPanel6";
			this->flowLayoutPanel6->Size = System::Drawing::Size(148, 49);
			this->flowLayoutPanel6->TabIndex = 15;
			// 
			// cashierPanel
			// 
			this->cashierPanel->Controls->Add(this->panel9);
			this->cashierPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cashierPanel->Location = System::Drawing::Point(0, 0);
			this->cashierPanel->Margin = System::Windows::Forms::Padding(2);
			this->cashierPanel->Name = L"cashierPanel";
			this->cashierPanel->Size = System::Drawing::Size(1326, 692);
			this->cashierPanel->TabIndex = 1;
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->CashierTablePanelContainer);
			this->panel9->Controls->Add(this->panel12);
			this->panel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel9->Location = System::Drawing::Point(0, 0);
			this->panel9->Margin = System::Windows::Forms::Padding(2);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(1326, 692);
			this->panel9->TabIndex = 4;
			// 
			// CashierTablePanelContainer
			// 
			this->CashierTablePanelContainer->AutoSize = true;
			this->CashierTablePanelContainer->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->CashierTablePanelContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CashierTablePanelContainer->Controls->Add(this->CashierTableTitlePanel);
			this->CashierTablePanelContainer->Controls->Add(this->CashierTablePanel);
			this->CashierTablePanelContainer->Dock = System::Windows::Forms::DockStyle::Left;
			this->CashierTablePanelContainer->FlowDirection = System::Windows::Forms::FlowDirection::RightToLeft;
			this->CashierTablePanelContainer->Location = System::Drawing::Point(0, 0);
			this->CashierTablePanelContainer->Margin = System::Windows::Forms::Padding(4, 8, 4, 8);
			this->CashierTablePanelContainer->MaximumSize = System::Drawing::Size(944, 692);
			this->CashierTablePanelContainer->MinimumSize = System::Drawing::Size(944, 692);
			this->CashierTablePanelContainer->Name = L"CashierTablePanelContainer";
			this->CashierTablePanelContainer->Size = System::Drawing::Size(944, 692);
			this->CashierTablePanelContainer->TabIndex = 8;
			// 
			// CashierTableTitlePanel
			// 
			this->CashierTableTitlePanel->AccessibleName = L"CashierTableTitlePanel";
			this->CashierTableTitlePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CashierTableTitlePanel->Controls->Add(this->CashierTableTitle);
			this->CashierTableTitlePanel->Location = System::Drawing::Point(18, 2);
			this->CashierTableTitlePanel->Margin = System::Windows::Forms::Padding(2);
			this->CashierTableTitlePanel->Name = L"CashierTableTitlePanel";
			this->CashierTableTitlePanel->Size = System::Drawing::Size(922, 63);
			this->CashierTableTitlePanel->TabIndex = 9;
			// 
			// CashierTableTitle
			// 
			this->CashierTableTitle->AccessibleName = L"CashierTableTitle";
			this->CashierTableTitle->AutoEllipsis = true;
			this->CashierTableTitle->AutoSize = true;
			this->CashierTableTitle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CashierTableTitle->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CashierTableTitle->ForeColor = System::Drawing::Color::White;
			this->CashierTableTitle->Location = System::Drawing::Point(418, 14);
			this->CashierTableTitle->Margin = System::Windows::Forms::Padding(80, 12, 40, 8);
			this->CashierTableTitle->Name = L"CashierTableTitle";
			this->CashierTableTitle->Size = System::Drawing::Size(90, 27);
			this->CashierTableTitle->TabIndex = 7;
			this->CashierTableTitle->Text = L"الفاتورة";
			this->CashierTableTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CashierTablePanel
			// 
			this->CashierTablePanel->AccessibleName = L"CashierTablePanel";
			this->CashierTablePanel->AutoSize = true;
			this->CashierTablePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CashierTablePanel->Controls->Add(this->CashierSearchProductPanel);
			this->CashierTablePanel->Controls->Add(this->CashierTable);
			this->CashierTablePanel->Controls->Add(this->flowLayoutPanel3);
			this->CashierTablePanel->Location = System::Drawing::Point(18, 69);
			this->CashierTablePanel->Margin = System::Windows::Forms::Padding(2);
			this->CashierTablePanel->MaximumSize = System::Drawing::Size(922, 620);
			this->CashierTablePanel->Name = L"CashierTablePanel";
			this->CashierTablePanel->Size = System::Drawing::Size(922, 620);
			this->CashierTablePanel->TabIndex = 13;
			// 
			// CashierSearchProductPanel
			// 
			this->CashierSearchProductPanel->AccessibleName = L"CashierSearchProductPanel";
			this->CashierSearchProductPanel->Controls->Add(this->CashierSearchProductContainer);
			this->CashierSearchProductPanel->Controls->Add(this->CashierSearchLab);
			this->CashierSearchProductPanel->Location = System::Drawing::Point(2, 2);
			this->CashierSearchProductPanel->Margin = System::Windows::Forms::Padding(2);
			this->CashierSearchProductPanel->Name = L"CashierSearchProductPanel";
			this->CashierSearchProductPanel->Size = System::Drawing::Size(940, 67);
			this->CashierSearchProductPanel->TabIndex = 14;
			// 
			// CashierSearchProductContainer
			// 
			this->CashierSearchProductContainer->AccessibleName = L"CashierSearchProductContainer";
			this->CashierSearchProductContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CashierSearchProductContainer->Controls->Add(this->CashierSearchProduct);
			this->CashierSearchProductContainer->Location = System::Drawing::Point(6, 12);
			this->CashierSearchProductContainer->Name = L"CashierSearchProductContainer";
			this->CashierSearchProductContainer->Padding = System::Windows::Forms::Padding(8);
			this->CashierSearchProductContainer->Size = System::Drawing::Size(806, 40);
			this->CashierSearchProductContainer->TabIndex = 13;
			// 
			// CashierSearchProduct
			// 
			this->CashierSearchProduct->AccessibleName = L"CashierSearchProduct";
			this->CashierSearchProduct->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->CashierSearchProduct->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->CashierSearchProduct->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CashierSearchProduct->ForeColor = System::Drawing::Color::White;
			this->CashierSearchProduct->Location = System::Drawing::Point(8, 8);
			this->CashierSearchProduct->Margin = System::Windows::Forms::Padding(0);
			this->CashierSearchProduct->MaxLength = 50;
			this->CashierSearchProduct->Multiline = true;
			this->CashierSearchProduct->Name = L"CashierSearchProduct";
			this->CashierSearchProduct->Size = System::Drawing::Size(786, 24);
			this->CashierSearchProduct->TabIndex = 5;
			this->CashierSearchProduct->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->CashierSearchProduct->TextChanged += gcnew System::EventHandler(this, &Dashboard::CashierSearchProduct_TextChanged);
			// 
			// CashierSearchLab
			// 
			this->CashierSearchLab->AccessibleName = L"CashierSearchLab";
			this->CashierSearchLab->AutoSize = true;
			this->CashierSearchLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CashierSearchLab->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CashierSearchLab.Image")));
			this->CashierSearchLab->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->CashierSearchLab->Location = System::Drawing::Point(816, 7);
			this->CashierSearchLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->CashierSearchLab->MinimumSize = System::Drawing::Size(96, 48);
			this->CashierSearchLab->Name = L"CashierSearchLab";
			this->CashierSearchLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->CashierSearchLab->Size = System::Drawing::Size(96, 48);
			this->CashierSearchLab->TabIndex = 6;
			this->CashierSearchLab->Text = L"البحث";
			this->CashierSearchLab->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// CashierTable
			// 
			this->CashierTable->AccessibleName = L"CashierTable";
			this->CashierTable->AllowUserToAddRows = false;
			this->CashierTable->AllowUserToDeleteRows = false;
			dataGridViewCellStyle41->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle41->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			dataGridViewCellStyle41->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle41->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle41->Padding = System::Windows::Forms::Padding(4);
			dataGridViewCellStyle41->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle41->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle41->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->CashierTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle41;
			this->CashierTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->CashierTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->CashierTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->CashierTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle42->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle42->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(65)));
			dataGridViewCellStyle42->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle42->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle42->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle42->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			dataGridViewCellStyle42->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle42->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->CashierTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle42;
			this->CashierTable->ColumnHeadersHeight = 50;
			this->CashierTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->CashierTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->CashProductId,
					this->CashProductName, this->CashProductPrice, this->CashProductQuantity, this->CashTotalProductPrice
			});
			dataGridViewCellStyle44->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle44->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle44->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle44->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle44->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle44->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle44->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle44->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->CashierTable->DefaultCellStyle = dataGridViewCellStyle44;
			this->CashierTable->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->CashierTable->EnableHeadersVisualStyles = false;
			this->CashierTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->CashierTable->Location = System::Drawing::Point(8, 79);
			this->CashierTable->Margin = System::Windows::Forms::Padding(8);
			this->CashierTable->MultiSelect = false;
			this->CashierTable->Name = L"CashierTable";
			this->CashierTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->CashierTable->RowHeadersVisible = false;
			this->CashierTable->RowHeadersWidth = 51;
			dataGridViewCellStyle45->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle45->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle45->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle45->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle45->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle45->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle45->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle45->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->CashierTable->RowsDefaultCellStyle = dataGridViewCellStyle45;
			this->CashierTable->RowTemplate->Height = 40;
			this->CashierTable->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->CashierTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->CashierTable->Size = System::Drawing::Size(922, 532);
			this->CashierTable->StandardTab = true;
			this->CashierTable->TabIndex = 0;
			this->CashierTable->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::CashierTable_CellEndEdit);
			this->CashierTable->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Dashboard::CashierTable_KeyDown);
			// 
			// CashProductId
			// 
			this->CashProductId->DataPropertyName = L"CashProductId";
			this->CashProductId->HeaderText = L"رقم المنتج";
			this->CashProductId->MaxInputLength = 10;
			this->CashProductId->MinimumWidth = 80;
			this->CashProductId->Name = L"CashProductId";
			this->CashProductId->ReadOnly = true;
			this->CashProductId->ToolTipText = L"الرقم التعريفي للمنتج";
			// 
			// CashProductName
			// 
			this->CashProductName->DataPropertyName = L"CashProductName";
			this->CashProductName->HeaderText = L"اسم االمنتج";
			this->CashProductName->MaxInputLength = 20;
			this->CashProductName->MinimumWidth = 80;
			this->CashProductName->Name = L"CashProductName";
			this->CashProductName->ReadOnly = true;
			this->CashProductName->ToolTipText = L"اسم االمنتج";
			// 
			// CashProductPrice
			// 
			this->CashProductPrice->DataPropertyName = L"CashProductPrice";
			dataGridViewCellStyle43->Padding = System::Windows::Forms::Padding(8);
			this->CashProductPrice->DefaultCellStyle = dataGridViewCellStyle43;
			this->CashProductPrice->HeaderText = L"السعر";
			this->CashProductPrice->MaxInputLength = 50;
			this->CashProductPrice->MinimumWidth = 80;
			this->CashProductPrice->Name = L"CashProductPrice";
			this->CashProductPrice->ReadOnly = true;
			this->CashProductPrice->ToolTipText = L"سعر المنتج";
			// 
			// CashProductQuantity
			// 
			this->CashProductQuantity->DataPropertyName = L"CashProductQuantity";
			this->CashProductQuantity->HeaderText = L"الكمية";
			this->CashProductQuantity->MinimumWidth = 6;
			this->CashProductQuantity->Name = L"CashProductQuantity";
			this->CashProductQuantity->ToolTipText = L"كمية المنتج";
			// 
			// CashTotalProductPrice
			// 
			this->CashTotalProductPrice->DataPropertyName = L"CashTotalProductPrice";
			this->CashTotalProductPrice->HeaderText = L"اجمالي سعر المنتج";
			this->CashTotalProductPrice->Name = L"CashTotalProductPrice";
			this->CashTotalProductPrice->ReadOnly = true;
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->Location = System::Drawing::Point(3, 622);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(148, 49);
			this->flowLayoutPanel3->TabIndex = 15;
			// 
			// panel12
			// 
			this->panel12->AccessibleName = L"ManageProductContainer";
			this->panel12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel12->Controls->Add(this->panel14);
			this->panel12->Controls->Add(this->panel15);
			this->panel12->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel12->Location = System::Drawing::Point(952, 0);
			this->panel12->Margin = System::Windows::Forms::Padding(4, 8, 4, 8);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(374, 692);
			this->panel12->TabIndex = 9;
			// 
			// panel14
			// 
			this->panel14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->panel14->Controls->Add(this->panel10);
			this->panel14->Controls->Add(this->button9);
			this->panel14->Controls->Add(this->button10);
			this->panel14->Controls->Add(this->PayInvoice);
			this->panel14->Controls->Add(this->RefreshInvoice);
			this->panel14->Controls->Add(this->button12);
			this->panel14->Controls->Add(this->payMethodComboBox);
			this->panel14->Controls->Add(this->TotalInvoiceLab);
			this->panel14->Controls->Add(this->label5);
			this->panel14->Controls->Add(this->payLab);
			this->panel14->Controls->Add(this->payFeildContainer);
			this->panel14->Controls->Add(this->payMethodLab);
			this->panel14->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel14->Location = System::Drawing::Point(0, 64);
			this->panel14->Margin = System::Windows::Forms::Padding(8);
			this->panel14->MaximumSize = System::Drawing::Size(372, 626);
			this->panel14->MinimumSize = System::Drawing::Size(372, 626);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(372, 626);
			this->panel14->TabIndex = 15;
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->panel10->Controls->Add(this->SearchSuggestionsList);
			this->panel10->Location = System::Drawing::Point(13, 11);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(260, 160);
			this->panel10->TabIndex = 47;
			// 
			// SearchSuggestionsList
			// 
			this->SearchSuggestionsList->AccessibleName = L"SearchSuggestionsList";
			this->SearchSuggestionsList->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->SearchSuggestionsList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SearchSuggestionsList->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SearchSuggestionsList->ForeColor = System::Drawing::Color::White;
			this->SearchSuggestionsList->FormattingEnabled = true;
			this->SearchSuggestionsList->ItemHeight = 25;
			this->SearchSuggestionsList->Location = System::Drawing::Point(9, 15);
			this->SearchSuggestionsList->Name = L"SearchSuggestionsList";
			this->SearchSuggestionsList->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SearchSuggestionsList->Size = System::Drawing::Size(244, 125);
			this->SearchSuggestionsList->TabIndex = 46;
			this->SearchSuggestionsList->SelectedIndexChanged += gcnew System::EventHandler(this, &Dashboard::SearchSuggestionsList_SelectedIndexChanged);
			this->SearchSuggestionsList->DoubleClick += gcnew System::EventHandler(this, &Dashboard::AddProductToCashierTable);
			// 
			// button9
			// 
			this->button9->AccessibleName = L"delProduct_Btn";
			this->button9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->button9->FlatAppearance->BorderSize = 0;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::Color::Red;
			this->button9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button9.Image")));
			this->button9->Location = System::Drawing::Point(293, 167);
			this->button9->Margin = System::Windows::Forms::Padding(2);
			this->button9->MaximumSize = System::Drawing::Size(60, 60);
			this->button9->Name = L"button9";
			this->button9->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button9->Size = System::Drawing::Size(60, 60);
			this->button9->TabIndex = 42;
			this->button9->UseVisualStyleBackColor = false;
			// 
			// button10
			// 
			this->button10->AccessibleName = L"editProduct_Btn";
			this->button10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->button10->FlatAppearance->BorderSize = 0;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button10.Image")));
			this->button10->Location = System::Drawing::Point(293, 109);
			this->button10->Margin = System::Windows::Forms::Padding(2);
			this->button10->MaximumSize = System::Drawing::Size(60, 60);
			this->button10->Name = L"button10";
			this->button10->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button10->Size = System::Drawing::Size(60, 60);
			this->button10->TabIndex = 43;
			this->button10->UseVisualStyleBackColor = false;
			// 
			// PayInvoice
			// 
			this->PayInvoice->AccessibleName = L"PayInvoice";
			this->PayInvoice->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->PayInvoice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->PayInvoice->FlatAppearance->BorderSize = 0;
			this->PayInvoice->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PayInvoice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PayInvoice->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->PayInvoice->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PayInvoice.Image")));
			this->PayInvoice->Location = System::Drawing::Point(294, 283);
			this->PayInvoice->Margin = System::Windows::Forms::Padding(2);
			this->PayInvoice->MaximumSize = System::Drawing::Size(60, 60);
			this->PayInvoice->Name = L"PayInvoice";
			this->PayInvoice->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->PayInvoice->Size = System::Drawing::Size(60, 60);
			this->PayInvoice->TabIndex = 44;
			this->PayInvoice->UseVisualStyleBackColor = false;
			this->PayInvoice->Click += gcnew System::EventHandler(this, &Dashboard::PayInvoice_Click);
			// 
			// RefreshInvoice
			// 
			this->RefreshInvoice->AccessibleName = L"RefreshInvoice";
			this->RefreshInvoice->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->RefreshInvoice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->RefreshInvoice->FlatAppearance->BorderSize = 0;
			this->RefreshInvoice->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RefreshInvoice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RefreshInvoice->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->RefreshInvoice->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RefreshInvoice.Image")));
			this->RefreshInvoice->Location = System::Drawing::Point(293, 226);
			this->RefreshInvoice->Margin = System::Windows::Forms::Padding(2);
			this->RefreshInvoice->MaximumSize = System::Drawing::Size(60, 60);
			this->RefreshInvoice->Name = L"RefreshInvoice";
			this->RefreshInvoice->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->RefreshInvoice->Size = System::Drawing::Size(60, 60);
			this->RefreshInvoice->TabIndex = 44;
			this->RefreshInvoice->UseVisualStyleBackColor = false;
			// 
			// button12
			// 
			this->button12->AccessibleName = L"addProduct_Btn";
			this->button12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->button12->FlatAppearance->BorderSize = 0;
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button12.Image")));
			this->button12->Location = System::Drawing::Point(293, 51);
			this->button12->Margin = System::Windows::Forms::Padding(2);
			this->button12->MaximumSize = System::Drawing::Size(60, 60);
			this->button12->Name = L"button12";
			this->button12->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button12->Size = System::Drawing::Size(60, 60);
			this->button12->TabIndex = 45;
			this->button12->UseVisualStyleBackColor = false;
			// 
			// payMethodComboBox
			// 
			this->payMethodComboBox->AccessibleName = L"payMethodComboBox";
			this->payMethodComboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->payMethodComboBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->payMethodComboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->payMethodComboBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->payMethodComboBox->ForeColor = System::Drawing::Color::White;
			this->payMethodComboBox->FormattingEnabled = true;
			this->payMethodComboBox->ItemHeight = 21;
			this->payMethodComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(22) {
				L"11duew", L"232", L"92jnjsa", L"AAGUAGUGAUGUAGUA",
					L"c", L"cew", L"cewcew", L"cvvew", L"cvwd", L"cwe", L"dsvdsvhuidsuivdhiovods", L"eveedvdsvednhvuuvhewvhoewhvoewov", L"ew", L"ew",
					L"ewc", L"ewcnwuhcuw", L"ewcw", L"sffw", L"vb,jotjoktrbrtb", L"wcwec", L"wec", L"wec"
			});
			this->payMethodComboBox->Location = System::Drawing::Point(109, 500);
			this->payMethodComboBox->Margin = System::Windows::Forms::Padding(2);
			this->payMethodComboBox->MaxDropDownItems = 3;
			this->payMethodComboBox->Name = L"payMethodComboBox";
			this->payMethodComboBox->Size = System::Drawing::Size(249, 29);
			this->payMethodComboBox->Sorted = true;
			this->payMethodComboBox->TabIndex = 40;
			// 
			// TotalInvoiceLab
			// 
			this->TotalInvoiceLab->AccessibleName = L"TotalInvoiceLab";
			this->TotalInvoiceLab->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->TotalInvoiceLab->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TotalInvoiceLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TotalInvoiceLab->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->TotalInvoiceLab->Location = System::Drawing::Point(22, 388);
			this->TotalInvoiceLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->TotalInvoiceLab->Name = L"TotalInvoiceLab";
			this->TotalInvoiceLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->TotalInvoiceLab->Size = System::Drawing::Size(205, 66);
			this->TotalInvoiceLab->TabIndex = 39;
			this->TotalInvoiceLab->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label5
			// 
			this->label5->AccessibleName = L"payLab";
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(71, 356);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->label5->Size = System::Drawing::Size(106, 21);
			this->label5->TabIndex = 39;
			this->label5->Text = L"اجمالي الفاتورة";
			// 
			// payLab
			// 
			this->payLab->AccessibleName = L"payLab";
			this->payLab->AutoSize = true;
			this->payLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->payLab->Location = System::Drawing::Point(264, 356);
			this->payLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->payLab->Name = L"payLab";
			this->payLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->payLab->Size = System::Drawing::Size(63, 21);
			this->payLab->TabIndex = 39;
			this->payLab->Text = L"ادفع هنا";
			// 
			// payFeildContainer
			// 
			this->payFeildContainer->AccessibleName = L"payFeildContainer";
			this->payFeildContainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->payFeildContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->payFeildContainer->Controls->Add(this->payFeild);
			this->payFeildContainer->Location = System::Drawing::Point(232, 388);
			this->payFeildContainer->Name = L"payFeildContainer";
			this->payFeildContainer->Padding = System::Windows::Forms::Padding(8);
			this->payFeildContainer->Size = System::Drawing::Size(126, 66);
			this->payFeildContainer->TabIndex = 38;
			// 
			// payFeild
			// 
			this->payFeild->AccessibleName = L"payFeild";
			this->payFeild->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->payFeild->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->payFeild->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->payFeild->ForeColor = System::Drawing::Color::White;
			this->payFeild->Location = System::Drawing::Point(8, 8);
			this->payFeild->Margin = System::Windows::Forms::Padding(0);
			this->payFeild->MaxLength = 50;
			this->payFeild->Multiline = true;
			this->payFeild->Name = L"payFeild";
			this->payFeild->Size = System::Drawing::Size(109, 48);
			this->payFeild->TabIndex = 5;
			this->payFeild->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// payMethodLab
			// 
			this->payMethodLab->AccessibleName = L"payMethodLab";
			this->payMethodLab->AutoSize = true;
			this->payMethodLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->payMethodLab->Location = System::Drawing::Point(264, 465);
			this->payMethodLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->payMethodLab->Name = L"payMethodLab";
			this->payMethodLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->payMethodLab->Size = System::Drawing::Size(90, 21);
			this->payMethodLab->TabIndex = 28;
			this->payMethodLab->Text = L"طريقة الدفع";
			// 
			// panel15
			// 
			this->panel15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel15->Controls->Add(this->label14);
			this->panel15->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel15->Location = System::Drawing::Point(0, 0);
			this->panel15->Margin = System::Windows::Forms::Padding(2);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(372, 64);
			this->panel15->TabIndex = 10;
			// 
			// label14
			// 
			this->label14->AccessibleName = L"catFormTitle";
			this->label14->AutoEllipsis = true;
			this->label14->AutoSize = true;
			this->label14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label14->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::White;
			this->label14->Location = System::Drawing::Point(108, 16);
			this->label14->Margin = System::Windows::Forms::Padding(80, 12, 40, 8);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(144, 27);
			this->label14->TabIndex = 7;
			this->label14->Text = L"ادارة الفاتورة";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// productPanel
			// 
			this->productPanel->Controls->Add(this->ProductTableContainer);
			this->productPanel->Controls->Add(this->ManageProductContainer);
			this->productPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->productPanel->Location = System::Drawing::Point(0, 0);
			this->productPanel->Margin = System::Windows::Forms::Padding(2);
			this->productPanel->Name = L"productPanel";
			this->productPanel->Size = System::Drawing::Size(1326, 692);
			this->productPanel->TabIndex = 3;
			// 
			// ProductTableContainer
			// 
			this->ProductTableContainer->AutoSize = true;
			this->ProductTableContainer->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ProductTableContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ProductTableContainer->Controls->Add(this->ProductTableTitlePanel);
			this->ProductTableContainer->Controls->Add(this->ProductTablePanel);
			this->ProductTableContainer->Dock = System::Windows::Forms::DockStyle::Left;
			this->ProductTableContainer->FlowDirection = System::Windows::Forms::FlowDirection::RightToLeft;
			this->ProductTableContainer->Location = System::Drawing::Point(0, 0);
			this->ProductTableContainer->Margin = System::Windows::Forms::Padding(4, 8, 4, 8);
			this->ProductTableContainer->MaximumSize = System::Drawing::Size(944, 692);
			this->ProductTableContainer->MinimumSize = System::Drawing::Size(944, 692);
			this->ProductTableContainer->Name = L"ProductTableContainer";
			this->ProductTableContainer->Size = System::Drawing::Size(944, 692);
			this->ProductTableContainer->TabIndex = 8;
			// 
			// ProductTableTitlePanel
			// 
			this->ProductTableTitlePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ProductTableTitlePanel->Controls->Add(this->ProductTableTitle);
			this->ProductTableTitlePanel->Location = System::Drawing::Point(-14, 2);
			this->ProductTableTitlePanel->Margin = System::Windows::Forms::Padding(2);
			this->ProductTableTitlePanel->Name = L"ProductTableTitlePanel";
			this->ProductTableTitlePanel->Size = System::Drawing::Size(954, 63);
			this->ProductTableTitlePanel->TabIndex = 9;
			// 
			// ProductTableTitle
			// 
			this->ProductTableTitle->AutoEllipsis = true;
			this->ProductTableTitle->AutoSize = true;
			this->ProductTableTitle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ProductTableTitle->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ProductTableTitle->ForeColor = System::Drawing::Color::White;
			this->ProductTableTitle->Location = System::Drawing::Point(338, 17);
			this->ProductTableTitle->Margin = System::Windows::Forms::Padding(80, 12, 40, 8);
			this->ProductTableTitle->Name = L"ProductTableTitle";
			this->ProductTableTitle->Size = System::Drawing::Size(170, 27);
			this->ProductTableTitle->TabIndex = 7;
			this->ProductTableTitle->Text = L"جدول المنتجات";
			this->ProductTableTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ProductTablePanel
			// 
			this->ProductTablePanel->AccessibleName = L"CategoryTablePanel";
			this->ProductTablePanel->AutoSize = true;
			this->ProductTablePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ProductTablePanel->Controls->Add(this->ProductSearchContainer);
			this->ProductTablePanel->Controls->Add(this->ProductTable);
			this->ProductTablePanel->Location = System::Drawing::Point(18, 69);
			this->ProductTablePanel->Margin = System::Windows::Forms::Padding(2);
			this->ProductTablePanel->MaximumSize = System::Drawing::Size(922, 620);
			this->ProductTablePanel->Name = L"ProductTablePanel";
			this->ProductTablePanel->Size = System::Drawing::Size(922, 620);
			this->ProductTablePanel->TabIndex = 13;
			// 
			// ProductSearchContainer
			// 
			this->ProductSearchContainer->Controls->Add(this->ProductSearchPanel);
			this->ProductSearchContainer->Controls->Add(this->ProductSearchLab);
			this->ProductSearchContainer->Location = System::Drawing::Point(2, 2);
			this->ProductSearchContainer->Margin = System::Windows::Forms::Padding(2);
			this->ProductSearchContainer->Name = L"ProductSearchContainer";
			this->ProductSearchContainer->Size = System::Drawing::Size(940, 67);
			this->ProductSearchContainer->TabIndex = 14;
			// 
			// ProductSearchPanel
			// 
			this->ProductSearchPanel->AccessibleName = L"CategorySearchPanel";
			this->ProductSearchPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ProductSearchPanel->Controls->Add(this->ProductSearch);
			this->ProductSearchPanel->Location = System::Drawing::Point(6, 12);
			this->ProductSearchPanel->Name = L"ProductSearchPanel";
			this->ProductSearchPanel->Padding = System::Windows::Forms::Padding(8);
			this->ProductSearchPanel->Size = System::Drawing::Size(806, 40);
			this->ProductSearchPanel->TabIndex = 13;
			// 
			// ProductSearch
			// 
			this->ProductSearch->AccessibleName = L"CategorySearch";
			this->ProductSearch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ProductSearch->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ProductSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ProductSearch->ForeColor = System::Drawing::Color::White;
			this->ProductSearch->Location = System::Drawing::Point(8, 8);
			this->ProductSearch->Margin = System::Windows::Forms::Padding(0);
			this->ProductSearch->MaxLength = 50;
			this->ProductSearch->Multiline = true;
			this->ProductSearch->Name = L"ProductSearch";
			this->ProductSearch->Size = System::Drawing::Size(772, 24);
			this->ProductSearch->TabIndex = 5;
			this->ProductSearch->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->ProductSearch->TextChanged += gcnew System::EventHandler(this, &Dashboard::ProductSearch_TextChanged);
			// 
			// ProductSearchLab
			// 
			this->ProductSearchLab->AccessibleName = L"catSearchLab";
			this->ProductSearchLab->AutoSize = true;
			this->ProductSearchLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ProductSearchLab->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ProductSearchLab.Image")));
			this->ProductSearchLab->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->ProductSearchLab->Location = System::Drawing::Point(816, 7);
			this->ProductSearchLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ProductSearchLab->MinimumSize = System::Drawing::Size(96, 48);
			this->ProductSearchLab->Name = L"ProductSearchLab";
			this->ProductSearchLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->ProductSearchLab->Size = System::Drawing::Size(96, 48);
			this->ProductSearchLab->TabIndex = 6;
			this->ProductSearchLab->Text = L"البحث";
			this->ProductSearchLab->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// ProductTable
			// 
			this->ProductTable->AccessibleName = L"CategoryTable";
			this->ProductTable->AllowUserToAddRows = false;
			this->ProductTable->AllowUserToDeleteRows = false;
			dataGridViewCellStyle46->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle46->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			dataGridViewCellStyle46->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle46->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle46->Padding = System::Windows::Forms::Padding(4);
			dataGridViewCellStyle46->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle46->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle46->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->ProductTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle46;
			this->ProductTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->ProductTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->ProductTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ProductTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle47->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle47->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(65)));
			dataGridViewCellStyle47->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle47->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle47->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle47->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			dataGridViewCellStyle47->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle47->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->ProductTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle47;
			this->ProductTable->ColumnHeadersHeight = 50;
			this->ProductTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->ProductTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->ProductColId,
					this->ProductColName, this->ProductColPrice, this->ProductColQuantity, this->ProductColCategory, this->ProductColSupplier, this->ProductColCreated_At,
					this->ProductColUpdated_At
			});
			dataGridViewCellStyle49->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle49->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle49->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle49->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle49->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle49->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle49->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle49->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->ProductTable->DefaultCellStyle = dataGridViewCellStyle49;
			this->ProductTable->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->ProductTable->EnableHeadersVisualStyles = false;
			this->ProductTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->ProductTable->Location = System::Drawing::Point(8, 79);
			this->ProductTable->Margin = System::Windows::Forms::Padding(8);
			this->ProductTable->MultiSelect = false;
			this->ProductTable->Name = L"ProductTable";
			this->ProductTable->ReadOnly = true;
			this->ProductTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->ProductTable->RowHeadersVisible = false;
			this->ProductTable->RowHeadersWidth = 51;
			dataGridViewCellStyle50->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle50->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle50->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle50->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle50->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle50->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle50->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle50->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->ProductTable->RowsDefaultCellStyle = dataGridViewCellStyle50;
			this->ProductTable->RowTemplate->Height = 40;
			this->ProductTable->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ProductTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ProductTable->Size = System::Drawing::Size(922, 532);
			this->ProductTable->StandardTab = true;
			this->ProductTable->TabIndex = 0;
			this->ProductTable->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::ProductTable_CellClick);
			this->ProductTable->CellMouseEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::DataGridView_CellMouseEnter);
			this->ProductTable->CellMouseLeave += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::DataGridView_CellMouseLeave);
			// 
			// ProductColId
			// 
			this->ProductColId->DataPropertyName = L"Id";
			this->ProductColId->HeaderText = L"رقم المنتج";
			this->ProductColId->MaxInputLength = 10;
			this->ProductColId->MinimumWidth = 80;
			this->ProductColId->Name = L"ProductColId";
			this->ProductColId->ReadOnly = true;
			this->ProductColId->ToolTipText = L"الرقم التعريفي للمنتج";
			// 
			// ProductColName
			// 
			this->ProductColName->DataPropertyName = L"name";
			this->ProductColName->HeaderText = L"اسم االمنتج";
			this->ProductColName->MaxInputLength = 20;
			this->ProductColName->MinimumWidth = 80;
			this->ProductColName->Name = L"ProductColName";
			this->ProductColName->ReadOnly = true;
			this->ProductColName->ToolTipText = L"اسم االمنتج";
			// 
			// ProductColPrice
			// 
			this->ProductColPrice->DataPropertyName = L"Description";
			dataGridViewCellStyle48->Padding = System::Windows::Forms::Padding(8);
			this->ProductColPrice->DefaultCellStyle = dataGridViewCellStyle48;
			this->ProductColPrice->HeaderText = L"السعر";
			this->ProductColPrice->MaxInputLength = 50;
			this->ProductColPrice->MinimumWidth = 80;
			this->ProductColPrice->Name = L"ProductColPrice";
			this->ProductColPrice->ReadOnly = true;
			this->ProductColPrice->ToolTipText = L"سعر المنتج";
			// 
			// ProductColQuantity
			// 
			this->ProductColQuantity->HeaderText = L"الكمية";
			this->ProductColQuantity->MinimumWidth = 6;
			this->ProductColQuantity->Name = L"ProductColQuantity";
			this->ProductColQuantity->ReadOnly = true;
			this->ProductColQuantity->ToolTipText = L"كمية المنتج";
			// 
			// ProductColCategory
			// 
			this->ProductColCategory->DataPropertyName = L"ProductColCategoryId";
			this->ProductColCategory->HeaderText = L"الصنف";
			this->ProductColCategory->MinimumWidth = 6;
			this->ProductColCategory->Name = L"ProductColCategory";
			this->ProductColCategory->ReadOnly = true;
			this->ProductColCategory->ToolTipText = L"الضنف الخاص بالمنتج";
			// 
			// ProductColSupplier
			// 
			this->ProductColSupplier->DataPropertyName = L"ProductColSupplierId";
			this->ProductColSupplier->HeaderText = L"المورد";
			this->ProductColSupplier->MinimumWidth = 6;
			this->ProductColSupplier->Name = L"ProductColSupplier";
			this->ProductColSupplier->ReadOnly = true;
			this->ProductColSupplier->ToolTipText = L"المورد الخاص بالمنتج";
			// 
			// ProductColCreated_At
			// 
			this->ProductColCreated_At->DataPropertyName = L"Created_At";
			this->ProductColCreated_At->HeaderText = L"تاريخ الاضافة";
			this->ProductColCreated_At->MaxInputLength = 16;
			this->ProductColCreated_At->MinimumWidth = 100;
			this->ProductColCreated_At->Name = L"ProductColCreated_At";
			this->ProductColCreated_At->ReadOnly = true;
			this->ProductColCreated_At->ToolTipText = L"تاريخ اضافة المنتج";
			// 
			// ProductColUpdated_At
			// 
			this->ProductColUpdated_At->DataPropertyName = L"Updated_At";
			this->ProductColUpdated_At->HeaderText = L"تاريخ التعديل";
			this->ProductColUpdated_At->MaxInputLength = 16;
			this->ProductColUpdated_At->MinimumWidth = 6;
			this->ProductColUpdated_At->Name = L"ProductColUpdated_At";
			this->ProductColUpdated_At->ReadOnly = true;
			this->ProductColUpdated_At->ToolTipText = L"تاريخ تعديل المنتج";
			// 
			// ManageProductContainer
			// 
			this->ManageProductContainer->AccessibleName = L"ManageProductContainer";
			this->ManageProductContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ManageProductContainer->Controls->Add(this->ManageProductFormPanel);
			this->ManageProductContainer->Controls->Add(this->ManageProductTitlePanel);
			this->ManageProductContainer->Dock = System::Windows::Forms::DockStyle::Right;
			this->ManageProductContainer->Location = System::Drawing::Point(952, 0);
			this->ManageProductContainer->Margin = System::Windows::Forms::Padding(4, 8, 4, 8);
			this->ManageProductContainer->Name = L"ManageProductContainer";
			this->ManageProductContainer->Size = System::Drawing::Size(374, 692);
			this->ManageProductContainer->TabIndex = 9;
			// 
			// ManageProductFormPanel
			// 
			this->ManageProductFormPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->ManageProductFormPanel->Controls->Add(this->delProduct_Btn);
			this->ManageProductFormPanel->Controls->Add(this->editProduct_Btn);
			this->ManageProductFormPanel->Controls->Add(this->RefreshProductData);
			this->ManageProductFormPanel->Controls->Add(this->addProduct_Btn);
			this->ManageProductFormPanel->Controls->Add(this->SupplierComboBox);
			this->ManageProductFormPanel->Controls->Add(this->CategoryComboBox);
			this->ManageProductFormPanel->Controls->Add(this->ProductNameLab);
			this->ManageProductFormPanel->Controls->Add(this->ContainerOfProductQuantity);
			this->ManageProductFormPanel->Controls->Add(this->ContainerOfProductPrice);
			this->ManageProductFormPanel->Controls->Add(this->ContainerOfProductName);
			this->ManageProductFormPanel->Controls->Add(this->SupplierComboBoxLab);
			this->ManageProductFormPanel->Controls->Add(this->CategoryComboBoxLab);
			this->ManageProductFormPanel->Controls->Add(this->ProductQuantityLab);
			this->ManageProductFormPanel->Controls->Add(this->ProductPriceLab);
			this->ManageProductFormPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ManageProductFormPanel->Location = System::Drawing::Point(0, 64);
			this->ManageProductFormPanel->Margin = System::Windows::Forms::Padding(8);
			this->ManageProductFormPanel->MaximumSize = System::Drawing::Size(372, 626);
			this->ManageProductFormPanel->MinimumSize = System::Drawing::Size(372, 626);
			this->ManageProductFormPanel->Name = L"ManageProductFormPanel";
			this->ManageProductFormPanel->Size = System::Drawing::Size(372, 626);
			this->ManageProductFormPanel->TabIndex = 15;
			// 
			// delProduct_Btn
			// 
			this->delProduct_Btn->AccessibleName = L"delProduct_Btn";
			this->delProduct_Btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->delProduct_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->delProduct_Btn->FlatAppearance->BorderSize = 0;
			this->delProduct_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delProduct_Btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delProduct_Btn->ForeColor = System::Drawing::Color::Red;
			this->delProduct_Btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"delProduct_Btn.Image")));
			this->delProduct_Btn->Location = System::Drawing::Point(293, 167);
			this->delProduct_Btn->Margin = System::Windows::Forms::Padding(2);
			this->delProduct_Btn->MaximumSize = System::Drawing::Size(60, 60);
			this->delProduct_Btn->Name = L"delProduct_Btn";
			this->delProduct_Btn->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->delProduct_Btn->Size = System::Drawing::Size(60, 60);
			this->delProduct_Btn->TabIndex = 42;
			this->delProduct_Btn->UseVisualStyleBackColor = false;
			this->delProduct_Btn->Click += gcnew System::EventHandler(this, &Dashboard::delProduct_Click);
			// 
			// editProduct_Btn
			// 
			this->editProduct_Btn->AccessibleName = L"editProduct_Btn";
			this->editProduct_Btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->editProduct_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->editProduct_Btn->FlatAppearance->BorderSize = 0;
			this->editProduct_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->editProduct_Btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editProduct_Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->editProduct_Btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editProduct_Btn.Image")));
			this->editProduct_Btn->Location = System::Drawing::Point(293, 109);
			this->editProduct_Btn->Margin = System::Windows::Forms::Padding(2);
			this->editProduct_Btn->MaximumSize = System::Drawing::Size(60, 60);
			this->editProduct_Btn->Name = L"editProduct_Btn";
			this->editProduct_Btn->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->editProduct_Btn->Size = System::Drawing::Size(60, 60);
			this->editProduct_Btn->TabIndex = 43;
			this->editProduct_Btn->UseVisualStyleBackColor = false;
			this->editProduct_Btn->Click += gcnew System::EventHandler(this, &Dashboard::updateProduct_Click);
			// 
			// RefreshProductData
			// 
			this->RefreshProductData->AccessibleName = L"RefreshProductData";
			this->RefreshProductData->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->RefreshProductData->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->RefreshProductData->FlatAppearance->BorderSize = 0;
			this->RefreshProductData->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RefreshProductData->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RefreshProductData->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->RefreshProductData->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RefreshProductData.Image")));
			this->RefreshProductData->Location = System::Drawing::Point(293, 226);
			this->RefreshProductData->Margin = System::Windows::Forms::Padding(2);
			this->RefreshProductData->MaximumSize = System::Drawing::Size(60, 60);
			this->RefreshProductData->Name = L"RefreshProductData";
			this->RefreshProductData->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->RefreshProductData->Size = System::Drawing::Size(60, 60);
			this->RefreshProductData->TabIndex = 44;
			this->RefreshProductData->UseVisualStyleBackColor = false;
			this->RefreshProductData->Click += gcnew System::EventHandler(this, &Dashboard::RefreshProductData_Click);
			// 
			// addProduct_Btn
			// 
			this->addProduct_Btn->AccessibleName = L"addProduct_Btn";
			this->addProduct_Btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->addProduct_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->addProduct_Btn->FlatAppearance->BorderSize = 0;
			this->addProduct_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addProduct_Btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addProduct_Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->addProduct_Btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addProduct_Btn.Image")));
			this->addProduct_Btn->Location = System::Drawing::Point(293, 51);
			this->addProduct_Btn->Margin = System::Windows::Forms::Padding(2);
			this->addProduct_Btn->MaximumSize = System::Drawing::Size(60, 60);
			this->addProduct_Btn->Name = L"addProduct_Btn";
			this->addProduct_Btn->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->addProduct_Btn->Size = System::Drawing::Size(60, 60);
			this->addProduct_Btn->TabIndex = 45;
			this->addProduct_Btn->UseVisualStyleBackColor = false;
			this->addProduct_Btn->Click += gcnew System::EventHandler(this, &Dashboard::addProduct_Click);
			// 
			// SupplierComboBox
			// 
			this->SupplierComboBox->AccessibleName = L"SupplierComboBox";
			this->SupplierComboBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->SupplierComboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SupplierComboBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SupplierComboBox->ForeColor = System::Drawing::Color::White;
			this->SupplierComboBox->FormattingEnabled = true;
			this->SupplierComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(22) {
				L"11duew", L"232", L"92jnjsa", L"AAGUAGUGAUGUAGUA",
					L"c", L"cew", L"cewcew", L"cvvew", L"cvwd", L"cwe", L"dsvdsvhuidsuivdhiovods", L"eveedvdsvednhvuuvhewvhoewhvoewov", L"ew", L"ew",
					L"ewc", L"ewcnwuhcuw", L"ewcw", L"sffw", L"vb,jotjoktrbrtb", L"wcwec", L"wec", L"wec"
			});
			this->SupplierComboBox->Location = System::Drawing::Point(23, 406);
			this->SupplierComboBox->Margin = System::Windows::Forms::Padding(2);
			this->SupplierComboBox->Name = L"SupplierComboBox";
			this->SupplierComboBox->Size = System::Drawing::Size(249, 29);
			this->SupplierComboBox->Sorted = true;
			this->SupplierComboBox->TabIndex = 40;
			// 
			// CategoryComboBox
			// 
			this->CategoryComboBox->AccessibleName = L"CategoryComboBox";
			this->CategoryComboBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->CategoryComboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CategoryComboBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->CategoryComboBox->ForeColor = System::Drawing::Color::White;
			this->CategoryComboBox->FormattingEnabled = true;
			this->CategoryComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(22) {
				L"11duew", L"232", L"92jnjsa", L"AAGUAGUGAUGUAGUA",
					L"c", L"cew", L"cewcew", L"cvvew", L"cvwd", L"cwe", L"dsvdsvhuidsuivdhiovods", L"eveedvdsvednhvuuvhewvhoewhvoewov", L"ew", L"ew",
					L"ewc", L"ewcnwuhcuw", L"ewcw", L"sffw", L"vb,jotjoktrbrtb", L"wcwec", L"wec", L"wec"
			});
			this->CategoryComboBox->Location = System::Drawing::Point(23, 310);
			this->CategoryComboBox->Margin = System::Windows::Forms::Padding(2);
			this->CategoryComboBox->Name = L"CategoryComboBox";
			this->CategoryComboBox->Size = System::Drawing::Size(249, 29);
			this->CategoryComboBox->Sorted = true;
			this->CategoryComboBox->TabIndex = 41;
			// 
			// ProductNameLab
			// 
			this->ProductNameLab->AccessibleName = L"ProductNameLab";
			this->ProductNameLab->AutoSize = true;
			this->ProductNameLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ProductNameLab->Location = System::Drawing::Point(186, 23);
			this->ProductNameLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ProductNameLab->Name = L"ProductNameLab";
			this->ProductNameLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->ProductNameLab->Size = System::Drawing::Size(77, 21);
			this->ProductNameLab->TabIndex = 39;
			this->ProductNameLab->Text = L"اسم المنتج";
			// 
			// ContainerOfProductQuantity
			// 
			this->ContainerOfProductQuantity->AccessibleName = L"ContainerOfProductQuantity";
			this->ContainerOfProductQuantity->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ContainerOfProductQuantity->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ContainerOfProductQuantity->Controls->Add(this->productQuantity);
			this->ContainerOfProductQuantity->Location = System::Drawing::Point(25, 226);
			this->ContainerOfProductQuantity->Name = L"ContainerOfProductQuantity";
			this->ContainerOfProductQuantity->Padding = System::Windows::Forms::Padding(8);
			this->ContainerOfProductQuantity->Size = System::Drawing::Size(248, 40);
			this->ContainerOfProductQuantity->TabIndex = 36;
			// 
			// productQuantity
			// 
			this->productQuantity->AccessibleName = L"productQuantity";
			this->productQuantity->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->productQuantity->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->productQuantity->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->productQuantity->ForeColor = System::Drawing::Color::White;
			this->productQuantity->Location = System::Drawing::Point(8, 8);
			this->productQuantity->Margin = System::Windows::Forms::Padding(0);
			this->productQuantity->MaxLength = 50;
			this->productQuantity->Multiline = true;
			this->productQuantity->Name = L"productQuantity";
			this->productQuantity->Size = System::Drawing::Size(232, 24);
			this->productQuantity->TabIndex = 5;
			this->productQuantity->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// ContainerOfProductPrice
			// 
			this->ContainerOfProductPrice->AccessibleName = L"ContainerOfProductPrice";
			this->ContainerOfProductPrice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ContainerOfProductPrice->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ContainerOfProductPrice->Controls->Add(this->productPrice);
			this->ContainerOfProductPrice->Location = System::Drawing::Point(24, 138);
			this->ContainerOfProductPrice->Name = L"ContainerOfProductPrice";
			this->ContainerOfProductPrice->Padding = System::Windows::Forms::Padding(8);
			this->ContainerOfProductPrice->Size = System::Drawing::Size(248, 40);
			this->ContainerOfProductPrice->TabIndex = 37;
			// 
			// productPrice
			// 
			this->productPrice->AccessibleName = L"productPrice";
			this->productPrice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->productPrice->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->productPrice->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->productPrice->ForeColor = System::Drawing::Color::White;
			this->productPrice->Location = System::Drawing::Point(8, 8);
			this->productPrice->Margin = System::Windows::Forms::Padding(0);
			this->productPrice->MaxLength = 50;
			this->productPrice->Multiline = true;
			this->productPrice->Name = L"productPrice";
			this->productPrice->Size = System::Drawing::Size(232, 24);
			this->productPrice->TabIndex = 5;
			this->productPrice->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// ContainerOfProductName
			// 
			this->ContainerOfProductName->AccessibleName = L"ContainerOfProductName";
			this->ContainerOfProductName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ContainerOfProductName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ContainerOfProductName->Controls->Add(this->productName);
			this->ContainerOfProductName->Location = System::Drawing::Point(24, 53);
			this->ContainerOfProductName->Name = L"ContainerOfProductName";
			this->ContainerOfProductName->Padding = System::Windows::Forms::Padding(8);
			this->ContainerOfProductName->Size = System::Drawing::Size(248, 40);
			this->ContainerOfProductName->TabIndex = 38;
			// 
			// productName
			// 
			this->productName->AccessibleName = L"productName";
			this->productName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->productName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->productName->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->productName->ForeColor = System::Drawing::Color::White;
			this->productName->Location = System::Drawing::Point(8, 8);
			this->productName->Margin = System::Windows::Forms::Padding(0);
			this->productName->MaxLength = 50;
			this->productName->Multiline = true;
			this->productName->Name = L"productName";
			this->productName->Size = System::Drawing::Size(232, 24);
			this->productName->TabIndex = 5;
			this->productName->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// SupplierComboBoxLab
			// 
			this->SupplierComboBoxLab->AccessibleName = L"SupplierComboBoxLab";
			this->SupplierComboBoxLab->AutoSize = true;
			this->SupplierComboBoxLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SupplierComboBoxLab->Location = System::Drawing::Point(216, 356);
			this->SupplierComboBoxLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->SupplierComboBoxLab->Name = L"SupplierComboBoxLab";
			this->SupplierComboBoxLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SupplierComboBoxLab->Size = System::Drawing::Size(50, 21);
			this->SupplierComboBoxLab->TabIndex = 28;
			this->SupplierComboBoxLab->Text = L"المورد";
			// 
			// CategoryComboBoxLab
			// 
			this->CategoryComboBoxLab->AccessibleName = L"CategoryComboBoxLab";
			this->CategoryComboBoxLab->AutoSize = true;
			this->CategoryComboBoxLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CategoryComboBoxLab->Location = System::Drawing::Point(209, 278);
			this->CategoryComboBoxLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->CategoryComboBoxLab->Name = L"CategoryComboBoxLab";
			this->CategoryComboBoxLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->CategoryComboBoxLab->Size = System::Drawing::Size(56, 21);
			this->CategoryComboBoxLab->TabIndex = 29;
			this->CategoryComboBoxLab->Text = L"الصنف";
			// 
			// ProductQuantityLab
			// 
			this->ProductQuantityLab->AccessibleName = L"ProductQuantityLab";
			this->ProductQuantityLab->AutoSize = true;
			this->ProductQuantityLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ProductQuantityLab->Location = System::Drawing::Point(186, 193);
			this->ProductQuantityLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ProductQuantityLab->Name = L"ProductQuantityLab";
			this->ProductQuantityLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->ProductQuantityLab->Size = System::Drawing::Size(81, 21);
			this->ProductQuantityLab->TabIndex = 30;
			this->ProductQuantityLab->Text = L"كمية المنتج";
			// 
			// ProductPriceLab
			// 
			this->ProductPriceLab->AccessibleName = L"catdescLab";
			this->ProductPriceLab->AutoSize = true;
			this->ProductPriceLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ProductPriceLab->Location = System::Drawing::Point(186, 106);
			this->ProductPriceLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ProductPriceLab->Name = L"ProductPriceLab";
			this->ProductPriceLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->ProductPriceLab->Size = System::Drawing::Size(80, 21);
			this->ProductPriceLab->TabIndex = 31;
			this->ProductPriceLab->Text = L"سعر المنتج";
			// 
			// ManageProductTitlePanel
			// 
			this->ManageProductTitlePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ManageProductTitlePanel->Controls->Add(this->ManageProductTitle);
			this->ManageProductTitlePanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->ManageProductTitlePanel->Location = System::Drawing::Point(0, 0);
			this->ManageProductTitlePanel->Margin = System::Windows::Forms::Padding(2);
			this->ManageProductTitlePanel->Name = L"ManageProductTitlePanel";
			this->ManageProductTitlePanel->Size = System::Drawing::Size(372, 64);
			this->ManageProductTitlePanel->TabIndex = 10;
			// 
			// ManageProductTitle
			// 
			this->ManageProductTitle->AccessibleName = L"catFormTitle";
			this->ManageProductTitle->AutoEllipsis = true;
			this->ManageProductTitle->AutoSize = true;
			this->ManageProductTitle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ManageProductTitle->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ManageProductTitle->ForeColor = System::Drawing::Color::White;
			this->ManageProductTitle->Location = System::Drawing::Point(108, 16);
			this->ManageProductTitle->Margin = System::Windows::Forms::Padding(80, 12, 40, 8);
			this->ManageProductTitle->Name = L"ManageProductTitle";
			this->ManageProductTitle->Size = System::Drawing::Size(159, 27);
			this->ManageProductTitle->TabIndex = 7;
			this->ManageProductTitle->Text = L"ادارة المنتجات";
			this->ManageProductTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// categoryPanel
			// 
			this->categoryPanel->Controls->Add(this->CategoryTableContainer);
			this->categoryPanel->Controls->Add(this->ManageCategoryPanel);
			this->categoryPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->categoryPanel->Location = System::Drawing::Point(0, 0);
			this->categoryPanel->Margin = System::Windows::Forms::Padding(2);
			this->categoryPanel->Name = L"categoryPanel";
			this->categoryPanel->Size = System::Drawing::Size(1326, 692);
			this->categoryPanel->TabIndex = 2;
			// 
			// CategoryTableContainer
			// 
			this->CategoryTableContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CategoryTableContainer->Controls->Add(this->CategoryTableTitlePanel);
			this->CategoryTableContainer->Controls->Add(this->CategoryTablePanel);
			this->CategoryTableContainer->Dock = System::Windows::Forms::DockStyle::Left;
			this->CategoryTableContainer->FlowDirection = System::Windows::Forms::FlowDirection::RightToLeft;
			this->CategoryTableContainer->Location = System::Drawing::Point(0, 0);
			this->CategoryTableContainer->Margin = System::Windows::Forms::Padding(4, 8, 4, 8);
			this->CategoryTableContainer->Name = L"CategoryTableContainer";
			this->CategoryTableContainer->Size = System::Drawing::Size(942, 692);
			this->CategoryTableContainer->TabIndex = 3;
			// 
			// CategoryTableTitlePanel
			// 
			this->CategoryTableTitlePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CategoryTableTitlePanel->Controls->Add(this->CategoryTableTitle);
			this->CategoryTableTitlePanel->Location = System::Drawing::Point(2, 2);
			this->CategoryTableTitlePanel->Margin = System::Windows::Forms::Padding(2);
			this->CategoryTableTitlePanel->Name = L"CategoryTableTitlePanel";
			this->CategoryTableTitlePanel->Size = System::Drawing::Size(936, 64);
			this->CategoryTableTitlePanel->TabIndex = 9;
			// 
			// CategoryTableTitle
			// 
			this->CategoryTableTitle->AutoEllipsis = true;
			this->CategoryTableTitle->AutoSize = true;
			this->CategoryTableTitle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CategoryTableTitle->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CategoryTableTitle->ForeColor = System::Drawing::Color::White;
			this->CategoryTableTitle->Location = System::Drawing::Point(380, 17);
			this->CategoryTableTitle->Margin = System::Windows::Forms::Padding(80, 12, 40, 8);
			this->CategoryTableTitle->Name = L"CategoryTableTitle";
			this->CategoryTableTitle->Size = System::Drawing::Size(159, 27);
			this->CategoryTableTitle->TabIndex = 7;
			this->CategoryTableTitle->Text = L"جدول الاصناف";
			this->CategoryTableTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CategoryTablePanel
			// 
			this->CategoryTablePanel->AccessibleName = L"CategoryTablePanel";
			this->CategoryTablePanel->Controls->Add(this->SearchPanelContainer);
			this->CategoryTablePanel->Controls->Add(this->CategoryTable);
			this->CategoryTablePanel->Location = System::Drawing::Point(2, 70);
			this->CategoryTablePanel->Margin = System::Windows::Forms::Padding(2);
			this->CategoryTablePanel->Name = L"CategoryTablePanel";
			this->CategoryTablePanel->Size = System::Drawing::Size(936, 619);
			this->CategoryTablePanel->TabIndex = 13;
			// 
			// SearchPanelContainer
			// 
			this->SearchPanelContainer->Controls->Add(this->CategorySearchPanel);
			this->SearchPanelContainer->Controls->Add(this->catSearchLab);
			this->SearchPanelContainer->Location = System::Drawing::Point(2, 2);
			this->SearchPanelContainer->Margin = System::Windows::Forms::Padding(2);
			this->SearchPanelContainer->Name = L"SearchPanelContainer";
			this->SearchPanelContainer->Size = System::Drawing::Size(933, 67);
			this->SearchPanelContainer->TabIndex = 14;
			// 
			// CategorySearchPanel
			// 
			this->CategorySearchPanel->AccessibleName = L"CategorySearchPanel";
			this->CategorySearchPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CategorySearchPanel->Controls->Add(this->CategorySearch);
			this->CategorySearchPanel->Location = System::Drawing::Point(17, 12);
			this->CategorySearchPanel->Name = L"CategorySearchPanel";
			this->CategorySearchPanel->Padding = System::Windows::Forms::Padding(8);
			this->CategorySearchPanel->Size = System::Drawing::Size(790, 40);
			this->CategorySearchPanel->TabIndex = 13;
			// 
			// CategorySearch
			// 
			this->CategorySearch->AccessibleName = L"CategorySearch";
			this->CategorySearch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->CategorySearch->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->CategorySearch->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CategorySearch->ForeColor = System::Drawing::Color::White;
			this->CategorySearch->Location = System::Drawing::Point(8, 8);
			this->CategorySearch->Margin = System::Windows::Forms::Padding(0);
			this->CategorySearch->MaxLength = 50;
			this->CategorySearch->Multiline = true;
			this->CategorySearch->Name = L"CategorySearch";
			this->CategorySearch->Size = System::Drawing::Size(766, 24);
			this->CategorySearch->TabIndex = 5;
			this->CategorySearch->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->CategorySearch->TextChanged += gcnew System::EventHandler(this, &Dashboard::CategorySearch_TextChanged);
			// 
			// catSearchLab
			// 
			this->catSearchLab->AccessibleName = L"catSearchLab";
			this->catSearchLab->AutoSize = true;
			this->catSearchLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->catSearchLab->Location = System::Drawing::Point(812, 21);
			this->catSearchLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->catSearchLab->Name = L"catSearchLab";
			this->catSearchLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->catSearchLab->Size = System::Drawing::Size(108, 21);
			this->catSearchLab->TabIndex = 6;
			this->catSearchLab->Text = L"ابحث عن صنف";
			// 
			// CategoryTable
			// 
			this->CategoryTable->AccessibleName = L"CategoryTable";
			this->CategoryTable->AllowUserToAddRows = false;
			this->CategoryTable->AllowUserToDeleteRows = false;
			dataGridViewCellStyle51->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle51->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			dataGridViewCellStyle51->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle51->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle51->Padding = System::Windows::Forms::Padding(4);
			dataGridViewCellStyle51->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle51->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle51->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->CategoryTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle51;
			this->CategoryTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->CategoryTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->CategoryTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->CategoryTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle52->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle52->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(65)));
			dataGridViewCellStyle52->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle52->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle52->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle52->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			dataGridViewCellStyle52->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle52->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->CategoryTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle52;
			this->CategoryTable->ColumnHeadersHeight = 50;
			this->CategoryTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->CategoryTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->categoryColId,
					this->categoryColName, this->categoryColDescription, this->categoryColCreated_At, this->categoryColUpdated_At
			});
			dataGridViewCellStyle54->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle54->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle54->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle54->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle54->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle54->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle54->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle54->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->CategoryTable->DefaultCellStyle = dataGridViewCellStyle54;
			this->CategoryTable->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->CategoryTable->EnableHeadersVisualStyles = false;
			this->CategoryTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->CategoryTable->Location = System::Drawing::Point(8, 79);
			this->CategoryTable->Margin = System::Windows::Forms::Padding(8);
			this->CategoryTable->MultiSelect = false;
			this->CategoryTable->Name = L"CategoryTable";
			this->CategoryTable->ReadOnly = true;
			this->CategoryTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->CategoryTable->RowHeadersVisible = false;
			this->CategoryTable->RowHeadersWidth = 51;
			dataGridViewCellStyle55->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle55->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle55->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle55->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle55->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle55->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle55->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle55->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->CategoryTable->RowsDefaultCellStyle = dataGridViewCellStyle55;
			this->CategoryTable->RowTemplate->Height = 40;
			this->CategoryTable->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->CategoryTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->CategoryTable->Size = System::Drawing::Size(927, 532);
			this->CategoryTable->StandardTab = true;
			this->CategoryTable->TabIndex = 0;
			this->CategoryTable->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::CategoryTable_CellClick);
			this->CategoryTable->CellMouseEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::DataGridView_CellMouseEnter);
			this->CategoryTable->CellMouseLeave += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::DataGridView_CellMouseLeave);
			// 
			// categoryColId
			// 
			this->categoryColId->DataPropertyName = L"Id";
			this->categoryColId->HeaderText = L"رقم الصنف";
			this->categoryColId->MaxInputLength = 10;
			this->categoryColId->MinimumWidth = 80;
			this->categoryColId->Name = L"categoryColId";
			this->categoryColId->ReadOnly = true;
			this->categoryColId->ToolTipText = L"الرقم التعريفي للصنف";
			// 
			// categoryColName
			// 
			this->categoryColName->DataPropertyName = L"name";
			this->categoryColName->HeaderText = L"اسم الصنف";
			this->categoryColName->MaxInputLength = 20;
			this->categoryColName->MinimumWidth = 80;
			this->categoryColName->Name = L"categoryColName";
			this->categoryColName->ReadOnly = true;
			this->categoryColName->ToolTipText = L"اسم الصنف";
			// 
			// categoryColDescription
			// 
			this->categoryColDescription->DataPropertyName = L"Description";
			dataGridViewCellStyle53->Padding = System::Windows::Forms::Padding(8);
			this->categoryColDescription->DefaultCellStyle = dataGridViewCellStyle53;
			this->categoryColDescription->HeaderText = L"وصف الصنف";
			this->categoryColDescription->MaxInputLength = 50;
			this->categoryColDescription->MinimumWidth = 80;
			this->categoryColDescription->Name = L"categoryColDescription";
			this->categoryColDescription->ReadOnly = true;
			this->categoryColDescription->ToolTipText = L"وصف الصنف";
			// 
			// categoryColCreated_At
			// 
			this->categoryColCreated_At->DataPropertyName = L"Created_At";
			this->categoryColCreated_At->HeaderText = L"تاريخ الاضافة";
			this->categoryColCreated_At->MaxInputLength = 16;
			this->categoryColCreated_At->MinimumWidth = 100;
			this->categoryColCreated_At->Name = L"categoryColCreated_At";
			this->categoryColCreated_At->ReadOnly = true;
			this->categoryColCreated_At->ToolTipText = L"تاريخ اضافة الصنف";
			// 
			// categoryColUpdated_At
			// 
			this->categoryColUpdated_At->DataPropertyName = L"Updated_At";
			this->categoryColUpdated_At->HeaderText = L"تاريخ التعديل";
			this->categoryColUpdated_At->MaxInputLength = 16;
			this->categoryColUpdated_At->MinimumWidth = 6;
			this->categoryColUpdated_At->Name = L"categoryColUpdated_At";
			this->categoryColUpdated_At->ReadOnly = true;
			// 
			// ManageCategoryPanel
			// 
			this->ManageCategoryPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ManageCategoryPanel->Controls->Add(this->panel8);
			this->ManageCategoryPanel->Controls->Add(this->CategoryFormTitkePanel);
			this->ManageCategoryPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->ManageCategoryPanel->Location = System::Drawing::Point(950, 0);
			this->ManageCategoryPanel->Margin = System::Windows::Forms::Padding(4, 8, 4, 8);
			this->ManageCategoryPanel->Name = L"ManageCategoryPanel";
			this->ManageCategoryPanel->Size = System::Drawing::Size(376, 692);
			this->ManageCategoryPanel->TabIndex = 7;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->panel8->Controls->Add(this->catNameLab);
			this->panel8->Controls->Add(this->delCat);
			this->panel8->Controls->Add(this->updateCat);
			this->panel8->Controls->Add(this->addCat);
			this->panel8->Controls->Add(this->catdescLab);
			this->panel8->Controls->Add(this->ContainerOfCatDesc);
			this->panel8->Controls->Add(this->ContainerOfCatName);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel8->Location = System::Drawing::Point(0, 64);
			this->panel8->Margin = System::Windows::Forms::Padding(2);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(374, 626);
			this->panel8->TabIndex = 14;
			// 
			// catNameLab
			// 
			this->catNameLab->AccessibleName = L"catNameLab";
			this->catNameLab->AutoSize = true;
			this->catNameLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->catNameLab->Location = System::Drawing::Point(174, 57);
			this->catNameLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->catNameLab->Name = L"catNameLab";
			this->catNameLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->catNameLab->Size = System::Drawing::Size(86, 21);
			this->catNameLab->TabIndex = 27;
			this->catNameLab->Text = L"اسم الصنف";
			// 
			// delCat
			// 
			this->delCat->AccessibleName = L"delCat";
			this->delCat->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->delCat->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->delCat->FlatAppearance->BorderSize = 0;
			this->delCat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delCat->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delCat->ForeColor = System::Drawing::Color::Red;
			this->delCat->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"delCat.Image")));
			this->delCat->Location = System::Drawing::Point(293, 172);
			this->delCat->Margin = System::Windows::Forms::Padding(2);
			this->delCat->MaximumSize = System::Drawing::Size(60, 60);
			this->delCat->MinimumSize = System::Drawing::Size(60, 60);
			this->delCat->Name = L"delCat";
			this->delCat->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->delCat->Size = System::Drawing::Size(60, 60);
			this->delCat->TabIndex = 22;
			this->delCat->UseVisualStyleBackColor = false;
			this->delCat->Click += gcnew System::EventHandler(this, &Dashboard::delCat_Click);
			// 
			// updateCat
			// 
			this->updateCat->AccessibleName = L"updateCat";
			this->updateCat->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->updateCat->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->updateCat->FlatAppearance->BorderSize = 0;
			this->updateCat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->updateCat->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->updateCat->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->updateCat->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"updateCat.Image")));
			this->updateCat->Location = System::Drawing::Point(293, 113);
			this->updateCat->Margin = System::Windows::Forms::Padding(2);
			this->updateCat->MaximumSize = System::Drawing::Size(60, 60);
			this->updateCat->MinimumSize = System::Drawing::Size(60, 60);
			this->updateCat->Name = L"updateCat";
			this->updateCat->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->updateCat->Size = System::Drawing::Size(60, 60);
			this->updateCat->TabIndex = 23;
			this->updateCat->UseVisualStyleBackColor = false;
			this->updateCat->Click += gcnew System::EventHandler(this, &Dashboard::updateCat_Click);
			// 
			// addCat
			// 
			this->addCat->AccessibleName = L"addCat";
			this->addCat->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->addCat->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->addCat->FlatAppearance->BorderSize = 0;
			this->addCat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addCat->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addCat->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->addCat->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addCat.Image")));
			this->addCat->Location = System::Drawing::Point(293, 53);
			this->addCat->Margin = System::Windows::Forms::Padding(2);
			this->addCat->MaximumSize = System::Drawing::Size(60, 60);
			this->addCat->MinimumSize = System::Drawing::Size(60, 60);
			this->addCat->Name = L"addCat";
			this->addCat->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->addCat->Size = System::Drawing::Size(60, 60);
			this->addCat->TabIndex = 24;
			this->addCat->UseVisualStyleBackColor = false;
			this->addCat->Click += gcnew System::EventHandler(this, &Dashboard::addCat_Click);
			// 
			// catdescLab
			// 
			this->catdescLab->AccessibleName = L"catdescLab";
			this->catdescLab->AutoSize = true;
			this->catdescLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->catdescLab->Location = System::Drawing::Point(163, 139);
			this->catdescLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->catdescLab->Name = L"catdescLab";
			this->catdescLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->catdescLab->Size = System::Drawing::Size(100, 21);
			this->catdescLab->TabIndex = 21;
			this->catdescLab->Text = L"وصف الصنف";
			// 
			// ContainerOfCatDesc
			// 
			this->ContainerOfCatDesc->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ContainerOfCatDesc->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ContainerOfCatDesc->Controls->Add(this->Catdesc);
			this->ContainerOfCatDesc->Location = System::Drawing::Point(20, 172);
			this->ContainerOfCatDesc->Margin = System::Windows::Forms::Padding(2);
			this->ContainerOfCatDesc->Name = L"ContainerOfCatDesc";
			this->ContainerOfCatDesc->Padding = System::Windows::Forms::Padding(8);
			this->ContainerOfCatDesc->Size = System::Drawing::Size(248, 72);
			this->ContainerOfCatDesc->TabIndex = 26;
			// 
			// Catdesc
			// 
			this->Catdesc->AccessibleName = L"Catdesc";
			this->Catdesc->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->Catdesc->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Catdesc->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Catdesc->ForeColor = System::Drawing::Color::White;
			this->Catdesc->Location = System::Drawing::Point(8, 8);
			this->Catdesc->Margin = System::Windows::Forms::Padding(0);
			this->Catdesc->MaxLength = 50;
			this->Catdesc->Multiline = true;
			this->Catdesc->Name = L"Catdesc";
			this->Catdesc->Size = System::Drawing::Size(232, 56);
			this->Catdesc->TabIndex = 5;
			this->Catdesc->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// ContainerOfCatName
			// 
			this->ContainerOfCatName->AccessibleName = L"ContainerOfCatName";
			this->ContainerOfCatName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ContainerOfCatName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ContainerOfCatName->Controls->Add(this->CatName);
			this->ContainerOfCatName->Location = System::Drawing::Point(20, 87);
			this->ContainerOfCatName->Name = L"ContainerOfCatName";
			this->ContainerOfCatName->Padding = System::Windows::Forms::Padding(8);
			this->ContainerOfCatName->Size = System::Drawing::Size(248, 40);
			this->ContainerOfCatName->TabIndex = 25;
			// 
			// CatName
			// 
			this->CatName->AccessibleName = L"CatName";
			this->CatName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->CatName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->CatName->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CatName->ForeColor = System::Drawing::Color::White;
			this->CatName->Location = System::Drawing::Point(8, 8);
			this->CatName->Margin = System::Windows::Forms::Padding(0);
			this->CatName->MaxLength = 50;
			this->CatName->Multiline = true;
			this->CatName->Name = L"CatName";
			this->CatName->Size = System::Drawing::Size(232, 24);
			this->CatName->TabIndex = 5;
			this->CatName->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// CategoryFormTitkePanel
			// 
			this->CategoryFormTitkePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CategoryFormTitkePanel->Controls->Add(this->catFormTitle);
			this->CategoryFormTitkePanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->CategoryFormTitkePanel->Location = System::Drawing::Point(0, 0);
			this->CategoryFormTitkePanel->Margin = System::Windows::Forms::Padding(2);
			this->CategoryFormTitkePanel->Name = L"CategoryFormTitkePanel";
			this->CategoryFormTitkePanel->Size = System::Drawing::Size(374, 64);
			this->CategoryFormTitkePanel->TabIndex = 10;
			// 
			// catFormTitle
			// 
			this->catFormTitle->AccessibleName = L"catFormTitle";
			this->catFormTitle->AutoEllipsis = true;
			this->catFormTitle->AutoSize = true;
			this->catFormTitle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->catFormTitle->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->catFormTitle->ForeColor = System::Drawing::Color::White;
			this->catFormTitle->Location = System::Drawing::Point(98, 18);
			this->catFormTitle->Margin = System::Windows::Forms::Padding(80, 12, 40, 8);
			this->catFormTitle->Name = L"catFormTitle";
			this->catFormTitle->Size = System::Drawing::Size(148, 27);
			this->catFormTitle->TabIndex = 7;
			this->catFormTitle->Text = L"ادارة الاصناف";
			this->catFormTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// supplierPanel
			// 
			this->supplierPanel->Controls->Add(this->SupplierTableContainer);
			this->supplierPanel->Controls->Add(this->ManageSupplierContainer);
			this->supplierPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->supplierPanel->Location = System::Drawing::Point(0, 0);
			this->supplierPanel->Margin = System::Windows::Forms::Padding(2);
			this->supplierPanel->Name = L"supplierPanel";
			this->supplierPanel->Size = System::Drawing::Size(1326, 692);
			this->supplierPanel->TabIndex = 4;
			// 
			// SupplierTableContainer
			// 
			this->SupplierTableContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SupplierTableContainer->Controls->Add(this->SupplierTableTitlePanel);
			this->SupplierTableContainer->Controls->Add(this->SupplierTablePanel);
			this->SupplierTableContainer->Dock = System::Windows::Forms::DockStyle::Left;
			this->SupplierTableContainer->FlowDirection = System::Windows::Forms::FlowDirection::RightToLeft;
			this->SupplierTableContainer->Location = System::Drawing::Point(0, 0);
			this->SupplierTableContainer->Margin = System::Windows::Forms::Padding(4, 8, 4, 8);
			this->SupplierTableContainer->Name = L"SupplierTableContainer";
			this->SupplierTableContainer->Size = System::Drawing::Size(944, 692);
			this->SupplierTableContainer->TabIndex = 10;
			// 
			// SupplierTableTitlePanel
			// 
			this->SupplierTableTitlePanel->Controls->Add(this->SupplierTableTitle);
			this->SupplierTableTitlePanel->Location = System::Drawing::Point(4, 2);
			this->SupplierTableTitlePanel->Margin = System::Windows::Forms::Padding(2);
			this->SupplierTableTitlePanel->Name = L"SupplierTableTitlePanel";
			this->SupplierTableTitlePanel->Size = System::Drawing::Size(936, 63);
			this->SupplierTableTitlePanel->TabIndex = 9;
			// 
			// SupplierTableTitle
			// 
			this->SupplierTableTitle->AutoEllipsis = true;
			this->SupplierTableTitle->AutoSize = true;
			this->SupplierTableTitle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SupplierTableTitle->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SupplierTableTitle->ForeColor = System::Drawing::Color::White;
			this->SupplierTableTitle->Location = System::Drawing::Point(354, 15);
			this->SupplierTableTitle->Margin = System::Windows::Forms::Padding(80, 12, 40, 8);
			this->SupplierTableTitle->Name = L"SupplierTableTitle";
			this->SupplierTableTitle->Size = System::Drawing::Size(168, 27);
			this->SupplierTableTitle->TabIndex = 7;
			this->SupplierTableTitle->Text = L"جدول الموردين";
			this->SupplierTableTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SupplierTablePanel
			// 
			this->SupplierTablePanel->AccessibleName = L"CategoryTablePanel";
			this->SupplierTablePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SupplierTablePanel->Controls->Add(this->SupplierSearchContainer);
			this->SupplierTablePanel->Controls->Add(this->SupplierTable);
			this->SupplierTablePanel->Location = System::Drawing::Point(5, 69);
			this->SupplierTablePanel->Margin = System::Windows::Forms::Padding(2);
			this->SupplierTablePanel->Name = L"SupplierTablePanel";
			this->SupplierTablePanel->Size = System::Drawing::Size(935, 620);
			this->SupplierTablePanel->TabIndex = 13;
			// 
			// SupplierSearchContainer
			// 
			this->SupplierSearchContainer->Controls->Add(this->SupplierSearchPanel);
			this->SupplierSearchContainer->Controls->Add(this->SupplierSearchLab);
			this->SupplierSearchContainer->Location = System::Drawing::Point(2, 2);
			this->SupplierSearchContainer->Margin = System::Windows::Forms::Padding(2);
			this->SupplierSearchContainer->Name = L"SupplierSearchContainer";
			this->SupplierSearchContainer->Size = System::Drawing::Size(927, 67);
			this->SupplierSearchContainer->TabIndex = 14;
			// 
			// SupplierSearchPanel
			// 
			this->SupplierSearchPanel->AccessibleName = L"CategorySearchPanel";
			this->SupplierSearchPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SupplierSearchPanel->Controls->Add(this->SupplierSearch);
			this->SupplierSearchPanel->Location = System::Drawing::Point(17, 12);
			this->SupplierSearchPanel->Name = L"SupplierSearchPanel";
			this->SupplierSearchPanel->Padding = System::Windows::Forms::Padding(8);
			this->SupplierSearchPanel->Size = System::Drawing::Size(757, 40);
			this->SupplierSearchPanel->TabIndex = 13;
			// 
			// SupplierSearch
			// 
			this->SupplierSearch->AccessibleName = L"CategorySearch";
			this->SupplierSearch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->SupplierSearch->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SupplierSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SupplierSearch->ForeColor = System::Drawing::Color::White;
			this->SupplierSearch->Location = System::Drawing::Point(8, 8);
			this->SupplierSearch->Margin = System::Windows::Forms::Padding(0);
			this->SupplierSearch->MaxLength = 50;
			this->SupplierSearch->Multiline = true;
			this->SupplierSearch->Name = L"SupplierSearch";
			this->SupplierSearch->Size = System::Drawing::Size(737, 24);
			this->SupplierSearch->TabIndex = 5;
			this->SupplierSearch->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->SupplierSearch->TextChanged += gcnew System::EventHandler(this, &Dashboard::SupplierSearch_TextChanged);
			// 
			// SupplierSearchLab
			// 
			this->SupplierSearchLab->AccessibleName = L"catSearchLab";
			this->SupplierSearchLab->AutoSize = true;
			this->SupplierSearchLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SupplierSearchLab->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SupplierSearchLab.Image")));
			this->SupplierSearchLab->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->SupplierSearchLab->Location = System::Drawing::Point(779, 5);
			this->SupplierSearchLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->SupplierSearchLab->MinimumSize = System::Drawing::Size(120, 60);
			this->SupplierSearchLab->Name = L"SupplierSearchLab";
			this->SupplierSearchLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SupplierSearchLab->Size = System::Drawing::Size(120, 60);
			this->SupplierSearchLab->TabIndex = 6;
			this->SupplierSearchLab->Text = L"ابحث";
			this->SupplierSearchLab->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// SupplierTable
			// 
			this->SupplierTable->AccessibleName = L"CategoryTable";
			this->SupplierTable->AllowUserToAddRows = false;
			this->SupplierTable->AllowUserToDeleteRows = false;
			dataGridViewCellStyle56->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle56->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			dataGridViewCellStyle56->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle56->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle56->Padding = System::Windows::Forms::Padding(4);
			dataGridViewCellStyle56->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle56->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle56->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->SupplierTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle56;
			this->SupplierTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->SupplierTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->SupplierTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SupplierTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle57->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle57->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(65)));
			dataGridViewCellStyle57->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle57->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle57->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle57->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			dataGridViewCellStyle57->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle57->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->SupplierTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle57;
			this->SupplierTable->ColumnHeadersHeight = 50;
			this->SupplierTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->SupplierTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->SupplierColId,
					this->SupplierColName, this->SupplierColContactInfo, this->SupplierColCreated_At, this->SupplierColUpdated_At
			});
			dataGridViewCellStyle59->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle59->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle59->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle59->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle59->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle59->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle59->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle59->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->SupplierTable->DefaultCellStyle = dataGridViewCellStyle59;
			this->SupplierTable->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->SupplierTable->EnableHeadersVisualStyles = false;
			this->SupplierTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->SupplierTable->Location = System::Drawing::Point(8, 79);
			this->SupplierTable->Margin = System::Windows::Forms::Padding(8);
			this->SupplierTable->MultiSelect = false;
			this->SupplierTable->Name = L"SupplierTable";
			this->SupplierTable->ReadOnly = true;
			this->SupplierTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SupplierTable->RowHeadersVisible = false;
			this->SupplierTable->RowHeadersWidth = 51;
			dataGridViewCellStyle60->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle60->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle60->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle60->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle60->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle60->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle60->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle60->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->SupplierTable->RowsDefaultCellStyle = dataGridViewCellStyle60;
			this->SupplierTable->RowTemplate->Height = 40;
			this->SupplierTable->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->SupplierTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->SupplierTable->Size = System::Drawing::Size(922, 540);
			this->SupplierTable->StandardTab = true;
			this->SupplierTable->TabIndex = 0;
			this->SupplierTable->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::SupplierTable_CellClick);
			// 
			// SupplierColId
			// 
			this->SupplierColId->DataPropertyName = L"SupplierColId";
			this->SupplierColId->HeaderText = L"رقم المورد";
			this->SupplierColId->MaxInputLength = 10;
			this->SupplierColId->MinimumWidth = 80;
			this->SupplierColId->Name = L"SupplierColId";
			this->SupplierColId->ReadOnly = true;
			this->SupplierColId->ToolTipText = L"الرقم التعريفي للمورد";
			// 
			// SupplierColName
			// 
			this->SupplierColName->DataPropertyName = L"SupplierColName";
			this->SupplierColName->HeaderText = L"اسم المورد";
			this->SupplierColName->MaxInputLength = 20;
			this->SupplierColName->MinimumWidth = 80;
			this->SupplierColName->Name = L"SupplierColName";
			this->SupplierColName->ReadOnly = true;
			this->SupplierColName->ToolTipText = L"اسم المورد";
			// 
			// SupplierColContactInfo
			// 
			this->SupplierColContactInfo->DataPropertyName = L"SupplierColContactInfo";
			dataGridViewCellStyle58->Padding = System::Windows::Forms::Padding(8);
			this->SupplierColContactInfo->DefaultCellStyle = dataGridViewCellStyle58;
			this->SupplierColContactInfo->HeaderText = L"تواصل";
			this->SupplierColContactInfo->MaxInputLength = 50;
			this->SupplierColContactInfo->MinimumWidth = 80;
			this->SupplierColContactInfo->Name = L"SupplierColContactInfo";
			this->SupplierColContactInfo->ReadOnly = true;
			this->SupplierColContactInfo->ToolTipText = L"التواصل مع المورد";
			// 
			// SupplierColCreated_At
			// 
			this->SupplierColCreated_At->DataPropertyName = L"SupplierColCreated_At";
			this->SupplierColCreated_At->HeaderText = L"تاريخ الاضافة";
			this->SupplierColCreated_At->MaxInputLength = 16;
			this->SupplierColCreated_At->MinimumWidth = 100;
			this->SupplierColCreated_At->Name = L"SupplierColCreated_At";
			this->SupplierColCreated_At->ReadOnly = true;
			this->SupplierColCreated_At->ToolTipText = L"تاريخ اضافة المنتج";
			// 
			// SupplierColUpdated_At
			// 
			this->SupplierColUpdated_At->DataPropertyName = L"SupplierColUpdated_At";
			this->SupplierColUpdated_At->HeaderText = L"تاريخ التعديل";
			this->SupplierColUpdated_At->MaxInputLength = 16;
			this->SupplierColUpdated_At->MinimumWidth = 6;
			this->SupplierColUpdated_At->Name = L"SupplierColUpdated_At";
			this->SupplierColUpdated_At->ReadOnly = true;
			this->SupplierColUpdated_At->ToolTipText = L"تاريخ تعديل المنتج";
			// 
			// ManageSupplierContainer
			// 
			this->ManageSupplierContainer->AccessibleName = L"ManageProductContainer";
			this->ManageSupplierContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ManageSupplierContainer->Controls->Add(this->ManageSupplierFormsPanel);
			this->ManageSupplierContainer->Controls->Add(this->panel13);
			this->ManageSupplierContainer->Dock = System::Windows::Forms::DockStyle::Right;
			this->ManageSupplierContainer->Location = System::Drawing::Point(952, 0);
			this->ManageSupplierContainer->Margin = System::Windows::Forms::Padding(4, 8, 4, 8);
			this->ManageSupplierContainer->Name = L"ManageSupplierContainer";
			this->ManageSupplierContainer->Size = System::Drawing::Size(374, 692);
			this->ManageSupplierContainer->TabIndex = 11;
			// 
			// ManageSupplierFormsPanel
			// 
			this->ManageSupplierFormsPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->ManageSupplierFormsPanel->Controls->Add(this->SupplierNameLab);
			this->ManageSupplierFormsPanel->Controls->Add(this->ContainerOfSupplierContact_Info);
			this->ManageSupplierFormsPanel->Controls->Add(this->ContainerOfSupplierName);
			this->ManageSupplierFormsPanel->Controls->Add(this->DelSupplier_Btn);
			this->ManageSupplierFormsPanel->Controls->Add(this->EditSupplier_Btn);
			this->ManageSupplierFormsPanel->Controls->Add(this->AddSupplier_Btn);
			this->ManageSupplierFormsPanel->Controls->Add(this->label11);
			this->ManageSupplierFormsPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ManageSupplierFormsPanel->Location = System::Drawing::Point(0, 64);
			this->ManageSupplierFormsPanel->Margin = System::Windows::Forms::Padding(8);
			this->ManageSupplierFormsPanel->Name = L"ManageSupplierFormsPanel";
			this->ManageSupplierFormsPanel->Size = System::Drawing::Size(372, 626);
			this->ManageSupplierFormsPanel->TabIndex = 15;
			// 
			// SupplierNameLab
			// 
			this->SupplierNameLab->AccessibleName = L"SupplierNameLab";
			this->SupplierNameLab->AutoSize = true;
			this->SupplierNameLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SupplierNameLab->Location = System::Drawing::Point(173, 54);
			this->SupplierNameLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->SupplierNameLab->Name = L"SupplierNameLab";
			this->SupplierNameLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SupplierNameLab->Size = System::Drawing::Size(80, 21);
			this->SupplierNameLab->TabIndex = 32;
			this->SupplierNameLab->Text = L"اسم المورد";
			// 
			// ContainerOfSupplierContact_Info
			// 
			this->ContainerOfSupplierContact_Info->AccessibleName = L"ContainerOfSupplierContact_Info";
			this->ContainerOfSupplierContact_Info->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ContainerOfSupplierContact_Info->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ContainerOfSupplierContact_Info->Controls->Add(this->SupplierContact_Info);
			this->ContainerOfSupplierContact_Info->Location = System::Drawing::Point(13, 184);
			this->ContainerOfSupplierContact_Info->Name = L"ContainerOfSupplierContact_Info";
			this->ContainerOfSupplierContact_Info->Padding = System::Windows::Forms::Padding(8);
			this->ContainerOfSupplierContact_Info->Size = System::Drawing::Size(248, 40);
			this->ContainerOfSupplierContact_Info->TabIndex = 30;
			// 
			// SupplierContact_Info
			// 
			this->SupplierContact_Info->AccessibleName = L"SupplierContact_Info";
			this->SupplierContact_Info->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->SupplierContact_Info->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SupplierContact_Info->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SupplierContact_Info->ForeColor = System::Drawing::Color::White;
			this->SupplierContact_Info->Location = System::Drawing::Point(8, 8);
			this->SupplierContact_Info->Margin = System::Windows::Forms::Padding(0);
			this->SupplierContact_Info->MaxLength = 50;
			this->SupplierContact_Info->Multiline = true;
			this->SupplierContact_Info->Name = L"SupplierContact_Info";
			this->SupplierContact_Info->Size = System::Drawing::Size(232, 24);
			this->SupplierContact_Info->TabIndex = 5;
			this->SupplierContact_Info->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// ContainerOfSupplierName
			// 
			this->ContainerOfSupplierName->AccessibleName = L"ContainerOfSupplierName";
			this->ContainerOfSupplierName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ContainerOfSupplierName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ContainerOfSupplierName->Controls->Add(this->SupplierName);
			this->ContainerOfSupplierName->Location = System::Drawing::Point(13, 92);
			this->ContainerOfSupplierName->Name = L"ContainerOfSupplierName";
			this->ContainerOfSupplierName->Padding = System::Windows::Forms::Padding(8);
			this->ContainerOfSupplierName->Size = System::Drawing::Size(248, 40);
			this->ContainerOfSupplierName->TabIndex = 31;
			// 
			// SupplierName
			// 
			this->SupplierName->AccessibleName = L"SupplierName";
			this->SupplierName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->SupplierName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SupplierName->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SupplierName->ForeColor = System::Drawing::Color::White;
			this->SupplierName->Location = System::Drawing::Point(8, 8);
			this->SupplierName->Margin = System::Windows::Forms::Padding(0);
			this->SupplierName->MaxLength = 50;
			this->SupplierName->Multiline = true;
			this->SupplierName->Name = L"SupplierName";
			this->SupplierName->Size = System::Drawing::Size(232, 24);
			this->SupplierName->TabIndex = 5;
			this->SupplierName->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// DelSupplier_Btn
			// 
			this->DelSupplier_Btn->AccessibleName = L"DelSupplier_Btn";
			this->DelSupplier_Btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->DelSupplier_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->DelSupplier_Btn->FlatAppearance->BorderSize = 0;
			this->DelSupplier_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->DelSupplier_Btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DelSupplier_Btn->ForeColor = System::Drawing::Color::Red;
			this->DelSupplier_Btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DelSupplier_Btn.Image")));
			this->DelSupplier_Btn->Location = System::Drawing::Point(291, 173);
			this->DelSupplier_Btn->Margin = System::Windows::Forms::Padding(2);
			this->DelSupplier_Btn->MaximumSize = System::Drawing::Size(60, 60);
			this->DelSupplier_Btn->MinimumSize = System::Drawing::Size(60, 60);
			this->DelSupplier_Btn->Name = L"DelSupplier_Btn";
			this->DelSupplier_Btn->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->DelSupplier_Btn->Size = System::Drawing::Size(60, 60);
			this->DelSupplier_Btn->TabIndex = 27;
			this->DelSupplier_Btn->UseVisualStyleBackColor = false;
			this->DelSupplier_Btn->Click += gcnew System::EventHandler(this, &Dashboard::DelSupplier_Btn_Click);
			// 
			// EditSupplier_Btn
			// 
			this->EditSupplier_Btn->AccessibleName = L"EditSupplier_Btn";
			this->EditSupplier_Btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->EditSupplier_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->EditSupplier_Btn->FlatAppearance->BorderSize = 0;
			this->EditSupplier_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->EditSupplier_Btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EditSupplier_Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->EditSupplier_Btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"EditSupplier_Btn.Image")));
			this->EditSupplier_Btn->Location = System::Drawing::Point(291, 113);
			this->EditSupplier_Btn->Margin = System::Windows::Forms::Padding(2);
			this->EditSupplier_Btn->MaximumSize = System::Drawing::Size(60, 60);
			this->EditSupplier_Btn->MinimumSize = System::Drawing::Size(60, 60);
			this->EditSupplier_Btn->Name = L"EditSupplier_Btn";
			this->EditSupplier_Btn->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->EditSupplier_Btn->Size = System::Drawing::Size(60, 60);
			this->EditSupplier_Btn->TabIndex = 28;
			this->EditSupplier_Btn->UseVisualStyleBackColor = false;
			this->EditSupplier_Btn->Click += gcnew System::EventHandler(this, &Dashboard::EditSupplier_Btn_Click);
			// 
			// AddSupplier_Btn
			// 
			this->AddSupplier_Btn->AccessibleName = L"AddSupplier_Btn";
			this->AddSupplier_Btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->AddSupplier_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->AddSupplier_Btn->FlatAppearance->BorderSize = 0;
			this->AddSupplier_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AddSupplier_Btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AddSupplier_Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->AddSupplier_Btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AddSupplier_Btn.Image")));
			this->AddSupplier_Btn->Location = System::Drawing::Point(291, 54);
			this->AddSupplier_Btn->Margin = System::Windows::Forms::Padding(2);
			this->AddSupplier_Btn->MaximumSize = System::Drawing::Size(60, 60);
			this->AddSupplier_Btn->MinimumSize = System::Drawing::Size(60, 60);
			this->AddSupplier_Btn->Name = L"AddSupplier_Btn";
			this->AddSupplier_Btn->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->AddSupplier_Btn->Size = System::Drawing::Size(60, 60);
			this->AddSupplier_Btn->TabIndex = 29;
			this->AddSupplier_Btn->UseVisualStyleBackColor = false;
			this->AddSupplier_Btn->Click += gcnew System::EventHandler(this, &Dashboard::AddSupplier_Btn_Click);
			// 
			// label11
			// 
			this->label11->AccessibleName = L"catdescLab";
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(186, 147);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->label11->Size = System::Drawing::Size(67, 21);
			this->label11->TabIndex = 26;
			this->label11->Text = L"التواصل ";
			// 
			// panel13
			// 
			this->panel13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel13->Controls->Add(this->label12);
			this->panel13->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel13->Location = System::Drawing::Point(0, 0);
			this->panel13->Margin = System::Windows::Forms::Padding(2);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(372, 64);
			this->panel13->TabIndex = 10;
			// 
			// label12
			// 
			this->label12->AccessibleName = L"catFormTitle";
			this->label12->AutoEllipsis = true;
			this->label12->AutoSize = true;
			this->label12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label12->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::White;
			this->label12->Location = System::Drawing::Point(108, 18);
			this->label12->Margin = System::Windows::Forms::Padding(80, 12, 40, 8);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(157, 27);
			this->label12->TabIndex = 7;
			this->label12->Text = L"ادارة الموردين";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Dashboard
			// 
			this->AccessibleName = L"DashboardFrame";
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ClientSize = System::Drawing::Size(1536, 849);
			this->Controls->Add(this->CenterPanel);
			this->Controls->Add(this->RightPanel);
			this->Controls->Add(this->FooterPanel);
			this->Controls->Add(this->Header);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Dashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dashboard";
			this->Load += gcnew System::EventHandler(this, &Dashboard::Dashboard_Load);
			this->Header->ResumeLayout(false);
			this->Header->PerformLayout();
			this->FooterPanel->ResumeLayout(false);
			this->FooterPanel->PerformLayout();
			this->RightPanel->ResumeLayout(false);
			this->NavPanel->ResumeLayout(false);
			this->UserPanel->ResumeLayout(false);
			this->CenterPanel->ResumeLayout(false);
			this->HomePanel->ResumeLayout(false);
			this->HomePanel->PerformLayout();
			this->fastNav->ResumeLayout(false);
			this->recentSalesPanel->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->recentSalesTable))->EndInit();
			this->Cards->ResumeLayout(false);
			this->CardPanelHead->ResumeLayout(false);
			this->CardPanelHead->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->stockPanel->ResumeLayout(false);
			this->stockPanel->PerformLayout();
			this->InvoiceDetailsContainer->ResumeLayout(false);
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			this->InvoiceHeaderContainer->ResumeLayout(false);
			this->InvoiceHeaderContainer->PerformLayout();
			this->InvoiceHeaderTitlepanel->ResumeLayout(false);
			this->InvoiceHeaderTitlepanel->PerformLayout();
			this->InvoiceHeaderTableContainer->ResumeLayout(false);
			this->SearchInvoiceHeaderPanel->ResumeLayout(false);
			this->SearchInvoiceHeaderPanel->PerformLayout();
			this->SearchInvoiceHeaderContainer->ResumeLayout(false);
			this->SearchInvoiceHeaderContainer->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InvoiceHeaderTable))->EndInit();
			this->cashierPanel->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->CashierTablePanelContainer->ResumeLayout(false);
			this->CashierTablePanelContainer->PerformLayout();
			this->CashierTableTitlePanel->ResumeLayout(false);
			this->CashierTableTitlePanel->PerformLayout();
			this->CashierTablePanel->ResumeLayout(false);
			this->CashierSearchProductPanel->ResumeLayout(false);
			this->CashierSearchProductPanel->PerformLayout();
			this->CashierSearchProductContainer->ResumeLayout(false);
			this->CashierSearchProductContainer->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CashierTable))->EndInit();
			this->panel12->ResumeLayout(false);
			this->panel14->ResumeLayout(false);
			this->panel14->PerformLayout();
			this->panel10->ResumeLayout(false);
			this->payFeildContainer->ResumeLayout(false);
			this->payFeildContainer->PerformLayout();
			this->panel15->ResumeLayout(false);
			this->panel15->PerformLayout();
			this->productPanel->ResumeLayout(false);
			this->productPanel->PerformLayout();
			this->ProductTableContainer->ResumeLayout(false);
			this->ProductTableContainer->PerformLayout();
			this->ProductTableTitlePanel->ResumeLayout(false);
			this->ProductTableTitlePanel->PerformLayout();
			this->ProductTablePanel->ResumeLayout(false);
			this->ProductSearchContainer->ResumeLayout(false);
			this->ProductSearchContainer->PerformLayout();
			this->ProductSearchPanel->ResumeLayout(false);
			this->ProductSearchPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProductTable))->EndInit();
			this->ManageProductContainer->ResumeLayout(false);
			this->ManageProductFormPanel->ResumeLayout(false);
			this->ManageProductFormPanel->PerformLayout();
			this->ContainerOfProductQuantity->ResumeLayout(false);
			this->ContainerOfProductQuantity->PerformLayout();
			this->ContainerOfProductPrice->ResumeLayout(false);
			this->ContainerOfProductPrice->PerformLayout();
			this->ContainerOfProductName->ResumeLayout(false);
			this->ContainerOfProductName->PerformLayout();
			this->ManageProductTitlePanel->ResumeLayout(false);
			this->ManageProductTitlePanel->PerformLayout();
			this->categoryPanel->ResumeLayout(false);
			this->CategoryTableContainer->ResumeLayout(false);
			this->CategoryTableTitlePanel->ResumeLayout(false);
			this->CategoryTableTitlePanel->PerformLayout();
			this->CategoryTablePanel->ResumeLayout(false);
			this->SearchPanelContainer->ResumeLayout(false);
			this->SearchPanelContainer->PerformLayout();
			this->CategorySearchPanel->ResumeLayout(false);
			this->CategorySearchPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CategoryTable))->EndInit();
			this->ManageCategoryPanel->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->ContainerOfCatDesc->ResumeLayout(false);
			this->ContainerOfCatDesc->PerformLayout();
			this->ContainerOfCatName->ResumeLayout(false);
			this->ContainerOfCatName->PerformLayout();
			this->CategoryFormTitkePanel->ResumeLayout(false);
			this->CategoryFormTitkePanel->PerformLayout();
			this->supplierPanel->ResumeLayout(false);
			this->SupplierTableContainer->ResumeLayout(false);
			this->SupplierTableTitlePanel->ResumeLayout(false);
			this->SupplierTableTitlePanel->PerformLayout();
			this->SupplierTablePanel->ResumeLayout(false);
			this->SupplierSearchContainer->ResumeLayout(false);
			this->SupplierSearchContainer->PerformLayout();
			this->SupplierSearchPanel->ResumeLayout(false);
			this->SupplierSearchPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SupplierTable))->EndInit();
			this->ManageSupplierContainer->ResumeLayout(false);
			this->ManageSupplierFormsPanel->ResumeLayout(false);
			this->ManageSupplierFormsPanel->PerformLayout();
			this->ContainerOfSupplierContact_Info->ResumeLayout(false);
			this->ContainerOfSupplierContact_Info->PerformLayout();
			this->ContainerOfSupplierName->ResumeLayout(false);
			this->ContainerOfSupplierName->PerformLayout();
			this->panel13->ResumeLayout(false);
			this->panel13->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		// 1. First, let's create event handlers for the shortcut buttons
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

		// 2. Now, add the declarations to your Dashboard.h file in the private section
		/*
		private: System::Void SCAddCategory_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void SCAddSupplier_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void SCAddProduct_Click(System::Object^ sender, System::EventArgs^ e);
		*/

		// 3. Finally, connect these handlers to the buttons in the constructor or InitializeComponent method
		/*
		this->SCAddCategory->Click += gcnew System::EventHandler(this, &Dashboard::SCAddCategory_Click);
		this->SCAddSupplier->Click += gcnew System::EventHandler(this, &Dashboard::SCAddSupplier_Click);
		this->SCAddProduct->Click += gcnew System::EventHandler(this, &Dashboard::SCAddProduct_Click);
		*/

	};
}