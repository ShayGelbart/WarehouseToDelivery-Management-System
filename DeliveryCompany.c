#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DeliveryCompany.h"
#include "DeliveryPerson.h"
#include "General.h"

int initDeliveryCompany(DeliveryCompany* pDelComp, DeliveryCompany* delCompArr, int size)
{
	int personCount;
	pDelComp->region = getRegion();
	for (int i = 0; i < size; i++)
		if (delCompArr[i].region == pDelComp->region)
			return 0;
	pDelComp->name = getStrExactName("Enter Name:");
	pDelComp->delPerArray = NULL;
	pDelComp->deliveryPersonCount = 0;
	
	do {
		printf("Enter how many Delivery persons you want to add to company\n");
		scanf("%d", &personCount);
	} while (personCount < 0);

	for (int i = 0; i < personCount; i++)
	{
		if (!addDeliveryPerson(pDelComp))
			return 0;
		printf("Successfully added\n");
	}
	return 1;
}

int initDeliveryCompanyFromTextFile(FILE* fp, DeliveryCompany* pDelComp)
{
	int temp;
	char name[MAX_STR_LEN] = { 0 };
	fgetc(fp);
	if (fgets(name, MAX_STR_LEN, fp) == NULL)
		return 0;
	name[strlen(name) - 1] = '\0';
	pDelComp->name = _strdup(name);

	if (fscanf(fp, "%d", &pDelComp->deliveryPersonCount) < 0)
		return 0;

	pDelComp->delPerArray = (DeliveryPerson**)malloc(pDelComp->deliveryPersonCount * sizeof(DeliveryPerson*));
	if (!pDelComp->delPerArray)
		return 0;

	for (int i = 0; i < pDelComp->deliveryPersonCount; i++)
	{
		pDelComp->delPerArray[i] = (DeliveryPerson*)malloc(sizeof(DeliveryPerson));
		if (!pDelComp->delPerArray[i])
			return 0;
		if (!initDeliveryPersonFromTextFile(fp, pDelComp->delPerArray[i]))
			return 0;
	}

	if (fscanf(fp, "%d", &temp) < 0)
		return 0;
	pDelComp->region = (eRegionType)temp;
	return 1;
}

int initDeliveryCompanyFromBinaryFile(FILE* fp, DeliveryCompany* pDelComp)
{
	int lenName;
		//, temp;
	if(fread(&lenName, sizeof(int), 1, fp) != 1)
		return 0;
	if (lenName >= sizeof(pDelComp->name))
		return 0;
	pDelComp->name = (char*)malloc(sizeof(char) * lenName);
	IF_NULL_RETURN_ZERO(pDelComp->name)
	if (fread(pDelComp->name, sizeof(char), lenName, fp) != lenName)
		return 0;
	pDelComp->name[lenName] = '\0';
	if (fread(&pDelComp->deliveryPersonCount, sizeof(int), 1, fp) != 1)
		return 0;

	pDelComp->delPerArray = (DeliveryPerson**)malloc(pDelComp->deliveryPersonCount * sizeof(DeliveryPerson*));
	if (!pDelComp->delPerArray)
		return 0;

	for (int i = 0; i < pDelComp->deliveryPersonCount; i++)
	{
		pDelComp->delPerArray[i] = (DeliveryPerson*)malloc(sizeof(DeliveryPerson));
		if (!pDelComp->delPerArray[i])
			return 0;
		if (!initDeliveryPersonFromBinaryFile(fp, pDelComp->delPerArray[i]))
			return 0;
	}

	if (fread(&pDelComp->region, sizeof(int), 1, fp) != 1)
		return 0;
	//pDelComp->region = (eRegionType)temp;
	return 1;
}

int writeDeliveryCompanyToTextFile(FILE* fp, DeliveryCompany* pDelComp)
{
	fprintf(fp, "%s\n%d\n", pDelComp->name, pDelComp->deliveryPersonCount);

	for (int i = 0; i < pDelComp->deliveryPersonCount; i++)
		if (!writeDeliveryPersonToTextFile(fp, pDelComp->delPerArray[i]))
			return 0;

	fprintf(fp, "%d\n", pDelComp->region);
	return 1;
}

