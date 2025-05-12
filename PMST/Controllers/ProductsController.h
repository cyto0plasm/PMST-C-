#pragma once
#include "../Database/DBConnection.h"
#include "../Models/ProductModel.h"


using namespace System;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;

namespace PMST {

    public ref class ProductController
    {
	public:
        static void Validate(ProductModel^ m, bool requireId);
        static bool PharmacyExists(int pharmacyId);
        //static bool CategoryExists(int categoryId);
        static bool ProductController::CategoryExistsForPharmacy(int categoryId, int pharmacyId);
        static bool SupplierExists(int supplierId);

        List<ProductModel^>^ SearchProducts(String^ searchText, int pharmacyId);

        static ProductModel^ Create(ProductModel^ m);
        static ProductModel^ GetById(int id);
        static List<ProductModel^>^ GetAll();
        static List<ProductModel^>^ GetByPharmacy(int pharmacyId);
        static bool Update(ProductModel^ m);
        static bool Delete(int id);
    };
}
