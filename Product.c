#include <stdio.h>
#include <string.h>
#include "Product.h"
#include "General.h"

void initProduct(Product* pProduct, Manufacturer** manArray, int numOfManufacturers)
{
	pProduct->nameOfProduct = getStrExactName("Enter the name of your product");
	pProduct->productType = getTypeProduct();
}

int initProductFromTextFile(FILE* fp, Product* pProduct)
{
	int temp;
	char name[MAX_STR_LEN] = { 0 };
	if(!readManufacturerFromTextFile( &pProduct->manufacturer, fp))
	return 0;
	
	pProduct->productType = pProduct->manufacturer.type;
	fgetc(fp);
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

int compareTwoProductsByManufacturerId(const void* v1, const void* v2)
{
	Product* p1 = (Product*)v1;
	Product* p2 = (Product*)v2;
	return p1->manufacturer.id - p2->manufacturer.id;
}

int	compareProductsByName(const void* v1, const void* v2)
{
	Product* p1 = (Product*)v1;
	Product* p2 = (Product*)v2;
	return strcmp(p1->nameOfProduct, p2->nameOfProduct);
}

int compareProductsByProductType(const void* v1, const void* v2)
{
	Product* p1 = (Product*)v1;
	Product* p2 = (Product*)v2;
	if (p1->productType < p2->productType) return -1;
	else if (p1->productType > p2->productType) return 1;
	else return 0;
}

void printProduct(const Product* pProduct)
{
	printf("Name of product: %s\tType of product: %s\tManufacturer: %s\n", pProduct->nameOfProduct, productTypeStr[pProduct->productType], pProduct->manufacturer.name);
}

void printProductGeneral(const Product** ppProduct)
{
	Product* pProduct = *ppProduct;
	printf("Name of product: %s\tType of product: %-12s\tManufacturer: %s\n", pProduct->nameOfProduct, productTypeStr[pProduct->productType], pProduct->manufacturer.name);
}


