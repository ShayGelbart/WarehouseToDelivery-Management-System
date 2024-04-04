#ifndef MANUFACTURER
#define MANUFACTURER
 // !MANUFACTURER

#include "General.h"

typedef struct
{
	char name[MAX_STR_LEN];
	int id;
}Manufacturer;

void initManufacturer(Manufacturer* pMan , Manufacturer** manArray,int numOfManufacturers);
int	 readManufacturerFromTextFile(Manufacturer* pMan, FILE* fp);
int  writeManufacturerToTextFile(Manufacturer* pMan, FILE* fp);
int  readManufacturerFromBinFile(Manufacturer* pMan, FILE* fp);
int  writeManufacturerToBinFile(Manufacturer* pMan, FILE* fp);
int findManufacturersById(Manufacturer* pMan, Manufacturer** manArray,int numOfManufacturers);
void printManufacturer(Manufacturer* pMan);

#endif