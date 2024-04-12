#pragma once
#ifndef __STORAGE__
#define __STORAGE__

#include "Product.h"
#include "DeliveryCompany.h"
#include "Delivery.h"

#define CLOSE_RETURN_ZERO(fp) {fclose(fp); return 0;}

typedef struct
{
	int numOfProducts;
	Product** productArr;
	int numOfDeliveryComp;
	DeliveryCompany* deliveryCompanyArr; // array
	int numOfDeliveries;
	Delivery** deliveryArr;
	int numOfManufacturers;
	Manufacturer** manArray;
}Storage;

void				initStorage(Storage* pStorage);
int					initStorageFromTextFile(char* fileName, Storage* pStorage);
int					initStorageFromBinaryFile(char* fileName, Storage* pStorage);
int					writeStorageToTextFile(char* fileName, Storage* pStorage);
int					writeStorageToBinaryFile(char* fileName, Storage* pStorage);
void				uploadSystemFromFile(char* fileNameText, char* fileNameBin, Storage* pStorage);
void				addSpecificElement(Storage* pStorage);
int					addProductToStorage(Storage* pStorage);
int					addDeliveryCompany(Storage* pStorage);
int					addDelivery(Storage* pStorage);
int					addManufacturer(Storage* pStorage);
int					sortMenuProductArray(Storage* pStorage);
void				qsortProductArr(Storage* pStorage, int(*compare)(const void*, const void*));
void				bsearchProductArray(Storage* pStorage, int choice);
DeliveryCompany*	findDeliveryCompanyByRegion(DeliveryCompany* deliveryCompArr, int size, eRegionType region);
int					assignDeliveryCompany(Storage* pStorage, Delivery* pDelivery);
void				menuPrintSpecificElement(Storage* pStorage);
void				printProductArr(Storage* pStorage);
void				printDeliveryCompanyArr(Storage* pStorage);
void				printDeliveryArr(Storage* pStorage);
void				printManufacturerArr(Storage* pStorage);
void				printStorage(Storage* pStorage);

#endif // !__STORAGE__