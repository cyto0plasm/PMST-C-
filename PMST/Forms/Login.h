#pragma once
#include "Register.h"

namespace PMST {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Login : public System::Windows::Forms::Form
    {
    public:
        Login(void);
    protected:
        ~Login();
    private:
        System::Void LoginBtn_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void RegisterBtn_Click(System::Object^ sender, System::EventArgs^ e);

    private:
        System::Windows::Forms::Panel^ mainPanel;
        System::Windows::Forms::Panel^ headerPanel;
        System::Windows::Forms::Label^ headerLabel;
        System::Windows::Forms::Panel^ formPanel;
        System::Windows::Forms::TextBox^ usernameTextBox;
        System::Windows::Forms::Label^ usernameLabel;
        System::Windows::Forms::TextBox^ passwordTextBox;
        System::Windows::Forms::Label^ passwordLabel;
        System::Windows::Forms::Button^ loginButton;
        System::Windows::Forms::Button^ registerButton;
        System::Windows::Forms::Panel^ footerPanel;
        System::Windows::Forms::Label^ copyrightLabel;

    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->mainPanel = (gcnew System::Windows::Forms::Panel());
            this->formPanel = (gcnew System::Windows::Forms::Panel());
            this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
            this->passwordLabel = (gcnew System::Windows::Forms::Label());
            this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->usernameLabel = (gcnew System::Windows::Forms::Label());
            this->loginButton = (gcnew System::Windows::Forms::Button());
            this->registerButton = (gcnew System::Windows::Forms::Button());
            this->headerPanel = (gcnew System::Windows::Forms::Panel());
            this->headerLabel = (gcnew System::Windows::Forms::Label());
            this->footerPanel = (gcnew System::Windows::Forms::Panel());
            this->copyrightLabel = (gcnew System::Windows::Forms::Label());
            this->mainPanel->SuspendLayout();
            this->formPanel->SuspendLayout();
            this->headerPanel->SuspendLayout();
            this->footerPanel->SuspendLayout();
            this->SuspendLayout();

            // 
            // mainPanel
            // 
            this->mainPanel->Controls->Add(this->formPanel);
            this->mainPanel->Controls->Add(this->headerPanel);
            this->mainPanel->Controls->Add(this->footerPanel);
            this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->mainPanel->Location = System::Drawing::Point(0, 0);
            this->mainPanel->Name = L"mainPanel";
            this->mainPanel->Size = System::Drawing::Size(450, 500);
            this->mainPanel->TabIndex = 0;

            // 
            // formPanel
            // 
            this->formPanel->BackColor = System::Drawing::Color::White;
            this->formPanel->Controls->Add(this->passwordTextBox);
            this->formPanel->Controls->Add(this->passwordLabel);
            this->formPanel->Controls->Add(this->usernameTextBox);
            this->formPanel->Controls->Add(this->usernameLabel);
            this->formPanel->Controls->Add(this->loginButton);
            this->formPanel->Controls->Add(this->registerButton);
            this->formPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->formPanel->Location = System::Drawing::Point(0, 80);
            this->formPanel->Name = L"formPanel";
            this->formPanel->Padding = System::Windows::Forms::Padding(40);
            this->formPanel->Size = System::Drawing::Size(450, 380);
            this->formPanel->TabIndex = 1;

            // 
            // passwordTextBox
            // 
            this->passwordTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->passwordTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->passwordTextBox->Location = System::Drawing::Point(40, 180);
            this->passwordTextBox->Name = L"passwordTextBox";
            this->passwordTextBox->PasswordChar = '*';
            this->passwordTextBox->Size = System::Drawing::Size(370, 30);
            this->passwordTextBox->TabIndex = 2;
            this->passwordTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->passwordTextBox->UseSystemPasswordChar = true;

            // 
            // passwordLabel
            // 
            this->passwordLabel->AutoSize = true;
            this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->passwordLabel->Location = System::Drawing::Point(40, 150);
            this->passwordLabel->Name = L"passwordLabel";
            this->passwordLabel->Size = System::Drawing::Size(92, 23);
            this->passwordLabel->TabIndex = 3;
            this->passwordLabel->Text = L"الرقم السري";

            // 
            // usernameTextBox
            // 
            this->usernameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->usernameTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->usernameTextBox->Location = System::Drawing::Point(40, 100);
            this->usernameTextBox->Name = L"usernameTextBox";
            this->usernameTextBox->Size = System::Drawing::Size(370, 30);
            this->usernameTextBox->TabIndex = 1;
            this->usernameTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;

