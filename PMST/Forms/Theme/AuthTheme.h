#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

public ref struct Theme {
    Color BackColor;
    Color ForeColor;
    Color RegisterButtonBackColor;
    Color LoginButtonBackColor;
    Color HeaderBackColor;
    Color FooterBackColor;
    Color PanelTitleForeColor;   
    Color ButtonForeColor;
};


public ref class AuthTheme abstract sealed {

public: static Theme^ CreateLightTheme() {
    Theme^ t = gcnew Theme();
    t->BackColor = Color::White;
    t->ForeColor = Color::Black;
    t->RegisterButtonBackColor = Color::FromArgb(0, 123, 255);
    t->LoginButtonBackColor = Color::FromArgb(108, 117, 125);
    t->HeaderBackColor = Color::FromArgb(240, 240, 240);
    t->FooterBackColor = Color::FromArgb(240, 240, 240);
    t->PanelTitleForeColor = Color::FromArgb(0, 123, 255);
    t->ButtonForeColor =Color::White ;
    return t;
}

public: static Theme^ CreateDarkTheme() {
    Theme^ t = gcnew Theme();
    t->BackColor = Color::FromArgb(45,45,45);
    t->ForeColor = Color::White;
    t->RegisterButtonBackColor = Color::FromArgb(45, 45, 48);
    t->LoginButtonBackColor = Color::FromArgb(45, 45, 48);
    t->HeaderBackColor = Color::FromArgb(50, 50, 50);
    t->FooterBackColor = Color::FromArgb(40, 40, 40);
    t->PanelTitleForeColor = Color::FromArgb(255, 208, 75);
    t->ButtonForeColor = Color::White;
    return t;
}

    

public: static void ApplyTheme(Theme^ theme, Control^ parent) {
    parent->BackColor = theme->BackColor;
    parent->ForeColor = theme->ForeColor;

    for each (Control ^ ctrl in parent->Controls) {
        // Header Panel
        if (ctrl->Name == "headerPanel") {
            ctrl->BackColor = theme->HeaderBackColor;
            ctrl->ForeColor = theme->ForeColor;
        }
        // Footer Panel (if you have one)
        else if (ctrl->Name == "footerPanel") {
            ctrl->BackColor = theme->FooterBackColor;
            ctrl->ForeColor = theme->ForeColor;
        }
        // Register Button
        else if (ctrl->Name == "registerButton") {
            ctrl->BackColor = theme->RegisterButtonBackColor;
            ctrl->ForeColor = theme->ButtonForeColor;
        }
        // Login Button
        else if (ctrl->Name == "loginButton") {
            ctrl->BackColor = theme->LoginButtonBackColor;
            ctrl->ForeColor = theme->ButtonForeColor;
        }
        // Exit Button - customize color here
        else if (ctrl->Name == "closeBtn") {
            ctrl->BackColor = Color::Transparent; 
        }
        // Dark and Light mode buttons - 
        else if (ctrl->Name == "darkModeBtn" || ctrl->Name == "lightModeBtn") {
            ctrl->BackColor = Color::Transparent; 
        }
        // Panel Titles (e.g. labels containing "Title")
        else if (ctrl->Name->Contains("Title") && dynamic_cast<Label^>(ctrl)) {
            ctrl->ForeColor = theme->PanelTitleForeColor;
          
        }
        // All other buttons get login button style 
        else if (dynamic_cast<Button^>(ctrl)) {
            ctrl->BackColor = theme->LoginButtonBackColor;
            ctrl->ForeColor = theme->ButtonForeColor;
        }
        // Other controls (labels, panels, textboxes etc.)
        else {
            ctrl->BackColor = theme->BackColor;
            ctrl->ForeColor = theme->ForeColor;
        }

        if (ctrl->HasChildren)
            ApplyTheme(theme, ctrl);
    }
}

};
