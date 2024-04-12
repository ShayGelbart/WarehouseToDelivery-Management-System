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

int initStorageFromTextFile(char* fileName, Storage* pStorage)
{
	FILE* fp;
	fp = fopen(fileName, "r");
	if (!fp)
		return 0;
	// init product array
	if(fscanf(fp, "%d", &pStorage->numOfProducts) < 0)
	{
		CLOSE_RETURN_ZERO(fp)
	}
	pStorage->productArr = (Product**)malloc(sizeof(Product*) * pStorage->numOfProducts);
	if (!pStorage->productArr)
	{
		CLOSE_RETURN_ZERO(fp)
	}

	for (int i = 0; i < pStorage->numOfProducts; i++)
	{
		pStorage->productArr[i] = (Product*)malloc(sizeof(Product));
		if(!pStorage->productArr[i])
		{
			CLOSE_RETURN_ZERO(fp)
		}
		if (i == 0)
			fgetc(fp);
		if (!initProductFromTextFile(fp, pStorage->productArr[i]))
		{
			CLOSE_RETURN_ZERO(fp)
		}
	}
	//init deliveryCompany array
	if (fscanf(fp, "%d", &pStorage->numOfDeliveryComp) < 0)
	{
		CLOSE_RETURN_ZERO(fp)
	}
	pStorage->deliveryCompanyArr = (DeliveryCompany*)malloc(sizeof(DeliveryCompany) * pStorage->numOfDeliveryComp);
	if (!pStorage->deliveryCompanyArr)
	{
		CLOSE_RETURN_ZERO(fp)
	}

	for (int i = 0; i < pStorage->numOfDeliveryComp; i++)
		if (!initDeliveryCompanyFromTextFile(fp, &pStorage->deliveryCompanyArr[i]))
		{
			CLOSE_RETURN_ZERO(fp)
		}

	//init Delivery array
	if (fscanf(fp, "%d", &pStorage->numOfDeliveries) < 0)
	{
		CLOSE_RETURN_ZERO(fp)
	}
	pStorage->deliveryArr = (Delivery**)malloc(sizeof(Delivery*) * pStorage->numOfDeliveries);
	if (!pStorage->deliveryArr)
	{
		CLOSE_RETURN_ZERO(fp)
	}

	for (int i = 0; i < pStorage->numOfDeliveries; i++)
	{
		pStorage->deliveryArr[i] = (Delivery*)malloc(sizeof(Delivery));
		if (!pStorage->deliveryArr[i])
		{
			CLOSE_RETURN_ZERO(fp)
		}

		if (!readDeliveryFromTextFile(fp, pStorage->deliveryArr[i]))
		{
			CLOSE_RETURN_ZERO(fp)
		}
	}
	//init manufacturer array
	if (fscanf(fp, "%d", &pStorage->numOfManufacturers) < 0)
	{
		CLOSE_RETURN_ZERO(fp)
	}
	pStorage->manArray = (Manufacturer**)malloc(sizeof(Manufacturer*) * pStorage->numOfManufacturers);
	if (!pStorage->manArray)
	{
		CLOSE_RETURN_ZERO(fp)
	}

	for (int i = 0; i < pStorage->numOfManufacturers; i++)
	{
		pStorage->manArray[i] = (Manufacturer*)malloc(sizeof(Manufacturer));
		if (!pStorage->manArray[i])
		{
			CLOSE_RETURN_ZERO(fp)
		}
		fgetc(fp);
		if (!readManufacturerFromTextFile(pStorage->manArray[i], fp))
		{
			CLOSE_RETURN_ZERO(fp)
		}
	}
	fclose(fp);
	return 1;
}