            // 
            // usernameLabel
            // 
            this->usernameLabel->AutoSize = true;
            this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->usernameLabel->Location = System::Drawing::Point(40, 70);
            this->usernameLabel->Name = L"usernameLabel";
            this->usernameLabel->Size = System::Drawing::Size(112, 23);
            this->usernameLabel->TabIndex = 0;
            this->usernameLabel->Text = L"اسم المستخدم";

            // 
            // loginButton
            // 
            this->loginButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->loginButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(123)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->loginButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->loginButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->loginButton->ForeColor = System::Drawing::Color::White;
            this->loginButton->Location = System::Drawing::Point(40, 250);
            this->loginButton->Name = L"loginButton";
            this->loginButton->Size = System::Drawing::Size(370, 45);
            this->loginButton->TabIndex = 4;
            this->loginButton->Text = L"تسجيل الدخول";
            this->loginButton->UseVisualStyleBackColor = false;
            this->loginButton->Click += gcnew System::EventHandler(this, &Login::LoginBtn_Click);

            // 
            // registerButton
            // 
            this->registerButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->registerButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(108)),
                static_cast<System::Int32>(static_cast<System::Byte>(117)), static_cast<System::Int32>(static_cast<System::Byte>(125)));
            this->registerButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->registerButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->registerButton->ForeColor = System::Drawing::Color::White;
            this->registerButton->Location = System::Drawing::Point(40, 310);
            this->registerButton->Name = L"registerButton";
            this->registerButton->Size = System::Drawing::Size(370, 45);
            this->registerButton->TabIndex = 5;
            this->registerButton->Text = L"إنشاء حساب جديد";
            this->registerButton->UseVisualStyleBackColor = false;
            this->registerButton->Click += gcnew System::EventHandler(this, &Login::RegisterBtn_Click);

            // 
            // headerPanel
            // 
            this->headerPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(123)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->headerPanel->Controls->Add(this->headerLabel);
            this->headerPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->headerPanel->Location = System::Drawing::Point(0, 0);
            this->headerPanel->Name = L"headerPanel";
            this->headerPanel->Size = System::Drawing::Size(450, 80);
            this->headerPanel->TabIndex = 0;

            // 
            // headerLabel
            // 
            this->headerLabel->AutoSize = true;
            this->headerLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->headerLabel->ForeColor = System::Drawing::Color::White;
            this->headerLabel->Location = System::Drawing::Point(150, 20);
            this->headerLabel->Name = L"headerLabel";
            this->headerLabel->Size = System::Drawing::Size(150, 38);
            this->headerLabel->TabIndex = 0;
            this->headerLabel->Text = L"تسجيل الدخول";

            // 
            // footerPanel
            // 
            this->footerPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)),
                static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->footerPanel->Controls->Add(this->copyrightLabel);
            this->footerPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->footerPanel->Location = System::Drawing::Point(0, 460);
            this->footerPanel->Name = L"footerPanel";
            this->footerPanel->Size = System::Drawing::Size(450, 40);
            this->footerPanel->TabIndex = 2;

            // 
            // copyrightLabel
            // 
            this->copyrightLabel->AutoSize = true;
            this->copyrightLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->copyrightLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(108)),
                static_cast<System::Int32>(static_cast<System::Byte>(117)), static_cast<System::Int32>(static_cast<System::Byte>(125)));
            this->copyrightLabel->Location = System::Drawing::Point(170, 10);
            this->copyrightLabel->Name = L"copyrightLabel";
            this->copyrightLabel->Size = System::Drawing::Size(111, 20);
            this->copyrightLabel->TabIndex = 0;
            this->copyrightLabel->Text = L"© 2025 PMST";

            // 
            // Login
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::White;
            this->ClientSize = System::Drawing::Size(450, 500);
            this->Controls->Add(this->mainPanel);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Login";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"نظام إدارة الصيدليات - تسجيل الدخول";
            this->mainPanel->ResumeLayout(false);
            this->formPanel->ResumeLayout(false);
            this->formPanel->PerformLayout();
            this->headerPanel->ResumeLayout(false);
            this->headerPanel->PerformLayout();
            this->footerPanel->ResumeLayout(false);
            this->footerPanel->PerformLayout();
            this->ResumeLayout(false);
        }
#pragma endregion
    };
}