#ifndef MANUFACTURER
#define MANUFACTURER
 // !MANUFACTURER

#include "General.h"

typedef struct
{
	char name[MAX_STR_LEN];
	int id;
}Manufacturer;

void initManufacturer(Manufacturer* pMan , Manufacturer** manArray);
int	 readManufacturerFromTextFile(Manufacturer* pMan, const char* fileName);
int  writeManufacturerToTextFile(Manufacturer* pMan, const char* fileName);
int  readManufacturerfromBinFile(Manufacturer* pMan,const char* fileName);
int  writeManufacturerfromBinFile(Manufacturer* pMan, const char* fileName);
int compareManufacturersById(Manufacturer* pMan, Manufacturer** manArray);
void printManufacturer(Manufacturer* pMan);

#endif