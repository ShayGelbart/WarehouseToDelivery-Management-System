#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Product.h"
#include "General.h"

void initProduct(Product* pProduct)
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
	//if (fread(&temp, sizeof(int), 1, fp) != 1)
	//	return 0;
	//pProduct->productType = (eProductType)temp;
	pProduct->productType = pProduct->manufacturer.type;

	if (fread(&lenName, sizeof(int), 1, fp) != 1)
		return 0;
	pProduct->nameOfProduct = (char*)malloc(sizeof(char) * lenName);
	IF_NULL_RETURN_ZERO(pProduct->nameOfProduct)
	if (fread(pProduct->nameOfProduct, sizeof(char), lenName, fp) != lenName)
		return 0;
	pProduct->nameOfProduct[lenName] = '\0';
	return 1;
}

int writeProductToTextFile(FILE* fp, Product* pProduct)
{
	if (!writeManufacturerToTextFile(&pProduct->manufacturer, fp))
		return 0;
	fprintf(fp, "%s\n", pProduct->nameOfProduct);
	return 1;
}

int writeProductToBinaryFile(FILE* fp, Product* pProduct)
{
	int lenName = (int)strlen(pProduct->nameOfProduct);
	if(!writeManufacturerToBinFile(&pProduct->manufacturer, fp))
		return 0;
	//if (fwrite(&pProduct->productType, sizeof(eProductType), 1, fp) != 1)
	//	return 0;
	
	if (fwrite(&lenName, sizeof(int), 1, fp) != 1)
		return 0;
	if (fwrite(pProduct->nameOfProduct, sizeof(char), lenName, fp) != lenName)
		return 0;
	return 1;

}

int compareTwoProductsByManufacturerId(const void* v1, const void* v2)
{
	Product** pp1 = (Product**)v1;
	Product** pp2 = (Product**)v2;
	/*Product* p1 = (Product*)pp1;
	Product* p2 = (Product*)pp2;*/
	return pp1[0]->manufacturer.id - pp2[0]->manufacturer.id;
}

int	compareProductsByName(const void* v1, const void* v2)
{
	Product** pp1 = (Product**)v1;
	Product** pp2 = (Product**)v2;
	return strcmp(pp1[0]->nameOfProduct, pp2[0]->nameOfProduct);
}

int	compareProductsByNameForList(const void* v1, const void* v2)
{
	Product* p1 = (Product*)v1;
	Product* p2 = (Product*)v2;
	return strcmp(p1->nameOfProduct, p2->nameOfProduct);
}

int compareTwoProductsByManufacturerIdForFind(const void* v1, const void* v2)
{
	Product** pp1 = (Product**)v1;
	Product** pp2 = (Product**)v2;
	Product* p1 = (Product*)pp1;
	//Product* p2 = (Product*)pp2;*/
	return p1->manufacturer.id - pp2[0]->manufacturer.id;
}

int	compareProductsByNameForFind(const void* v1, const void* v2)
{
	Product** pp1 = (Product**)v1;
	Product** pp2 = (Product**)v2;
	Product* p1 = (Product*)pp1;
	return strcmp(p1->nameOfProduct, pp2[0]->nameOfProduct);
}

int compareProductsByProductTypeForFind(const void* v1, const void* v2)
{
	Product** pp1 = (Product**)v1;
	Product** pp2 = (Product**)v2;
	Product* p1 = (Product*)pp1;
	//Product* p2 = (Product*)pp2;*/
	if (p1->productType < pp2[0]->productType) return -1;
	else if (p1->productType > pp2[0]->productType) return 1;
	else return 0;
}

int compareProductsByProductType(const void* v1, const void* v2)
{
	Product** pp1 = (Product**)v1;
	Product** pp2 = (Product**)v2;
	/*Product* p1 = (Product*)pp1;
	Product* p2 = (Product*)pp2;*/
	if (pp1[0]->productType < pp2[0]->productType) return -1;
	else if (pp1[0]->productType > pp2[0]->productType) return 1;
	else return 0;
}

void printProduct(const Product* pProduct)
{
	printf("Name of product: %-17s\tType of product: %-12s\tManufacturer: %-10s\tID: %d\n", pProduct->nameOfProduct, productTypeStr[pProduct->productType], pProduct->manufacturer.name, pProduct->manufacturer.id);
}

void printProductGeneral(const Product** ppProduct)
{
	Product* pProduct = *ppProduct;
	printf("Name of product: %-17s\tType of product: %-12s\tManufacturer: %-10s\tID: %d\n", pProduct->nameOfProduct, productTypeStr[pProduct->productType], pProduct->manufacturer.name, pProduct->manufacturer.id);
}


