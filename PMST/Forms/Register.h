#pragma once
#include "../Forms/Login.h"
#include "../Controllers/UsersController.h"
#include "../Controllers/PharmaciesController.h"
#include "Theme/AuthTheme.h"
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
        //Theme Modes
        Theme^ LightTheme ;
        Theme^ DarkTheme ;
        Theme^ currentTheme ;

        System::Windows::Forms::Panel^ mainPanel;
        System::Windows::Forms::Panel^ headerPanel;
        System::Windows::Forms::Label^ headerLabel;
        System::Windows::Forms::Panel^ formContainer;
        System::Windows::Forms::Panel^ userPanel;
        System::Windows::Forms::Panel^ pharmacyPanel;
    private: System::Windows::Forms::Label^ userTitleLabel;

        // User controls

        System::Windows::Forms::TextBox^ nameTextBox;
        System::Windows::Forms::Label^ nameLabel;

        System::Windows::Forms::Label^ emailLabel;
        System::Windows::Forms::TextBox^ passwordTextBox;
        System::Windows::Forms::Label^ passwordLabel;
        System::Windows::Forms::TextBox^ confirmPasswordTextBox;
        System::Windows::Forms::Label^ confirmPasswordLabel;
    private: System::Windows::Forms::Label^ pharmacyTitleLabel;

        // Pharmacy controls

        System::Windows::Forms::TextBox^ pharmacyNameTextBox;
        System::Windows::Forms::Label^ pharmacyNameLabel;
        System::Windows::Forms::TextBox^ pharmacyLocationTextBox;
        System::Windows::Forms::Label^ pharmacyLocationLabel;

        // Buttons
        System::Windows::Forms::Button^ registerButton;
        System::Windows::Forms::Button^ loginButton;
        System::Windows::Forms::Panel^ buttonPanel;
    private: System::Windows::Forms::TextBox^ emailTextBox;
    private: System::Windows::Forms::Button^ closeBtn;
    private: System::Windows::Forms::Button^ darkModeBtn;
    private: System::Windows::Forms::Button^ lightModeBtn;






    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Register::typeid));
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
            this->pharmacyTitleLabel = (gcnew System::Windows::Forms::Label());
            this->userPanel = (gcnew System::Windows::Forms::Panel());
            this->emailTextBox = (gcnew System::Windows::Forms::TextBox());
            this->confirmPasswordTextBox = (gcnew System::Windows::Forms::TextBox());
            this->confirmPasswordLabel = (gcnew System::Windows::Forms::Label());
            this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
            this->passwordLabel = (gcnew System::Windows::Forms::Label());
            this->emailLabel = (gcnew System::Windows::Forms::Label());
            this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->nameLabel = (gcnew System::Windows::Forms::Label());
            this->userTitleLabel = (gcnew System::Windows::Forms::Label());
            this->headerPanel = (gcnew System::Windows::Forms::Panel());
            this->darkModeBtn = (gcnew System::Windows::Forms::Button());
            this->lightModeBtn = (gcnew System::Windows::Forms::Button());
            this->closeBtn = (gcnew System::Windows::Forms::Button());
            this->headerLabel = (gcnew System::Windows::Forms::Label());
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
            this->mainPanel->Size = System::Drawing::Size(470, 763);
            this->mainPanel->TabIndex = 0;
            // 
            // formContainer
            // 
            this->formContainer->AutoScroll = true;
            this->formContainer->Controls->Add(this->buttonPanel);
            this->formContainer->Controls->Add(this->pharmacyPanel);
            this->formContainer->Controls->Add(this->userPanel);
            this->formContainer->Dock = System::Windows::Forms::DockStyle::Fill;
            this->formContainer->Location = System::Drawing::Point(0, 75);
            this->formContainer->Name = L"formContainer";
            this->formContainer->Padding = System::Windows::Forms::Padding(30);
            this->formContainer->Size = System::Drawing::Size(470, 688);
            this->formContainer->TabIndex = 1;
            // 
            // buttonPanel
            // 
            this->buttonPanel->Controls->Add(this->registerButton);
            this->buttonPanel->Controls->Add(this->loginButton);
            this->buttonPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->buttonPanel->Location = System::Drawing::Point(30, 599);
            this->buttonPanel->Name = L"buttonPanel";
            this->buttonPanel->Size = System::Drawing::Size(410, 59);
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
            this->registerButton->Location = System::Drawing::Point(222, 6);
            this->registerButton->Name = L"registerButton";
            this->registerButton->Size = System::Drawing::Size(180, 50);
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
            this->loginButton->Location = System::Drawing::Point(8, 6);
            this->loginButton->Name = L"loginButton";
            this->loginButton->Size = System::Drawing::Size(180, 50);
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
            this->pharmacyPanel->Controls->Add(this->pharmacyTitleLabel);
            this->pharmacyPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->pharmacyPanel->Location = System::Drawing::Point(30, 380);
            this->pharmacyPanel->Name = L"pharmacyPanel";
            this->pharmacyPanel->Padding = System::Windows::Forms::Padding(20);
            this->pharmacyPanel->Size = System::Drawing::Size(410, 202);
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
            this->pharmacyLocationTextBox->Size = System::Drawing::Size(382, 30);
            this->pharmacyLocationTextBox->TabIndex = 3;
            this->pharmacyLocationTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // pharmacyLocationLabel
            // 
            this->pharmacyLocationLabel->AutoSize = true;
            this->pharmacyLocationLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->pharmacyLocationLabel->Location = System::Drawing::Point(280, 92);
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
            this->pharmacyNameTextBox->Size = System::Drawing::Size(382, 30);
            this->pharmacyNameTextBox->TabIndex = 1;
            this->pharmacyNameTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // pharmacyNameLabel
            // 
            this->pharmacyNameLabel->AutoSize = true;
            this->pharmacyNameLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->pharmacyNameLabel->Location = System::Drawing::Point(292, 16);
            this->pharmacyNameLabel->Name = L"pharmacyNameLabel";
            this->pharmacyNameLabel->Size = System::Drawing::Size(106, 23);
            this->pharmacyNameLabel->TabIndex = 0;
            this->pharmacyNameLabel->Text = L"اسم الصيدلية";
            // 
            // pharmacyTitleLabel
            // 
            this->pharmacyTitleLabel->AutoSize = true;
            this->pharmacyTitleLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->pharmacyTitleLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(123)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->pharmacyTitleLabel->Location = System::Drawing::Point(20, 10);
            this->pharmacyTitleLabel->Name = L"pharmacyTitleLabel";
            this->pharmacyTitleLabel->Size = System::Drawing::Size(140, 28);
            this->pharmacyTitleLabel->TabIndex = 0;
            this->pharmacyTitleLabel->Text = L"بيانات الصيدلية";
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
            this->userPanel->Controls->Add(this->userTitleLabel);
            this->userPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->userPanel->Location = System::Drawing::Point(30, 30);
            this->userPanel->Name = L"userPanel";
            this->userPanel->Padding = System::Windows::Forms::Padding(20);
            this->userPanel->Size = System::Drawing::Size(410, 350);
            this->userPanel->TabIndex = 0;
            // 
            // emailTextBox
            // 
            this->emailTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->emailTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->emailTextBox->Location = System::Drawing::Point(16, 135);
            this->emailTextBox->Name = L"emailTextBox";
            this->emailTextBox->Size = System::Drawing::Size(382, 30);
            this->emailTextBox->TabIndex = 8;
            this->emailTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // confirmPasswordTextBox
            // 
            this->confirmPasswordTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->confirmPasswordTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->confirmPasswordTextBox->Location = System::Drawing::Point(17, 288);
            this->confirmPasswordTextBox->Name = L"confirmPasswordTextBox";
            this->confirmPasswordTextBox->PasswordChar = '*';
            this->confirmPasswordTextBox->Size = System::Drawing::Size(382, 30);
            this->confirmPasswordTextBox->TabIndex = 7;
            this->confirmPasswordTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->confirmPasswordTextBox->UseSystemPasswordChar = true;
            // 
            // confirmPasswordLabel
            // 
            this->confirmPasswordLabel->AutoSize = true;
            this->confirmPasswordLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->confirmPasswordLabel->Location = System::Drawing::Point(267, 262);
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
            this->passwordTextBox->Location = System::Drawing::Point(20, 209);
            this->passwordTextBox->Name = L"passwordTextBox";
            this->passwordTextBox->PasswordChar = '*';
            this->passwordTextBox->Size = System::Drawing::Size(382, 30);
            this->passwordTextBox->TabIndex = 5;
            this->passwordTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->passwordTextBox->UseSystemPasswordChar = true;
            // 
            // passwordLabel
            // 
            this->passwordLabel->AutoSize = true;
            this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->passwordLabel->Location = System::Drawing::Point(306, 184);
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
            this->emailLabel->Location = System::Drawing::Point(276, 110);
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
            this->nameTextBox->Location = System::Drawing::Point(16, 53);
            this->nameTextBox->Name = L"nameTextBox";
            this->nameTextBox->Size = System::Drawing::Size(382, 30);
            this->nameTextBox->TabIndex = 1;
            this->nameTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // nameLabel
            // 
            this->nameLabel->AutoSize = true;
            this->nameLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->nameLabel->Location = System::Drawing::Point(288, 26);
            this->nameLabel->Name = L"nameLabel";
            this->nameLabel->Size = System::Drawing::Size(112, 23);
            this->nameLabel->TabIndex = 0;
            this->nameLabel->Text = L"اسم المستخدم";
            // 
            // userTitleLabel
            // 
            this->userTitleLabel->AutoSize = true;
            this->userTitleLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->userTitleLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(123)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->userTitleLabel->Location = System::Drawing::Point(11, 11);
            this->userTitleLabel->Name = L"userTitleLabel";
            this->userTitleLabel->Size = System::Drawing::Size(149, 28);
            this->userTitleLabel->TabIndex = 0;
            this->userTitleLabel->Text = L"بيانات المستخدم";
            // 
            // headerPanel
            // 
            this->headerPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
                static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->headerPanel->Controls->Add(this->darkModeBtn);
            this->headerPanel->Controls->Add(this->lightModeBtn);
            this->headerPanel->Controls->Add(this->closeBtn);
            this->headerPanel->Controls->Add(this->headerLabel);
            this->headerPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->headerPanel->Location = System::Drawing::Point(0, 0);
            this->headerPanel->Name = L"headerPanel";
            this->headerPanel->Size = System::Drawing::Size(470, 75);
            this->headerPanel->TabIndex = 0;
            // 
            // darkModeBtn
            // 
            this->darkModeBtn->FlatAppearance->BorderSize = 0;
            this->darkModeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->darkModeBtn->ForeColor = System::Drawing::Color::Black;
            this->darkModeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"darkModeBtn.Image")));
            this->darkModeBtn->Location = System::Drawing::Point(3, 3);
            this->darkModeBtn->Name = L"darkModeBtn";
            this->darkModeBtn->Size = System::Drawing::Size(80, 70);
            this->darkModeBtn->TabIndex = 2;
            this->darkModeBtn->UseVisualStyleBackColor = true;
            this->darkModeBtn->Click += gcnew System::EventHandler(this, &Register::darkModeBtn_Click);
            // 
            // lightModeBtn
            // 
            this->lightModeBtn->FlatAppearance->BorderSize = 0;
            this->lightModeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->lightModeBtn->ForeColor = System::Drawing::Color::Black;
            this->lightModeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lightModeBtn.Image")));
            this->lightModeBtn->Location = System::Drawing::Point(3, 3);
            this->lightModeBtn->Name = L"lightModeBtn";
            this->lightModeBtn->Size = System::Drawing::Size(80, 70);
            this->lightModeBtn->TabIndex = 2;
            this->lightModeBtn->UseVisualStyleBackColor = true;
            this->lightModeBtn->Click += gcnew System::EventHandler(this, &Register::lightModeBtn_Click);
            // 
            // closeBtn
            // 
            this->closeBtn->FlatAppearance->BorderSize = 0;
            this->closeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->closeBtn->ForeColor = System::Drawing::Color::Black;
            this->closeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeBtn.Image")));
            this->closeBtn->Location = System::Drawing::Point(387, 3);
            this->closeBtn->Name = L"closeBtn";
            this->closeBtn->Size = System::Drawing::Size(80, 70);
            this->closeBtn->TabIndex = 2;
            this->closeBtn->UseVisualStyleBackColor = true;
            this->closeBtn->Click += gcnew System::EventHandler(this, &Register::closeBtn_Click);
            // 
            // headerLabel
            // 
            this->headerLabel->AutoSize = true;
            this->headerLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->headerLabel->ForeColor = System::Drawing::Color::Black;
            this->headerLabel->Location = System::Drawing::Point(150, 22);
            this->headerLabel->Name = L"headerLabel";
            this->headerLabel->Size = System::Drawing::Size(154, 38);
            this->headerLabel->TabIndex = 0;
            this->headerLabel->Text = L"تسجيل جديد";
            // 
            // Register
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->ClientSize = System::Drawing::Size(470, 763);
            this->Controls->Add(this->mainPanel);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->KeyPreview = true;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Register";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"نظام إدارة الصيدليات - تسجيل جديد";
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Register::Register_KeyDown);
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
    private: System::Void Register_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
        if (e->KeyCode == System::Windows::Forms::Keys::Escape) {
            System::Windows::Forms::DialogResult result = MessageBox::Show(
                "Are you sure you want to Exit Register?",
                "Confirm Exit",
                MessageBoxButtons::YesNo,
                MessageBoxIcon::Question
            );
            if (result == System::Windows::Forms::DialogResult::Yes) {
                this->Close();
            }
        }
    }
private: System::Void darkModeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    currentTheme = DarkTheme;
    AuthTheme::ApplyTheme(currentTheme, this);
    darkModeBtn->Hide();
    lightModeBtn->Show();
}

private: System::Void lightModeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    currentTheme = LightTheme;
    AuthTheme::ApplyTheme(currentTheme, this);
    darkModeBtn->Show();
    lightModeBtn->Hide();
}

private: System::Void closeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    Application::Exit();
}
};
}