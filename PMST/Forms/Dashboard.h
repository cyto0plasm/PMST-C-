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
#include "../Forms/Profile.h"
#include "../Forms/calculator.h"
#include "../Forms/Helper/PieChartPanel.h"
#include "../Helpers/UIHelper.h"
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
		  ProductController^ productController;
		  PieChartPanel^ pieChart;
	private:
		//DATABASE
		UserModel^ currentUser;
		PharmacyModel^ currentPharmacy;
		String^ categoryName;
		
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

	private: System::Windows::Forms::DataGridView^ CashierTable;
	private: System::Windows::Forms::Panel^ ManageSaleContainer;
	private: System::Windows::Forms::Panel^ ManageSalePanel;


	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ RefreshInvoice;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Label^ payLab;
	private: System::Windows::Forms::FlowLayoutPanel^ payFeildContainer;
	private: System::Windows::Forms::TextBox^ payFeild;

	private: System::Windows::Forms::Panel^ panel15;
	private: System::Windows::Forms::Label^ label14;

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
private: System::Windows::Forms::Panel^ headerPanel;

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


		System::Windows::Forms::Panel^ CardPanelHead;
		System::Windows::Forms::Label^ CardPanelTitle;
		System::Windows::Forms::FlowLayoutPanel^ CategoryTableContainer;
		System::Windows::Forms::Panel^ CategoryTableTitlePanel;
		System::Windows::Forms::Label^ CategoryTableTitle;
		System::Windows::Forms::DataGridView^ CategoryTable;


		System::Windows::Forms::Button^ cashier;
private: System::Windows::Forms::SplitContainer^ splitContainer1;





private: System::Windows::Forms::FlowLayoutPanel^ InvoiceHeaderContainer;
private: System::Windows::Forms::Panel^ InvoiceHeaderTitlepanel;
private: System::Windows::Forms::Button^ showHideInvoiceTable;

private: System::Windows::Forms::Label^ InvoiceHeaderTitleLab;
private: System::Windows::Forms::FlowLayoutPanel^ InvoiceHeaderTableContainer;
private: System::Windows::Forms::Panel^ SearchInvoiceHeaderPanel;
private: System::Windows::Forms::FlowLayoutPanel^ SearchInvoiceHeaderContainer;
private: System::Windows::Forms::TextBox^ SearchInvoiceHeaderFeild;

private: System::Windows::Forms::DataGridView^ InvoiceHeaderTable;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ InvoiceHeaderId;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ InvoiceTotalPrice;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ InvoiceHeaderCreatedAt;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ InvoiceHeaderUpdatedAt;

private: System::Windows::Forms::Panel^ InvoiceDetailsContainer;
private: System::Windows::Forms::Panel^ InvoiceDetailsPanel;
private: System::Windows::Forms::Panel^ panel11;
private: System::Windows::Forms::Button^ showHideInvoiceDetails;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Panel^ ChartPanel;
private: System::Windows::Forms::Button^ PrintToPdfBtnprod;

private: System::Windows::Forms::Button^ exportToexcelBtnProd;

private: System::Windows::Forms::Button^ PrintToPdfBtnCat;

private: System::Windows::Forms::Button^ exportToexcelBtnCat;

