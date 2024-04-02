#include <stdio.h>
#include "Address.h"

int initAddressFromFile(Address* pAddress, FILE* fp)
{
    return 0;
}

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

void printAddress(Address* pAddress)
{
    printf("In region: %s\nCity: %s\tStreet: %s\tHouse: %d\n" , regionTypeStr[pAddress->region], pAddress->city, pAddress->street , pAddress->houseNumber);
}
