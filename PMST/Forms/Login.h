#pragma once
#include "Register.h"
#include "Theme/AuthTheme.h"

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
        //Theme Modes
        Theme^ LightTheme;
        Theme^ DarkTheme;
    private: System::Windows::Forms::Panel^ panel2;
    private: System::Windows::Forms::Panel^ panel1;
           Theme^ currentTheme;
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
    private: System::Windows::Forms::Button^ closeBtn;
    private: System::Windows::Forms::Button^ darkModeBtn;
    private: System::Windows::Forms::Button^ lightModeBtn;

    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
            this->mainPanel = (gcnew System::Windows::Forms::Panel());
            this->formPanel = (gcnew System::Windows::Forms::Panel());
            this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
            this->passwordLabel = (gcnew System::Windows::Forms::Label());
            this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->usernameLabel = (gcnew System::Windows::Forms::Label());
            this->loginButton = (gcnew System::Windows::Forms::Button());
            this->registerButton = (gcnew System::Windows::Forms::Button());
            this->headerPanel = (gcnew System::Windows::Forms::Panel());
            this->darkModeBtn = (gcnew System::Windows::Forms::Button());
            this->lightModeBtn = (gcnew System::Windows::Forms::Button());
            this->closeBtn = (gcnew System::Windows::Forms::Button());
            this->headerLabel = (gcnew System::Windows::Forms::Label());
            this->footerPanel = (gcnew System::Windows::Forms::Panel());
            this->copyrightLabel = (gcnew System::Windows::Forms::Label());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->mainPanel->SuspendLayout();
            this->formPanel->SuspendLayout();
            this->headerPanel->SuspendLayout();
            this->footerPanel->SuspendLayout();
            this->panel1->SuspendLayout();
            this->panel2->SuspendLayout();
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
            this->formPanel->Controls->Add(this->panel2);
            this->formPanel->Controls->Add(this->panel1);
            this->formPanel->Controls->Add(this->passwordLabel);
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
            this->passwordTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->passwordTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->passwordTextBox->Location = System::Drawing::Point(16, 10);
            this->passwordTextBox->Name = L"passwordTextBox";
            this->passwordTextBox->PasswordChar = '*';
            this->passwordTextBox->Size = System::Drawing::Size(327, 27);
            this->passwordTextBox->TabIndex = 2;
            this->passwordTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->passwordTextBox->UseSystemPasswordChar = true;
            // 
            // passwordLabel
            // 
            this->passwordLabel->AutoSize = true;
            this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->passwordLabel->Location = System::Drawing::Point(313, 144);
            this->passwordLabel->Name = L"passwordLabel";
            this->passwordLabel->Size = System::Drawing::Size(92, 23);
            this->passwordLabel->TabIndex = 3;
            this->passwordLabel->Text = L"الرقم السري";
            // 
            // usernameTextBox
            // 
            this->usernameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->usernameTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->usernameTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->usernameTextBox->Location = System::Drawing::Point(16, 6);
            this->usernameTextBox->Multiline = true;
            this->usernameTextBox->Name = L"usernameTextBox";
            this->usernameTextBox->Size = System::Drawing::Size(329, 32);
            this->usernameTextBox->TabIndex = 1;
            this->usernameTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // usernameLabel
            // 
            this->usernameLabel->AutoSize = true;
            this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->usernameLabel->Location = System::Drawing::Point(298, 56);
            this->usernameLabel->Name = L"usernameLabel";
            this->usernameLabel->Size = System::Drawing::Size(112, 23);
            this->usernameLabel->TabIndex = 0;
            this->usernameLabel->Text = L"اسم المستخدم";
            // 
            // loginButton
            // 
            this->loginButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->loginButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(123)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->loginButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->loginButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->loginButton->ForeColor = System::Drawing::Color::White;
            this->loginButton->Location = System::Drawing::Point(128, 249);
            this->loginButton->Name = L"loginButton";
            this->loginButton->Size = System::Drawing::Size(203, 45);
            this->loginButton->TabIndex = 4;
            this->loginButton->Text = L"تسجيل الدخول";
            this->loginButton->UseVisualStyleBackColor = false;
            this->loginButton->Click += gcnew System::EventHandler(this, &Login::LoginBtn_Click);
            // 
            // registerButton
            // 
            this->registerButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->registerButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(108)), static_cast<System::Int32>(static_cast<System::Byte>(117)),
                static_cast<System::Int32>(static_cast<System::Byte>(125)));
            this->registerButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->registerButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->registerButton->ForeColor = System::Drawing::Color::White;
            this->registerButton->Location = System::Drawing::Point(75, 310);
            this->registerButton->Name = L"registerButton";
            this->registerButton->Size = System::Drawing::Size(296, 45);
            this->registerButton->TabIndex = 5;
            this->registerButton->Text = L"ليس لدي حساب";
            this->registerButton->UseVisualStyleBackColor = false;
            this->registerButton->Click += gcnew System::EventHandler(this, &Login::RegisterBtn_Click);
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
            this->headerPanel->Size = System::Drawing::Size(450, 80);
            this->headerPanel->TabIndex = 0;
            // 
            // darkModeBtn
            // 
            this->darkModeBtn->FlatAppearance->BorderSize = 0;
            this->darkModeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->darkModeBtn->ForeColor = System::Drawing::Color::Black;
            this->darkModeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"darkModeBtn.Image")));
            this->darkModeBtn->Location = System::Drawing::Point(3, 5);
            this->darkModeBtn->Name = L"darkModeBtn";
            this->darkModeBtn->Size = System::Drawing::Size(80, 70);
            this->darkModeBtn->TabIndex = 3;
            this->darkModeBtn->UseVisualStyleBackColor = true;
            this->darkModeBtn->Click += gcnew System::EventHandler(this, &Login::darkModeBtn_Click);
            // 
            // lightModeBtn
            // 
            this->lightModeBtn->FlatAppearance->BorderSize = 0;
            this->lightModeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->lightModeBtn->ForeColor = System::Drawing::Color::Black;
            this->lightModeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lightModeBtn.Image")));
            this->lightModeBtn->Location = System::Drawing::Point(3, 5);
            this->lightModeBtn->Name = L"lightModeBtn";
            this->lightModeBtn->Size = System::Drawing::Size(80, 70);
            this->lightModeBtn->TabIndex = 4;
            this->lightModeBtn->UseVisualStyleBackColor = true;
            this->lightModeBtn->Click += gcnew System::EventHandler(this, &Login::lightModeBtn_Click);
            // 
            // closeBtn
            // 
            this->closeBtn->FlatAppearance->BorderSize = 0;
            this->closeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->closeBtn->ForeColor = System::Drawing::Color::Black;
            this->closeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeBtn.Image")));
            this->closeBtn->Location = System::Drawing::Point(367, 1);
            this->closeBtn->Name = L"closeBtn";
            this->closeBtn->Size = System::Drawing::Size(80, 74);
            this->closeBtn->TabIndex = 1;
            this->closeBtn->UseVisualStyleBackColor = true;
            this->closeBtn->Click += gcnew System::EventHandler(this, &Login::closeBtn_Click);
            // 
            // headerLabel
            // 
            this->headerLabel->AutoSize = true;
            this->headerLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->headerLabel->ForeColor = System::Drawing::Color::Black;
            this->headerLabel->Location = System::Drawing::Point(129, 15);
            this->headerLabel->Name = L"headerLabel";
            this->headerLabel->Size = System::Drawing::Size(180, 38);
            this->headerLabel->TabIndex = 0;
            this->headerLabel->Text = L"تسجيل الدخول";
            // 
            // footerPanel
            // 
            this->footerPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
                static_cast<System::Int32>(static_cast<System::Byte>(240)));
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
            this->copyrightLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->copyrightLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(108)), static_cast<System::Int32>(static_cast<System::Byte>(117)),
                static_cast<System::Int32>(static_cast<System::Byte>(125)));
            this->copyrightLabel->Location = System::Drawing::Point(170, 10);
            this->copyrightLabel->Name = L"copyrightLabel";
            this->copyrightLabel->Size = System::Drawing::Size(99, 20);
            this->copyrightLabel->TabIndex = 0;
            this->copyrightLabel->Text = L"© 2025 PMST";
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::SystemColors::Window;
            this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel1->Controls->Add(this->usernameTextBox);
            this->panel1->Location = System::Drawing::Point(41, 94);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(364, 45);
            this->panel1->TabIndex = 6;
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::SystemColors::Window;
            this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel2->Controls->Add(this->passwordTextBox);
            this->panel2->Location = System::Drawing::Point(41, 182);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(364, 45);
            this->panel2->TabIndex = 7;
            // 
            // Login
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::White;
            this->ClientSize = System::Drawing::Size(450, 500);
            this->Controls->Add(this->mainPanel);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->KeyPreview = true;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Login";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"نظام إدارة الصيدليات - تسجيل الدخول";
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Login::Login_KeyDown);
            this->mainPanel->ResumeLayout(false);
            this->formPanel->ResumeLayout(false);
            this->formPanel->PerformLayout();
            this->headerPanel->ResumeLayout(false);
            this->headerPanel->PerformLayout();
            this->footerPanel->ResumeLayout(false);
            this->footerPanel->PerformLayout();
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->panel2->ResumeLayout(false);
            this->panel2->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void closeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
        Application::Exit();
    }
private: System::Void Login_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
    if (e->KeyCode == System::Windows::Forms::Keys::Escape) {
        System::Windows::Forms::DialogResult result = MessageBox::Show(
            "Are you sure you want to Exit Login?",
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


};
}