private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Button^ PrintToPdfBtnSup;
private: System::Windows::Forms::Button^ exportToexcelBtnSup;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::Button^ PrintToPdfBtnInv;
private: System::Windows::Forms::Button^ exportToexcelBtnInv;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::Label^ label9;


























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
		public:System::Void LoadProfitSummaries();
		Bitmap^ ResizeImage(Image^ image, int maxWidth, int maxHeight);
		String^ FormatCustomDate(DateTime dt);
		//HOME SCREEN
		private: System::Void SCAddCategory_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void SCAddSupplier_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void SCAddProduct_Click(System::Object^ sender, System::EventArgs^ e);
			   void InitializeChart();
			   void LoadChartData(int pharmacyId);
		// Generic event handlers for all DataGridView controls
		Void DataGridView_CellMouseEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		Void DataGridView_CellMouseLeave(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
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
		/*System::Void recentSalesTable_CellMouseEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		System::Void recentSalesTable_CellMouseLeave(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		System::Void recentSalesTable_DataBindingComplete(System::Object^ sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs^ e);
		*///Cashier table 
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle61 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle62 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle64 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle65 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle63 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle66 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle67 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle69 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle70 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle68 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle71 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle72 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle74 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle75 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle73 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->headerPanel = (gcnew System::Windows::Forms::Panel());
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
			this->stockPanel = (gcnew System::Windows::Forms::Panel());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->InvoiceHeaderContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->InvoiceHeaderTitlepanel = (gcnew System::Windows::Forms::Panel());
			this->PrintToPdfBtnInv = (gcnew System::Windows::Forms::Button());
			this->exportToexcelBtnInv = (gcnew System::Windows::Forms::Button());
			this->showHideInvoiceTable = (gcnew System::Windows::Forms::Button());
			this->InvoiceHeaderTitleLab = (gcnew System::Windows::Forms::Label());
			this->InvoiceHeaderTableContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SearchInvoiceHeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->SearchInvoiceHeaderContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SearchInvoiceHeaderFeild = (gcnew System::Windows::Forms::TextBox());
			this->InvoiceHeaderTable = (gcnew System::Windows::Forms::DataGridView());
			this->InvoiceHeaderId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->InvoiceTotalPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->InvoiceHeaderCreatedAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->InvoiceHeaderUpdatedAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->InvoiceDetailsContainer = (gcnew System::Windows::Forms::Panel());
			this->InvoiceDetailsPanel = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->showHideInvoiceDetails = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->categoryPanel = (gcnew System::Windows::Forms::Panel());
			this->CategoryTableContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->CategoryTableTitlePanel = (gcnew System::Windows::Forms::Panel());
			this->CategoryTableTitle = (gcnew System::Windows::Forms::Label());
			this->CategoryTablePanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SearchPanelContainer = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->CategorySearchPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->CategorySearch = (gcnew System::Windows::Forms::TextBox());
			this->CategoryTable = (gcnew System::Windows::Forms::DataGridView());
			this->categoryColId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->categoryColName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->categoryColDescription = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->categoryColCreated_At = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->categoryColUpdated_At = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ManageCategoryPanel = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->PrintToPdfBtnCat = (gcnew System::Windows::Forms::Button());
			this->exportToexcelBtnCat = (gcnew System::Windows::Forms::Button());
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
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SupplierSearchPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SupplierSearch = (gcnew System::Windows::Forms::TextBox());
			this->SupplierTable = (gcnew System::Windows::Forms::DataGridView());
			this->SupplierColId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SupplierColName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SupplierColContactInfo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SupplierColCreated_At = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SupplierColUpdated_At = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ManageSupplierContainer = (gcnew System::Windows::Forms::Panel());
			this->ManageSupplierFormsPanel = (gcnew System::Windows::Forms::Panel());
			this->PrintToPdfBtnSup = (gcnew System::Windows::Forms::Button());
			this->exportToexcelBtnSup = (gcnew System::Windows::Forms::Button());
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
			this->PrintToPdfBtnprod = (gcnew System::Windows::Forms::Button());
			this->exportToexcelBtnProd = (gcnew System::Windows::Forms::Button());
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
			this->cashierPanel = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->CashierTablePanelContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->CashierTableTitlePanel = (gcnew System::Windows::Forms::Panel());
			this->CashierTableTitle = (gcnew System::Windows::Forms::Label());
			this->CashierTablePanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->CashierSearchProductPanel = (gcnew System::Windows::Forms::Panel());
			this->CashierSearchProductContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->CashierSearchProduct = (gcnew System::Windows::Forms::TextBox());
			this->CashierTable = (gcnew System::Windows::Forms::DataGridView());
			this->CashProductId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CashProductName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CashProductPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CashProductQuantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CashTotalProductPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ManageSaleContainer = (gcnew System::Windows::Forms::Panel());
			this->ManageSalePanel = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SearchSuggestionsList = (gcnew System::Windows::Forms::ListBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->PayInvoice = (gcnew System::Windows::Forms::Button());
			this->RefreshInvoice = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->TotalInvoiceLab = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->payLab = (gcnew System::Windows::Forms::Label());
			this->payFeildContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->payFeild = (gcnew System::Windows::Forms::TextBox());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->HomePanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->fastNav = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->totalSales = (gcnew System::Windows::Forms::Button());
			this->SCAddSupplier = (gcnew System::Windows::Forms::Button());
			this->SCAddCategory = (gcnew System::Windows::Forms::Button());
			this->SCAddProduct = (gcnew System::Windows::Forms::Button());
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
			this->ChartPanel = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->headerPanel->SuspendLayout();
			this->FooterPanel->SuspendLayout();
			this->RightPanel->SuspendLayout();
			this->NavPanel->SuspendLayout();
			this->UserPanel->SuspendLayout();
			this->CenterPanel->SuspendLayout();
			this->stockPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->InvoiceHeaderContainer->SuspendLayout();
			this->InvoiceHeaderTitlepanel->SuspendLayout();
			this->InvoiceHeaderTableContainer->SuspendLayout();
			this->SearchInvoiceHeaderPanel->SuspendLayout();
			this->SearchInvoiceHeaderContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InvoiceHeaderTable))->BeginInit();
			this->InvoiceDetailsContainer->SuspendLayout();
			this->panel11->SuspendLayout();
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
			this->cashierPanel->SuspendLayout();
			this->panel9->SuspendLayout();
			this->CashierTablePanelContainer->SuspendLayout();
			this->CashierTableTitlePanel->SuspendLayout();
			this->CashierTablePanel->SuspendLayout();
			this->CashierSearchProductPanel->SuspendLayout();
			this->CashierSearchProductContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CashierTable))->BeginInit();
			this->ManageSaleContainer->SuspendLayout();
			this->ManageSalePanel->SuspendLayout();
			this->panel10->SuspendLayout();
			this->payFeildContainer->SuspendLayout();
			this->panel15->SuspendLayout();
			this->HomePanel->SuspendLayout();
			this->fastNav->SuspendLayout();
			this->Cards->SuspendLayout();
			this->CardPanelHead->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel6->SuspendLayout();
			this->SuspendLayout();
			// 
			// headerPanel
			// 
			this->headerPanel->AccessibleName = L"headerPanel";
			this->headerPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->headerPanel->Controls->Add(this->minMax);
			this->headerPanel->Controls->Add(this->mimimizeBtn);
			this->headerPanel->Controls->Add(this->closeBtn);
			this->headerPanel->Controls->Add(this->logo);
			this->headerPanel->Controls->Add(this->label1);
			this->headerPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->headerPanel->Location = System::Drawing::Point(0, 0);
			this->headerPanel->Margin = System::Windows::Forms::Padding(4);
			this->headerPanel->Name = L"headerPanel";
			this->headerPanel->Size = System::Drawing::Size(1920, 84);
			this->headerPanel->TabIndex = 0;
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
			this->minMax->Location = System::Drawing::Point(1752, 14);
			this->minMax->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->minMax->Name = L"minMax";
			this->minMax->Size = System::Drawing::Size(71, 55);
			this->minMax->TabIndex = 3;
			this->minMax->UseVisualStyleBackColor = false;
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
			this->mimimizeBtn->Location = System::Drawing::Point(1688, 20);
			this->mimimizeBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->mimimizeBtn->Name = L"mimimizeBtn";
			this->mimimizeBtn->Size = System::Drawing::Size(56, 42);
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
			this->closeBtn->Location = System::Drawing::Point(1831, 11);
			this->closeBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(75, 61);
			this->closeBtn->TabIndex = 3;
			this->closeBtn->UseVisualStyleBackColor = false;
			this->closeBtn->Click += gcnew System::EventHandler(this, &Dashboard::closeBtn_Click);
			// 
			// logo
			// 
			this->logo->AutoSize = true;
			this->logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logo.Image")));
			this->logo->Location = System::Drawing::Point(11, 5);
			this->logo->Margin = System::Windows::Forms::Padding(5, 5, 2, 0);
			this->logo->MaximumSize = System::Drawing::Size(0, 80);
			this->logo->MinimumSize = System::Drawing::Size(250, 20);
			this->logo->Name = L"logo";
			this->logo->Padding = System::Windows::Forms::Padding(40, 35, 70, 35);
			this->logo->Size = System::Drawing::Size(250, 80);
			this->logo->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AccessibleName = L"AppTitle";
			this->label1->AutoSize = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(841, 22);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"مدير الصيدلية";
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
			this->FooterPanel->Location = System::Drawing::Point(0, 947);
			this->FooterPanel->Margin = System::Windows::Forms::Padding(4);
			this->FooterPanel->Name = L"FooterPanel";
			this->FooterPanel->Size = System::Drawing::Size(1920, 108);
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
			this->label4->Location = System::Drawing::Point(9, 48);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(192, 25);
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
			this->label3->Location = System::Drawing::Point(2, 19);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(313, 25);
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
			this->pharmacyName->Location = System::Drawing::Point(1666, 35);
			this->pharmacyName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->pharmacyName->Name = L"pharmacyName";
			this->pharmacyName->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->pharmacyName->Size = System::Drawing::Size(0, 38);
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
			this->pharmacyNameLabel->Location = System::Drawing::Point(1708, 38);
			this->pharmacyNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->pharmacyNameLabel->Name = L"pharmacyNameLabel";
			this->pharmacyNameLabel->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->pharmacyNameLabel->Size = System::Drawing::Size(0, 38);
			this->pharmacyNameLabel->TabIndex = 0;
			// 
			// RightPanel
			// 
			this->RightPanel->AccessibleName = L"RightPanel";
			this->RightPanel->Controls->Add(this->NavPanel);
			this->RightPanel->Controls->Add(this->UserPanel);
			this->RightPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->RightPanel->Location = System::Drawing::Point(1660, 84);
			this->RightPanel->Margin = System::Windows::Forms::Padding(4);
			this->RightPanel->MaximumSize = System::Drawing::Size(260, 690);
			this->RightPanel->MinimumSize = System::Drawing::Size(70, 690);
			this->RightPanel->Name = L"RightPanel";
			this->RightPanel->Size = System::Drawing::Size(260, 690);
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
			this->NavPanel->Location = System::Drawing::Point(0, 146);
			this->NavPanel->Margin = System::Windows::Forms::Padding(4);
			this->NavPanel->MaximumSize = System::Drawing::Size(294, 711);
			this->NavPanel->Name = L"NavPanel";
			this->NavPanel->Size = System::Drawing::Size(260, 544);
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
			this->homeBtn->Location = System::Drawing::Point(4, 6);
			this->homeBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->homeBtn->MaximumSize = System::Drawing::Size(250, 80);
			this->homeBtn->MinimumSize = System::Drawing::Size(80, 80);
			this->homeBtn->Name = L"homeBtn";
			this->homeBtn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			this->homeBtn->Size = System::Drawing::Size(250, 80);
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
			this->cashierBtn->Location = System::Drawing::Point(4, 96);
			this->cashierBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->cashierBtn->MaximumSize = System::Drawing::Size(250, 80);
			this->cashierBtn->MinimumSize = System::Drawing::Size(80, 80);
			this->cashierBtn->Name = L"cashierBtn";
			this->cashierBtn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			this->cashierBtn->Size = System::Drawing::Size(250, 80);
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
			this->productBtn->Location = System::Drawing::Point(4, 186);
			this->productBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->productBtn->MaximumSize = System::Drawing::Size(250, 80);
			this->productBtn->MinimumSize = System::Drawing::Size(80, 80);
			this->productBtn->Name = L"productBtn";
			this->productBtn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			this->productBtn->Size = System::Drawing::Size(250, 80);
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
			this->categoryBtn->Location = System::Drawing::Point(4, 276);
			this->categoryBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->categoryBtn->MaximumSize = System::Drawing::Size(250, 80);
			this->categoryBtn->MinimumSize = System::Drawing::Size(80, 80);
			this->categoryBtn->Name = L"categoryBtn";
			this->categoryBtn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			this->categoryBtn->Size = System::Drawing::Size(250, 80);
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
			this->supplierBtn->Location = System::Drawing::Point(4, 366);
			this->supplierBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->supplierBtn->MaximumSize = System::Drawing::Size(250, 80);
			this->supplierBtn->MinimumSize = System::Drawing::Size(80, 80);
			this->supplierBtn->Name = L"supplierBtn";
			this->supplierBtn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			this->supplierBtn->Size = System::Drawing::Size(250, 80);
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
			this->stockBtn->Location = System::Drawing::Point(4, 456);
			this->stockBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->stockBtn->MaximumSize = System::Drawing::Size(250, 80);
			this->stockBtn->MinimumSize = System::Drawing::Size(80, 80);
			this->stockBtn->Name = L"stockBtn";
			this->stockBtn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			this->stockBtn->Size = System::Drawing::Size(250, 80);
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
			this->UserPanel->Margin = System::Windows::Forms::Padding(4);
			this->UserPanel->Name = L"UserPanel";
			this->UserPanel->Size = System::Drawing::Size(260, 146);
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
			this->userBtn->Location = System::Drawing::Point(5, 42);
			this->userBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->userBtn->MaximumSize = System::Drawing::Size(250, 96);
			this->userBtn->MinimumSize = System::Drawing::Size(80, 96);
			this->userBtn->Name = L"userBtn";
			this->userBtn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			this->userBtn->Size = System::Drawing::Size(250, 96);
			this->userBtn->TabIndex = 5;
			this->userBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->userBtn->UseVisualStyleBackColor = false;
			this->userBtn->Click += gcnew System::EventHandler(this, &Dashboard::userBtn_Click);
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
			this->collaps->Location = System::Drawing::Point(19, 10);
			this->collaps->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->collaps->Name = L"collaps";
			this->collaps->Size = System::Drawing::Size(30, 30);
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
			this->expandBtn->Location = System::Drawing::Point(19, 10);
			this->expandBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->expandBtn->Name = L"expandBtn";
			this->expandBtn->Size = System::Drawing::Size(30, 30);
			this->expandBtn->TabIndex = 3;
			this->expandBtn->UseVisualStyleBackColor = false;
			this->expandBtn->Click += gcnew System::EventHandler(this, &Dashboard::collaps_Click);
			// 
			// CenterPanel
			// 
			this->CenterPanel->AccessibleName = L"Home";
			this->CenterPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CenterPanel->Controls->Add(this->HomePanel);
			this->CenterPanel->Controls->Add(this->cashierPanel);
			this->CenterPanel->Controls->Add(this->productPanel);
			this->CenterPanel->Controls->Add(this->categoryPanel);
			this->CenterPanel->Controls->Add(this->supplierPanel);
			this->CenterPanel->Controls->Add(this->stockPanel);
			this->CenterPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CenterPanel->Location = System::Drawing::Point(0, 84);
			this->CenterPanel->Margin = System::Windows::Forms::Padding(4);
			this->CenterPanel->Name = L"CenterPanel";
			this->CenterPanel->Size = System::Drawing::Size(1660, 863);
			this->CenterPanel->TabIndex = 3;
			// 
			// stockPanel
			// 
			this->stockPanel->Controls->Add(this->splitContainer1);
			this->stockPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->stockPanel->Location = System::Drawing::Point(0, 0);
			this->stockPanel->Margin = System::Windows::Forms::Padding(2);
			this->stockPanel->Name = L"stockPanel";
			this->stockPanel->Size = System::Drawing::Size(1658, 861);
			this->stockPanel->TabIndex = 5;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->InvoiceHeaderContainer);
			this->splitContainer1->Panel1MinSize = 500;
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->InvoiceDetailsContainer);
			this->splitContainer1->Panel2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->splitContainer1->Panel2MinSize = 400;
			this->splitContainer1->Size = System::Drawing::Size(1658, 861);
			this->splitContainer1->SplitterDistance = 1050;
			this->splitContainer1->TabIndex = 0;
			// 
			// InvoiceHeaderContainer
			// 
			this->InvoiceHeaderContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->InvoiceHeaderContainer->Controls->Add(this->InvoiceHeaderTitlepanel);
			this->InvoiceHeaderContainer->Controls->Add(this->InvoiceHeaderTableContainer);
			this->InvoiceHeaderContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->InvoiceHeaderContainer->FlowDirection = System::Windows::Forms::FlowDirection::RightToLeft;
			this->InvoiceHeaderContainer->Location = System::Drawing::Point(0, 0);
			this->InvoiceHeaderContainer->Margin = System::Windows::Forms::Padding(5, 10, 5, 10);
			this->InvoiceHeaderContainer->MaximumSize = System::Drawing::Size(1500, 864);
			this->InvoiceHeaderContainer->MinimumSize = System::Drawing::Size(500, 600);
			this->InvoiceHeaderContainer->Name = L"InvoiceHeaderContainer";
			this->InvoiceHeaderContainer->Size = System::Drawing::Size(1050, 861);
			this->InvoiceHeaderContainer->TabIndex = 13;
			// 
			// InvoiceHeaderTitlepanel
			// 
			this->InvoiceHeaderTitlepanel->AccessibleName = L"CashierTableTitlePanel";
			this->InvoiceHeaderTitlepanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->InvoiceHeaderTitlepanel->Controls->Add(this->PrintToPdfBtnInv);
			this->InvoiceHeaderTitlepanel->Controls->Add(this->exportToexcelBtnInv);
			this->InvoiceHeaderTitlepanel->Controls->Add(this->showHideInvoiceTable);
			this->InvoiceHeaderTitlepanel->Controls->Add(this->InvoiceHeaderTitleLab);
			this->InvoiceHeaderTitlepanel->Location = System::Drawing::Point(-84, 2);
			this->InvoiceHeaderTitlepanel->Margin = System::Windows::Forms::Padding(2);
			this->InvoiceHeaderTitlepanel->Name = L"InvoiceHeaderTitlepanel";
			this->InvoiceHeaderTitlepanel->Size = System::Drawing::Size(1130, 80);
			this->InvoiceHeaderTitlepanel->TabIndex = 9;
			// 
			// PrintToPdfBtnInv
			// 
			this->PrintToPdfBtnInv->AccessibleName = L"PrintToPdfBtnInv";
			this->PrintToPdfBtnInv->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->PrintToPdfBtnInv->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->PrintToPdfBtnInv->FlatAppearance->BorderSize = 0;
			this->PrintToPdfBtnInv->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PrintToPdfBtnInv->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PrintToPdfBtnInv->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->PrintToPdfBtnInv->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PrintToPdfBtnInv.Image")));
			this->PrintToPdfBtnInv->Location = System::Drawing::Point(964, 9);
			this->PrintToPdfBtnInv->Margin = System::Windows::Forms::Padding(2);
			this->PrintToPdfBtnInv->MaximumSize = System::Drawing::Size(75, 75);
			this->PrintToPdfBtnInv->Name = L"PrintToPdfBtnInv";
			this->PrintToPdfBtnInv->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->PrintToPdfBtnInv->Size = System::Drawing::Size(75, 65);
			this->PrintToPdfBtnInv->TabIndex = 48;
			this->PrintToPdfBtnInv->UseVisualStyleBackColor = false;
			this->PrintToPdfBtnInv->Click += gcnew System::EventHandler(this, &Dashboard::PrintToPdfBtnInv_Click);
			// 
			// exportToexcelBtnInv
			// 
			this->exportToexcelBtnInv->AccessibleName = L"exportToexcelBtnInv";
			this->exportToexcelBtnInv->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->exportToexcelBtnInv->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->exportToexcelBtnInv->FlatAppearance->BorderSize = 0;
			this->exportToexcelBtnInv->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exportToexcelBtnInv->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exportToexcelBtnInv->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->exportToexcelBtnInv->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exportToexcelBtnInv.Image")));
			this->exportToexcelBtnInv->Location = System::Drawing::Point(885, 9);
			this->exportToexcelBtnInv->Margin = System::Windows::Forms::Padding(2);
			this->exportToexcelBtnInv->MaximumSize = System::Drawing::Size(75, 75);
			this->exportToexcelBtnInv->Name = L"exportToexcelBtnInv";
			this->exportToexcelBtnInv->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->exportToexcelBtnInv->Size = System::Drawing::Size(75, 65);
			this->exportToexcelBtnInv->TabIndex = 49;
			this->exportToexcelBtnInv->UseVisualStyleBackColor = false;
			this->exportToexcelBtnInv->Click += gcnew System::EventHandler(this, &Dashboard::exportToexcelBtnInv_Click);
			// 
			// showHideInvoiceTable
			// 
			this->showHideInvoiceTable->AccessibleName = L"showHideInvoiceTable";
			this->showHideInvoiceTable->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->showHideInvoiceTable->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->showHideInvoiceTable->FlatAppearance->BorderSize = 0;
			this->showHideInvoiceTable->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->showHideInvoiceTable->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->showHideInvoiceTable->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->showHideInvoiceTable->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"showHideInvoiceTable.Image")));
			this->showHideInvoiceTable->Location = System::Drawing::Point(1045, 9);
			this->showHideInvoiceTable->Margin = System::Windows::Forms::Padding(2);
			this->showHideInvoiceTable->MaximumSize = System::Drawing::Size(75, 75);
			this->showHideInvoiceTable->Name = L"showHideInvoiceTable";
			this->showHideInvoiceTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->showHideInvoiceTable->Size = System::Drawing::Size(75, 65);
			this->showHideInvoiceTable->TabIndex = 47;
			this->showHideInvoiceTable->UseVisualStyleBackColor = false;
			this->showHideInvoiceTable->Click += gcnew System::EventHandler(this, &Dashboard::showHideInvoiceTable_Click);
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
			this->InvoiceHeaderTitleLab->Location = System::Drawing::Point(515, 21);
			this->InvoiceHeaderTitleLab->Margin = System::Windows::Forms::Padding(100, 15, 50, 10);
			this->InvoiceHeaderTitleLab->Name = L"InvoiceHeaderTitleLab";
			this->InvoiceHeaderTitleLab->Size = System::Drawing::Size(114, 34);
			this->InvoiceHeaderTitleLab->TabIndex = 7;
			this->InvoiceHeaderTitleLab->Text = L"فواتيرك";
			this->InvoiceHeaderTitleLab->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// InvoiceHeaderTableContainer
			// 
			this->InvoiceHeaderTableContainer->AccessibleName = L"InvoiceHeaderTableContainer";
			this->InvoiceHeaderTableContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->InvoiceHeaderTableContainer->Controls->Add(this->SearchInvoiceHeaderPanel);
			this->InvoiceHeaderTableContainer->Controls->Add(this->InvoiceHeaderTable);
			this->InvoiceHeaderTableContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->InvoiceHeaderTableContainer->Location = System::Drawing::Point(-84, 86);
			this->InvoiceHeaderTableContainer->Margin = System::Windows::Forms::Padding(2);
			this->InvoiceHeaderTableContainer->MaximumSize = System::Drawing::Size(1300, 774);
			this->InvoiceHeaderTableContainer->MinimumSize = System::Drawing::Size(600, 774);
			this->InvoiceHeaderTableContainer->Name = L"InvoiceHeaderTableContainer";
			this->InvoiceHeaderTableContainer->Size = System::Drawing::Size(1130, 774);
			this->InvoiceHeaderTableContainer->TabIndex = 14;
			// 
			// SearchInvoiceHeaderPanel
			// 
			this->SearchInvoiceHeaderPanel->AccessibleName = L"CashierSearchProductPanel";
			this->SearchInvoiceHeaderPanel->Controls->Add(this->label9);
			this->SearchInvoiceHeaderPanel->Controls->Add(this->SearchInvoiceHeaderContainer);
			this->SearchInvoiceHeaderPanel->Location = System::Drawing::Point(2, 2);
			this->SearchInvoiceHeaderPanel->Margin = System::Windows::Forms::Padding(2);
			this->SearchInvoiceHeaderPanel->Name = L"SearchInvoiceHeaderPanel";
			this->SearchInvoiceHeaderPanel->Size = System::Drawing::Size(1128, 84);
			this->SearchInvoiceHeaderPanel->TabIndex = 14;
			// 
			// SearchInvoiceHeaderContainer
			// 
			this->SearchInvoiceHeaderContainer->AccessibleName = L"CashierSearchProductContainer";
			this->SearchInvoiceHeaderContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SearchInvoiceHeaderContainer->Controls->Add(this->SearchInvoiceHeaderFeild);
			this->SearchInvoiceHeaderContainer->Location = System::Drawing::Point(8, 15);
			this->SearchInvoiceHeaderContainer->Margin = System::Windows::Forms::Padding(4);
			this->SearchInvoiceHeaderContainer->Name = L"SearchInvoiceHeaderContainer";
			this->SearchInvoiceHeaderContainer->Padding = System::Windows::Forms::Padding(10);
			this->SearchInvoiceHeaderContainer->Size = System::Drawing::Size(989, 50);
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
			this->SearchInvoiceHeaderFeild->Location = System::Drawing::Point(10, 10);
			this->SearchInvoiceHeaderFeild->Margin = System::Windows::Forms::Padding(0);
			this->SearchInvoiceHeaderFeild->MaxLength = 50;
			this->SearchInvoiceHeaderFeild->Multiline = true;
			this->SearchInvoiceHeaderFeild->Name = L"SearchInvoiceHeaderFeild";
			this->SearchInvoiceHeaderFeild->Size = System::Drawing::Size(965, 30);
			this->SearchInvoiceHeaderFeild->TabIndex = 5;
			this->SearchInvoiceHeaderFeild->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// InvoiceHeaderTable
			// 
			this->InvoiceHeaderTable->AccessibleName = L"InvoiceHeaderTable";
			this->InvoiceHeaderTable->AllowUserToAddRows = false;
			this->InvoiceHeaderTable->AllowUserToDeleteRows = false;
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
			this->InvoiceHeaderTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle51;
			this->InvoiceHeaderTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->InvoiceHeaderTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->InvoiceHeaderTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->InvoiceHeaderTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
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
			this->InvoiceHeaderTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle52;
			this->InvoiceHeaderTable->ColumnHeadersHeight = 50;
			this->InvoiceHeaderTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->InvoiceHeaderTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->InvoiceHeaderId,
					this->InvoiceTotalPrice, this->InvoiceHeaderCreatedAt, this->InvoiceHeaderUpdatedAt
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
			this->InvoiceHeaderTable->DefaultCellStyle = dataGridViewCellStyle54;
			this->InvoiceHeaderTable->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->InvoiceHeaderTable->EnableHeadersVisualStyles = false;
			this->InvoiceHeaderTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->InvoiceHeaderTable->Location = System::Drawing::Point(10, 98);
			this->InvoiceHeaderTable->Margin = System::Windows::Forms::Padding(10);
			this->InvoiceHeaderTable->MaximumSize = System::Drawing::Size(1500, 665);
			this->InvoiceHeaderTable->MinimumSize = System::Drawing::Size(500, 665);
			this->InvoiceHeaderTable->MultiSelect = false;
			this->InvoiceHeaderTable->Name = L"InvoiceHeaderTable";
			this->InvoiceHeaderTable->ReadOnly = true;
			this->InvoiceHeaderTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->InvoiceHeaderTable->RowHeadersVisible = false;
			this->InvoiceHeaderTable->RowHeadersWidth = 51;
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
			this->InvoiceHeaderTable->RowsDefaultCellStyle = dataGridViewCellStyle55;
			this->InvoiceHeaderTable->RowTemplate->Height = 40;
			this->InvoiceHeaderTable->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->InvoiceHeaderTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->InvoiceHeaderTable->Size = System::Drawing::Size(1120, 665);
			this->InvoiceHeaderTable->StandardTab = true;
			this->InvoiceHeaderTable->TabIndex = 0;
			this->InvoiceHeaderTable->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::InvoiceHeaderTable_CellClick);
			this->InvoiceHeaderTable->CellMouseEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::DataGridView_CellMouseEnter);
			this->InvoiceHeaderTable->CellMouseLeave += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::DataGridView_CellMouseLeave);
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
			dataGridViewCellStyle53->Padding = System::Windows::Forms::Padding(8);
			this->InvoiceTotalPrice->DefaultCellStyle = dataGridViewCellStyle53;
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
			this->InvoiceHeaderUpdatedAt->MinimumWidth = 6;
			this->InvoiceHeaderUpdatedAt->Name = L"InvoiceHeaderUpdatedAt";
			this->InvoiceHeaderUpdatedAt->ReadOnly = true;
			// 
			// InvoiceDetailsContainer
			// 
			this->InvoiceDetailsContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->InvoiceDetailsContainer->Controls->Add(this->InvoiceDetailsPanel);
			this->InvoiceDetailsContainer->Controls->Add(this->panel11);
			this->InvoiceDetailsContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->InvoiceDetailsContainer->Location = System::Drawing::Point(0, 0);
			this->InvoiceDetailsContainer->Margin = System::Windows::Forms::Padding(0);
			this->InvoiceDetailsContainer->MaximumSize = System::Drawing::Size(800, 861);
			this->InvoiceDetailsContainer->MinimumSize = System::Drawing::Size(400, 600);
			this->InvoiceDetailsContainer->Name = L"InvoiceDetailsContainer";
			this->InvoiceDetailsContainer->Size = System::Drawing::Size(604, 861);
			this->InvoiceDetailsContainer->TabIndex = 15;
			// 
			// InvoiceDetailsPanel
			// 
			this->InvoiceDetailsPanel->AccessibleName = L"InvoiceDetailsPanel";
			this->InvoiceDetailsPanel->AutoScroll = true;
			this->InvoiceDetailsPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->InvoiceDetailsPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->InvoiceDetailsPanel->Location = System::Drawing::Point(0, 80);
			this->InvoiceDetailsPanel->Margin = System::Windows::Forms::Padding(0);
			this->InvoiceDetailsPanel->MaximumSize = System::Drawing::Size(465, 770);
			this->InvoiceDetailsPanel->MinimumSize = System::Drawing::Size(300, 0);
			this->InvoiceDetailsPanel->Name = L"InvoiceDetailsPanel";
			this->InvoiceDetailsPanel->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->InvoiceDetailsPanel->Size = System::Drawing::Size(465, 770);
			this->InvoiceDetailsPanel->TabIndex = 12;
			// 
			// panel11
			// 
			this->panel11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel11->Controls->Add(this->showHideInvoiceDetails);
			this->panel11->Controls->Add(this->label6);
			this->panel11->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel11->Location = System::Drawing::Point(0, 0);
			this->panel11->Margin = System::Windows::Forms::Padding(10);
			this->panel11->MaximumSize = System::Drawing::Size(465, 80);
			this->panel11->MinimumSize = System::Drawing::Size(300, 80);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(465, 80);
			this->panel11->TabIndex = 13;
			// 
			// showHideInvoiceDetails
			// 
			this->showHideInvoiceDetails->AccessibleName = L"showHideInvoiceDetails";
			this->showHideInvoiceDetails->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->showHideInvoiceDetails->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->showHideInvoiceDetails->FlatAppearance->BorderSize = 0;
			this->showHideInvoiceDetails->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->showHideInvoiceDetails->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->showHideInvoiceDetails->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->showHideInvoiceDetails->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"showHideInvoiceDetails.Image")));
			this->showHideInvoiceDetails->Location = System::Drawing::Point(392, 8);
			this->showHideInvoiceDetails->Margin = System::Windows::Forms::Padding(2);
			this->showHideInvoiceDetails->MaximumSize = System::Drawing::Size(75, 75);
			this->showHideInvoiceDetails->Name = L"showHideInvoiceDetails";
			this->showHideInvoiceDetails->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->showHideInvoiceDetails->Size = System::Drawing::Size(65, 65);
			this->showHideInvoiceDetails->TabIndex = 47;
			this->showHideInvoiceDetails->UseVisualStyleBackColor = false;
			this->showHideInvoiceDetails->Click += gcnew System::EventHandler(this, &Dashboard::showHideInvoiceDetails_Click);
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
			this->label6->Location = System::Drawing::Point(106, 21);
			this->label6->Margin = System::Windows::Forms::Padding(100, 15, 50, 10);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(218, 34);
			this->label6->TabIndex = 7;
			this->label6->Text = L"تفاصيل الفاتورة";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// categoryPanel
			// 
			this->categoryPanel->Controls->Add(this->CategoryTableContainer);
			this->categoryPanel->Controls->Add(this->ManageCategoryPanel);
			this->categoryPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->categoryPanel->Location = System::Drawing::Point(0, 0);
			this->categoryPanel->Margin = System::Windows::Forms::Padding(2);
			this->categoryPanel->Name = L"categoryPanel";
			this->categoryPanel->Size = System::Drawing::Size(1658, 861);
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
			this->CategoryTableContainer->Margin = System::Windows::Forms::Padding(5, 10, 5, 10);
			this->CategoryTableContainer->Name = L"CategoryTableContainer";
			this->CategoryTableContainer->Size = System::Drawing::Size(1177, 861);
			this->CategoryTableContainer->TabIndex = 3;
			// 
			// CategoryTableTitlePanel
			// 
			this->CategoryTableTitlePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CategoryTableTitlePanel->Controls->Add(this->CategoryTableTitle);
			this->CategoryTableTitlePanel->Location = System::Drawing::Point(3, 2);
			this->CategoryTableTitlePanel->Margin = System::Windows::Forms::Padding(2);
			this->CategoryTableTitlePanel->Name = L"CategoryTableTitlePanel";
			this->CategoryTableTitlePanel->Size = System::Drawing::Size(1170, 80);
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
			this->CategoryTableTitle->Location = System::Drawing::Point(475, 21);
			this->CategoryTableTitle->Margin = System::Windows::Forms::Padding(100, 15, 50, 10);
			this->CategoryTableTitle->Name = L"CategoryTableTitle";
			this->CategoryTableTitle->Size = System::Drawing::Size(201, 34);
			this->CategoryTableTitle->TabIndex = 7;
			this->CategoryTableTitle->Text = L"جدول الاصناف";
			this->CategoryTableTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CategoryTablePanel
			// 
			this->CategoryTablePanel->AccessibleName = L"CategoryTablePanel";
			this->CategoryTablePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CategoryTablePanel->Controls->Add(this->SearchPanelContainer);
			this->CategoryTablePanel->Controls->Add(this->CategoryTable);
			this->CategoryTablePanel->Location = System::Drawing::Point(3, 86);
			this->CategoryTablePanel->Margin = System::Windows::Forms::Padding(2);
			this->CategoryTablePanel->Name = L"CategoryTablePanel";
			this->CategoryTablePanel->Size = System::Drawing::Size(1170, 774);
			this->CategoryTablePanel->TabIndex = 13;
			// 
			// SearchPanelContainer
			// 
			this->SearchPanelContainer->Controls->Add(this->label7);
			this->SearchPanelContainer->Controls->Add(this->CategorySearchPanel);
			this->SearchPanelContainer->Location = System::Drawing::Point(2, 2);
			this->SearchPanelContainer->Margin = System::Windows::Forms::Padding(2);
			this->SearchPanelContainer->Name = L"SearchPanelContainer";
			this->SearchPanelContainer->Size = System::Drawing::Size(1166, 84);
			this->SearchPanelContainer->TabIndex = 14;
			// 
			// label7
			// 
			this->label7->AccessibleName = L"catSearchLab";
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label7.Image")));
			this->label7->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label7->Location = System::Drawing::Point(1038, 11);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->MinimumSize = System::Drawing::Size(110, 60);
			this->label7->Name = L"label7";
			this->label7->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label7->Size = System::Drawing::Size(110, 60);
			this->label7->TabIndex = 14;
			this->label7->Text = L"البحث";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// CategorySearchPanel
			// 
			this->CategorySearchPanel->AccessibleName = L"CategorySearchPanel";
			this->CategorySearchPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CategorySearchPanel->Controls->Add(this->CategorySearch);
			this->CategorySearchPanel->Location = System::Drawing::Point(13, 15);
			this->CategorySearchPanel->Margin = System::Windows::Forms::Padding(4);
			this->CategorySearchPanel->Name = L"CategorySearchPanel";
			this->CategorySearchPanel->Padding = System::Windows::Forms::Padding(10);
			this->CategorySearchPanel->Size = System::Drawing::Size(995, 50);
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
			this->CategorySearch->Location = System::Drawing::Point(10, 10);
			this->CategorySearch->Margin = System::Windows::Forms::Padding(0);
			this->CategorySearch->MaxLength = 50;
			this->CategorySearch->Multiline = true;
			this->CategorySearch->Name = L"CategorySearch";
			this->CategorySearch->Size = System::Drawing::Size(966, 30);
			this->CategorySearch->TabIndex = 5;
			this->CategorySearch->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->CategorySearch->TextChanged += gcnew System::EventHandler(this, &Dashboard::CategorySearch_TextChanged);
			// 
			// CategoryTable
			// 
			this->CategoryTable->AccessibleName = L"CategoryTable";
			this->CategoryTable->AllowUserToAddRows = false;
			this->CategoryTable->AllowUserToDeleteRows = false;
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
			this->CategoryTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle56;
			this->CategoryTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->CategoryTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->CategoryTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->CategoryTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
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
			this->CategoryTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle57;
			this->CategoryTable->ColumnHeadersHeight = 50;
			this->CategoryTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->CategoryTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->categoryColId,
					this->categoryColName, this->categoryColDescription, this->categoryColCreated_At, this->categoryColUpdated_At
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
			this->CategoryTable->DefaultCellStyle = dataGridViewCellStyle59;
			this->CategoryTable->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->CategoryTable->EnableHeadersVisualStyles = false;
			this->CategoryTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->CategoryTable->Location = System::Drawing::Point(10, 98);
			this->CategoryTable->Margin = System::Windows::Forms::Padding(10);
			this->CategoryTable->MultiSelect = false;
			this->CategoryTable->Name = L"CategoryTable";
			this->CategoryTable->ReadOnly = true;
			this->CategoryTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->CategoryTable->RowHeadersVisible = false;
			this->CategoryTable->RowHeadersWidth = 51;
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
			this->CategoryTable->RowsDefaultCellStyle = dataGridViewCellStyle60;
			this->CategoryTable->RowTemplate->Height = 40;
			this->CategoryTable->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->CategoryTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->CategoryTable->Size = System::Drawing::Size(1159, 665);
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
			dataGridViewCellStyle58->Padding = System::Windows::Forms::Padding(8);
			this->categoryColDescription->DefaultCellStyle = dataGridViewCellStyle58;
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
			this->ManageCategoryPanel->Location = System::Drawing::Point(1188, 0);
			this->ManageCategoryPanel->Margin = System::Windows::Forms::Padding(5, 10, 5, 10);
			this->ManageCategoryPanel->Name = L"ManageCategoryPanel";
			this->ManageCategoryPanel->Size = System::Drawing::Size(470, 861);
			this->ManageCategoryPanel->TabIndex = 7;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->panel8->Controls->Add(this->PrintToPdfBtnCat);
			this->panel8->Controls->Add(this->exportToexcelBtnCat);
			this->panel8->Controls->Add(this->catNameLab);
			this->panel8->Controls->Add(this->delCat);
			this->panel8->Controls->Add(this->updateCat);
			this->panel8->Controls->Add(this->addCat);
			this->panel8->Controls->Add(this->catdescLab);
			this->panel8->Controls->Add(this->ContainerOfCatDesc);
			this->panel8->Controls->Add(this->ContainerOfCatName);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel8->Location = System::Drawing::Point(0, 80);
			this->panel8->Margin = System::Windows::Forms::Padding(2);
			this->panel8->MaximumSize = System::Drawing::Size(465, 770);
			this->panel8->MinimumSize = System::Drawing::Size(465, 770);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(465, 770);
			this->panel8->TabIndex = 14;
			// 
			// PrintToPdfBtnCat
			// 
			this->PrintToPdfBtnCat->AccessibleName = L"PrintToPdfBtnCat";
			this->PrintToPdfBtnCat->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->PrintToPdfBtnCat->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->PrintToPdfBtnCat->FlatAppearance->BorderSize = 0;
			this->PrintToPdfBtnCat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PrintToPdfBtnCat->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PrintToPdfBtnCat->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->PrintToPdfBtnCat->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PrintToPdfBtnCat.Image")));
			this->PrintToPdfBtnCat->Location = System::Drawing::Point(368, 330);
			this->PrintToPdfBtnCat->Margin = System::Windows::Forms::Padding(2);
			this->PrintToPdfBtnCat->MaximumSize = System::Drawing::Size(75, 75);
			this->PrintToPdfBtnCat->Name = L"PrintToPdfBtnCat";
			this->PrintToPdfBtnCat->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->PrintToPdfBtnCat->Size = System::Drawing::Size(75, 75);
			this->PrintToPdfBtnCat->TabIndex = 46;
			this->PrintToPdfBtnCat->UseVisualStyleBackColor = false;
			this->PrintToPdfBtnCat->Click += gcnew System::EventHandler(this, &Dashboard::PrintToPdfBtnCat_Click);
			// 
			// exportToexcelBtnCat
			// 
			this->exportToexcelBtnCat->AccessibleName = L"exportToexcelBtnCat";
			this->exportToexcelBtnCat->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->exportToexcelBtnCat->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->exportToexcelBtnCat->FlatAppearance->BorderSize = 0;
			this->exportToexcelBtnCat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exportToexcelBtnCat->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exportToexcelBtnCat->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->exportToexcelBtnCat->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exportToexcelBtnCat.Image")));
			this->exportToexcelBtnCat->Location = System::Drawing::Point(368, 257);
			this->exportToexcelBtnCat->Margin = System::Windows::Forms::Padding(2);
			this->exportToexcelBtnCat->MaximumSize = System::Drawing::Size(75, 75);
			this->exportToexcelBtnCat->Name = L"exportToexcelBtnCat";
			this->exportToexcelBtnCat->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->exportToexcelBtnCat->Size = System::Drawing::Size(75, 75);
			this->exportToexcelBtnCat->TabIndex = 47;
			this->exportToexcelBtnCat->UseVisualStyleBackColor = false;
			this->exportToexcelBtnCat->Click += gcnew System::EventHandler(this, &Dashboard::exportToexcelBtnCat_Click);
			// 
			// catNameLab
			// 
			this->catNameLab->AccessibleName = L"catNameLab";
			this->catNameLab->AutoSize = true;
			this->catNameLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->catNameLab->Location = System::Drawing::Point(218, 71);
			this->catNameLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->catNameLab->Name = L"catNameLab";
			this->catNameLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->catNameLab->Size = System::Drawing::Size(111, 28);
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
			this->delCat->Location = System::Drawing::Point(368, 155);
			this->delCat->Margin = System::Windows::Forms::Padding(2);
			this->delCat->MaximumSize = System::Drawing::Size(75, 75);
			this->delCat->MinimumSize = System::Drawing::Size(75, 75);
			this->delCat->Name = L"delCat";
			this->delCat->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->delCat->Size = System::Drawing::Size(75, 75);
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
			this->updateCat->Location = System::Drawing::Point(368, 85);
			this->updateCat->Margin = System::Windows::Forms::Padding(2);
			this->updateCat->MaximumSize = System::Drawing::Size(75, 75);
			this->updateCat->MinimumSize = System::Drawing::Size(75, 75);
			this->updateCat->Name = L"updateCat";
			this->updateCat->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->updateCat->Size = System::Drawing::Size(75, 75);
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
			this->addCat->Location = System::Drawing::Point(368, 13);
			this->addCat->Margin = System::Windows::Forms::Padding(2);
			this->addCat->MaximumSize = System::Drawing::Size(75, 75);
			this->addCat->MinimumSize = System::Drawing::Size(75, 75);
			this->addCat->Name = L"addCat";
			this->addCat->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->addCat->Size = System::Drawing::Size(75, 75);
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
			this->catdescLab->Location = System::Drawing::Point(204, 174);
			this->catdescLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->catdescLab->Name = L"catdescLab";
			this->catdescLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->catdescLab->Size = System::Drawing::Size(127, 28);
			this->catdescLab->TabIndex = 21;
			this->catdescLab->Text = L"وصف الصنف";
			// 
			// ContainerOfCatDesc
			// 
			this->ContainerOfCatDesc->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ContainerOfCatDesc->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ContainerOfCatDesc->Controls->Add(this->Catdesc);
			this->ContainerOfCatDesc->Location = System::Drawing::Point(25, 215);
			this->ContainerOfCatDesc->Margin = System::Windows::Forms::Padding(2);
			this->ContainerOfCatDesc->Name = L"ContainerOfCatDesc";
			this->ContainerOfCatDesc->Padding = System::Windows::Forms::Padding(10);
			this->ContainerOfCatDesc->Size = System::Drawing::Size(310, 90);
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
			this->Catdesc->Location = System::Drawing::Point(10, 10);
			this->Catdesc->Margin = System::Windows::Forms::Padding(0);
			this->Catdesc->MaxLength = 50;
			this->Catdesc->Multiline = true;
			this->Catdesc->Name = L"Catdesc";
			this->Catdesc->Size = System::Drawing::Size(290, 70);
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
			this->ContainerOfCatName->Location = System::Drawing::Point(25, 109);
			this->ContainerOfCatName->Margin = System::Windows::Forms::Padding(4);
			this->ContainerOfCatName->Name = L"ContainerOfCatName";
			this->ContainerOfCatName->Padding = System::Windows::Forms::Padding(10);
			this->ContainerOfCatName->Size = System::Drawing::Size(310, 50);
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
			this->CatName->Location = System::Drawing::Point(10, 10);
			this->CatName->Margin = System::Windows::Forms::Padding(0);
			this->CatName->MaxLength = 50;
			this->CatName->Multiline = true;
			this->CatName->Name = L"CatName";
			this->CatName->Size = System::Drawing::Size(290, 30);
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
			this->CategoryFormTitkePanel->Size = System::Drawing::Size(468, 80);
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
			this->catFormTitle->Location = System::Drawing::Point(135, 22);
			this->catFormTitle->Margin = System::Windows::Forms::Padding(100, 15, 50, 10);
			this->catFormTitle->Name = L"catFormTitle";
			this->catFormTitle->Size = System::Drawing::Size(188, 34);
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
			this->supplierPanel->Size = System::Drawing::Size(1658, 861);
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
			this->SupplierTableContainer->Margin = System::Windows::Forms::Padding(5, 10, 5, 10);
			this->SupplierTableContainer->Name = L"SupplierTableContainer";
			this->SupplierTableContainer->Size = System::Drawing::Size(1180, 861);
			this->SupplierTableContainer->TabIndex = 10;
			// 
			// SupplierTableTitlePanel
			// 
			this->SupplierTableTitlePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SupplierTableTitlePanel->Controls->Add(this->SupplierTableTitle);
			this->SupplierTableTitlePanel->Location = System::Drawing::Point(8, 2);
			this->SupplierTableTitlePanel->Margin = System::Windows::Forms::Padding(2);
			this->SupplierTableTitlePanel->Name = L"SupplierTableTitlePanel";
			this->SupplierTableTitlePanel->Size = System::Drawing::Size(1168, 79);
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
			this->SupplierTableTitle->Location = System::Drawing::Point(442, 19);
			this->SupplierTableTitle->Margin = System::Windows::Forms::Padding(100, 15, 50, 10);
			this->SupplierTableTitle->Name = L"SupplierTableTitle";
			this->SupplierTableTitle->Size = System::Drawing::Size(212, 34);
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
			this->SupplierTablePanel->Location = System::Drawing::Point(8, 85);
			this->SupplierTablePanel->Margin = System::Windows::Forms::Padding(2);
			this->SupplierTablePanel->Name = L"SupplierTablePanel";
			this->SupplierTablePanel->Size = System::Drawing::Size(1168, 774);
			this->SupplierTablePanel->TabIndex = 13;
			// 
			// SupplierSearchContainer
			// 
			this->SupplierSearchContainer->Controls->Add(this->label8);
			this->SupplierSearchContainer->Controls->Add(this->SupplierSearchPanel);
			this->SupplierSearchContainer->Location = System::Drawing::Point(2, 2);
			this->SupplierSearchContainer->Margin = System::Windows::Forms::Padding(2);
			this->SupplierSearchContainer->Name = L"SupplierSearchContainer";
			this->SupplierSearchContainer->Size = System::Drawing::Size(1159, 84);
			this->SupplierSearchContainer->TabIndex = 14;
			// 
			// label8
			// 
			this->label8->AccessibleName = L"catSearchLab";
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label8.Image")));
			this->label8->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label8->Location = System::Drawing::Point(1035, 12);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->MinimumSize = System::Drawing::Size(110, 60);
			this->label8->Name = L"label8";
			this->label8->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label8->Size = System::Drawing::Size(110, 60);
			this->label8->TabIndex = 14;
			this->label8->Text = L"البحث";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// SupplierSearchPanel
			// 
			this->SupplierSearchPanel->AccessibleName = L"CategorySearchPanel";
			this->SupplierSearchPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SupplierSearchPanel->Controls->Add(this->SupplierSearch);
			this->SupplierSearchPanel->Location = System::Drawing::Point(13, 15);
			this->SupplierSearchPanel->Margin = System::Windows::Forms::Padding(4);
			this->SupplierSearchPanel->Name = L"SupplierSearchPanel";
			this->SupplierSearchPanel->Padding = System::Windows::Forms::Padding(10);
			this->SupplierSearchPanel->Size = System::Drawing::Size(1006, 50);
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
			this->SupplierSearch->Location = System::Drawing::Point(10, 10);
			this->SupplierSearch->Margin = System::Windows::Forms::Padding(0);
			this->SupplierSearch->MaxLength = 50;
			this->SupplierSearch->Multiline = true;
			this->SupplierSearch->Name = L"SupplierSearch";
			this->SupplierSearch->Size = System::Drawing::Size(976, 30);
			this->SupplierSearch->TabIndex = 5;
			this->SupplierSearch->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->SupplierSearch->TextChanged += gcnew System::EventHandler(this, &Dashboard::SupplierSearch_TextChanged);
			// 
			// SupplierTable
			// 
			this->SupplierTable->AccessibleName = L"CategoryTable";
			this->SupplierTable->AllowUserToAddRows = false;
			this->SupplierTable->AllowUserToDeleteRows = false;
			dataGridViewCellStyle61->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle61->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			dataGridViewCellStyle61->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle61->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle61->Padding = System::Windows::Forms::Padding(4);
			dataGridViewCellStyle61->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle61->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle61->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->SupplierTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle61;
			this->SupplierTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->SupplierTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->SupplierTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SupplierTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle62->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle62->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(65)));
			dataGridViewCellStyle62->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle62->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle62->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle62->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			dataGridViewCellStyle62->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle62->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->SupplierTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle62;
			this->SupplierTable->ColumnHeadersHeight = 50;
			this->SupplierTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->SupplierTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->SupplierColId,
					this->SupplierColName, this->SupplierColContactInfo, this->SupplierColCreated_At, this->SupplierColUpdated_At
			});
			dataGridViewCellStyle64->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle64->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle64->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle64->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle64->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle64->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle64->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle64->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->SupplierTable->DefaultCellStyle = dataGridViewCellStyle64;
			this->SupplierTable->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->SupplierTable->EnableHeadersVisualStyles = false;
			this->SupplierTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->SupplierTable->Location = System::Drawing::Point(10, 98);
			this->SupplierTable->Margin = System::Windows::Forms::Padding(10);
			this->SupplierTable->MultiSelect = false;
			this->SupplierTable->Name = L"SupplierTable";
			this->SupplierTable->ReadOnly = true;
			this->SupplierTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SupplierTable->RowHeadersVisible = false;
			this->SupplierTable->RowHeadersWidth = 51;
			dataGridViewCellStyle65->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle65->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle65->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle65->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle65->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle65->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle65->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle65->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->SupplierTable->RowsDefaultCellStyle = dataGridViewCellStyle65;
			this->SupplierTable->RowTemplate->Height = 40;
			this->SupplierTable->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->SupplierTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->SupplierTable->Size = System::Drawing::Size(1152, 674);
			this->SupplierTable->StandardTab = true;
			this->SupplierTable->TabIndex = 0;
			this->SupplierTable->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::SupplierTable_CellClick);
			this->SupplierTable->CellMouseEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::DataGridView_CellMouseEnter);
			this->SupplierTable->CellMouseLeave += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::DataGridView_CellMouseLeave);
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
			dataGridViewCellStyle63->Padding = System::Windows::Forms::Padding(8);
			this->SupplierColContactInfo->DefaultCellStyle = dataGridViewCellStyle63;
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
			this->ManageSupplierContainer->Location = System::Drawing::Point(1188, 0);
			this->ManageSupplierContainer->Margin = System::Windows::Forms::Padding(5, 10, 5, 10);
			this->ManageSupplierContainer->Name = L"ManageSupplierContainer";
			this->ManageSupplierContainer->Size = System::Drawing::Size(470, 861);
			this->ManageSupplierContainer->TabIndex = 11;
			// 
			// ManageSupplierFormsPanel
			// 
			this->ManageSupplierFormsPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->ManageSupplierFormsPanel->Controls->Add(this->PrintToPdfBtnSup);
			this->ManageSupplierFormsPanel->Controls->Add(this->exportToexcelBtnSup);
			this->ManageSupplierFormsPanel->Controls->Add(this->SupplierNameLab);
			this->ManageSupplierFormsPanel->Controls->Add(this->ContainerOfSupplierContact_Info);
			this->ManageSupplierFormsPanel->Controls->Add(this->ContainerOfSupplierName);
			this->ManageSupplierFormsPanel->Controls->Add(this->DelSupplier_Btn);
			this->ManageSupplierFormsPanel->Controls->Add(this->EditSupplier_Btn);
			this->ManageSupplierFormsPanel->Controls->Add(this->AddSupplier_Btn);
			this->ManageSupplierFormsPanel->Controls->Add(this->label11);
			this->ManageSupplierFormsPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ManageSupplierFormsPanel->Location = System::Drawing::Point(0, 80);
			this->ManageSupplierFormsPanel->Margin = System::Windows::Forms::Padding(10);
			this->ManageSupplierFormsPanel->MaximumSize = System::Drawing::Size(465, 770);
			this->ManageSupplierFormsPanel->MinimumSize = System::Drawing::Size(465, 770);
			this->ManageSupplierFormsPanel->Name = L"ManageSupplierFormsPanel";
			this->ManageSupplierFormsPanel->Size = System::Drawing::Size(465, 770);
			this->ManageSupplierFormsPanel->TabIndex = 15;
			// 
			// PrintToPdfBtnSup
			// 
			this->PrintToPdfBtnSup->AccessibleName = L"PrintToPdfBtnSup";
			this->PrintToPdfBtnSup->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->PrintToPdfBtnSup->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->PrintToPdfBtnSup->FlatAppearance->BorderSize = 0;
			this->PrintToPdfBtnSup->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PrintToPdfBtnSup->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PrintToPdfBtnSup->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->PrintToPdfBtnSup->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PrintToPdfBtnSup.Image")));
			this->PrintToPdfBtnSup->Location = System::Drawing::Point(368, 330);
			this->PrintToPdfBtnSup->Margin = System::Windows::Forms::Padding(2);
			this->PrintToPdfBtnSup->MaximumSize = System::Drawing::Size(75, 75);
			this->PrintToPdfBtnSup->Name = L"PrintToPdfBtnSup";
			this->PrintToPdfBtnSup->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->PrintToPdfBtnSup->Size = System::Drawing::Size(75, 75);
			this->PrintToPdfBtnSup->TabIndex = 46;
			this->PrintToPdfBtnSup->UseVisualStyleBackColor = false;
			this->PrintToPdfBtnSup->Click += gcnew System::EventHandler(this, &Dashboard::PrintToPdfBtnSup_Click);
			// 
			// exportToexcelBtnSup
			// 
			this->exportToexcelBtnSup->AccessibleName = L"exportToexcelBtnSup";
			this->exportToexcelBtnSup->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->exportToexcelBtnSup->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->exportToexcelBtnSup->FlatAppearance->BorderSize = 0;
			this->exportToexcelBtnSup->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exportToexcelBtnSup->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exportToexcelBtnSup->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->exportToexcelBtnSup->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exportToexcelBtnSup.Image")));
			this->exportToexcelBtnSup->Location = System::Drawing::Point(368, 257);
			this->exportToexcelBtnSup->Margin = System::Windows::Forms::Padding(2);
			this->exportToexcelBtnSup->MaximumSize = System::Drawing::Size(75, 75);
			this->exportToexcelBtnSup->Name = L"exportToexcelBtnSup";
			this->exportToexcelBtnSup->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->exportToexcelBtnSup->Size = System::Drawing::Size(75, 75);
			this->exportToexcelBtnSup->TabIndex = 47;
			this->exportToexcelBtnSup->UseVisualStyleBackColor = false;
			this->exportToexcelBtnSup->Click += gcnew System::EventHandler(this, &Dashboard::exportToexcelBtnSup_Click);
			// 
			// SupplierNameLab
			// 
			this->SupplierNameLab->AccessibleName = L"SupplierNameLab";
			this->SupplierNameLab->AutoSize = true;
			this->SupplierNameLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SupplierNameLab->Location = System::Drawing::Point(216, 68);
			this->SupplierNameLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->SupplierNameLab->Name = L"SupplierNameLab";
			this->SupplierNameLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SupplierNameLab->Size = System::Drawing::Size(102, 28);
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
			this->ContainerOfSupplierContact_Info->Location = System::Drawing::Point(16, 230);
			this->ContainerOfSupplierContact_Info->Margin = System::Windows::Forms::Padding(4);
			this->ContainerOfSupplierContact_Info->Name = L"ContainerOfSupplierContact_Info";
			this->ContainerOfSupplierContact_Info->Padding = System::Windows::Forms::Padding(10);
			this->ContainerOfSupplierContact_Info->Size = System::Drawing::Size(310, 50);
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
			this->SupplierContact_Info->Location = System::Drawing::Point(10, 10);
			this->SupplierContact_Info->Margin = System::Windows::Forms::Padding(0);
			this->SupplierContact_Info->MaxLength = 50;
			this->SupplierContact_Info->Multiline = true;
			this->SupplierContact_Info->Name = L"SupplierContact_Info";
			this->SupplierContact_Info->Size = System::Drawing::Size(290, 30);
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
			this->ContainerOfSupplierName->Location = System::Drawing::Point(16, 115);
			this->ContainerOfSupplierName->Margin = System::Windows::Forms::Padding(4);
			this->ContainerOfSupplierName->Name = L"ContainerOfSupplierName";
			this->ContainerOfSupplierName->Padding = System::Windows::Forms::Padding(10);
			this->ContainerOfSupplierName->Size = System::Drawing::Size(310, 50);
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
			this->SupplierName->Location = System::Drawing::Point(10, 10);
			this->SupplierName->Margin = System::Windows::Forms::Padding(0);
			this->SupplierName->MaxLength = 50;
			this->SupplierName->Multiline = true;
			this->SupplierName->Name = L"SupplierName";
			this->SupplierName->Size = System::Drawing::Size(290, 30);
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
			this->DelSupplier_Btn->Location = System::Drawing::Point(368, 160);
			this->DelSupplier_Btn->Margin = System::Windows::Forms::Padding(2);
			this->DelSupplier_Btn->MaximumSize = System::Drawing::Size(75, 75);
			this->DelSupplier_Btn->MinimumSize = System::Drawing::Size(75, 75);
			this->DelSupplier_Btn->Name = L"DelSupplier_Btn";
			this->DelSupplier_Btn->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->DelSupplier_Btn->Size = System::Drawing::Size(75, 75);
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
			this->EditSupplier_Btn->Location = System::Drawing::Point(368, 85);
			this->EditSupplier_Btn->Margin = System::Windows::Forms::Padding(2);
			this->EditSupplier_Btn->MaximumSize = System::Drawing::Size(75, 75);
			this->EditSupplier_Btn->MinimumSize = System::Drawing::Size(75, 75);
			this->EditSupplier_Btn->Name = L"EditSupplier_Btn";
			this->EditSupplier_Btn->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->EditSupplier_Btn->Size = System::Drawing::Size(75, 75);
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
			this->AddSupplier_Btn->Location = System::Drawing::Point(368, 13);
			this->AddSupplier_Btn->Margin = System::Windows::Forms::Padding(2);
			this->AddSupplier_Btn->MaximumSize = System::Drawing::Size(75, 75);
			this->AddSupplier_Btn->MinimumSize = System::Drawing::Size(75, 75);
			this->AddSupplier_Btn->Name = L"AddSupplier_Btn";
			this->AddSupplier_Btn->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->AddSupplier_Btn->Size = System::Drawing::Size(75, 75);
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
			this->label11->Location = System::Drawing::Point(232, 184);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->label11->Size = System::Drawing::Size(85, 28);
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
			this->panel13->Size = System::Drawing::Size(468, 80);
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
			this->label12->Location = System::Drawing::Point(135, 22);
			this->label12->Margin = System::Windows::Forms::Padding(100, 15, 50, 10);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(199, 34);
			this->label12->TabIndex = 7;
			this->label12->Text = L"ادارة الموردين";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// productPanel
			// 
			this->productPanel->Controls->Add(this->ProductTableContainer);
			this->productPanel->Controls->Add(this->ManageProductContainer);
			this->productPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->productPanel->Location = System::Drawing::Point(0, 0);
			this->productPanel->Margin = System::Windows::Forms::Padding(2);
			this->productPanel->Name = L"productPanel";
			this->productPanel->Size = System::Drawing::Size(1658, 861);
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
			this->ProductTableContainer->Margin = System::Windows::Forms::Padding(5, 10, 5, 10);
			this->ProductTableContainer->MaximumSize = System::Drawing::Size(1180, 864);
			this->ProductTableContainer->MinimumSize = System::Drawing::Size(1180, 864);
			this->ProductTableContainer->Name = L"ProductTableContainer";
			this->ProductTableContainer->Size = System::Drawing::Size(1180, 864);
			this->ProductTableContainer->TabIndex = 8;
			// 
			// ProductTableTitlePanel
			// 
			this->ProductTableTitlePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ProductTableTitlePanel->Controls->Add(this->ProductTableTitle);
			this->ProductTableTitlePanel->Location = System::Drawing::Point(-16, 2);
			this->ProductTableTitlePanel->Margin = System::Windows::Forms::Padding(2);
			this->ProductTableTitlePanel->Name = L"ProductTableTitlePanel";
			this->ProductTableTitlePanel->Size = System::Drawing::Size(1192, 78);
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
			this->ProductTableTitle->Location = System::Drawing::Point(422, 21);
			this->ProductTableTitle->Margin = System::Windows::Forms::Padding(100, 15, 50, 10);
			this->ProductTableTitle->Name = L"ProductTableTitle";
			this->ProductTableTitle->Size = System::Drawing::Size(213, 34);
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
			this->ProductTablePanel->Location = System::Drawing::Point(24, 84);
			this->ProductTablePanel->Margin = System::Windows::Forms::Padding(2);
			this->ProductTablePanel->MaximumSize = System::Drawing::Size(1152, 774);
			this->ProductTablePanel->Name = L"ProductTablePanel";
			this->ProductTablePanel->Size = System::Drawing::Size(1152, 774);
			this->ProductTablePanel->TabIndex = 13;
			// 
			// ProductSearchContainer
			// 
			this->ProductSearchContainer->Controls->Add(this->ProductSearchPanel);
			this->ProductSearchContainer->Controls->Add(this->ProductSearchLab);
			this->ProductSearchContainer->Location = System::Drawing::Point(2, 2);
			this->ProductSearchContainer->Margin = System::Windows::Forms::Padding(2);
			this->ProductSearchContainer->Name = L"ProductSearchContainer";
			this->ProductSearchContainer->Size = System::Drawing::Size(1175, 84);
			this->ProductSearchContainer->TabIndex = 14;
			// 
			// ProductSearchPanel
			// 
			this->ProductSearchPanel->AccessibleName = L"CategorySearchPanel";
			this->ProductSearchPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ProductSearchPanel->Controls->Add(this->ProductSearch);
			this->ProductSearchPanel->Location = System::Drawing::Point(8, 15);
			this->ProductSearchPanel->Margin = System::Windows::Forms::Padding(4);
			this->ProductSearchPanel->Name = L"ProductSearchPanel";
			this->ProductSearchPanel->Padding = System::Windows::Forms::Padding(10);
			this->ProductSearchPanel->Size = System::Drawing::Size(1007, 50);
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
			this->ProductSearch->Location = System::Drawing::Point(10, 10);
			this->ProductSearch->Margin = System::Windows::Forms::Padding(0);
			this->ProductSearch->MaxLength = 50;
			this->ProductSearch->Multiline = true;
			this->ProductSearch->Name = L"ProductSearch";
			this->ProductSearch->Size = System::Drawing::Size(965, 30);
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
			this->ProductSearchLab->Location = System::Drawing::Point(1028, 10);
			this->ProductSearchLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ProductSearchLab->MinimumSize = System::Drawing::Size(110, 60);
			this->ProductSearchLab->Name = L"ProductSearchLab";
			this->ProductSearchLab->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->ProductSearchLab->Size = System::Drawing::Size(110, 60);
			this->ProductSearchLab->TabIndex = 6;
			this->ProductSearchLab->Text = L"البحث";
			this->ProductSearchLab->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// ProductTable
			// 
			this->ProductTable->AccessibleName = L"CategoryTable";
			this->ProductTable->AllowUserToAddRows = false;
			this->ProductTable->AllowUserToDeleteRows = false;
			dataGridViewCellStyle66->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle66->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			dataGridViewCellStyle66->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle66->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle66->Padding = System::Windows::Forms::Padding(4);
			dataGridViewCellStyle66->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle66->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle66->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->ProductTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle66;
			this->ProductTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->ProductTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->ProductTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ProductTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle67->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle67->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(65)));
			dataGridViewCellStyle67->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle67->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle67->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle67->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			dataGridViewCellStyle67->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle67->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->ProductTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle67;
			this->ProductTable->ColumnHeadersHeight = 50;
			this->ProductTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->ProductTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->ProductColId,
					this->ProductColName, this->ProductColPrice, this->ProductColQuantity, this->ProductColCategory, this->ProductColSupplier, this->ProductColCreated_At,
					this->ProductColUpdated_At
			});
			dataGridViewCellStyle69->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle69->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle69->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle69->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle69->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle69->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle69->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle69->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->ProductTable->DefaultCellStyle = dataGridViewCellStyle69;
			this->ProductTable->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->ProductTable->EnableHeadersVisualStyles = false;
			this->ProductTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->ProductTable->Location = System::Drawing::Point(10, 98);
			this->ProductTable->Margin = System::Windows::Forms::Padding(10);
			this->ProductTable->MultiSelect = false;
			this->ProductTable->Name = L"ProductTable";
			this->ProductTable->ReadOnly = true;
			this->ProductTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->ProductTable->RowHeadersVisible = false;
			this->ProductTable->RowHeadersWidth = 51;
			dataGridViewCellStyle70->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle70->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle70->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle70->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle70->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle70->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle70->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle70->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->ProductTable->RowsDefaultCellStyle = dataGridViewCellStyle70;
			this->ProductTable->RowTemplate->Height = 40;
			this->ProductTable->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ProductTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ProductTable->Size = System::Drawing::Size(1152, 672);
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
			dataGridViewCellStyle68->Padding = System::Windows::Forms::Padding(8);
			this->ProductColPrice->DefaultCellStyle = dataGridViewCellStyle68;
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
			this->ManageProductContainer->AutoScroll = true;
			this->ManageProductContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ManageProductContainer->Controls->Add(this->ManageProductFormPanel);
			this->ManageProductContainer->Controls->Add(this->ManageProductTitlePanel);
			this->ManageProductContainer->Dock = System::Windows::Forms::DockStyle::Right;
			this->ManageProductContainer->Location = System::Drawing::Point(1188, 0);
			this->ManageProductContainer->Margin = System::Windows::Forms::Padding(5, 10, 5, 10);
			this->ManageProductContainer->MinimumSize = System::Drawing::Size(470, 672);
			this->ManageProductContainer->Name = L"ManageProductContainer";
			this->ManageProductContainer->Size = System::Drawing::Size(470, 861);
			this->ManageProductContainer->TabIndex = 9;
			// 
			// ManageProductFormPanel
			// 
			this->ManageProductFormPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->ManageProductFormPanel->Controls->Add(this->delProduct_Btn);
			this->ManageProductFormPanel->Controls->Add(this->editProduct_Btn);
			this->ManageProductFormPanel->Controls->Add(this->RefreshProductData);
			this->ManageProductFormPanel->Controls->Add(this->PrintToPdfBtnprod);
			this->ManageProductFormPanel->Controls->Add(this->exportToexcelBtnProd);
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
			this->ManageProductFormPanel->Location = System::Drawing::Point(0, 80);
			this->ManageProductFormPanel->Margin = System::Windows::Forms::Padding(10);
			this->ManageProductFormPanel->MaximumSize = System::Drawing::Size(465, 770);
			this->ManageProductFormPanel->MinimumSize = System::Drawing::Size(465, 772);
			this->ManageProductFormPanel->Name = L"ManageProductFormPanel";
			this->ManageProductFormPanel->Size = System::Drawing::Size(465, 772);
			this->ManageProductFormPanel->TabIndex = 15;
			// 
			// delProduct_Btn
			// 
			this->delProduct_Btn->AccessibleName = L"delProduct_Btn";
			this->delProduct_Btn->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->delProduct_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->delProduct_Btn->FlatAppearance->BorderSize = 0;
			this->delProduct_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delProduct_Btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delProduct_Btn->ForeColor = System::Drawing::Color::Red;
			this->delProduct_Btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"delProduct_Btn.Image")));
			this->delProduct_Btn->Location = System::Drawing::Point(368, 152);
			this->delProduct_Btn->Margin = System::Windows::Forms::Padding(2);
			this->delProduct_Btn->MaximumSize = System::Drawing::Size(75, 75);
			this->delProduct_Btn->Name = L"delProduct_Btn";
			this->delProduct_Btn->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->delProduct_Btn->Size = System::Drawing::Size(75, 75);
			this->delProduct_Btn->TabIndex = 42;
			this->delProduct_Btn->UseVisualStyleBackColor = false;
			this->delProduct_Btn->Click += gcnew System::EventHandler(this, &Dashboard::delProduct_Click);
			// 
			// editProduct_Btn
			// 
			this->editProduct_Btn->AccessibleName = L"editProduct_Btn";
			this->editProduct_Btn->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->editProduct_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->editProduct_Btn->FlatAppearance->BorderSize = 0;
			this->editProduct_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->editProduct_Btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editProduct_Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->editProduct_Btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editProduct_Btn.Image")));
			this->editProduct_Btn->Location = System::Drawing::Point(368, 84);
			this->editProduct_Btn->Margin = System::Windows::Forms::Padding(2);
			this->editProduct_Btn->MaximumSize = System::Drawing::Size(75, 75);
			this->editProduct_Btn->Name = L"editProduct_Btn";
			this->editProduct_Btn->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->editProduct_Btn->Size = System::Drawing::Size(75, 75);
			this->editProduct_Btn->TabIndex = 43;
			this->editProduct_Btn->UseVisualStyleBackColor = false;
			this->editProduct_Btn->Click += gcnew System::EventHandler(this, &Dashboard::updateProduct_Click);
			// 
			// RefreshProductData
			// 
			this->RefreshProductData->AccessibleName = L"RefreshProductData";
			this->RefreshProductData->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->RefreshProductData->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->RefreshProductData->FlatAppearance->BorderSize = 0;
			this->RefreshProductData->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RefreshProductData->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RefreshProductData->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->RefreshProductData->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RefreshProductData.Image")));
			this->RefreshProductData->Location = System::Drawing::Point(368, 226);
			this->RefreshProductData->Margin = System::Windows::Forms::Padding(2);
			this->RefreshProductData->MaximumSize = System::Drawing::Size(75, 75);
			this->RefreshProductData->Name = L"RefreshProductData";
			this->RefreshProductData->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->RefreshProductData->Size = System::Drawing::Size(75, 75);
			this->RefreshProductData->TabIndex = 44;
			this->RefreshProductData->UseVisualStyleBackColor = false;
			this->RefreshProductData->Click += gcnew System::EventHandler(this, &Dashboard::RefreshProductData_Click);
			// 
			// PrintToPdfBtnprod
			// 
			this->PrintToPdfBtnprod->AccessibleName = L"PrintToPdfBtnprod";
			this->PrintToPdfBtnprod->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->PrintToPdfBtnprod->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->PrintToPdfBtnprod->FlatAppearance->BorderSize = 0;
			this->PrintToPdfBtnprod->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PrintToPdfBtnprod->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PrintToPdfBtnprod->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->PrintToPdfBtnprod->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PrintToPdfBtnprod.Image")));
			this->PrintToPdfBtnprod->Location = System::Drawing::Point(368, 395);
			this->PrintToPdfBtnprod->Margin = System::Windows::Forms::Padding(2);
			this->PrintToPdfBtnprod->MaximumSize = System::Drawing::Size(75, 75);
			this->PrintToPdfBtnprod->Name = L"PrintToPdfBtnprod";
			this->PrintToPdfBtnprod->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->PrintToPdfBtnprod->Size = System::Drawing::Size(75, 75);
			this->PrintToPdfBtnprod->TabIndex = 45;
			this->PrintToPdfBtnprod->UseVisualStyleBackColor = false;
			// 
			// exportToexcelBtnProd
			// 
			this->exportToexcelBtnProd->AccessibleName = L"exportToexcelBtnProd";
			this->exportToexcelBtnProd->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->exportToexcelBtnProd->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->exportToexcelBtnProd->FlatAppearance->BorderSize = 0;
			this->exportToexcelBtnProd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exportToexcelBtnProd->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exportToexcelBtnProd->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->exportToexcelBtnProd->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exportToexcelBtnProd.Image")));
			this->exportToexcelBtnProd->Location = System::Drawing::Point(368, 322);
			this->exportToexcelBtnProd->Margin = System::Windows::Forms::Padding(2);
			this->exportToexcelBtnProd->MaximumSize = System::Drawing::Size(75, 75);
			this->exportToexcelBtnProd->Name = L"exportToexcelBtnProd";
			this->exportToexcelBtnProd->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->exportToexcelBtnProd->Size = System::Drawing::Size(75, 75);
			this->exportToexcelBtnProd->TabIndex = 45;
			this->exportToexcelBtnProd->UseVisualStyleBackColor = false;
			this->exportToexcelBtnProd->Click += gcnew System::EventHandler(this, &Dashboard::exportToexcelBtnProd_Click);
			// 
			// addProduct_Btn
			// 
			this->addProduct_Btn->AccessibleName = L"addProduct_Btn";
			this->addProduct_Btn->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->addProduct_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->addProduct_Btn->FlatAppearance->BorderSize = 0;
			this->addProduct_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addProduct_Btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addProduct_Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->addProduct_Btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addProduct_Btn.Image")));
			this->addProduct_Btn->Location = System::Drawing::Point(368, 13);
			this->addProduct_Btn->Margin = System::Windows::Forms::Padding(2);
			this->addProduct_Btn->MaximumSize = System::Drawing::Size(75, 75);
			this->addProduct_Btn->Name = L"addProduct_Btn";
			this->addProduct_Btn->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->addProduct_Btn->Size = System::Drawing::Size(75, 75);
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
			this->SupplierComboBox->Location = System::Drawing::Point(29, 508);
			this->SupplierComboBox->Margin = System::Windows::Forms::Padding(2);
			this->SupplierComboBox->Name = L"SupplierComboBox";
			this->SupplierComboBox->Size = System::Drawing::Size(310, 36);
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
			this->CategoryComboBox->Location = System::Drawing::Point(29, 388);
			this->CategoryComboBox->Margin = System::Windows::Forms::Padding(2);
			this->CategoryComboBox->Name = L"CategoryComboBox";
			this->CategoryComboBox->Size = System::Drawing::Size(310, 36);
			this->CategoryComboBox->Sorted = true;
			this->CategoryComboBox->TabIndex = 41;
			// 
			// ProductNameLab
			// 
			this->ProductNameLab->AccessibleName = L"ProductNameLab";
			this->ProductNameLab->AutoSize = true;
			this->ProductNameLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ProductNameLab->Location = System::Drawing::Point(232, 29);
			this->ProductNameLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ProductNameLab->Name = L"ProductNameLab";
			this->ProductNameLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->ProductNameLab->Size = System::Drawing::Size(102, 28);
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
			this->ContainerOfProductQuantity->Location = System::Drawing::Point(31, 282);
			this->ContainerOfProductQuantity->Margin = System::Windows::Forms::Padding(4);
			this->ContainerOfProductQuantity->Name = L"ContainerOfProductQuantity";
			this->ContainerOfProductQuantity->Padding = System::Windows::Forms::Padding(10);
			this->ContainerOfProductQuantity->Size = System::Drawing::Size(310, 50);
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
			this->productQuantity->Location = System::Drawing::Point(10, 10);
			this->productQuantity->Margin = System::Windows::Forms::Padding(0);
			this->productQuantity->MaxLength = 50;
			this->productQuantity->Multiline = true;
			this->productQuantity->Name = L"productQuantity";
			this->productQuantity->Size = System::Drawing::Size(290, 30);
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
			this->ContainerOfProductPrice->Location = System::Drawing::Point(30, 172);
			this->ContainerOfProductPrice->Margin = System::Windows::Forms::Padding(4);
			this->ContainerOfProductPrice->Name = L"ContainerOfProductPrice";
			this->ContainerOfProductPrice->Padding = System::Windows::Forms::Padding(10);
			this->ContainerOfProductPrice->Size = System::Drawing::Size(310, 50);
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
			this->productPrice->Location = System::Drawing::Point(10, 10);
			this->productPrice->Margin = System::Windows::Forms::Padding(0);
			this->productPrice->MaxLength = 50;
			this->productPrice->Multiline = true;
			this->productPrice->Name = L"productPrice";
			this->productPrice->Size = System::Drawing::Size(290, 30);
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
			this->ContainerOfProductName->Location = System::Drawing::Point(30, 66);
			this->ContainerOfProductName->Margin = System::Windows::Forms::Padding(4);
			this->ContainerOfProductName->Name = L"ContainerOfProductName";
			this->ContainerOfProductName->Padding = System::Windows::Forms::Padding(10);
			this->ContainerOfProductName->Size = System::Drawing::Size(310, 50);
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
			this->productName->Location = System::Drawing::Point(10, 10);
			this->productName->Margin = System::Windows::Forms::Padding(0);
			this->productName->MaxLength = 50;
			this->productName->Multiline = true;
			this->productName->Name = L"productName";
			this->productName->Size = System::Drawing::Size(290, 30);
			this->productName->TabIndex = 5;
			this->productName->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// SupplierComboBoxLab
			// 
			this->SupplierComboBoxLab->AccessibleName = L"SupplierComboBoxLab";
			this->SupplierComboBoxLab->AutoSize = true;
			this->SupplierComboBoxLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SupplierComboBoxLab->Location = System::Drawing::Point(270, 445);
			this->SupplierComboBoxLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->SupplierComboBoxLab->Name = L"SupplierComboBoxLab";
			this->SupplierComboBoxLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SupplierComboBoxLab->Size = System::Drawing::Size(62, 28);
			this->SupplierComboBoxLab->TabIndex = 28;
			this->SupplierComboBoxLab->Text = L"المورد";
			// 
			// CategoryComboBoxLab
			// 
			this->CategoryComboBoxLab->AccessibleName = L"CategoryComboBoxLab";
			this->CategoryComboBoxLab->AutoSize = true;
			this->CategoryComboBoxLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CategoryComboBoxLab->Location = System::Drawing::Point(261, 348);
			this->CategoryComboBoxLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->CategoryComboBoxLab->Name = L"CategoryComboBoxLab";
			this->CategoryComboBoxLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->CategoryComboBoxLab->Size = System::Drawing::Size(71, 28);
			this->CategoryComboBoxLab->TabIndex = 29;
			this->CategoryComboBoxLab->Text = L"الصنف";
			// 
			// ProductQuantityLab
			// 
			this->ProductQuantityLab->AccessibleName = L"ProductQuantityLab";
			this->ProductQuantityLab->AutoSize = true;
			this->ProductQuantityLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ProductQuantityLab->Location = System::Drawing::Point(232, 241);
			this->ProductQuantityLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ProductQuantityLab->Name = L"ProductQuantityLab";
			this->ProductQuantityLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->ProductQuantityLab->Size = System::Drawing::Size(107, 28);
			this->ProductQuantityLab->TabIndex = 30;
			this->ProductQuantityLab->Text = L"كمية المنتج";
			// 
			// ProductPriceLab
			// 
			this->ProductPriceLab->AccessibleName = L"catdescLab";
			this->ProductPriceLab->AutoSize = true;
			this->ProductPriceLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ProductPriceLab->Location = System::Drawing::Point(232, 132);
			this->ProductPriceLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ProductPriceLab->Name = L"ProductPriceLab";
			this->ProductPriceLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->ProductPriceLab->Size = System::Drawing::Size(105, 28);
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
			this->ManageProductTitlePanel->Size = System::Drawing::Size(468, 80);
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
			this->ManageProductTitle->Location = System::Drawing::Point(135, 22);
			this->ManageProductTitle->Margin = System::Windows::Forms::Padding(100, 15, 50, 10);
			this->ManageProductTitle->Name = L"ManageProductTitle";
			this->ManageProductTitle->Size = System::Drawing::Size(200, 34);
			this->ManageProductTitle->TabIndex = 7;
			this->ManageProductTitle->Text = L"ادارة المنتجات";
			this->ManageProductTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// cashierPanel
			// 
			this->cashierPanel->Controls->Add(this->panel9);
			this->cashierPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cashierPanel->Location = System::Drawing::Point(0, 0);
			this->cashierPanel->Margin = System::Windows::Forms::Padding(2);
			this->cashierPanel->Name = L"cashierPanel";
			this->cashierPanel->Size = System::Drawing::Size(1658, 861);
			this->cashierPanel->TabIndex = 1;
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->CashierTablePanelContainer);
			this->panel9->Controls->Add(this->ManageSaleContainer);
			this->panel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel9->Location = System::Drawing::Point(0, 0);
			this->panel9->Margin = System::Windows::Forms::Padding(2);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(1658, 861);
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
			this->CashierTablePanelContainer->Margin = System::Windows::Forms::Padding(5, 10, 5, 10);
			this->CashierTablePanelContainer->MaximumSize = System::Drawing::Size(1180, 864);
			this->CashierTablePanelContainer->MinimumSize = System::Drawing::Size(1180, 864);
			this->CashierTablePanelContainer->Name = L"CashierTablePanelContainer";
			this->CashierTablePanelContainer->Size = System::Drawing::Size(1180, 864);
			this->CashierTablePanelContainer->TabIndex = 8;
			// 
			// CashierTableTitlePanel
			// 
			this->CashierTableTitlePanel->AccessibleName = L"CashierTableTitlePanel";
			this->CashierTableTitlePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CashierTableTitlePanel->Controls->Add(this->CashierTableTitle);
			this->CashierTableTitlePanel->Location = System::Drawing::Point(24, 2);
			this->CashierTableTitlePanel->Margin = System::Windows::Forms::Padding(2);
			this->CashierTableTitlePanel->Name = L"CashierTableTitlePanel";
			this->CashierTableTitlePanel->Size = System::Drawing::Size(1152, 75);
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
			this->CashierTableTitle->Location = System::Drawing::Point(522, 18);
			this->CashierTableTitle->Margin = System::Windows::Forms::Padding(100, 15, 50, 10);
			this->CashierTableTitle->Name = L"CashierTableTitle";
			this->CashierTableTitle->Size = System::Drawing::Size(114, 34);
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
			this->CashierTablePanel->Location = System::Drawing::Point(24, 81);
			this->CashierTablePanel->Margin = System::Windows::Forms::Padding(2);
			this->CashierTablePanel->MaximumSize = System::Drawing::Size(1152, 774);
			this->CashierTablePanel->Name = L"CashierTablePanel";
			this->CashierTablePanel->Size = System::Drawing::Size(1152, 774);
			this->CashierTablePanel->TabIndex = 13;
			// 
			// CashierSearchProductPanel
			// 
			this->CashierSearchProductPanel->AccessibleName = L"CashierSearchProductPanel";
			this->CashierSearchProductPanel->Controls->Add(this->label10);
			this->CashierSearchProductPanel->Controls->Add(this->CashierSearchProductContainer);
			this->CashierSearchProductPanel->Location = System::Drawing::Point(2, 2);
			this->CashierSearchProductPanel->Margin = System::Windows::Forms::Padding(2);
			this->CashierSearchProductPanel->Name = L"CashierSearchProductPanel";
			this->CashierSearchProductPanel->Size = System::Drawing::Size(1152, 84);
			this->CashierSearchProductPanel->TabIndex = 14;
			// 
			// CashierSearchProductContainer
			// 
			this->CashierSearchProductContainer->AccessibleName = L"CashierSearchProductContainer";
			this->CashierSearchProductContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CashierSearchProductContainer->Controls->Add(this->CashierSearchProduct);
			this->CashierSearchProductContainer->Location = System::Drawing::Point(8, 15);
			this->CashierSearchProductContainer->Margin = System::Windows::Forms::Padding(4);
			this->CashierSearchProductContainer->Name = L"CashierSearchProductContainer";
			this->CashierSearchProductContainer->Padding = System::Windows::Forms::Padding(10);
			this->CashierSearchProductContainer->Size = System::Drawing::Size(1007, 50);
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
			this->CashierSearchProduct->Location = System::Drawing::Point(10, 10);
			this->CashierSearchProduct->Margin = System::Windows::Forms::Padding(0);
			this->CashierSearchProduct->MaxLength = 50;
			this->CashierSearchProduct->Multiline = true;
			this->CashierSearchProduct->Name = L"CashierSearchProduct";
			this->CashierSearchProduct->Size = System::Drawing::Size(982, 30);
			this->CashierSearchProduct->TabIndex = 5;
			this->CashierSearchProduct->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->CashierSearchProduct->TextChanged += gcnew System::EventHandler(this, &Dashboard::CashierSearchProduct_TextChanged);
			// 
			// CashierTable
			// 
			this->CashierTable->AccessibleName = L"CashierTable";
			this->CashierTable->AllowUserToAddRows = false;
			this->CashierTable->AllowUserToDeleteRows = false;
			dataGridViewCellStyle71->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle71->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			dataGridViewCellStyle71->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle71->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle71->Padding = System::Windows::Forms::Padding(4);
			dataGridViewCellStyle71->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle71->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle71->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->CashierTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle71;
			this->CashierTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->CashierTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->CashierTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->CashierTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle72->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle72->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(65)));
			dataGridViewCellStyle72->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle72->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle72->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle72->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			dataGridViewCellStyle72->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle72->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->CashierTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle72;
			this->CashierTable->ColumnHeadersHeight = 50;
			this->CashierTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->CashierTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->CashProductId,
					this->CashProductName, this->CashProductPrice, this->CashProductQuantity, this->CashTotalProductPrice
			});
			dataGridViewCellStyle74->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle74->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle74->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle74->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle74->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle74->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle74->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle74->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->CashierTable->DefaultCellStyle = dataGridViewCellStyle74;
			this->CashierTable->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->CashierTable->EnableHeadersVisualStyles = false;
			this->CashierTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->CashierTable->Location = System::Drawing::Point(10, 98);
			this->CashierTable->Margin = System::Windows::Forms::Padding(10);
			this->CashierTable->MultiSelect = false;
			this->CashierTable->Name = L"CashierTable";
			this->CashierTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->CashierTable->RowHeadersVisible = false;
			this->CashierTable->RowHeadersWidth = 51;
			dataGridViewCellStyle75->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle75->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			dataGridViewCellStyle75->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle75->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle75->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle75->SelectionBackColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle75->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle75->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->CashierTable->RowsDefaultCellStyle = dataGridViewCellStyle75;
			this->CashierTable->RowTemplate->Height = 40;
			this->CashierTable->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->CashierTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->CashierTable->Size = System::Drawing::Size(1152, 678);
			this->CashierTable->StandardTab = true;
			this->CashierTable->TabIndex = 0;
			this->CashierTable->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::CashierTable_CellEndEdit);
			this->CashierTable->CellMouseEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::DataGridView_CellMouseEnter);
			this->CashierTable->CellMouseLeave += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard::DataGridView_CellMouseLeave);
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
			dataGridViewCellStyle73->Padding = System::Windows::Forms::Padding(8);
			this->CashProductPrice->DefaultCellStyle = dataGridViewCellStyle73;
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
			this->CashTotalProductPrice->MinimumWidth = 6;
			this->CashTotalProductPrice->Name = L"CashTotalProductPrice";
			this->CashTotalProductPrice->ReadOnly = true;
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->Location = System::Drawing::Point(4, 790);
			this->flowLayoutPanel3->Margin = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(185, 61);
			this->flowLayoutPanel3->TabIndex = 15;
			// 
			// ManageSaleContainer
			// 
			this->ManageSaleContainer->AccessibleName = L"ManageSaleContainer";
			this->ManageSaleContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ManageSaleContainer->Controls->Add(this->ManageSalePanel);
			this->ManageSaleContainer->Controls->Add(this->panel15);
			this->ManageSaleContainer->Dock = System::Windows::Forms::DockStyle::Right;
			this->ManageSaleContainer->Location = System::Drawing::Point(1188, 0);
			this->ManageSaleContainer->Margin = System::Windows::Forms::Padding(5, 10, 5, 10);
			this->ManageSaleContainer->Name = L"ManageSaleContainer";
			this->ManageSaleContainer->Size = System::Drawing::Size(470, 861);
			this->ManageSaleContainer->TabIndex = 9;
			// 
			// ManageSalePanel
			// 
			this->ManageSalePanel->AccessibleName = L"ManageSalePanel";
			this->ManageSalePanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->ManageSalePanel->Controls->Add(this->panel10);
			this->ManageSalePanel->Controls->Add(this->button9);
			this->ManageSalePanel->Controls->Add(this->button10);
			this->ManageSalePanel->Controls->Add(this->PayInvoice);
			this->ManageSalePanel->Controls->Add(this->RefreshInvoice);
			this->ManageSalePanel->Controls->Add(this->button12);
			this->ManageSalePanel->Controls->Add(this->TotalInvoiceLab);
			this->ManageSalePanel->Controls->Add(this->label5);
			this->ManageSalePanel->Controls->Add(this->payLab);
			this->ManageSalePanel->Controls->Add(this->payFeildContainer);
			this->ManageSalePanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ManageSalePanel->Location = System::Drawing::Point(0, 80);
			this->ManageSalePanel->Margin = System::Windows::Forms::Padding(10);
			this->ManageSalePanel->MaximumSize = System::Drawing::Size(465, 770);
			this->ManageSalePanel->MinimumSize = System::Drawing::Size(465, 770);
			this->ManageSalePanel->Name = L"ManageSalePanel";
			this->ManageSalePanel->Size = System::Drawing::Size(465, 770);
			this->ManageSalePanel->TabIndex = 15;
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->panel10->Controls->Add(this->label2);
			this->panel10->Controls->Add(this->SearchSuggestionsList);
			this->panel10->Location = System::Drawing::Point(16, 14);
			this->panel10->Margin = System::Windows::Forms::Padding(4);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(325, 200);
			this->panel10->TabIndex = 47;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::LawnGreen;
			this->label2->Location = System::Drawing::Point(122, 10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(193, 24);
			this->label2->TabIndex = 47;
			this->label2->Text = L"نتائج بحث المنتجات";
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
			this->SearchSuggestionsList->ItemHeight = 32;
			this->SearchSuggestionsList->Location = System::Drawing::Point(11, 50);
			this->SearchSuggestionsList->Margin = System::Windows::Forms::Padding(4);
			this->SearchSuggestionsList->Name = L"SearchSuggestionsList";
			this->SearchSuggestionsList->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SearchSuggestionsList->Size = System::Drawing::Size(305, 128);
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
			this->button9->Location = System::Drawing::Point(368, 158);
			this->button9->Margin = System::Windows::Forms::Padding(2);
			this->button9->MaximumSize = System::Drawing::Size(75, 75);
			this->button9->Name = L"button9";
			this->button9->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button9->Size = System::Drawing::Size(75, 75);
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
			this->button10->Location = System::Drawing::Point(368, 85);
			this->button10->Margin = System::Windows::Forms::Padding(2);
			this->button10->MaximumSize = System::Drawing::Size(75, 75);
			this->button10->Name = L"button10";
			this->button10->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button10->Size = System::Drawing::Size(75, 75);
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
			this->PayInvoice->Location = System::Drawing::Point(368, 298);
			this->PayInvoice->Margin = System::Windows::Forms::Padding(2);
			this->PayInvoice->MaximumSize = System::Drawing::Size(75, 75);
			this->PayInvoice->Name = L"PayInvoice";
			this->PayInvoice->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->PayInvoice->Size = System::Drawing::Size(75, 75);
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
			this->RefreshInvoice->Location = System::Drawing::Point(368, 231);
			this->RefreshInvoice->Margin = System::Windows::Forms::Padding(2);
			this->RefreshInvoice->MaximumSize = System::Drawing::Size(75, 75);
			this->RefreshInvoice->Name = L"RefreshInvoice";
			this->RefreshInvoice->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->RefreshInvoice->Size = System::Drawing::Size(75, 75);
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
			this->button12->Location = System::Drawing::Point(368, 13);
			this->button12->Margin = System::Windows::Forms::Padding(2);
			this->button12->MaximumSize = System::Drawing::Size(75, 75);
			this->button12->Name = L"button12";
			this->button12->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button12->Size = System::Drawing::Size(75, 75);
			this->button12->TabIndex = 45;
			this->button12->UseVisualStyleBackColor = false;
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
			this->TotalInvoiceLab->Location = System::Drawing::Point(57, 282);
			this->TotalInvoiceLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->TotalInvoiceLab->Name = L"TotalInvoiceLab";
			this->TotalInvoiceLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->TotalInvoiceLab->Size = System::Drawing::Size(256, 66);
			this->TotalInvoiceLab->TabIndex = 39;
			this->TotalInvoiceLab->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label5
			// 
			this->label5->AccessibleName = L"payLab";
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(118, 242);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->label5->Size = System::Drawing::Size(136, 28);
			this->label5->TabIndex = 39;
			this->label5->Text = L"اجمالي الفاتورة";
			// 
			// payLab
			// 
			this->payLab->AccessibleName = L"payLab";
			this->payLab->AutoSize = true;
			this->payLab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->payLab->Location = System::Drawing::Point(158, 366);
			this->payLab->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->payLab->Name = L"payLab";
			this->payLab->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->payLab->Size = System::Drawing::Size(80, 28);
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
			this->payFeildContainer->Location = System::Drawing::Point(118, 406);
			this->payFeildContainer->Margin = System::Windows::Forms::Padding(4);
			this->payFeildContainer->Name = L"payFeildContainer";
			this->payFeildContainer->Padding = System::Windows::Forms::Padding(10);
			this->payFeildContainer->Size = System::Drawing::Size(157, 68);
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
			this->payFeild->ForeColor = System::Drawing::Color::LawnGreen;
			this->payFeild->Location = System::Drawing::Point(10, 10);
			this->payFeild->Margin = System::Windows::Forms::Padding(0);
			this->payFeild->MaxLength = 50;
			this->payFeild->Multiline = true;
			this->payFeild->Name = L"payFeild";
			this->payFeild->Size = System::Drawing::Size(136, 48);
			this->payFeild->TabIndex = 5;
			this->payFeild->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// panel15
			// 
			this->panel15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel15->Controls->Add(this->label14);
			this->panel15->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel15->Location = System::Drawing::Point(0, 0);
			this->panel15->Margin = System::Windows::Forms::Padding(2);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(468, 80);
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
			this->label14->Location = System::Drawing::Point(135, 22);
			this->label14->Margin = System::Windows::Forms::Padding(100, 15, 50, 10);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(183, 34);
			this->label14->TabIndex = 7;
			this->label14->Text = L"ادارة الفاتورة";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// HomePanel
			// 
			this->HomePanel->AutoScroll = true;
			this->HomePanel->Controls->Add(this->fastNav);
			this->HomePanel->Controls->Add(this->Cards);
			this->HomePanel->Controls->Add(this->ChartPanel);
			this->HomePanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->HomePanel->Location = System::Drawing::Point(0, 0);
			this->HomePanel->Margin = System::Windows::Forms::Padding(2);
			this->HomePanel->Name = L"HomePanel";
			this->HomePanel->Size = System::Drawing::Size(1658, 861);
			this->HomePanel->TabIndex = 0;
			// 
			// fastNav
			// 
			this->fastNav->AutoSize = true;
			this->fastNav->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->fastNav->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->fastNav->Controls->Add(this->totalSales);
			this->fastNav->Controls->Add(this->SCAddSupplier);
			this->fastNav->Controls->Add(this->SCAddCategory);
			this->fastNav->Controls->Add(this->SCAddProduct);
			this->fastNav->Dock = System::Windows::Forms::DockStyle::Top;
			this->fastNav->Location = System::Drawing::Point(0, 0);
			this->fastNav->Margin = System::Windows::Forms::Padding(0);
			this->fastNav->MinimumSize = System::Drawing::Size(1900, 110);
			this->fastNav->Name = L"fastNav";
			this->fastNav->Size = System::Drawing::Size(1900, 110);
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
			this->totalSales->Size = System::Drawing::Size(328, 104);
			this->totalSales->TabIndex = 0;
			this->totalSales->Text = L"الة حاسبة";
			this->totalSales->UseVisualStyleBackColor = true;
			this->totalSales->Click += gcnew System::EventHandler(this, &Dashboard::totalSales_Click);
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
			this->SCAddSupplier->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SCAddSupplier.Image")));
			this->SCAddSupplier->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->SCAddSupplier->Location = System::Drawing::Point(334, 2);
			this->SCAddSupplier->Margin = System::Windows::Forms::Padding(2);
			this->SCAddSupplier->Name = L"SCAddSupplier";
			this->SCAddSupplier->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SCAddSupplier->Size = System::Drawing::Size(328, 104);
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
			this->SCAddCategory->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SCAddCategory.Image")));
			this->SCAddCategory->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->SCAddCategory->Location = System::Drawing::Point(666, 2);
			this->SCAddCategory->Margin = System::Windows::Forms::Padding(2);
			this->SCAddCategory->Name = L"SCAddCategory";
			this->SCAddCategory->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SCAddCategory->Size = System::Drawing::Size(328, 104);
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
			this->SCAddProduct->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SCAddProduct.Image")));
			this->SCAddProduct->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->SCAddProduct->Location = System::Drawing::Point(998, 2);
			this->SCAddProduct->Margin = System::Windows::Forms::Padding(2);
			this->SCAddProduct->Name = L"SCAddProduct";
			this->SCAddProduct->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SCAddProduct->Size = System::Drawing::Size(328, 104);
			this->SCAddProduct->TabIndex = 0;
			this->SCAddProduct->Text = L"اضافة منتج";
			this->SCAddProduct->UseVisualStyleBackColor = true;
			this->SCAddProduct->Click += gcnew System::EventHandler(this, &Dashboard::SCAddProduct_Click);
			// 
			// Cards
			// 
			this->Cards->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Cards->Controls->Add(this->CardPanelHead);
			this->Cards->Controls->Add(this->panel5);
			this->Cards->Controls->Add(this->panel3);
			this->Cards->Controls->Add(this->panel4);
			this->Cards->Controls->Add(this->panel6);
			this->Cards->Location = System::Drawing::Point(5, 120);
			this->Cards->Margin = System::Windows::Forms::Padding(5, 10, 5, 10);
			this->Cards->MaximumSize = System::Drawing::Size(840, 600);
			this->Cards->Name = L"Cards";
			this->Cards->Size = System::Drawing::Size(837, 440);
			this->Cards->TabIndex = 4;
			// 
			// CardPanelHead
			// 
			this->CardPanelHead->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CardPanelHead->Controls->Add(this->CardPanelTitle);
			this->CardPanelHead->Location = System::Drawing::Point(5, 2);
			this->CardPanelHead->Margin = System::Windows::Forms::Padding(5, 2, 2, 2);
			this->CardPanelHead->Name = L"CardPanelHead";
			this->CardPanelHead->Size = System::Drawing::Size(826, 80);
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
			this->CardPanelTitle->Location = System::Drawing::Point(350, 22);
			this->CardPanelTitle->Margin = System::Windows::Forms::Padding(100, 15, 50, 10);
			this->CardPanelTitle->Name = L"CardPanelTitle";
			this->CardPanelTitle->Size = System::Drawing::Size(140, 34);
			this->CardPanelTitle->TabIndex = 7;
			this->CardPanelTitle->Text = L"احصائيات";
			this->CardPanelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->LatestProductsListBox);
			this->panel5->Controls->Add(this->button6);
			this->panel5->Location = System::Drawing::Point(10, 94);
			this->panel5->Margin = System::Windows::Forms::Padding(10);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(394, 158);
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
			this->LatestProductsListBox->ItemHeight = 28;
			this->LatestProductsListBox->Location = System::Drawing::Point(0, 40);
			this->LatestProductsListBox->Margin = System::Windows::Forms::Padding(2);
			this->LatestProductsListBox->Name = L"LatestProductsListBox";
			this->LatestProductsListBox->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->LatestProductsListBox->Size = System::Drawing::Size(394, 118);
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
			this->button6->Size = System::Drawing::Size(394, 40);
			this->button6->TabIndex = 0;
			this->button6->Text = L"احدث المنتجات";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Dashboard::productBtn_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->TotalProfitsListBox);
			this->panel3->Controls->Add(this->button4);
			this->panel3->Location = System::Drawing::Point(424, 94);
			this->panel3->Margin = System::Windows::Forms::Padding(10);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(394, 158);
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
			this->TotalProfitsListBox->ItemHeight = 28;
			this->TotalProfitsListBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"ارباح اليوم:", L"ارباح الشهر:", L"ارباح السنة:" });
			this->TotalProfitsListBox->Location = System::Drawing::Point(0, 40);
			this->TotalProfitsListBox->Margin = System::Windows::Forms::Padding(2);
			this->TotalProfitsListBox->Name = L"TotalProfitsListBox";
			this->TotalProfitsListBox->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->TotalProfitsListBox->Size = System::Drawing::Size(394, 118);
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
			this->button4->Size = System::Drawing::Size(394, 40);
			this->button4->TabIndex = 0;
			this->button4->Text = L"الارباح";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Dashboard::stockBtn_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->LatestCategoriesListBox);
			this->panel4->Controls->Add(this->button5);
			this->panel4->Location = System::Drawing::Point(10, 272);
			this->panel4->Margin = System::Windows::Forms::Padding(10);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(394, 158);
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
			this->LatestCategoriesListBox->ItemHeight = 28;
			this->LatestCategoriesListBox->Location = System::Drawing::Point(0, 40);
			this->LatestCategoriesListBox->Margin = System::Windows::Forms::Padding(2);
			this->LatestCategoriesListBox->Name = L"LatestCategoriesListBox";
			this->LatestCategoriesListBox->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->LatestCategoriesListBox->Size = System::Drawing::Size(394, 118);
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
			this->button5->Size = System::Drawing::Size(394, 40);
			this->button5->TabIndex = 0;
			this->button5->Text = L"احدث الاصناف";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Dashboard::categoryBtn_Click);
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->LatestSuppliersListBox);
			this->panel6->Controls->Add(this->button7);
			this->panel6->Location = System::Drawing::Point(424, 272);
			this->panel6->Margin = System::Windows::Forms::Padding(10);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(394, 158);
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
			this->LatestSuppliersListBox->ItemHeight = 28;
			this->LatestSuppliersListBox->Location = System::Drawing::Point(0, 40);
			this->LatestSuppliersListBox->Margin = System::Windows::Forms::Padding(2);
			this->LatestSuppliersListBox->Name = L"LatestSuppliersListBox";
			this->LatestSuppliersListBox->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->LatestSuppliersListBox->Size = System::Drawing::Size(394, 118);
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
			this->button7->Size = System::Drawing::Size(394, 40);
			this->button7->TabIndex = 0;
			this->button7->Text = L"احدث الموردين";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Dashboard::supplierBtn_Click);
			// 
			// ChartPanel
			// 
			this->ChartPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ChartPanel->Location = System::Drawing::Point(850, 113);
			this->ChartPanel->Name = L"ChartPanel";
			this->ChartPanel->Size = System::Drawing::Size(801, 447);
			this->ChartPanel->TabIndex = 5;
			// 
			// label9
			// 
			this->label9->AccessibleName = L"catSearchLab";
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label9.Image")));
			this->label9->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label9->Location = System::Drawing::Point(1006, 12);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->MinimumSize = System::Drawing::Size(110, 60);
			this->label9->Name = L"label9";
			this->label9->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label9->Size = System::Drawing::Size(110, 60);
			this->label9->TabIndex = 15;
			this->label9->Text = L"البحث";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label10
			// 
			this->label10->AccessibleName = L"catSearchLab";
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label10.Image")));
			this->label10->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label10->Location = System::Drawing::Point(1024, 13);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->MinimumSize = System::Drawing::Size(110, 60);
			this->label10->Name = L"label10";
			this->label10->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label10->Size = System::Drawing::Size(110, 60);
			this->label10->TabIndex = 16;
			this->label10->Text = L"البحث";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Dashboard
			// 
			this->AccessibleName = L"DashboardFrame";
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ClientSize = System::Drawing::Size(1920, 1055);
			this->Controls->Add(this->CenterPanel);
			this->Controls->Add(this->RightPanel);
			this->Controls->Add(this->FooterPanel);
			this->Controls->Add(this->headerPanel);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Dashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dashboard";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Dashboard::Dashboard_Load);
			this->headerPanel->ResumeLayout(false);
			this->headerPanel->PerformLayout();
			this->FooterPanel->ResumeLayout(false);
			this->FooterPanel->PerformLayout();
			this->RightPanel->ResumeLayout(false);
			this->NavPanel->ResumeLayout(false);
			this->UserPanel->ResumeLayout(false);
			this->CenterPanel->ResumeLayout(false);
			this->stockPanel->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->InvoiceHeaderContainer->ResumeLayout(false);
			this->InvoiceHeaderTitlepanel->ResumeLayout(false);
			this->InvoiceHeaderTitlepanel->PerformLayout();
			this->InvoiceHeaderTableContainer->ResumeLayout(false);
			this->SearchInvoiceHeaderPanel->ResumeLayout(false);
			this->SearchInvoiceHeaderPanel->PerformLayout();
			this->SearchInvoiceHeaderContainer->ResumeLayout(false);
			this->SearchInvoiceHeaderContainer->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InvoiceHeaderTable))->EndInit();
			this->InvoiceDetailsContainer->ResumeLayout(false);
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
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
			this->ManageSaleContainer->ResumeLayout(false);
			this->ManageSalePanel->ResumeLayout(false);
			this->ManageSalePanel->PerformLayout();
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->payFeildContainer->ResumeLayout(false);
			this->payFeildContainer->PerformLayout();
			this->panel15->ResumeLayout(false);
			this->panel15->PerformLayout();
			this->HomePanel->ResumeLayout(false);
			this->HomePanel->PerformLayout();
			this->fastNav->ResumeLayout(false);
			this->Cards->ResumeLayout(false);
			this->CardPanelHead->ResumeLayout(false);
			this->CardPanelHead->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion


		

	private: System::Void ShowHideFormButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ManageProductContainer->Visible == true) {
			ManageProductContainer->Visible = false;
		}
		else {
			ManageProductContainer->Visible = true;
		}
		{

		}
	}
