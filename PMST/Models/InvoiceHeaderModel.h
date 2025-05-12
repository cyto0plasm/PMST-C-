#pragma once
using namespace System;

namespace PMST {
    public ref class InvoiceHeaderModel {
    public:
        property int Id;
        property int Pharmacy_Id;
        property int User_Id;
        property Decimal Total_Price;
        property DateTime Created_At;
        property DateTime Updated_At;
    };
}
