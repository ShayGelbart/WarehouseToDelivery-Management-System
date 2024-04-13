#include <stdio.h>
#include <string.h>
#include "Address.h"

void initAddress(Address* pAddress)
{
    pAddress->region = getRegion(pAddress);
	
	printf("Enter your city's name\n");
	myGets(pAddress->city, MAX_STR_LEN);

	printf("Enter your street's name\n");
	myGets(pAddress->street, MAX_STR_LEN);

	do
	{
		printf("Enter your house number\n");
		scanf("%d", &pAddress->houseNumber);
	} while (pAddress->houseNumber <= 0);
}

int getRegion()
{
		int option;
		printf("\n\n");
		do {
			printf("Please enter one of the following types\n");
			for (int i = 0; i < eNofRegions; i++)
				printf("%d for %s\n", i, regionTypeStr[i]);
			scanf("%d", &option);
		} while (option < 0 || option >= eNofRegions);
		getchar();
		return (eRegionType)option;
}

int initAddressFromTextFile(FILE* fp, Address* pAddress)
{
	int temp;
	if (fscanf(fp, "%d", &temp) < 0)
		return 0;
	pAddress->region = (eRegionType)temp;
	char city[MAX_STR_LEN] = { 0 };
	char street[MAX_STR_LEN] = { 0 };
	fgetc(fp);
	if (fgets(city, MAX_STR_LEN, fp) == NULL)
		return 0;
	city[strlen(city) - 1] = '\0';

	if (fgets(street, MAX_STR_LEN, fp) == NULL)
		return 0;
	street[strlen(street) - 1] = '\0';
	
	strcpy(pAddress->city, city);
	strcpy(pAddress->street, street);

	if (fscanf(fp, "%d", &pAddress->houseNumber) < 0)
		return 0;
	return 1;
}

int initAddressFromBinaryFile(FILE* fp, Address* pAddress)
{
	int lenCity, lenStreet;
	if(fread(&pAddress->region, sizeof(int), 1 ,fp) != 1)
		return 0;
	if (fread(&lenCity, sizeof(int), 1, fp) != 1)
		return 0;
	if (fread(pAddress->city, sizeof(char), MAX_STR_LEN, fp) != MAX_STR_LEN)
		return 0;
	pAddress->city[lenCity] = '\0';
	if (fread(&lenStreet, sizeof(int), 1, fp) != 1)
		return 0;
	if (fread(pAddress->street, sizeof(char), MAX_STR_LEN, fp) != MAX_STR_LEN)
		return 0;
	pAddress->street[lenStreet] = '\0';
	return 1;
}

void writeAddressToTextFile(FILE* fp, Address* pAddress)
{
	fprintf(fp, "%d\n%s\n%s\n%d\n", pAddress->region, pAddress->city, pAddress->street, pAddress->houseNumber);
}

int writeAddressToBinaryFile(FILE* fp, Address* pAddress)
{
	int lenCity = (int)strlen(pAddress->city), lenStreet = (int)strlen(pAddress->street);
	if (fwrite(&pAddress->region, sizeof(eRegionType), 1, fp) != 1)
		return 0;
	if (fwrite(&lenCity, sizeof(int), 1, fp) != 1)
		return 0;
	if (fwrite(pAddress->city, sizeof(char), lenCity, fp) != lenCity)
		return 0;
	if (fwrite(&lenStreet, sizeof(int), 1, fp) != 1)
		return 0;
	if (fwrite(pAddress->street, sizeof(char), lenStreet, fp) != lenStreet)
		return 0;
	return 1;
}

void printAddress(Address* pAddress)
{
    printf("Region: %s\nCity: %s\tStreet: %s\tHouse: %d\n" , regionTypeStr[pAddress->region], pAddress->city, pAddress->street , pAddress->houseNumber);
}