private: System::Void showHideInvoiceDetails_Click(System::Object^ sender, System::EventArgs^ e) {
	if (InvoiceDetailsPanel->Visible==true)
	{
		InvoiceDetailsPanel->Visible = false;

	}else{
		InvoiceDetailsPanel->Visible = true;
	}
}
private: System::Void ShowHideSaleFormPanel_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ManageSalePanel->Visible==true)
	{
		ManageSalePanel->Visible = false;

	}
	else
	{
		ManageSalePanel->Visible = true;

	}

}
private: System::Void ShowHideSaletable_Click(System::Object^ sender, System::EventArgs^ e) {
	if (CashierTable->Visible == true) 
		{
		CashierTable->Visible = false;

		}
	else {
		CashierTable->Visible = true;

	}
	}

private: System::Void userBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (currentUser == nullptr || currentPharmacy == nullptr) {
		MessageBox::Show("No user or pharmacy found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Pass the current user and pharmacy to the Profile screen
	Profile^ profileScreen = gcnew Profile(currentUser, currentPharmacy);
	profileScreen->Show();
}
private: System::Void totalSales_Click(System::Object^ sender, System::EventArgs^ e) {
	calculator^ calculatorFrame = gcnew calculator();
	calculatorFrame->Show();
}

private: System::Void showHideInvoiceTable_Click(System::Object^ sender, System::EventArgs^ e) {
	if (InvoiceHeaderTable->Visible==true)
	{
		InvoiceHeaderTable->Visible = false;
	}
	else {
		InvoiceHeaderTable->Visible = true;
	}
}
	   //Category Exportation
private: System::Void exportToexcelBtnCat_Click(System::Object^ sender, System::EventArgs^ e) {
	UIHelper::ExportTableToCsv(CategoryTable );
}
private: System::Void PrintToPdfBtnCat_Click(System::Object^ sender, System::EventArgs^ e) {
	UIHelper::PrintTable(CategoryTable);
}
	   //product exportation
private: System::Void exportToexcelBtnProd_Click(System::Object^ sender, System::EventArgs^ e) {
	UIHelper::ExportTableToCsv(ProductTable);
}
	   //Supplier Exportation
private: System::Void exportToexcelBtnSup_Click(System::Object^ sender, System::EventArgs^ e) {
	UIHelper::ExportTableToCsv(SupplierTable);
}
private: System::Void PrintToPdfBtnSup_Click(System::Object^ sender, System::EventArgs^ e) {
	UIHelper::PrintTable(SupplierTable);
}
	   //Invoices Exportation
private: System::Void PrintToPdfBtnInv_Click(System::Object^ sender, System::EventArgs^ e) {
	UIHelper::PrintTable(InvoiceHeaderTable);
}
private: System::Void exportToexcelBtnInv_Click(System::Object^ sender, System::EventArgs^ e) {
	UIHelper::ExportTableToCsv(InvoiceHeaderTable);
}
};
}