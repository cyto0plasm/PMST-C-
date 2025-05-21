#pragma once

namespace PMST {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for calculator
	/// </summary>
	public ref class calculator : public System::Windows::Forms::Form
	{
	public:
		calculator(void)
		{
			InitializeComponent();
			AttachMouseHandlers(this);

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~calculator()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		//Dragging variables
		bool dragging = false;
		System::Drawing::Point dragCursorPoint;
		System::Drawing::Point dragFormPoint;
		//esxpression variables
		double lastResult = 0;
		double lastOperand = 0;
		wchar_t lastOperator = '\0';
		bool justEvaluated = false; System::Windows::Forms::TextBox^ ResultText;
	protected:

	private: System::Windows::Forms::Panel^ ResultPanel;




	private: System::Windows::Forms::FlowLayoutPanel^ OutputPanel;



	private: System::Windows::Forms::Panel^ container;

	private: System::Windows::Forms::Panel^ ControlPanel;
	private: System::Windows::Forms::FlowLayoutPanel^ InputPanel;
	private: System::Windows::Forms::Button^ clear;
	private: System::Windows::Forms::Button^ deleteOne;

	private: System::Windows::Forms::Button^ seven;
	private: System::Windows::Forms::Button^ eight;
	private: System::Windows::Forms::Button^ nine;
	private: System::Windows::Forms::Button^ mul;
	private: System::Windows::Forms::Button^ four;
	private: System::Windows::Forms::Button^ five;
	private: System::Windows::Forms::Button^ sex;
	private: System::Windows::Forms::Button^ minus;
	private: System::Windows::Forms::Button^ one;
	private: System::Windows::Forms::Button^ two;
	private: System::Windows::Forms::Button^ three;
	private: System::Windows::Forms::Button^ plus;
	private: System::Windows::Forms::Button^ zero;
	private: System::Windows::Forms::Button^ dot;
	private: System::Windows::Forms::Button^ equals;
	private: System::Windows::Forms::Button^ posNig;
	private: System::Windows::Forms::Label^ ExpressionLabel;
	private: System::Windows::Forms::Button^ paste;

	private: System::Windows::Forms::Button^ copy;
	private: System::Windows::Forms::Button^ modulus;
	private: System::Windows::Forms::Button^ root;
	private: System::Windows::Forms::Button^ exponent;
	private: System::Windows::Forms::Button^ div;
	private: System::Windows::Forms::Button^ closeBtn;





























	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(calculator::typeid));
			this->ResultText = (gcnew System::Windows::Forms::TextBox());
			this->ResultPanel = (gcnew System::Windows::Forms::Panel());
			this->closeBtn = (gcnew System::Windows::Forms::Button());
			this->OutputPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ExpressionLabel = (gcnew System::Windows::Forms::Label());
			this->container = (gcnew System::Windows::Forms::Panel());
			this->InputPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->copy = (gcnew System::Windows::Forms::Button());
			this->paste = (gcnew System::Windows::Forms::Button());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->deleteOne = (gcnew System::Windows::Forms::Button());
			this->modulus = (gcnew System::Windows::Forms::Button());
			this->root = (gcnew System::Windows::Forms::Button());
			this->exponent = (gcnew System::Windows::Forms::Button());
			this->div = (gcnew System::Windows::Forms::Button());
			this->seven = (gcnew System::Windows::Forms::Button());
			this->eight = (gcnew System::Windows::Forms::Button());
			this->nine = (gcnew System::Windows::Forms::Button());
			this->mul = (gcnew System::Windows::Forms::Button());
			this->four = (gcnew System::Windows::Forms::Button());
			this->five = (gcnew System::Windows::Forms::Button());
			this->sex = (gcnew System::Windows::Forms::Button());
			this->minus = (gcnew System::Windows::Forms::Button());
			this->one = (gcnew System::Windows::Forms::Button());
			this->two = (gcnew System::Windows::Forms::Button());
			this->three = (gcnew System::Windows::Forms::Button());
			this->plus = (gcnew System::Windows::Forms::Button());
			this->posNig = (gcnew System::Windows::Forms::Button());
			this->zero = (gcnew System::Windows::Forms::Button());
			this->dot = (gcnew System::Windows::Forms::Button());
			this->equals = (gcnew System::Windows::Forms::Button());
			this->ControlPanel = (gcnew System::Windows::Forms::Panel());
			this->ResultPanel->SuspendLayout();
			this->OutputPanel->SuspendLayout();
			this->container->SuspendLayout();
			this->InputPanel->SuspendLayout();
			this->ControlPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// ResultText
			// 
			this->ResultText->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->ResultText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ResultText->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ResultText->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ResultText->ForeColor = System::Drawing::Color::White;
			this->ResultText->Location = System::Drawing::Point(0, 0);
			this->ResultText->Margin = System::Windows::Forms::Padding(0);
			this->ResultText->Multiline = true;
			this->ResultText->Name = L"ResultText";
			this->ResultText->Size = System::Drawing::Size(450, 91);
			this->ResultText->TabIndex = 0;
			// 
			// ResultPanel
			// 
			this->ResultPanel->Controls->Add(this->closeBtn);
			this->ResultPanel->Controls->Add(this->ResultText);
			this->ResultPanel->Location = System::Drawing::Point(0, 60);
			this->ResultPanel->Margin = System::Windows::Forms::Padding(0);
			this->ResultPanel->Name = L"ResultPanel";
			this->ResultPanel->Size = System::Drawing::Size(450, 91);
			this->ResultPanel->TabIndex = 1;
			// 
			// closeBtn
			// 
			this->closeBtn->AccessibleName = L"closeBtn";
			this->closeBtn->FlatAppearance->BorderSize = 0;
			this->closeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeBtn->ForeColor = System::Drawing::SystemColors::ControlText;
			this->closeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeBtn.Image")));
			this->closeBtn->Location = System::Drawing::Point(383, 37);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(64, 51);
			this->closeBtn->TabIndex = 1;
			this->closeBtn->UseVisualStyleBackColor = true;
			this->closeBtn->Click += gcnew System::EventHandler(this, &calculator::closeBtn_Click);
			// 
			// OutputPanel
			// 
			this->OutputPanel->Controls->Add(this->ExpressionLabel);
			this->OutputPanel->Controls->Add(this->ResultPanel);
			this->OutputPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->OutputPanel->Location = System::Drawing::Point(0, 0);
			this->OutputPanel->Name = L"OutputPanel";
			this->OutputPanel->Size = System::Drawing::Size(450, 154);
			this->OutputPanel->TabIndex = 5;
			// 
			// ExpressionLabel
			// 
			this->ExpressionLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->ExpressionLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->ExpressionLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ExpressionLabel->ForeColor = System::Drawing::Color::Silver;
			this->ExpressionLabel->Location = System::Drawing::Point(0, 0);
			this->ExpressionLabel->Margin = System::Windows::Forms::Padding(0);
			this->ExpressionLabel->Name = L"ExpressionLabel";
			this->ExpressionLabel->Size = System::Drawing::Size(450, 60);
			this->ExpressionLabel->TabIndex = 1;
			this->ExpressionLabel->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// container
			// 
			this->container->Controls->Add(this->InputPanel);
			this->container->Controls->Add(this->ControlPanel);
			this->container->Dock = System::Windows::Forms::DockStyle::Fill;
			this->container->Location = System::Drawing::Point(0, 0);
			this->container->Name = L"container";
			this->container->Size = System::Drawing::Size(450, 678);
			this->container->TabIndex = 6;
			// 
			// InputPanel
			// 
			this->InputPanel->Controls->Add(this->copy);
			this->InputPanel->Controls->Add(this->paste);
			this->InputPanel->Controls->Add(this->clear);
			this->InputPanel->Controls->Add(this->deleteOne);
			this->InputPanel->Controls->Add(this->modulus);
			this->InputPanel->Controls->Add(this->root);
			this->InputPanel->Controls->Add(this->exponent);
			this->InputPanel->Controls->Add(this->div);
			this->InputPanel->Controls->Add(this->seven);
			this->InputPanel->Controls->Add(this->eight);
			this->InputPanel->Controls->Add(this->nine);
			this->InputPanel->Controls->Add(this->mul);
			this->InputPanel->Controls->Add(this->four);
			this->InputPanel->Controls->Add(this->five);
			this->InputPanel->Controls->Add(this->sex);
			this->InputPanel->Controls->Add(this->minus);
			this->InputPanel->Controls->Add(this->one);
			this->InputPanel->Controls->Add(this->two);
			this->InputPanel->Controls->Add(this->three);
			this->InputPanel->Controls->Add(this->plus);
			this->InputPanel->Controls->Add(this->posNig);
			this->InputPanel->Controls->Add(this->zero);
			this->InputPanel->Controls->Add(this->dot);
			this->InputPanel->Controls->Add(this->equals);
			this->InputPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->InputPanel->Location = System::Drawing::Point(0, 155);
			this->InputPanel->Name = L"InputPanel";
			this->InputPanel->Size = System::Drawing::Size(450, 523);
			this->InputPanel->TabIndex = 5;
			// 
			// copy
			// 
			this->copy->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->copy->FlatAppearance->BorderSize = 0;
			this->copy->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->copy->Font = (gcnew System::Drawing::Font(L"Consolas", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->copy->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->copy->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"copy.Image")));
			this->copy->Location = System::Drawing::Point(3, 3);
			this->copy->Name = L"copy";
			this->copy->Size = System::Drawing::Size(104, 70);
			this->copy->TabIndex = 1;
			this->copy->UseVisualStyleBackColor = false;
			this->copy->Click += gcnew System::EventHandler(this, &calculator::copy_Click);
			// 
			// paste
			// 
			this->paste->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->paste->FlatAppearance->BorderSize = 0;
			this->paste->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->paste->Font = (gcnew System::Drawing::Font(L"Consolas", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->paste->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->paste->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"paste.Image")));
			this->paste->Location = System::Drawing::Point(113, 3);
			this->paste->Name = L"paste";
			this->paste->Size = System::Drawing::Size(104, 70);
			this->paste->TabIndex = 1;
			this->paste->UseVisualStyleBackColor = false;
			this->paste->Click += gcnew System::EventHandler(this, &calculator::paste_Click);
			// 
			// clear
			// 
			this->clear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->clear->FlatAppearance->BorderSize = 0;
			this->clear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->clear->Font = (gcnew System::Drawing::Font(L"Consolas", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clear->ForeColor = System::Drawing::Color::Tomato;
			this->clear->Location = System::Drawing::Point(225, 3);
			this->clear->Margin = System::Windows::Forms::Padding(5, 3, 3, 3);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(104, 70);
			this->clear->TabIndex = 1;
			this->clear->Text = L"C";
			this->clear->UseVisualStyleBackColor = false;
			this->clear->Click += gcnew System::EventHandler(this, &calculator::clear_Click);
			// 
			// deleteOne
			// 
			this->deleteOne->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->deleteOne->FlatAppearance->BorderSize = 0;
			this->deleteOne->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deleteOne->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deleteOne->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->deleteOne->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"deleteOne.Image")));
			this->deleteOne->Location = System::Drawing::Point(335, 3);
			this->deleteOne->Name = L"deleteOne";
			this->deleteOne->Size = System::Drawing::Size(110, 70);
			this->deleteOne->TabIndex = 1;
			this->deleteOne->UseVisualStyleBackColor = false;
			this->deleteOne->Click += gcnew System::EventHandler(this, &calculator::deleteOne_Click);
			// 
			// modulus
			// 
			this->modulus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->modulus->FlatAppearance->BorderSize = 0;
			this->modulus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->modulus->Font = (gcnew System::Drawing::Font(L"Consolas", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->modulus->ForeColor = System::Drawing::Color::White;
			this->modulus->Location = System::Drawing::Point(3, 79);
			this->modulus->Name = L"modulus";
			this->modulus->Size = System::Drawing::Size(104, 70);
			this->modulus->TabIndex = 1;
			this->modulus->Text = L"%";
			this->modulus->UseVisualStyleBackColor = false;
			this->modulus->Click += gcnew System::EventHandler(this, &calculator::modulus_Click);
			// 
			// root
			// 
			this->root->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->root->FlatAppearance->BorderSize = 0;
			this->root->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->root->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->root->ForeColor = System::Drawing::Color::White;
			this->root->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"root.Image")));
			this->root->Location = System::Drawing::Point(115, 79);
			this->root->Margin = System::Windows::Forms::Padding(5, 3, 3, 3);
			this->root->Name = L"root";
			this->root->Size = System::Drawing::Size(104, 70);
			this->root->TabIndex = 1;
			this->root->UseVisualStyleBackColor = false;
			this->root->Click += gcnew System::EventHandler(this, &calculator::root_Click);
			// 
			// exponent
			// 
			this->exponent->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->exponent->FlatAppearance->BorderSize = 0;
			this->exponent->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exponent->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exponent->ForeColor = System::Drawing::Color::White;
			this->exponent->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exponent.Image")));
			this->exponent->Location = System::Drawing::Point(225, 79);
			this->exponent->Name = L"exponent";
			this->exponent->Size = System::Drawing::Size(104, 70);
			this->exponent->TabIndex = 1;
			this->exponent->UseVisualStyleBackColor = false;
			this->exponent->Click += gcnew System::EventHandler(this, &calculator::exponent_Click);
			// 
			// div
			// 
			this->div->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->div->FlatAppearance->BorderSize = 0;
			this->div->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->div->Font = (gcnew System::Drawing::Font(L"Consolas", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->div->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->div->Location = System::Drawing::Point(335, 79);
			this->div->Name = L"div";
			this->div->Size = System::Drawing::Size(110, 70);
			this->div->TabIndex = 1;
			this->div->Text = L"÷";
			this->div->UseVisualStyleBackColor = false;
			this->div->Click += gcnew System::EventHandler(this, &calculator::div_Click);
			// 
			// seven
			// 
			this->seven->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->seven->FlatAppearance->BorderSize = 0;
			this->seven->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->seven->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->seven->ForeColor = System::Drawing::Color::White;
			this->seven->Location = System::Drawing::Point(5, 155);
			this->seven->Margin = System::Windows::Forms::Padding(5, 3, 3, 3);
			this->seven->Name = L"seven";
			this->seven->Size = System::Drawing::Size(104, 70);
			this->seven->TabIndex = 2;
			this->seven->Text = L"7";
			this->seven->UseVisualStyleBackColor = false;
			this->seven->Click += gcnew System::EventHandler(this, &calculator::seven_Click);
			// 
			// eight
			// 
			this->eight->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->eight->FlatAppearance->BorderSize = 0;
			this->eight->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->eight->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->eight->ForeColor = System::Drawing::Color::White;
			this->eight->Location = System::Drawing::Point(115, 155);
			this->eight->Name = L"eight";
			this->eight->Size = System::Drawing::Size(104, 70);
			this->eight->TabIndex = 3;
			this->eight->Text = L"8";
			this->eight->UseVisualStyleBackColor = false;
			this->eight->Click += gcnew System::EventHandler(this, &calculator::eight_Click);
			// 
			// nine
			// 
			this->nine->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->nine->FlatAppearance->BorderSize = 0;
			this->nine->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->nine->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nine->ForeColor = System::Drawing::Color::White;
			this->nine->Location = System::Drawing::Point(225, 155);
			this->nine->Name = L"nine";
			this->nine->Size = System::Drawing::Size(104, 70);
			this->nine->TabIndex = 4;
			this->nine->Text = L"9";
			this->nine->UseVisualStyleBackColor = false;
			this->nine->Click += gcnew System::EventHandler(this, &calculator::nine_Click);
			// 
			// mul
			// 
			this->mul->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->mul->FlatAppearance->BorderSize = 0;
			this->mul->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mul->Font = (gcnew System::Drawing::Font(L"Consolas", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mul->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->mul->Location = System::Drawing::Point(335, 155);
			this->mul->Name = L"mul";
			this->mul->Size = System::Drawing::Size(110, 70);
			this->mul->TabIndex = 5;
			this->mul->Text = L"x";
			this->mul->UseVisualStyleBackColor = false;
			this->mul->Click += gcnew System::EventHandler(this, &calculator::mul_Click);
			// 
			// four
			// 
			this->four->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->four->FlatAppearance->BorderSize = 0;
			this->four->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->four->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->four->ForeColor = System::Drawing::Color::White;
			this->four->Location = System::Drawing::Point(5, 231);
			this->four->Margin = System::Windows::Forms::Padding(5, 3, 3, 3);
			this->four->Name = L"four";
			this->four->Size = System::Drawing::Size(104, 70);
			this->four->TabIndex = 6;
			this->four->Text = L"4";
			this->four->UseVisualStyleBackColor = false;
			this->four->Click += gcnew System::EventHandler(this, &calculator::four_Click);
			// 
			// five
			// 
			this->five->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->five->FlatAppearance->BorderSize = 0;
			this->five->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->five->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->five->ForeColor = System::Drawing::Color::White;
			this->five->Location = System::Drawing::Point(115, 231);
			this->five->Name = L"five";
			this->five->Size = System::Drawing::Size(104, 70);
			this->five->TabIndex = 7;
			this->five->Text = L"5";
			this->five->UseVisualStyleBackColor = false;
			this->five->Click += gcnew System::EventHandler(this, &calculator::five_Click);
			// 
			// sex
			// 
			this->sex->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->sex->FlatAppearance->BorderSize = 0;
			this->sex->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sex->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sex->ForeColor = System::Drawing::Color::White;
			this->sex->Location = System::Drawing::Point(225, 231);
			this->sex->Name = L"sex";
			this->sex->Size = System::Drawing::Size(104, 70);
			this->sex->TabIndex = 8;
			this->sex->Text = L"6";
			this->sex->UseVisualStyleBackColor = false;
			this->sex->Click += gcnew System::EventHandler(this, &calculator::sex_Click);
			// 
			// minus
			// 
			this->minus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->minus->FlatAppearance->BorderSize = 0;
			this->minus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->minus->Font = (gcnew System::Drawing::Font(L"Consolas", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->minus->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->minus->Location = System::Drawing::Point(335, 231);
			this->minus->Name = L"minus";
			this->minus->Size = System::Drawing::Size(110, 70);
			this->minus->TabIndex = 9;
			this->minus->Text = L"-";
			this->minus->UseVisualStyleBackColor = false;
			this->minus->Click += gcnew System::EventHandler(this, &calculator::minus_Click);
			// 
			// one
			// 
			this->one->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->one->FlatAppearance->BorderSize = 0;
			this->one->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->one->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->one->ForeColor = System::Drawing::Color::White;
			this->one->Location = System::Drawing::Point(5, 307);
			this->one->Margin = System::Windows::Forms::Padding(5, 3, 3, 3);
			this->one->Name = L"one";
			this->one->Size = System::Drawing::Size(104, 70);
			this->one->TabIndex = 10;
			this->one->Text = L"1";
			this->one->UseVisualStyleBackColor = false;
			this->one->Click += gcnew System::EventHandler(this, &calculator::one_Click);
			// 
			// two
			// 
			this->two->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->two->FlatAppearance->BorderSize = 0;
			this->two->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->two->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->two->ForeColor = System::Drawing::Color::White;
			this->two->Location = System::Drawing::Point(115, 307);
			this->two->Name = L"two";
			this->two->Size = System::Drawing::Size(104, 70);
			this->two->TabIndex = 11;
			this->two->Text = L"2";
			this->two->UseVisualStyleBackColor = false;
			this->two->Click += gcnew System::EventHandler(this, &calculator::two_Click);
			// 
			// three
			// 
			this->three->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->three->FlatAppearance->BorderSize = 0;
			this->three->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->three->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->three->ForeColor = System::Drawing::Color::White;
			this->three->Location = System::Drawing::Point(225, 307);
			this->three->Name = L"three";
			this->three->Size = System::Drawing::Size(104, 70);
			this->three->TabIndex = 12;
			this->three->Text = L"3";
			this->three->UseVisualStyleBackColor = false;
			this->three->Click += gcnew System::EventHandler(this, &calculator::three_Click);
			// 
			// plus
			// 
			this->plus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->plus->FlatAppearance->BorderSize = 0;
			this->plus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->plus->Font = (gcnew System::Drawing::Font(L"Consolas", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->plus->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->plus->Location = System::Drawing::Point(335, 307);
			this->plus->Name = L"plus";
			this->plus->Size = System::Drawing::Size(110, 70);
			this->plus->TabIndex = 13;
			this->plus->Text = L"+";
			this->plus->UseVisualStyleBackColor = false;
			this->plus->Click += gcnew System::EventHandler(this, &calculator::plus_Click);
			// 
			// posNig
			// 
			this->posNig->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->posNig->FlatAppearance->BorderSize = 0;
			this->posNig->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->posNig->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posNig->ForeColor = System::Drawing::Color::White;
			this->posNig->Location = System::Drawing::Point(5, 383);
			this->posNig->Margin = System::Windows::Forms::Padding(5, 3, 3, 3);
			this->posNig->Name = L"posNig";
			this->posNig->Size = System::Drawing::Size(104, 70);
			this->posNig->TabIndex = 18;
			this->posNig->Text = L"+/-";
			this->posNig->UseVisualStyleBackColor = false;
			// 
			// zero
			// 
			this->zero->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->zero->FlatAppearance->BorderSize = 0;
			this->zero->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->zero->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->zero->ForeColor = System::Drawing::Color::White;
			this->zero->Location = System::Drawing::Point(117, 383);
			this->zero->Margin = System::Windows::Forms::Padding(5, 3, 3, 3);
			this->zero->Name = L"zero";
			this->zero->Size = System::Drawing::Size(104, 70);
			this->zero->TabIndex = 14;
			this->zero->Text = L"0";
			this->zero->UseVisualStyleBackColor = false;
			this->zero->Click += gcnew System::EventHandler(this, &calculator::zero_Click);
			// 
			// dot
			// 
			this->dot->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->dot->FlatAppearance->BorderSize = 0;
			this->dot->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dot->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dot->ForeColor = System::Drawing::Color::White;
			this->dot->Location = System::Drawing::Point(227, 383);
			this->dot->Name = L"dot";
			this->dot->Size = System::Drawing::Size(104, 70);
			this->dot->TabIndex = 16;
			this->dot->Text = L".";
			this->dot->UseVisualStyleBackColor = false;
			this->dot->Click += gcnew System::EventHandler(this, &calculator::dot_Click);
			// 
			// equals
			// 
			this->equals->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)), static_cast<System::Int32>(static_cast<System::Byte>(118)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->equals->FlatAppearance->BorderSize = 0;
			this->equals->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->equals->Font = (gcnew System::Drawing::Font(L"Consolas", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->equals->ForeColor = System::Drawing::Color::White;
			this->equals->Location = System::Drawing::Point(337, 383);
			this->equals->Name = L"equals";
			this->equals->Size = System::Drawing::Size(110, 70);
			this->equals->TabIndex = 17;
			this->equals->Text = L"=";
			this->equals->UseVisualStyleBackColor = false;
			this->equals->Click += gcnew System::EventHandler(this, &calculator::equals_Click);
			// 
			// ControlPanel
			// 
			this->ControlPanel->Controls->Add(this->OutputPanel);
			this->ControlPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->ControlPanel->Location = System::Drawing::Point(0, 0);
			this->ControlPanel->Name = L"ControlPanel";
			this->ControlPanel->Size = System::Drawing::Size(450, 155);
			this->ControlPanel->TabIndex = 4;
			// 
			// calculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ClientSize = System::Drawing::Size(450, 678);
			this->Controls->Add(this->container);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->KeyPreview = true;
			this->Name = L"calculator";
			this->Text = L"calculator";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &calculator::calculator_KeyDown);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &calculator::calculator_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &calculator::calculator_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &calculator::calculator_MouseUp);
			this->ResultPanel->ResumeLayout(false);
			this->ResultPanel->PerformLayout();
			this->OutputPanel->ResumeLayout(false);
			this->container->ResumeLayout(false);
			this->InputPanel->ResumeLayout(false);
			this->ControlPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dot_Click(System::Object^ sender, System::EventArgs^ e) {
		ResultText->Text += ".";

	}
	private: System::Void zero_Click(System::Object^ sender, System::EventArgs^ e) {
		AppendNumber("0");
	}
	private: System::Void one_Click(System::Object^ sender, System::EventArgs^ e) {
		AppendNumber("1");
	}
	private: System::Void two_Click(System::Object^ sender, System::EventArgs^ e) {
		AppendNumber("2");
	}
	private: System::Void three_Click(System::Object^ sender, System::EventArgs^ e) {
		AppendNumber("3");
	}
	private: System::Void four_Click(System::Object^ sender, System::EventArgs^ e) {
		AppendNumber("4");
	}
	private: System::Void five_Click(System::Object^ sender, System::EventArgs^ e) {
		AppendNumber("5");
	}
	private: System::Void sex_Click(System::Object^ sender, System::EventArgs^ e) {
		AppendNumber("6");
	}
	private: System::Void seven_Click(System::Object^ sender, System::EventArgs^ e) {
		AppendNumber("7");
	}
	private: System::Void eight_Click(System::Object^ sender, System::EventArgs^ e) {
		AppendNumber("8");
	}
	private: System::Void nine_Click(System::Object^ sender, System::EventArgs^ e) {
		AppendNumber("9");
	}

	private: System::Void div_Click(System::Object^ sender, System::EventArgs^ e) {
		AppendOperatorIfValid('/');
	}
	private: System::Void mul_Click(System::Object^ sender, System::EventArgs^ e) {
		AppendOperatorIfValid('*');
	}
	private: System::Void minus_Click(System::Object^ sender, System::EventArgs^ e) {
		AppendOperatorIfValid('-');
	}
	private: System::Void plus_Click(System::Object^ sender, System::EventArgs^ e) {
		AppendOperatorIfValid('+');
	}
	private: System::Void modulus_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ text = ResultText->Text;
		if (text->Length > 0 && Char::IsDigit(text[text->Length - 1])) {
			ResultText->Text += "%";
		}
	}
	private: System::Void root_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			double value = Convert::ToDouble(ResultText->Text);
			if (value < 0) {
				ResultText->Text = "Error";
				ExpressionLabel->Text = "";
			}
			else {
				double result = Math::Sqrt(value);
				ExpressionLabel->Text = "sqrt(" + ResultText->Text + ")";
				ResultText->Text = result.ToString();
				justEvaluated = true;
			}
		}
		catch (Exception^) {
			ResultText->Text = "Error";
			ExpressionLabel->Text = "";
		}
	}

	private: System::Void exponent_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			double value = Convert::ToDouble(ResultText->Text);
			double result = Math::Pow(value, 2);
			ExpressionLabel->Text = "(" + ResultText->Text + ")²";
			ResultText->Text = result.ToString();
			justEvaluated = true;
		}
		catch (Exception^) {
			ResultText->Text = "Error";
		}
	}

	private: System::Void equals_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (!justEvaluated) {
				String^ expression = ResultText->Text;

				// Show expression in gray label
				ExpressionLabel->Text = expression;

				// Evaluate
				System::Data::DataTable^ table = gcnew System::Data::DataTable();
				Object^ result = table->Compute(expression, nullptr);
				lastResult = Convert::ToDouble(result);

				// Extract last operator/operand
				int plusIndex = expression->LastIndexOf('+');
				int minusIndex = expression->LastIndexOf('-');
				int mulIndex = expression->LastIndexOf('*');
				int divIndex = expression->LastIndexOf('/');

				int lastOpIndex = Math::Max(
					Math::Max(plusIndex, minusIndex),
					Math::Max(mulIndex, divIndex));

				if (lastOpIndex != -1 && lastOpIndex < expression->Length - 1) {
					lastOperator = expression[lastOpIndex];
					String^ operandStr = expression->Substring(lastOpIndex + 1);
					lastOperand = Convert::ToDouble(operandStr);
				}
				else {
					lastOperator = '\0';
					lastOperand = 0;
				}

				ResultText->Text = lastResult.ToString();
				justEvaluated = true;
			}
			else {
				// Repeat last operation
				switch (lastOperator) {
				case '+': lastResult += lastOperand; break;
				case '-': lastResult -= lastOperand; break;
				case '*': lastResult *= lastOperand; break;
				case '/':
					if (lastOperand != 0)
						lastResult /= lastOperand;
					else {
						ResultText->Text = "Error: Division by zero";
						return;
					}
					break;
				default: return;
				}
				ResultText->Text = lastResult.ToString();
				ExpressionLabel->Text = ResultText->Text + " " + lastOperator + " " + lastOperand;
			}
		}
		catch (Exception^) {
			ResultText->Text = "Error";
		}
	}

	private: System::Void deleteOne_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ text = ResultText->Text;
		if (text->Length > 1) {
			ResultText->Text = text->Substring(0, text->Length - 1);
		}
		else {
			ResultText->Text = "0";
		}
	}
	private: System::Void clear_Click(System::Object^ sender, System::EventArgs^ e) {
		ResultText->Text = "0";
		ExpressionLabel->Text = "";
		lastOperator = '\0';
		lastOperand = 0;
		lastResult = 0;
		justEvaluated = false;
	}

	private: System::Void copy_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!String::IsNullOrEmpty(ResultText->Text)) {
			Clipboard::SetText(ResultText->Text);
		}
	}
	private: System::Void paste_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ clipboardText = Clipboard::GetText();
	double value;

	// Accept only valid numbers
	if (Double::TryParse(clipboardText, value)) {
		if (justEvaluated || ResultText->Text == "0") {
			ResultText->Text = clipboardText;
			justEvaluated = false;
		}
		else {
			ResultText->Text += clipboardText;
		}
	}
}

	private: void AppendNumber(String^ num) {
		if (justEvaluated) {
			ResultText->Text = num;
			justEvaluated = false;
		}
		else if (ResultText->Text == "0") {
			ResultText->Text = num;
		}
		else {
			ResultText->Text += num;
		}
	}
	private: void AppendOperatorIfValid(wchar_t op) {
		String^ text = ResultText->Text;

		if (text->Length == 0)
			return;

		wchar_t lastChar = text[text->Length - 1];
		if (!IsOperator(lastChar)) {
			ResultText->Text += op;
			justEvaluated = false;
		}
	}
	private: bool IsOperator(wchar_t ch) {
		return ch == '+' || ch == '-' || ch == '*' || ch == '/';
	}

	private: System::Void calculator_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			dragging = true;
			dragCursorPoint = Cursor->Position;
			dragFormPoint = this->Location;
		}
	}
private: System::Void calculator_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (dragging) {
		System::Drawing::Point diff = System::Drawing::Point(Cursor->Position.X - dragCursorPoint.X, Cursor->Position.Y - dragCursorPoint.Y);


		this->Location = System::Drawing::Point(dragFormPoint.X + diff.X, dragFormPoint.Y + diff.Y);
	}
}
private: System::Void calculator_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		dragging = false;
	}
}
	   void AttachMouseHandlers(Control^ ctrl) {
		   ctrl->MouseDown += gcnew MouseEventHandler(this, &calculator::calculator_MouseDown);
		   ctrl->MouseMove += gcnew MouseEventHandler(this, &calculator::calculator_MouseMove);
		   ctrl->MouseUp += gcnew MouseEventHandler(this, &calculator::calculator_MouseUp);
		   for each (Control ^ child in ctrl->Controls) {
			   AttachMouseHandlers(child);
		   }
	   }
private: System::Void calculator_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == System::Windows::Forms::Keys::Escape) {
		this->Close();
	}
}
private: System::Void closeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
