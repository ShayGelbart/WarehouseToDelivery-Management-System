#include <stdio.h>
#include <string.h>
#include "Product.h"
#include "General.h"

void initProduct(Product* pProduct, Manufacturer** manArray, int numOfManufacturers)
{
	pProduct->productType = getTypeProduct();
	printManufacturerByType(manArray , pProduct->productType);
	int isExist;
	printf("Does your manufacturer exist in the list above?\n");
	printf("Yes - enter 1\nNo - enter 0\n");
	scanf("%d", &isExist);
	if (isExist)
	{
		printManufacturerByType(manArray, pProduct->productType);
		printf("Pick a manufacturer\n");
		int manIndex;
		scanf("%d", &manIndex);
		pProduct->manufacturer = *manArray[manIndex - 1];
	}
	else
		initManufacturer(&pProduct->manufacturer , manArray, numOfManufacturers);

	pProduct->nameOfProduct = getStrExactName("Enter the name of your product\n");
}

int initProductFromTextFile(FILE* fp, Product* pProduct)
{
	int temp;
	char name[MAX_STR_LEN] = { 0 };
	if(!readManufacturerFromTextFile( &pProduct->manufacturer, fp))
	return 0;
	
	if (fscanf(fp, "%d", &temp))
		return 0;
	pProduct->productType = (eProductType)temp;

	if (fgets(name, MAX_STR_LEN, fp) == NULL)
		return 0;
	name[strlen(name) - 1] = '\0';
	pProduct->nameOfProduct = _strdup(name);
	return 1;
}

int initProductFromBinaryFile(FILE* fp, Product* pProduct)
{
	int lenName, temp;
	if(!readManufacturerFromBinFile(&pProduct->manufacturer, fp))
		return 0;
	if (fread(&temp, sizeof(int), 1, fp) != 1)
		return 0;
	pProduct->productType = (eProductType)temp;
	
	if (fread(&lenName, sizeof(int), 1, fp) != 1)
		return 0;
	if (fread(pProduct->nameOfProduct, sizeof(char), MAX_STR_LEN, fp) != MAX_STR_LEN)
		return 0;
	pProduct->nameOfProduct[lenName - 1] = '\0';
	return 1;
}

int writeProductToTextFile(FILE* fp, Product* pProduct)
{
	if (!writeManufacturerToTextFile(&pProduct->manufacturer, fp))
		return 0;
	fprintf(fp, "%d\n%s\n", pProduct->productType, pProduct->nameOfProduct);
	return 1;
}

int writeProductToBinaryFile(FILE* fp, Product* pProduct)
{
	int lenName = (int)strlen(pProduct->nameOfProduct);
	if(!writeManufacturerToBinFile(&pProduct->manufacturer, fp))
		return 0;
	if (fwrite(&pProduct->productType, sizeof(eProductType), 1, fp) != 1)
		return 0;
	
	if (fwrite(&lenName, sizeof(char), 1, fp) != 1)
		return 0;
	if (fwrite(pProduct->nameOfProduct, sizeof(char), lenName, fp) != lenName)
		return 0;
	return 1;

}

eProductType getTypeProduct()
{
	int option;
	printf("\n\n");
	do {
		printf("Please enter one of the following types\n");
		for (int i = 0; i < eNofProductTypes; i++)
			printf("%d for %s\n", i, productTypeStr[i]);
		scanf("%d", &option);
	} while (option < 0 || option >= eNofProductTypes);
	getchar();
	return (eProductType)option;
}
void printManufacturerByType(Manufacturer** manArray, eProductType productType) 
{

}

void printProduct(const Product* pProduct)
{
	printf("Name of product: %s\nType of product: %s\tManufacturer: %s\t", pProduct->nameOfProduct, productTypeStr[pProduct->productType], pProduct->manufacturer.name);
}

int compareProducts(const Product* p1, const Product* p2)
{
	
	return strcmp(p1->nameOfProduct,p2->nameOfProduct);
}
