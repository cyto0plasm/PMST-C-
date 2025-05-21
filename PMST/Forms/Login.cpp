#include "Login.h"
#include "Dashboard.h"
#include "Theme/AuthTheme.h"

namespace PMST {
	Login::Login(void) {
		InitializeComponent();
		LightTheme = AuthTheme::CreateLightTheme();
		DarkTheme = AuthTheme::CreateDarkTheme();
		currentTheme = LightTheme;
		AuthTheme::ApplyTheme(currentTheme, this);
	}

	Login::~Login() {
		if (components) delete components;
	}
	void Login::LoginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// 1. Read inputs
			String^ userName = this->usernameTextBox->Text;
			String^ password = this->passwordTextBox->Text;

			// 2. Attempt login
			auto user = PMST::UserController::Login(userName, password);
			if (user == nullptr) {
				MessageBox::Show(
					"Invalid credentials.",
					"Login Failed",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);
				return;
			}

			// 3. Load this user's pharmacies
			auto list = PMST::PharmacyController::GetByOwner(user->Id);
			if (list->Count > 0) {
				this->Hide();
				Dashboard^ dashboard = gcnew Dashboard(user, list[0]);
				dashboard->Show();
				//this->Close(); // Properly close the login form
			}
			else {
				MessageBox::Show("No pharmacies found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
	

		}
		catch (Exception^ ex) {
			MessageBox::Show(
				ex->Message,
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);


		}
	}

	void Login::RegisterBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		Register^ regForm = gcnew Register();
		regForm->ShowDialog(this);

	}
}