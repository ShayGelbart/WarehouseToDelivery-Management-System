#include <stdio.h>
#include <string.h>
#include "Product.h"
#include "General.h"

void initProduct(Product* pProduct, Manufacturer** manArray)
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
		pProduct->manufacturer = manArray[manIndex - 1];
	}
	else
		initManufacturer(pProduct->manufacturer , manArray);

	pProduct->nameOfProduct = getStrExactName("Enter the name of your product");
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

void printProduct(Product* pProduct)
{
	printf("Name of product: %s\nType of product: %s\tManufacturer: %s\t", pProduct->nameOfProduct, productTypeStr[pProduct->productType], pProduct->manufacturer->name);
}

int compareProducts(const Product* p1, const Product* p2)
{
	
	return strcmp(p1->nameOfProduct,p2->nameOfProduct);
}