int initStorageFromBinaryFile(char* fileName, Storage* pStorage)
{
	FILE* fp;
	fp = fopen(fileName, "rb");
	if (!fp)
		return 0;
	if (fread(&pStorage->numOfProducts, sizeof(int), 1, fp) != 1)
	{
		CLOSE_RETURN_ZERO(fp)
	}
	pStorage->productArr = (Product**)malloc(sizeof(Product*) * pStorage->numOfProducts);
	if (!pStorage->productArr)
	{
		CLOSE_RETURN_ZERO(fp)
	}

	for (int i = 0; i < pStorage->numOfProducts; i++)
	{
		pStorage->productArr[i] = (Product*)malloc(sizeof(Product));
		if (!pStorage->productArr[i])
		{
			CLOSE_RETURN_ZERO(fp)
		}

		if (!initProductFromBinaryFile(fp, pStorage->productArr[i]))
		{
			CLOSE_RETURN_ZERO(fp)
		}
	}
	//init deliveryCompany array
	if (fread(&pStorage->numOfDeliveryComp, sizeof(int), 1, fp) != 1)
	{
		CLOSE_RETURN_ZERO(fp)
	}
	pStorage->deliveryCompanyArr = (DeliveryCompany*)malloc(sizeof(DeliveryCompany) * pStorage->numOfDeliveryComp);
	if (!pStorage->deliveryCompanyArr)
	{
		CLOSE_RETURN_ZERO(fp)
	}

	for (int i = 0; i < pStorage->numOfDeliveryComp; i++)
		if (!initDeliveryCompanyFromBinaryFile(fp, &pStorage->deliveryCompanyArr[i]))
		{
			CLOSE_RETURN_ZERO(fp)
		}

	//init Delivery array
	if (fread(&pStorage->numOfDeliveries, sizeof(int), 1, fp) != 1)
	{
		CLOSE_RETURN_ZERO(fp)
	}
	pStorage->deliveryArr = (Delivery**)malloc(sizeof(Delivery*) * pStorage->numOfDeliveries);
	if (!pStorage->deliveryArr)
	{
		CLOSE_RETURN_ZERO(fp)
	}

	for (int i = 0; i < pStorage->numOfDeliveries; i++)
	{
		pStorage->deliveryArr[i] = (Delivery*)malloc(sizeof(Delivery));
		if (!pStorage->deliveryArr[i])
		{
			CLOSE_RETURN_ZERO(fp)
		}

		if (!readDeliveryFromBinaryFile(fp, pStorage->deliveryArr[i]))
		{
			CLOSE_RETURN_ZERO(fp)
		}
	}
	//init manufacturer array
	if (fread(&pStorage->numOfManufacturers, sizeof(int), 1, fp) != 1)
	{
		CLOSE_RETURN_ZERO(fp)
	}
	pStorage->manArray = (Manufacturer**)malloc(sizeof(Manufacturer*) * pStorage->numOfManufacturers);
	if (!pStorage->manArray)
	{
		CLOSE_RETURN_ZERO(fp)
	}

	for (int i = 0; i < pStorage->numOfManufacturers; i++)
	{
		pStorage->manArray[i] = (Manufacturer*)malloc(sizeof(Manufacturer));
		if (!pStorage->manArray[i])
		{
			CLOSE_RETURN_ZERO(fp)
		}

		if (!readManufacturerFromBinFile(pStorage->manArray[i], fp))
		{
			CLOSE_RETURN_ZERO(fp)
		}
	}
	fclose(fp);
	return 1;
}

int writeStorageToTextFile(char* fileName, Storage* pStorage)
{
	FILE* fp;
	fp = fopen(fileName, "w");
	if (!fp)
		return 0;

	fprintf(fp, "%d\n", pStorage->numOfProducts);
	for (int i = 0; i < pStorage->numOfProducts; i++)
		if (!writeProductToTextFile(fp, pStorage->productArr[i]))
		{
			CLOSE_RETURN_ZERO(fp)
		}

	fprintf(fp, "%d\n", pStorage->numOfDeliveryComp);
	for (int i = 0; i < pStorage->numOfDeliveryComp; i++)
		if (!writeDeliveryCompanyToTextFile(fp, &pStorage->deliveryCompanyArr[i]))
		{
			CLOSE_RETURN_ZERO(fp)
		}

	fprintf(fp, "%d\n", pStorage->numOfDeliveries);
	for (int i = 0; i < pStorage->numOfDeliveries; i++)
		if (!writeDeliveryToTextFile(fp, pStorage->deliveryArr[i]))
		{
			CLOSE_RETURN_ZERO(fp)
		}

	fprintf(fp, "%d\n", pStorage->numOfManufacturers);
	for (int i = 0; i < pStorage->numOfManufacturers; i++)
		if (!writeManufacturerToTextFile(pStorage->manArray[i], fp))
		{
			CLOSE_RETURN_ZERO(fp)
		}

	fclose(fp);
	return 1;
}

