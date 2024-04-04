#include <stdio.h>
#include <stdlib.h>
#include "Storage.h"

void initStorage(Storage* pStorage)
{
	pStorage->productArr = NULL;
	pStorage->numOfProducts = 0;
	pStorage->deliveryCompanyArr = NULL;
	pStorage->numOfDeliveryComp = 0;
	pStorage->deliveryArr = NULL;
	pStorage->numOfDeliveries = 0;
	pStorage->manArray = NULL;
	pStorage->numOfManufacturers = 0;
}

int addProductToStorage(Storage* pStorage)
{
	Product* newProduct = (Product*)malloc(sizeof(Product));
	if (!newProduct)
		return 0;

	Product** temp = (Product**)realloc(pStorage->productArr, (pStorage->numOfProducts + 1) * sizeof(Product*));
	if (!temp)
	{
		free(newProduct);
		return 0;
	}
	pStorage->productArr = temp;

	initProduct(newProduct, pStorage->manArray);
	pStorage->productArr[pStorage->numOfProducts] = newProduct;
	pStorage->numOfProducts++;
	return 1;
}

int addDeliveryCompany(Storage* pStorage)
{
	DeliveryCompany* temp = (DeliveryCompany*)realloc(pStorage->deliveryCompanyArr, (pStorage->numOfDeliveryComp + 1) * sizeof(DeliveryCompany));
	if (!temp)
		return 0;

	pStorage->deliveryCompanyArr = temp;
	initDeliveryCompany(&pStorage->deliveryCompanyArr[pStorage->numOfDeliveryComp]);
	pStorage->numOfDeliveryComp++;
	return 1;
}

int addDelivery(Storage* pStorage)
{
	Delivery* newDelivery = (Delivery*)malloc(sizeof(Delivery));
	if (!newDelivery)
		return 0;

	Delivery** temp = (Delivery**)realloc(pStorage->deliveryArr, (pStorage->numOfDeliveries + 1) * sizeof(Delivery*));
	if (!temp) 
	{
		free(newDelivery); 
		return 0; 
	}
	pStorage->deliveryArr = temp; 
	initDelivery(newDelivery);
	pStorage->deliveryArr[pStorage->numOfDeliveries] = newDelivery;
	pStorage->numOfDeliveries++;
	return 1;
}

int addManufacturer(Storage* pStorage)
{
	Manufacturer* newMan = (Manufacturer*)malloc(sizeof(Manufacturer));
	if (!newMan)
		return 0;

	Manufacturer** temp = (Manufacturer**)realloc(pStorage->manArray, (pStorage->numOfManufacturers + 1) * sizeof(Manufacturer*));
	if (!temp)
	{
		free(newMan);
		return 0;
	}
	pStorage->manArray = temp;

	initManufacturer(newMan, pStorage->manArray);
	pStorage->manArray[pStorage->numOfManufacturers] = newMan;
	pStorage->manArray++;
	return 1;
}


void printStorage(Storage* pStorage)
{

}