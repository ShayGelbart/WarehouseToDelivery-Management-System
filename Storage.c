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

		if (!readManufacturerFromTextFile(pStorage->manArray[i], fp))
		{
			CLOSE_RETURN_ZERO(fp)
		}
	}
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

	return 1;
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

	initProduct(newProduct, pStorage->manArray, pStorage->numOfManufacturers);
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

	initManufacturer(newMan, pStorage->manArray, pStorage->numOfManufacturers);
	pStorage->manArray[pStorage->numOfManufacturers] = newMan;
	pStorage->manArray++;
	return 1;
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

void printStorage(Storage* pStorage)
{
	printf("Every product in storage:\n");
	generalArrFunction(pStorage->productArr, pStorage->numOfProducts, sizeof(Product*), printProduct);

	printf("Every delivery company in storage:\n");
	generalArrFunction(pStorage->deliveryCompanyArr, pStorage->numOfDeliveryComp, sizeof(DeliveryCompany), printDeliveryCompany);

	printf("Every delivery in storage:\n");
	generalArrFunction(pStorage->deliveryArr, pStorage->numOfDeliveries, sizeof(Delivery*), printDelivery);

	printf("Every manufacturer in storage:\n");
	generalArrFunction(pStorage->manArray, pStorage->numOfManufacturers, sizeof(Manufacturer*), printManufacturer);
}