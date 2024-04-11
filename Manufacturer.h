#ifndef MANUFACTURER
#define MANUFACTURER
 // !MANUFACTURER

#include "General.h"

typedef struct
{
	char name[MAX_STR_LEN];
	int id;
	eProductType type;
}Manufacturer;

void			initManufacturer(Manufacturer* pMan, Manufacturer** manArray, int numOfManufacturers);
eProductType	getTypeProduct();
int				readManufacturerFromTextFile(Manufacturer* pMan, FILE* fp);
int				writeManufacturerToTextFile(Manufacturer* pMan, FILE* fp);
int				readManufacturerFromBinFile(Manufacturer* pMan, FILE* fp);
int				writeManufacturerToBinFile(Manufacturer* pMan, FILE* fp);
int				findManufacturerById(int id, Manufacturer** manArray, int numOfManufacturers);
Manufacturer*	returnManufacturerById(int id, Manufacturer** manArray, int numOfManufacturers);
Manufacturer*	assignExistingManufacturerByType(Manufacturer** manArray, int size, eProductType productType);
void			printManufacturer(Manufacturer* pMan);

#endif