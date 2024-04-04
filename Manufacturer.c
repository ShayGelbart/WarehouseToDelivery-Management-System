#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Manufacturer.h"

void initManufacturer(Manufacturer* pMan, Manufacturer** manArray, int numOfManufacturers)
{
	printf("Enter manufacturer name");
	myGets(pMan->name, MAX_STR_LEN);

	do
	{
		printf("Enter your id\n");
		scanf("%d", &pMan->id);
	} while (pMan->id <= 0 || findManufacturersById(pMan, manArray, numOfManufacturers));
}
int	 readManufacturerFromTextFile(Manufacturer* pMan, FILE* fp)
{
	char name[MAX_STR_LEN] = { 0 };
	int id = 0;

	if (fgets(name, MAX_STR_LEN, fp) == NULL)
		return 0;
	name[strlen(name) - 1] = '\0';

	fscanf(fp, "%d", &id);

	strcpy(pMan->name, name);
	return 1;


}

int  writeManufacturerToTextFile(Manufacturer* pMan, FILE* fp)
{
	if (fprintf(fp, "%s\n%d\n", pMan->name, pMan->id) < 0)
		return 0;
	return 1;
}

int  readManufacturerFromBinFile(Manufacturer* pMan, FILE* fp)
{
	int len;
	if (fread(&len, sizeof(int), 1, fp) != 1)
		return 0;

	if (fread(&pMan->name, sizeof(char), MAX_STR_LEN, fp) != MAX_STR_LEN)
		return 0;
	pMan->name[len] = '\0';

	if (fread(&pMan->id, sizeof(int), 1, fp) != 1)
		return 0;
	return 1;
}

int  writeManufacturerToBinFile(Manufacturer* pMan, FILE* fp)
{
	int len = (int)strlen(pMan->name) + 1;
	if (fwrite(&len, sizeof(int), 1, fp) != 1)
		return 0;
	if (fwrite(&pMan->name, sizeof(char), len, fp) != len)
		return 0;
	if (fwrite(&pMan->id, sizeof(int), 1, fp) != 1)
		return 0;
	return 1;
}

int findManufacturersById(Manufacturer* pMan, Manufacturer** manArray, int numOfManufacturers)
{

	for (int i = 0; i < numOfManufacturers; i++)
	{
		if (manArray[i]->id == pMan->id)
			return 1;
	}
	return 0;
}

void printManufacturer(Manufacturer* pMan)
{
	printf("Manufacturer:\nName: %s\tID: %d\n", pMan->name, pMan->id);
}
