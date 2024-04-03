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

    return 0;
}

int addDelivery(Storage* pStorage)
{
	Delivery* newDelivery = (Delivery*)malloc(sizeof(Delivery));
	if (!newDelivery)
		return 0;

	// Reallocate memory for deliveryArr
	Delivery** temp = (Delivery**)realloc(pStorage->deliveryArr, (pStorage->numOfDeliveries + 1) * sizeof(Delivery*));
	if (!temp) // Check if realloc failed
	{
		free(newDelivery); // Free the newly allocated memory
		return 0; // Return error code
	}
	pStorage->deliveryArr = temp; // Assign the reallocated pointer to deliveryArr

	initDelivery(newDelivery);
	pStorage->deliveryArr[pStorage->numOfDeliveries] = newDelivery;
	pStorage->numOfDeliveries++;
	return 1;
}

int addManufcturer(Storage* pStorage)
{

	return 1;
}

int compareManufacturersById(Storage* pStorage, Manufacturer* pMan)
{
    return 0;
}
