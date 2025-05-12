#pragma once
#include "../Forms/Login.h"
#include "../Controllers/UsersController.h"
#include "../Controllers/PharmaciesController.h"

namespace PMST {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Register : public System::Windows::Forms::Form
    {
    public:
        Register(void);
    protected:
        ~Register();
    private:
        System::Void NavToLoginBtn_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void RegisterBtn_Click(System::Object^ sender, System::EventArgs^ e);

    private:
        System::Windows::Forms::Panel^ mainPanel;
        System::Windows::Forms::Panel^ headerPanel;
        System::Windows::Forms::Label^ headerLabel;
        System::Windows::Forms::Panel^ formContainer;
        System::Windows::Forms::Panel^ userPanel;
        System::Windows::Forms::Panel^ pharmacyPanel;

        // User controls
        System::Windows::Forms::Label^ userSectionLabel;
        System::Windows::Forms::TextBox^ nameTextBox;
        System::Windows::Forms::Label^ nameLabel;

        System::Windows::Forms::Label^ emailLabel;
        System::Windows::Forms::TextBox^ passwordTextBox;
        System::Windows::Forms::Label^ passwordLabel;
        System::Windows::Forms::TextBox^ confirmPasswordTextBox;
        System::Windows::Forms::Label^ confirmPasswordLabel;

        // Pharmacy controls
        System::Windows::Forms::Label^ pharmacySectionLabel;
        System::Windows::Forms::TextBox^ pharmacyNameTextBox;
        System::Windows::Forms::Label^ pharmacyNameLabel;
        System::Windows::Forms::TextBox^ pharmacyLocationTextBox;
        System::Windows::Forms::Label^ pharmacyLocationLabel;

