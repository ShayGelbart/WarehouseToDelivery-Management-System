#ifndef PRODUCT
#define PRODUCT

#include "Manufacturer.h"



typedef struct
{
	Manufacturer manufacturer;
	eProductType productType;
	char* nameOfProduct;
}Product;

void			initProduct(Product* pProduct, Manufacturer** manArray, int numOfManufacturers);
int				initProductFromTextFile(FILE* fp, Product* pProduct);
int				initProductFromBinaryFile(FILE* fp, Product* pProduct);
int				writeProductToTextFile(FILE* fp, Product* pProduct);
int				writeProductToBinaryFile(FILE* fp, Product* pProduct);
int				compareTwoProductsByManufacturerId(const void* v1, const void* v2);
int				compareProductsByName(const void* v1, const void* v2);
int				compareProductsByProductType(const void* v1, const void* v2);
void			printProduct(const Product* pProduct);
void			printProductGeneral(const Product** ppProduct);

#endif
