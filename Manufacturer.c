#include <stdio.h>
#include "Manufacturer.h"

void initManufacturer(Manufacturer* pMan, Manufacturer** manArray)
{
    printf("Enter manufacturer name");
    myGets(pMan->name, MAX_STR_LEN);

	do
	{
		printf("Enter your id\n");
		scanf("%d", &pMan->id);
	} while (pMan->id <= 0);
		//&& compareManufacturersById(manArray , pMan));
}

void printManufacturer(Manufacturer* pMan)
{
    printf("Manufacturer:\nName: %s\tID: %d\n", pMan->name, pMan->id);
}
