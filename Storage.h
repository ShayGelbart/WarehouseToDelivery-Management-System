#pragma once
#ifndef __STORAGE__
#define __STORAGE__

#include "Product.h"
#include "DeliveryCompany.h"
#include "Delivery.h"

typedef struct
{
	Product** productArr;
	int numOfProducts;
	DeliveryCompany* deliveryCompanyArr; // array
	int numOfDeliveryComp;
	Delivery** deliveryArr;
	int numOfDeliveries;
	Manufacturer** manArray;
	int numOfManufacturers;
}Storage;

void initStorage(Storage* pStorage);
int addProductToStorage(Storage* pStorage);
int addDeliveryCompany(Storage* pStorage);
int addDelivery(Storage* pStorage);
int addManufcturer(Storage* pStorage);
void printStorage(Storage* pStorage);

#endif // !__STORAGE__