int writeStorageToBinaryFile(char* fileName, Storage* pStorage)
{
	FILE* fp;
	fp = fopen(fileName, "wb");
	if (!fp)
		return 0;

	if (fwrite(&pStorage->numOfProducts, sizeof(int), 1, fp) != 1)
	{
		CLOSE_RETURN_ZERO(fp)
	}
	for (int i = 0; i < pStorage->numOfProducts; i++)
		if (!writeProductToTextFile(fp, pStorage->productArr[i]))
		{
			CLOSE_RETURN_ZERO(fp)
		}


	if (fwrite(&pStorage->numOfDeliveryComp, sizeof(int), 1, fp) != 1)
	{
		CLOSE_RETURN_ZERO(fp)
	}
	for (int i = 0; i < pStorage->numOfDeliveryComp; i++)
		if (!writeDeliveryCompanyToTextFile(fp, &pStorage->deliveryCompanyArr[i]))
		{
			CLOSE_RETURN_ZERO(fp)
		}

	if (fwrite(&pStorage->numOfDeliveries, sizeof(int), 1, fp) != 1)
	{
		CLOSE_RETURN_ZERO(fp)
	}
	for (int i = 0; i < pStorage->numOfDeliveries; i++)
		if (!writeDeliveryToTextFile(fp, pStorage->deliveryArr[i]))
		{
			CLOSE_RETURN_ZERO(fp)
		}

	if (fwrite(&pStorage->numOfManufacturers, sizeof(int), 1, fp) != 1)
	{
		CLOSE_RETURN_ZERO(fp)
	}
	for (int i = 0; i < pStorage->numOfManufacturers; i++)
		if (!writeManufacturerToTextFile(pStorage->manArray[i], fp))
		{
			CLOSE_RETURN_ZERO(fp)
		}
	fclose(fp);
	return 1;
}

void uploadSystemFromFile(char* fileName, Storage* pStorage)
{
	int choice;
	printf("Choose the kind of file to upload the system from:\nText - Enter 0\nBinary - Enter 1\n");
	scanf("%d", &choice);
	if (choice == 0)
		initStorageFromTextFile(fileName, pStorage);
	else
		initStorageFromBinaryFile("CHANGE LATER", pStorage);
}

int addProductToStorage(Storage* pStorage)
{
	Product* newProduct = (Product*)malloc(sizeof(Product));
	IF_NULL_RETURN_ZERO(newProduct)

	Product** tempArr = (Product**)realloc(pStorage->productArr, (pStorage->numOfProducts + 1) * sizeof(Product*));
	if (!tempArr)
	{
		FREE_RETURN_ZERO(newProduct)
	}
	pStorage->productArr = tempArr;

	initProduct(newProduct, pStorage->manArray, pStorage->numOfManufacturers);
	Manufacturer* tempMan = assignExistingManufacturerByType(pStorage->manArray, pStorage->numOfManufacturers, newProduct->productType);
	if (tempMan == NULL) // if couldn't find manufacturer from the man array
	{
		if (!addManufacturer(pStorage)) // add new manufacturer
			return 0;
		newProduct->manufacturer = *pStorage->manArray[pStorage->numOfManufacturers - 1]; // pull the new manufacturer
	}
	else
		newProduct->manufacturer = *tempMan;
	pStorage->productArr[pStorage->numOfProducts] = newProduct;
	pStorage->numOfProducts++;
	return 1;
}

