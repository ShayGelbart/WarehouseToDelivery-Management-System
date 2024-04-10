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

void			initProduct(Product* pProduct, Manufacturer** manArray, int numOfManufacturers);
int				initProductFromTextFile(FILE* fp, Product* pProduct);
int				initProductFromBinaryFile(FILE* fp, Product* pProduct);
int				writeProductToTextFile(FILE* fp, Product* pProduct);
int				writeProductToBinaryFile(FILE* fp, Product* pProduct);
void			printManufacturerByType(Manufacturer** manArray, eProductType productType);
eProductType	getTypeProduct();
void			printProduct(const Product* pProduct);
int				compareProducts(const Product* p1, const Product* p2);

#endif