        // Buttons
        System::Windows::Forms::Button^ registerButton;
        System::Windows::Forms::Button^ loginButton;
        System::Windows::Forms::Panel^ buttonPanel;
    private: System::Windows::Forms::TextBox^ emailTextBox;

    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->mainPanel = (gcnew System::Windows::Forms::Panel());
            this->formContainer = (gcnew System::Windows::Forms::Panel());
            this->buttonPanel = (gcnew System::Windows::Forms::Panel());
            this->registerButton = (gcnew System::Windows::Forms::Button());
            this->loginButton = (gcnew System::Windows::Forms::Button());
            this->pharmacyPanel = (gcnew System::Windows::Forms::Panel());
            this->pharmacyLocationTextBox = (gcnew System::Windows::Forms::TextBox());
            this->pharmacyLocationLabel = (gcnew System::Windows::Forms::Label());
            this->pharmacyNameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->pharmacyNameLabel = (gcnew System::Windows::Forms::Label());
            this->pharmacySectionLabel = (gcnew System::Windows::Forms::Label());
            this->userPanel = (gcnew System::Windows::Forms::Panel());
            this->confirmPasswordTextBox = (gcnew System::Windows::Forms::TextBox());
            this->confirmPasswordLabel = (gcnew System::Windows::Forms::Label());
            this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
            this->passwordLabel = (gcnew System::Windows::Forms::Label());
            this->emailLabel = (gcnew System::Windows::Forms::Label());
            this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->nameLabel = (gcnew System::Windows::Forms::Label());
            this->userSectionLabel = (gcnew System::Windows::Forms::Label());
            this->headerPanel = (gcnew System::Windows::Forms::Panel());
            this->headerLabel = (gcnew System::Windows::Forms::Label());
            this->emailTextBox = (gcnew System::Windows::Forms::TextBox());
            this->mainPanel->SuspendLayout();
            this->formContainer->SuspendLayout();
            this->buttonPanel->SuspendLayout();
            this->pharmacyPanel->SuspendLayout();
            this->userPanel->SuspendLayout();
            this->headerPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // mainPanel
            // 
            this->mainPanel->Controls->Add(this->formContainer);
            this->mainPanel->Controls->Add(this->headerPanel);
            this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->mainPanel->Location = System::Drawing::Point(0, 0);
            this->mainPanel->Name = L"mainPanel";
            this->mainPanel->Size = System::Drawing::Size(650, 763);
            this->mainPanel->TabIndex = 0;
            // 
            // formContainer
            // 
            this->formContainer->AutoScroll = true;
            this->formContainer->Controls->Add(this->buttonPanel);
            this->formContainer->Controls->Add(this->pharmacyPanel);
            this->formContainer->Controls->Add(this->userPanel);
            this->formContainer->Dock = System::Windows::Forms::DockStyle::Fill;
            this->formContainer->Location = System::Drawing::Point(0, 66);
            this->formContainer->Name = L"formContainer";
            this->formContainer->Padding = System::Windows::Forms::Padding(30);
            this->formContainer->Size = System::Drawing::Size(650, 697);
            this->formContainer->TabIndex = 1;
            // 
            // buttonPanel
            // 
            this->buttonPanel->Controls->Add(this->registerButton);
            this->buttonPanel->Controls->Add(this->loginButton);
            this->buttonPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->buttonPanel->Location = System::Drawing::Point(30, 608);
            this->buttonPanel->Name = L"buttonPanel";
            this->buttonPanel->Size = System::Drawing::Size(590, 59);
            this->buttonPanel->TabIndex = 2;
            // 
            // registerButton
            // 
            this->registerButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(123)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->registerButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->registerButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->registerButton->ForeColor = System::Drawing::Color::White;
            this->registerButton->Location = System::Drawing::Point(314, 0);
            this->registerButton->Name = L"registerButton";
            this->registerButton->Size = System::Drawing::Size(200, 58);
            this->registerButton->TabIndex = 0;
            this->registerButton->Text = L"إنشاء حساب";
            this->registerButton->UseVisualStyleBackColor = false;
            this->registerButton->Click += gcnew System::EventHandler(this, &Register::RegisterBtn_Click);
            // 
            // loginButton
            // 
            this->loginButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(108)), static_cast<System::Int32>(static_cast<System::Byte>(117)),
                static_cast<System::Int32>(static_cast<System::Byte>(125)));
            this->loginButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->loginButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->loginButton->ForeColor = System::Drawing::Color::White;
            this->loginButton->Location = System::Drawing::Point(74, 0);
            this->loginButton->Name = L"loginButton";
            this->loginButton->Size = System::Drawing::Size(200, 58);
            this->loginButton->TabIndex = 1;
            this->loginButton->Text = L"تسجيل الدخول";
            this->loginButton->UseVisualStyleBackColor = false;
            this->loginButton->Click += gcnew System::EventHandler(this, &Register::NavToLoginBtn_Click);
            // 
            // pharmacyPanel
            // 
            this->pharmacyPanel->BackColor = System::Drawing::Color::White;
            this->pharmacyPanel->Controls->Add(this->pharmacyLocationTextBox);
            this->pharmacyPanel->Controls->Add(this->pharmacyLocationLabel);
            this->pharmacyPanel->Controls->Add(this->pharmacyNameTextBox);
            this->pharmacyPanel->Controls->Add(this->pharmacyNameLabel);
            this->pharmacyPanel->Controls->Add(this->pharmacySectionLabel);
            this->pharmacyPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->pharmacyPanel->Location = System::Drawing::Point(30, 400);
            this->pharmacyPanel->Name = L"pharmacyPanel";
            this->pharmacyPanel->Padding = System::Windows::Forms::Padding(20);
            this->pharmacyPanel->Size = System::Drawing::Size(590, 202);
            this->pharmacyPanel->TabIndex = 1;
            // 
            // pharmacyLocationTextBox
            // 
            this->pharmacyLocationTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->pharmacyLocationTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->pharmacyLocationTextBox->Location = System::Drawing::Point(20, 125);
            this->pharmacyLocationTextBox->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
            this->pharmacyLocationTextBox->Name = L"pharmacyLocationTextBox";
            this->pharmacyLocationTextBox->Size = System::Drawing::Size(550, 30);
            this->pharmacyLocationTextBox->TabIndex = 3;
            this->pharmacyLocationTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // pharmacyLocationLabel
            // 
            this->pharmacyLocationLabel->AutoSize = true;
            this->pharmacyLocationLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->pharmacyLocationLabel->Location = System::Drawing::Point(434, 89);
            this->pharmacyLocationLabel->Name = L"pharmacyLocationLabel";
            this->pharmacyLocationLabel->Size = System::Drawing::Size(118, 23);
            this->pharmacyLocationLabel->TabIndex = 2;
            this->pharmacyLocationLabel->Text = L"عنوان الصيدلية";
            // 
            // pharmacyNameTextBox
            // 
            this->pharmacyNameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->pharmacyNameTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->pharmacyNameTextBox->Location = System::Drawing::Point(20, 46);
            this->pharmacyNameTextBox->Name = L"pharmacyNameTextBox";
            this->pharmacyNameTextBox->Size = System::Drawing::Size(550, 30);
            this->pharmacyNameTextBox->TabIndex = 1;
            this->pharmacyNameTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // pharmacyNameLabel
            // 
            this->pharmacyNameLabel->AutoSize = true;
            this->pharmacyNameLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->pharmacyNameLabel->Location = System::Drawing::Point(446, 13);
            this->pharmacyNameLabel->Name = L"pharmacyNameLabel";
            this->pharmacyNameLabel->Size = System::Drawing::Size(106, 23);
            this->pharmacyNameLabel->TabIndex = 0;
            this->pharmacyNameLabel->Text = L"اسم الصيدلية";
            // 
            // pharmacySectionLabel
            // 
            this->pharmacySectionLabel->AutoSize = true;
            this->pharmacySectionLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->pharmacySectionLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(123)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->pharmacySectionLabel->Location = System::Drawing::Point(20, 10);
            this->pharmacySectionLabel->Name = L"pharmacySectionLabel";
            this->pharmacySectionLabel->Size = System::Drawing::Size(140, 28);
            this->pharmacySectionLabel->TabIndex = 0;
            this->pharmacySectionLabel->Text = L"بيانات الصيدلية";
            // 
            // userPanel
            // 
            this->userPanel->BackColor = System::Drawing::Color::White;
            this->userPanel->Controls->Add(this->emailTextBox);
            this->userPanel->Controls->Add(this->confirmPasswordTextBox);
            this->userPanel->Controls->Add(this->confirmPasswordLabel);
            this->userPanel->Controls->Add(this->passwordTextBox);
            this->userPanel->Controls->Add(this->passwordLabel);
            this->userPanel->Controls->Add(this->emailLabel);
            this->userPanel->Controls->Add(this->nameTextBox);
            this->userPanel->Controls->Add(this->nameLabel);
            this->userPanel->Controls->Add(this->userSectionLabel);
            this->userPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->userPanel->Location = System::Drawing::Point(30, 30);
            this->userPanel->Name = L"userPanel";
            this->userPanel->Padding = System::Windows::Forms::Padding(20);
            this->userPanel->Size = System::Drawing::Size(590, 370);
            this->userPanel->TabIndex = 0;
            // 
            // confirmPasswordTextBox
            // 
            this->confirmPasswordTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->confirmPasswordTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->confirmPasswordTextBox->Location = System::Drawing::Point(17, 298);
            this->confirmPasswordTextBox->Name = L"confirmPasswordTextBox";
            this->confirmPasswordTextBox->PasswordChar = '*';
            this->confirmPasswordTextBox->Size = System::Drawing::Size(550, 30);
            this->confirmPasswordTextBox->TabIndex = 7;
            this->confirmPasswordTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->confirmPasswordTextBox->UseSystemPasswordChar = true;
            // 
            // confirmPasswordLabel
            // 
            this->confirmPasswordLabel->AutoSize = true;
            this->confirmPasswordLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->confirmPasswordLabel->Location = System::Drawing::Point(421, 265);
            this->confirmPasswordLabel->Name = L"confirmPasswordLabel";
            this->confirmPasswordLabel->Size = System::Drawing::Size(131, 23);
            this->confirmPasswordLabel->TabIndex = 6;
            this->confirmPasswordLabel->Text = L"تأكيد الرقم السري";
            // 
            // passwordTextBox
            // 
            this->passwordTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->passwordTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->passwordTextBox->Location = System::Drawing::Point(20, 219);
            this->passwordTextBox->Name = L"passwordTextBox";
            this->passwordTextBox->PasswordChar = '*';
            this->passwordTextBox->Size = System::Drawing::Size(550, 30);
            this->passwordTextBox->TabIndex = 5;
            this->passwordTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->passwordTextBox->UseSystemPasswordChar = true;
            // 
            // passwordLabel
            // 
            this->passwordLabel->AutoSize = true;
            this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->passwordLabel->Location = System::Drawing::Point(460, 187);
            this->passwordLabel->Name = L"passwordLabel";
            this->passwordLabel->Size = System::Drawing::Size(92, 23);
            this->passwordLabel->TabIndex = 4;
            this->passwordLabel->Text = L"الرقم السري";
            // 
            // emailLabel
            // 
            this->emailLabel->AutoSize = true;
            this->emailLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->emailLabel->Location = System::Drawing::Point(430, 113);
            this->emailLabel->Name = L"emailLabel";
            this->emailLabel->Size = System::Drawing::Size(124, 23);
            this->emailLabel->TabIndex = 2;
            this->emailLabel->Text = L"البريد الإلكتروني";
            // 
            // nameTextBox
            // 
            this->nameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->nameTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->nameTextBox->Location = System::Drawing::Point(16, 63);
            this->nameTextBox->Name = L"nameTextBox";
            this->nameTextBox->Size = System::Drawing::Size(550, 30);
            this->nameTextBox->TabIndex = 1;
            this->nameTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // nameLabel
            // 
            this->nameLabel->AutoSize = true;
            this->nameLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->nameLabel->Location = System::Drawing::Point(442, 29);
            this->nameLabel->Name = L"nameLabel";
            this->nameLabel->Size = System::Drawing::Size(112, 23);
            this->nameLabel->TabIndex = 0;
            this->nameLabel->Text = L"اسم المستخدم";
            // 
            // userSectionLabel
            // 
            this->userSectionLabel->AutoSize = true;
            this->userSectionLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->userSectionLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(123)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->userSectionLabel->Location = System::Drawing::Point(11, 11);
            this->userSectionLabel->Name = L"userSectionLabel";
            this->userSectionLabel->Size = System::Drawing::Size(149, 28);
            this->userSectionLabel->TabIndex = 0;
            this->userSectionLabel->Text = L"بيانات المستخدم";
            // 
            // headerPanel
            // 
            this->headerPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(123)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->headerPanel->Controls->Add(this->headerLabel);
            this->headerPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->headerPanel->Location = System::Drawing::Point(0, 0);
            this->headerPanel->Name = L"headerPanel";
            this->headerPanel->Size = System::Drawing::Size(650, 66);
            this->headerPanel->TabIndex = 0;
            // 
            // headerLabel
            // 
            this->headerLabel->AutoSize = true;
            this->headerLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->headerLabel->ForeColor = System::Drawing::Color::White;
            this->headerLabel->Location = System::Drawing::Point(248, 15);
            this->headerLabel->Name = L"headerLabel";
            this->headerLabel->Size = System::Drawing::Size(154, 38);
            this->headerLabel->TabIndex = 0;
            this->headerLabel->Text = L"تسجيل جديد";
            // 
            // emailTextBox
            // 
            this->emailTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->emailTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->emailTextBox->Location = System::Drawing::Point(16, 145);
            this->emailTextBox->Name = L"emailTextBox";
            this->emailTextBox->Size = System::Drawing::Size(550, 30);
            this->emailTextBox->TabIndex = 8;
            this->emailTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // Register
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->ClientSize = System::Drawing::Size(650, 763);
            this->Controls->Add(this->mainPanel);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Register";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"نظام إدارة الصيدليات - تسجيل جديد";
            this->mainPanel->ResumeLayout(false);
            this->formContainer->ResumeLayout(false);
            this->buttonPanel->ResumeLayout(false);
            this->pharmacyPanel->ResumeLayout(false);
            this->pharmacyPanel->PerformLayout();
            this->userPanel->ResumeLayout(false);
            this->userPanel->PerformLayout();
            this->headerPanel->ResumeLayout(false);
            this->headerPanel->PerformLayout();
            this->ResumeLayout(false);

        }
    };
}