int addDeliveryCompany(Storage* pStorage)
{
	DeliveryCompany* temp = (DeliveryCompany*)realloc(pStorage->deliveryCompanyArr, (pStorage->numOfDeliveryComp + 1) * sizeof(DeliveryCompany));
	IF_NULL_RETURN_ZERO(temp)

	pStorage->deliveryCompanyArr = temp;
	if (!initDeliveryCompany(&pStorage->deliveryCompanyArr[pStorage->numOfDeliveryComp], pStorage->deliveryCompanyArr, pStorage->numOfDeliveryComp))
		return 0;
	pStorage->numOfDeliveryComp++;
	return 1;
}

int addDelivery(Storage* pStorage)
{
	Delivery* newDelivery = (Delivery*)malloc(sizeof(Delivery));
	IF_NULL_RETURN_ZERO(newDelivery)

	Delivery** temp = (Delivery**)realloc(pStorage->deliveryArr, (pStorage->numOfDeliveries + 1) * sizeof(Delivery*));
	if (!temp)
	{
		FREE_RETURN_ZERO(newDelivery)
	}
	pStorage->deliveryArr = temp;
	initDelivery(newDelivery);
	if (!assignDeliveryCompany(pStorage, newDelivery))
		if (!addDeliveryCompany)
			return 0;
	pStorage->deliveryArr[pStorage->numOfDeliveries] = newDelivery;
	pStorage->numOfDeliveries++;
	return 1;
}

int addManufacturer(Storage* pStorage)
{
	Manufacturer* newMan = (Manufacturer*)malloc(sizeof(Manufacturer));
	IF_NULL_RETURN_ZERO(newMan)

	Manufacturer** temp = (Manufacturer**)realloc(pStorage->manArray, (pStorage->numOfManufacturers + 1) * sizeof(Manufacturer*));
	if (!temp)
	{
		FREE_RETURN_ZERO(newMan)
	}
	pStorage->manArray = temp;

	initManufacturer(newMan, pStorage->manArray, pStorage->numOfManufacturers);
	pStorage->manArray[pStorage->numOfManufacturers] = newMan;
	pStorage->numOfManufacturers++;
	return 1;
}

void addSpecificElement(Storage* pStorage)
{
	int choice, check = 0;
	do {
		printf("Enter which element to add:\n1.Product\n2.Delivery company\n3.Delivery\n4.Manufacturer\n");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 4);

	switch (choice)
	{
	case 1:
		check = addProductToStorage(pStorage);
		break;
	case 2:
		check = addDeliveryCompany(pStorage);
		break;
	case 3:
		check = addDelivery(pStorage);
		break;
	case 4:
		check = addManufacturer(pStorage);
		break;
	}

	if (!check)
		printf("Error, unable to add\n");
	else
		printf("Successfully added\n");
}

int	sortMenuProductArray(Storage* pStorage)
{
	int choice, check = 0;
	do {
		printf("Enter in which order to sort:\nBy-\n1.Alphabetical order\n2.Product type\n3.Manufacturer ID\n");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 3);

	switch (choice)
	{
	case 1:
		qsortProductArr(pStorage, compareProductsByName);
		printf("Product array now sorted by alphabetical order\n");
		return 1;
		break;
	case 2:
		qsortProductArr(pStorage, compareProductsByProductType);
		printf("Product array now sorted by product type\n");
		return 2;
		break;
	case 3:
		qsortProductArr(pStorage, compareTwoProductsByManufacturerId);
		printf("Product array now sorted by manufacturer id\n");
		return 3;
		break;
	}
	return 0;
}

void qsortProductArr(Storage* pStorage, int(*compare)(const void*, const void*))
{
	qsort(pStorage->productArr, pStorage->numOfProducts, sizeof(Product*), compare);
}