int writeDeliveryCompanyToBinaryFile(FILE* fp, DeliveryCompany* pDelComp)
{
	int lenName = (int)strlen(pDelComp->name);
	if (fwrite(&lenName, sizeof(int), 1, fp) != 1)
		return 0;
	if (fwrite(pDelComp->name, sizeof(char), lenName, fp) != lenName)
		return 0;
	if (fwrite(&pDelComp->deliveryPersonCount, sizeof(int), 1, fp) != 1)
		return 0;

	for (int i = 0; i < pDelComp->deliveryPersonCount; i++)
		if (!writeDeliveryPersonToBinaryFile(fp, pDelComp->delPerArray[i]))
			return 0;

	if (fwrite(&pDelComp->region, sizeof(eRegionType), 1, fp) != 1)
		return 0;
	return 1;
}

int	addDeliveryPerson(DeliveryCompany* pDelComp)
{
	DeliveryPerson* newPer = (DeliveryPerson*)malloc(sizeof(DeliveryPerson));
	if (!newPer)
		return 0;
	DeliveryPerson** temp = (DeliveryPerson**)realloc(pDelComp->delPerArray, (pDelComp->deliveryPersonCount + 1) * sizeof(DeliveryPerson*));
	if (!temp)
	{
		free(newPer);
		return 0;
	}
	
	pDelComp->delPerArray = temp;
	initDeliveryPerson(newPer);

	if (findDeliveryPersonInArr(pDelComp, newPer) != -1)
		return 0;

	pDelComp->delPerArray[pDelComp->deliveryPersonCount] = newPer;
	pDelComp->deliveryPersonCount++;
	return 1;
}

int findDeliveryPersonInArr(DeliveryCompany* pDelComp, DeliveryPerson* pDelPer)
{
	for (int i = 0; i < pDelComp->deliveryPersonCount; i++)
	{
		if (compareTwoDeliveryPerson(pDelComp->delPerArray[i], pDelPer) == 0)
			return i;
	}
	return -1;
}

int	fireDeliveryPerson(DeliveryCompany* pDelComp, DeliveryPerson* pDelPer)
{
	int index = findDeliveryPersonInArr(pDelComp, pDelPer);
	pDelComp->delPerArray[index] = NULL;
	for (int i = index; i < (pDelComp->deliveryPersonCount - index - 1); i++)
	{
		pDelComp->delPerArray[i] = pDelComp->delPerArray[i + 1];
	}

	DeliveryPerson** newDelPerArray = (DeliveryPerson**)realloc(pDelComp->delPerArray, (pDelComp->deliveryPersonCount - 1) * sizeof(DeliveryPerson*));
	if (!newDelPerArray)
	{
		free(pDelComp->delPerArray);
		return 0;
	}

	pDelComp->delPerArray = newDelPerArray;
	pDelComp->deliveryPersonCount--;
	return 1;
}

int	compareTwoDeliveryPerson(DeliveryPerson* p1, DeliveryPerson* p2)
{
	return (p1->id - p2->id);
}

void printDeliveryPersonArrayWithIndex(DeliveryCompany* pDelComp)
{

	for (int i = 0; i < pDelComp->deliveryPersonCount; i++)
	{
		printf("%d)", (i + 1));
		printDeliveryPerson(pDelComp->delPerArray[i]);
	}
}

void printDeliveryCompany(DeliveryCompany* pDelComp)
{
	printf("Company: %s\tRegion: %s\tDelivery Persons: %d\n", pDelComp->name, regionTypeStr[pDelComp->region], pDelComp->deliveryPersonCount);
	printDeliveryPersonArrayWithIndex(pDelComp);
}

void freeDeliveryCompany(DeliveryCompany* pDelComp)
{
	free(pDelComp->name);
	for (int i = 0; i < pDelComp->deliveryPersonCount; i++)
	{
		freeDeliveryPerson(pDelComp->delPerArray[i]);
		free(pDelComp->delPerArray[i]);
	}
	free(pDelComp->delPerArray);
}