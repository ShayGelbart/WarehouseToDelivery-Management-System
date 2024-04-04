#include <stdio.h>
#include <string.h>
#include "Manufacturer.h"

void initManufacturer(Manufacturer* pMan, Manufacturer** manArray)
{
	printf("Enter manufacturer name");
	myGets(pMan->name, MAX_STR_LEN);

	do
	{
		printf("Enter your id\n");
		scanf("%d", &pMan->id);
	} while (pMan->id <= 0 && compareManufacturersById(manArray, pMan));
}
int	 readManufacturerFromTextFile(Manufacturer* pMan, const char* fileName)
{
	char name[MAX_STR_LEN] = { 0 };
	int id
	FILE* fp;
	fp = fopen(fileName, "r");
	if (!fp)
		return 0;
	if (fgets(name, MAX_STR_LEN, fp) == NULL)
		return 0;
	name[strlen(name) - 1] = '\0';

	if(fgets()
}
int  writeManufacturerToTextFile(Manufacturer* pMan, const char* fileName)
{
	return 0;

}
int  readManufacturerfromBinFile(Manufacturer* pMan, const char* fileName)
{
	return 0;
}
int  writeManufacturerfromBinFile(Manufacturer* pMan, const char* fileName)
{
	return 0;
}
int compareManufacturersById(Manufacturer* pMan, Manufacturer** manArray)
{
	return 0;
}

void printManufacturer(Manufacturer* pMan)
{
	printf("Manufacturer:\nName: %s\tID: %d\n", pMan->name, pMan->id);
}
