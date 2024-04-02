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
void printManufacturer(Manufacturer* pMan);

#endif