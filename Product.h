#ifndef PRODUCT
#define PRODUCT

#include "Manufacturer.h"

typedef enum {
	eToys, eBooks, eElectronics, eSports, eFurniture, eClothing, eBeauty, eNofProductTypes
} eProductType;

static const char* productTypeStr[eNofProductTypes]
= { "Toys", "Books", "Electronics", "Sports", "Furniture" , "Clothing", "Beauty" };


typedef struct
{
	Manufacturer manufacturer;
	eProductType productType;
	char* nameOfProduct;
}Product;

void initProduct(Product* pProduct, Manufacturer** manArray);
void printManufacturerByType(Manufacturer** manArray, eProductType productType);
eProductType getTypeProduct();
void printProduct(Product* pProduct);
int compareProducts(const Product* p1, const  Product* p2);

#endif
