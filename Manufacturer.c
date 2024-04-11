#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Manufacturer.h"

void initManufacturer(Manufacturer* pMan, Manufacturer** manArray, int numOfManufacturers)
{
	printf("Enter manufacturer name\n");
	myGets(pMan->name, MAX_STR_LEN);

	do
	{
		printf("Enter your id\n");
		scanf("%d", &pMan->id);
	} while (pMan->id <= 0 || findManufacturerById(pMan->id, manArray, numOfManufacturers));

	pMan->type = getTypeProduct();
}

eProductType getTypeProduct()
{
	int option;
	printf("\n\n");
	do {
		printf("Please enter one of the following types\n");
		for (int i = 0; i < eNofProductTypes; i++)
			printf("%d for %s\n", i, productTypeStr[i]);
		scanf("%d", &option);
	} while (option < 0 || option >= eNofProductTypes);
	getchar();
	return (eProductType)option;
}

int	 readManufacturerFromTextFile(Manufacturer* pMan, FILE* fp)
{
	char name[MAX_STR_LEN] = { 0 };
	int id = 0, temp;
	fgetc(fp);
	if (fgets(name, MAX_STR_LEN, fp) == NULL)
		return 0;
	name[strlen(name) - 1] = '\0';

	if (fscanf(fp, "%d", &pMan->id) < 0)
		return 0;

	strcpy(pMan->name, name);

	if (fscanf(fp, "%d", &temp) < 0)
		return 0;
	pMan->type = (eProductType)temp;
	return 1;
}

int  writeManufacturerToTextFile(Manufacturer* pMan, FILE* fp)
{
	if (fprintf(fp, "%s\n%d\n%d\n", pMan->name, pMan->id, pMan->type) < 0)
		return 0;
	return 1;
}

int  readManufacturerFromBinFile(Manufacturer* pMan, FILE* fp)
{
	int len, temp;
	if (fread(&len, sizeof(int), 1, fp) != 1)
		return 0;

	if (fread(&pMan->name, sizeof(char), MAX_STR_LEN, fp) != MAX_STR_LEN)
		return 0;
	pMan->name[len] = '\0';

	if (fread(&pMan->id, sizeof(int), 1, fp) != 1)
		return 0;

	if (fread(&temp, sizeof(int), 1, fp) != 1)
		return 0;
	pMan->type = (eProductType)temp;
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
	if (fwrite(&pMan->type, sizeof(eProductType), 1, fp) != 1)
		return 0;
	return 1;
}

int findManufacturerById(int id, Manufacturer** manArray, int numOfManufacturers)
{

	for (int i = 0; i < numOfManufacturers; i++)
	{
		if (manArray[i]->id == id)
			return 1;
	}
	return 0;
}

Manufacturer* returnManufacturerById(int id, Manufacturer** manArray, int numOfManufacturers)
{
	for (int i = 0; i < numOfManufacturers; i++)
	{
		if (manArray[i]->id == id)
			return manArray[i];
	}
	return NULL;
}

Manufacturer* assignExistingManufacturerByType(Manufacturer** manArray, int size, eProductType productType)
{
	int pointer = 0, manId, isExist;
	Manufacturer** temp = (Manufacturer**)malloc(sizeof(Manufacturer*) * size);
	IF_NULL_RETURN_ZERO(temp)
	
	for (int i = 0; i < size; i++)
		if (manArray[i]->type == productType)
		{
			temp[pointer] = manArray[i];
			pointer++;
		}

	generalArrFunction(temp, pointer, sizeof(Manufacturer*), printManufacturer);
	printf("Does your manufacturer exist in the list above?\n");
	printf("Yes - enter 1\nNo - enter 0\n");
	scanf("%d", &isExist);
	if (isExist)
	{
		do {
			printf("Pick a manufacturer by ID\n");
			scanf("%d", &manId);
		} while (manId < 0 || !findManufacturerById(manId, temp, pointer));

		free(temp);
		return returnManufacturerById(manId, manArray, size);
	}
	
	return NULL;
}

void printManufacturer(Manufacturer** ppMan)
{
	Manufacturer* pMan = *ppMan;
	printf("Manufacturer:\nName: %s\tID: %d\t\tProduct type: %s\n", pMan->name, pMan->id, productTypeStr[pMan->type]);
}
