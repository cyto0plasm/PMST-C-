#pragma once
#include "../Models/InvoiceHeaderModel.h"
#include "../Database/DBConnection.h"

namespace PMST {

    public ref class InvoiceHeaderController {
    public:
        static void Validate(InvoiceHeaderModel^ m, bool requireId);
        static bool PharmacyExists(int pharmacyId);
        static bool UserExists(int userId);

        static InvoiceHeaderModel^ Create(InvoiceHeaderModel^ m);
        static InvoiceHeaderModel^ GetById(int id);
        static System::Collections::Generic::List<InvoiceHeaderModel^>^ InvoiceHeaderController::GetByPharmacy(int pharmacyId);
        static System::Collections::Generic::List<InvoiceHeaderModel^>^ GetAll();
        static bool Update(InvoiceHeaderModel^ m);
        static bool Delete(int id);
    };
}