void bsearchProductArray(Storage* pStorage, int choice)
{
	int check = 0;
	Product* key = (Product*)malloc(sizeof(Product));
	Product* returnValue = NULL;
	if (!key)
	{
		printf("Error, try again\n");
		return;
	}

	switch (choice)
	{
	case 1:
		printf("Searching by Product name\n");
		key->nameOfProduct = getStrExactName("Enter name of product");
		returnValue = bsearch(key, pStorage->productArr, pStorage->numOfProducts, sizeof(Product*), compareProductsByNameForFind);
		free(key->nameOfProduct);
		break;
	case 2:
		printf("Searching by Product type\n");
		key->productType = getTypeProduct();
		returnValue = bsearch(key, pStorage->productArr, pStorage->numOfProducts, sizeof(Product*), compareProductsByProductTypeForFind);
		break;
	case 3:
		printf("Searching by Manufacturer ID\n");
		do {
			printf("Enter manufacturer ID\n");
			scanf("%d", &key->manufacturer.id);
		} while (key->manufacturer.id < LOWER_BORDER_ID || key->manufacturer.id > UPPER_BORDER_ID);
		returnValue = bsearch(key, pStorage->productArr, pStorage->numOfProducts, sizeof(Product*), compareTwoProductsByManufacturerIdForFind);
		break;
	default:
		printf("Product array not sorted, unable to search\n");
		break;
	}
	free(key);
	if (returnValue == NULL)
		printf("Not found in Product array\n");
	else
		printf("Found in Product array\n");
}

void printProductArr(Storage* pStorage)
{
	printf("Every product in storage:\n");
	generalArrFunction(pStorage->productArr, pStorage->numOfProducts, sizeof(Product*), printProductGeneral);
}

void printDeliveryCompanyArr(Storage* pStorage)
{
	printf("Every delivery company in storage:\n");
	generalArrFunction(pStorage->deliveryCompanyArr, pStorage->numOfDeliveryComp, sizeof(DeliveryCompany), printDeliveryCompany);
}

void printDeliveryArr(Storage* pStorage)
{
	printf("Every delivery in storage:\n");
	generalArrFunction(pStorage->deliveryArr, pStorage->numOfDeliveries, sizeof(Delivery*), printDelivery);
}

void printManufacturerArr(Storage* pStorage)
{
	printf("Every manufacturer in storage:\n");
	generalArrFunction(pStorage->manArray, pStorage->numOfManufacturers, sizeof(Manufacturer*), printManufacturer);
}

DeliveryCompany* findDeliveryCompanyByRegion(DeliveryCompany* deliveryCompArr, int size, eRegionType region)
{
	DeliveryCompany* returnValue = NULL;
	for (int i = 0; i < size; i++)
		if (deliveryCompArr[i].region == region)
			returnValue = &deliveryCompArr[i];
	return returnValue;
}

int assignDeliveryCompany(Storage* pStorage, Delivery* pDelivery)
{
	DeliveryCompany* temp = findDeliveryCompanyByRegion(pStorage->deliveryCompanyArr, pStorage->numOfDeliveryComp, pDelivery->customer->address.region);
	if (temp == NULL)
	{
		printf("Error, no existing delivery company in the specified region. Try adding a new one\n");
		return 0;
	}
	pDelivery->deliveryCompany = temp;
	return 1;
}

void menuPrintSpecificElement(Storage* pStorage)
{
	int choice;
	do {
		printf("Enter:\n1.Product array\n2.Delivery company array\n3.Delivery array\n4.Manufacturer array\n");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 4);
	
	switch (choice)
	{
	case 1:
		printProductArr(pStorage);
		break;
	case 2:
		printDeliveryCompanyArr(pStorage);
		break;
	case 3:
		printDeliveryArr(pStorage);
		break;
	case 4:
		printManufacturerArr(pStorage);
		break;
	}
}

void printStorage(Storage* pStorage)
{
	printProductArr(pStorage);
	printf("\n");
	printDeliveryCompanyArr(pStorage);
	printf("\n");
	printDeliveryArr(pStorage);
	printf("\n");
	printManufacturerArr(pStorage);
}