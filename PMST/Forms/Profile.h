#pragma once
#include "../Controllers/UsersController.h"
#include "../Controllers/PharmaciesController.h"

namespace PMST {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Summary for Profile
	/// </summary>
	public ref class Profile : public System::Windows::Forms::Form
	{
	public:
		Profile(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Profile(UserModel^ user, PharmacyModel^ pharmacy) {

			if (user == nullptr || pharmacy == nullptr) {
				throw gcnew ArgumentNullException("User or Pharmacy cannot be null");
			}
			currentUser = user;
			currentPharmacy = pharmacy;

			InitializeComponent();
			LoadUserAndPharmacyData();

		}
		UserModel^ currentUser;
		PharmacyModel^ currentPharmacy;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Profile()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ UserCenterPanel;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ PharmPanelTitle;
	private: System::Windows::Forms::Button^ UpdatePharmacy;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Panel^ UserHeaderPanel;
	private: System::Windows::Forms::Button^ closeBtn;
	private: System::Windows::Forms::Label^ UserEmailLab;
	private: System::Windows::Forms::Label^ UserNameLab;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ updateUser;
	private: System::Windows::Forms::Button^ ChangePasswordBtn;
	private: System::Windows::Forms::Button^ ChangeUserPicBtn;
	private: System::Windows::Forms::TextBox^ UserEmailFeild;
	private: System::Windows::Forms::TextBox^ UserNameFeild;
	private: System::Windows::Forms::PictureBox^ UserPicture;

	protected:


















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Profile::typeid));
			this->UserCenterPanel = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->PharmPanelTitle = (gcnew System::Windows::Forms::Label());
			this->UpdatePharmacy = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->UserHeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->closeBtn = (gcnew System::Windows::Forms::Button());
			this->UserEmailLab = (gcnew System::Windows::Forms::Label());
			this->UserNameLab = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->updateUser = (gcnew System::Windows::Forms::Button());
			this->ChangePasswordBtn = (gcnew System::Windows::Forms::Button());
			this->ChangeUserPicBtn = (gcnew System::Windows::Forms::Button());
			this->UserEmailFeild = (gcnew System::Windows::Forms::TextBox());
			this->UserNameFeild = (gcnew System::Windows::Forms::TextBox());
			this->UserPicture = (gcnew System::Windows::Forms::PictureBox());
			this->UserCenterPanel->SuspendLayout();
			this->UserHeaderPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UserPicture))->BeginInit();
			this->SuspendLayout();
			// 
			// UserCenterPanel
			// 
			this->UserCenterPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->UserCenterPanel->Controls->Add(this->label2);
			this->UserCenterPanel->Controls->Add(this->textBox2);
			this->UserCenterPanel->Controls->Add(this->PharmPanelTitle);
			this->UserCenterPanel->Controls->Add(this->UpdatePharmacy);
			this->UserCenterPanel->Controls->Add(this->label1);
			this->UserCenterPanel->Controls->Add(this->textBox1);
			this->UserCenterPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->UserCenterPanel->Location = System::Drawing::Point(0, 342);
			this->UserCenterPanel->Name = L"UserCenterPanel";
			this->UserCenterPanel->Size = System::Drawing::Size(462, 271);
			this->UserCenterPanel->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AccessibleName = L"UserEmailLab";
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(352, 134);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"عنوان الصيدلية";
			// 
			// textBox2
			// 
			this->textBox2->AccessibleName = L"UserEmailFeild";
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::Color::White;
			this->textBox2->Location = System::Drawing::Point(182, 163);
			this->textBox2->Name = L"textBox2";
			this->textBox2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->textBox2->Size = System::Drawing::Size(253, 31);
			this->textBox2->TabIndex = 1;
			// 
			// PharmPanelTitle
			// 
			this->PharmPanelTitle->AccessibleName = L"PharmPanelTitle";
			this->PharmPanelTitle->AutoSize = true;
			this->PharmPanelTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PharmPanelTitle->ForeColor = System::Drawing::Color::MediumTurquoise;
			this->PharmPanelTitle->Location = System::Drawing::Point(288, 14);
			this->PharmPanelTitle->Name = L"PharmPanelTitle";
			this->PharmPanelTitle->Size = System::Drawing::Size(167, 28);
			this->PharmPanelTitle->TabIndex = 3;
			this->PharmPanelTitle->Text = L"معلومات الصيدلية";
			// 
			// UpdatePharmacy
			// 
			this->UpdatePharmacy->AccessibleName = L"UpdatePharmacy";
			this->UpdatePharmacy->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->UpdatePharmacy->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->UpdatePharmacy->ForeColor = System::Drawing::Color::White;
			this->UpdatePharmacy->Location = System::Drawing::Point(325, 217);
			this->UpdatePharmacy->Name = L"UpdatePharmacy";
			this->UpdatePharmacy->Size = System::Drawing::Size(110, 30);
			this->UpdatePharmacy->TabIndex = 2;
			this->UpdatePharmacy->Text = L"تحديث البيانات";
			this->UpdatePharmacy->UseVisualStyleBackColor = false;
			this->UpdatePharmacy->Click += gcnew System::EventHandler(this, &Profile::UpdatePharmacy_Click);
			// 
			// label1
			// 
			this->label1->AccessibleName = L"UserNameLab";
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(362, 66);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"اسم الصيدلية";
			// 
			// textBox1
			// 
			this->textBox1->AccessibleName = L"UserNameFeild";
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(182, 97);
			this->textBox1->Name = L"textBox1";
			this->textBox1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->textBox1->Size = System::Drawing::Size(253, 31);
			this->textBox1->TabIndex = 1;
			// 
			// UserHeaderPanel
			// 
			this->UserHeaderPanel->AccessibleName = L"UserHeaderPanel";
			this->UserHeaderPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->UserHeaderPanel->Controls->Add(this->closeBtn);
			this->UserHeaderPanel->Controls->Add(this->UserEmailLab);
			this->UserHeaderPanel->Controls->Add(this->UserNameLab);
			this->UserHeaderPanel->Controls->Add(this->label3);
			this->UserHeaderPanel->Controls->Add(this->updateUser);
			this->UserHeaderPanel->Controls->Add(this->ChangePasswordBtn);
			this->UserHeaderPanel->Controls->Add(this->ChangeUserPicBtn);
			this->UserHeaderPanel->Controls->Add(this->UserEmailFeild);
			this->UserHeaderPanel->Controls->Add(this->UserNameFeild);
			this->UserHeaderPanel->Controls->Add(this->UserPicture);
			this->UserHeaderPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->UserHeaderPanel->Location = System::Drawing::Point(0, 0);
			this->UserHeaderPanel->Name = L"UserHeaderPanel";
			this->UserHeaderPanel->Size = System::Drawing::Size(462, 342);
			this->UserHeaderPanel->TabIndex = 2;
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
			this->closeBtn->Location = System::Drawing::Point(378, 6);
			this->closeBtn->Margin = System::Windows::Forms::Padding(4, 6, 4, 4);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(75, 61);
			this->closeBtn->TabIndex = 4;
			this->closeBtn->UseVisualStyleBackColor = false;
			this->closeBtn->Click += gcnew System::EventHandler(this, &Profile::closeBtn_Click);
			// 
			// UserEmailLab
			// 
			this->UserEmailLab->AccessibleName = L"UserEmailLab";
			this->UserEmailLab->AutoSize = true;
			this->UserEmailLab->ForeColor = System::Drawing::Color::White;
			this->UserEmailLab->Location = System::Drawing::Point(340, 181);
			this->UserEmailLab->Name = L"UserEmailLab";
			this->UserEmailLab->Size = System::Drawing::Size(86, 16);
			this->UserEmailLab->TabIndex = 3;
			this->UserEmailLab->Text = L"البريد الالكتروني";
			// 
			// UserNameLab
			// 
			this->UserNameLab->AccessibleName = L"UserNameLab";
			this->UserNameLab->AutoSize = true;
			this->UserNameLab->ForeColor = System::Drawing::Color::White;
			this->UserNameLab->Location = System::Drawing::Point(356, 113);
			this->UserNameLab->Name = L"UserNameLab";
			this->UserNameLab->Size = System::Drawing::Size(70, 16);
			this->UserNameLab->TabIndex = 3;
			this->UserNameLab->Text = L"اسم المستخدم";
			// 
			// label3
			// 
			this->label3->AccessibleName = L"PharmPanelTitle";
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::MediumTurquoise;
			this->label3->Location = System::Drawing::Point(279, 77);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(176, 28);
			this->label3->TabIndex = 3;
			this->label3->Text = L"معلومات المستخدم";
			// 
			// updateUser
			// 
			this->updateUser->AccessibleName = L"updateUser";
			this->updateUser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->updateUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->updateUser->ForeColor = System::Drawing::Color::White;
			this->updateUser->Location = System::Drawing::Point(316, 296);
			this->updateUser->Name = L"updateUser";
			this->updateUser->Size = System::Drawing::Size(110, 30);
			this->updateUser->TabIndex = 2;
			this->updateUser->Text = L"تحديث البيانات";
			this->updateUser->UseVisualStyleBackColor = false;
			this->updateUser->Click += gcnew System::EventHandler(this, &Profile::updateUser_Click);
			// 
			// ChangePasswordBtn
			// 
			this->ChangePasswordBtn->AccessibleName = L"ChangePasswordBtn";
			this->ChangePasswordBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->ChangePasswordBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ChangePasswordBtn->ForeColor = System::Drawing::Color::White;
			this->ChangePasswordBtn->Location = System::Drawing::Point(316, 252);
			this->ChangePasswordBtn->Name = L"ChangePasswordBtn";
			this->ChangePasswordBtn->Size = System::Drawing::Size(110, 30);
			this->ChangePasswordBtn->TabIndex = 2;
			this->ChangePasswordBtn->Text = L"تغيير الرقم السري";
			this->ChangePasswordBtn->UseVisualStyleBackColor = false;
			this->ChangePasswordBtn->Click += gcnew System::EventHandler(this, &Profile::ChangePasswordBtn_Click);
			// 
			// ChangeUserPicBtn
			// 
			this->ChangeUserPicBtn->AccessibleName = L"ChangeUserPicBtn";
			this->ChangeUserPicBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->ChangeUserPicBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ChangeUserPicBtn->ForeColor = System::Drawing::Color::White;
			this->ChangeUserPicBtn->Location = System::Drawing::Point(43, 133);
			this->ChangeUserPicBtn->Name = L"ChangeUserPicBtn";
			this->ChangeUserPicBtn->Size = System::Drawing::Size(75, 30);
			this->ChangeUserPicBtn->TabIndex = 2;
			this->ChangeUserPicBtn->Text = L"اختر صورة";
			this->ChangeUserPicBtn->UseVisualStyleBackColor = false;
			this->ChangeUserPicBtn->Click += gcnew System::EventHandler(this, &Profile::ChangeUserPicBtn_Click);
			// 
			// UserEmailFeild
			// 
			this->UserEmailFeild->AccessibleName = L"UserEmailFeild";
			this->UserEmailFeild->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->UserEmailFeild->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->UserEmailFeild->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UserEmailFeild->ForeColor = System::Drawing::Color::White;
			this->UserEmailFeild->Location = System::Drawing::Point(182, 210);
			this->UserEmailFeild->Name = L"UserEmailFeild";
			this->UserEmailFeild->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->UserEmailFeild->Size = System::Drawing::Size(253, 31);
			this->UserEmailFeild->TabIndex = 1;
			// 
			// UserNameFeild
			// 
			this->UserNameFeild->AccessibleName = L"UserNameFeild";
			this->UserNameFeild->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->UserNameFeild->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->UserNameFeild->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UserNameFeild->ForeColor = System::Drawing::Color::White;
			this->UserNameFeild->Location = System::Drawing::Point(182, 144);
			this->UserNameFeild->Name = L"UserNameFeild";
			this->UserNameFeild->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->UserNameFeild->Size = System::Drawing::Size(253, 31);
			this->UserNameFeild->TabIndex = 1;
			// 
			// UserPicture
			// 
			this->UserPicture->AccessibleName = L"UserPicture";
			this->UserPicture->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->UserPicture->ErrorImage = nullptr;
			this->UserPicture->Location = System::Drawing::Point(28, 29);
			this->UserPicture->Name = L"UserPicture";
			this->UserPicture->Size = System::Drawing::Size(105, 86);
			this->UserPicture->TabIndex = 0;
			this->UserPicture->TabStop = false;
			// 
			// Profile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ClientSize = System::Drawing::Size(462, 613);
			this->Controls->Add(this->UserCenterPanel);
			this->Controls->Add(this->UserHeaderPanel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Profile";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Profile";
			this->UserCenterPanel->ResumeLayout(false);
			this->UserCenterPanel->PerformLayout();
			this->UserHeaderPanel->ResumeLayout(false);
			this->UserHeaderPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UserPicture))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void closeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	   String^ PromptPassword(String^ promptText, String^ caption) {
		   Form^ passwordDialog = gcnew Form();
		   passwordDialog->Text = caption;
		   passwordDialog->Width = 400;
		   passwordDialog->Height = 180;
		   passwordDialog->StartPosition = FormStartPosition::CenterParent;
		   passwordDialog->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		   passwordDialog->MaximizeBox = false;
		   passwordDialog->MinimizeBox = false;

		   Label^ label = gcnew Label();
		   label->Text = promptText;
		   label->Left = 20;
		   label->Top = 20;
		   label->Width = 340;

		   TextBox^ inputBox = gcnew TextBox();
		   inputBox->Left = 20;
		   inputBox->Top = 50;
		   inputBox->Width = 340;
		   inputBox->UseSystemPasswordChar = true;

		   Button^ okButton = gcnew Button();
		   okButton->Text = "OK";
		   okButton->Left = 190;
		   okButton->Top = 90;
		   okButton->DialogResult = System::Windows::Forms::DialogResult::OK;

		   Button^ cancelButton = gcnew Button();
		   cancelButton->Text = "Cancel";
		   cancelButton->Left = 280;
		   cancelButton->Top = 90;
		   cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;

		   passwordDialog->Controls->Add(label);
		   passwordDialog->Controls->Add(inputBox);
		   passwordDialog->Controls->Add(okButton);
		   passwordDialog->Controls->Add(cancelButton);

		   passwordDialog->AcceptButton = okButton;
		   passwordDialog->CancelButton = cancelButton;

		   if (passwordDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			   return inputBox->Text;
		   else
			   return nullptr;
	   }


	   // Change Password
private: System::Void ChangePasswordBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// 1) Ask for old password
	String^ oldPwd = PromptPassword("Enter your current password:", "Current Password");
	if (String::IsNullOrEmpty(oldPwd)) return;

	// 2) Verify it
	String^ oldHash = UserController::HashPassword(oldPwd);
	if (oldHash != this->currentUser->Password) {
		MessageBox::Show("Old password is incorrect.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// 3) Ask for new password twice
	String^ newPwd = PromptPassword("Enter new password (min 6 chars):", "New Password");
	if (String::IsNullOrEmpty(newPwd) || newPwd->Length < 6) {
		MessageBox::Show("Password must be at least 6 characters.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	String^ confirm = PromptPassword("Confirm new password:", "Confirm Password");
	if (newPwd != confirm) {
		MessageBox::Show("New passwords do not match.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// 4) Hash & persist
	this->currentUser->Password = UserController::HashPassword(newPwd);
	if (UserController::Update(this->currentUser))
		MessageBox::Show("Password changed.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	else
		MessageBox::Show("Update failed.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
}

	   // Change User Picture
private: System::Void ChangeUserPicBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ dlg = gcnew OpenFileDialog();
	dlg->Filter = "Images|*.jpg;*.png;*.bmp";
	if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		this->UserPicture->Image = Image::FromFile(dlg->FileName);
		//this->currentUser->ImagePath = dlg->FileName;  // optional column later
	}
}

	   // Update User Info
private: System::Void updateUser_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		this->currentUser->Username = this->UserNameFeild->Text->Trim();
		this->currentUser->Email = this->UserEmailFeild->Text->Trim();
		if (UserController::Update(this->currentUser))
			MessageBox::Show("User updated.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		else
			MessageBox::Show("No changes made.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (ArgumentException^ ex) {
		MessageBox::Show(ex->Message, "Validation", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

	   // Update Pharmacy Info
private: System::Void UpdatePharmacy_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		this->currentPharmacy->Name = this->textBox1->Text->Trim();
		this->currentPharmacy->Location = this->textBox2->Text->Trim();
		if (PharmacyController::Update(this->currentPharmacy))
			MessageBox::Show("Pharmacy updated.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		else
			MessageBox::Show("No changes made.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (ArgumentException^ ex) {
		MessageBox::Show(ex->Message, "Validation", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
	   void Profile::LoadUserAndPharmacyData() {
		   // Assign user data to text fields
		   this->UserNameFeild->Text = currentUser->Username;
		   this->UserEmailFeild->Text = currentUser->Email;

		   // Assign pharmacy data to text fields
		   this->textBox1->Text = currentPharmacy->Name;
		   this->textBox2->Text = currentPharmacy->Location;
	   }
};
}
