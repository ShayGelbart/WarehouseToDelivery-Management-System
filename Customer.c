#include <stdio.h>
#include "Customer.h"

//Person* newCustomer(char* pName, Delivery* pDeliveries, Address* address, int credits, int numberOfDeliveries)
//{
//    Customer* pCustomer;
//    Person* pPerson;
//    pCustomer = newPerson(pName);
//    return nullptr;
//}

void initCustomer(Customer* pCustomer)
{
	printf("Adding a customer:\n");
	initPerson(&pCustomer->person);
	initAddress(&pCustomer->address);

	int tempCredits;
	do
	{
		printf("Enter how many credits you want to deposit\n");
		scanf("%d", &tempCredits);
	} while (tempCredits <= 0);

	pCustomer->credits = tempCredits;
}

void printCustomer(Customer* pCustomer)
{
	printPerson(&pCustomer->person);
	printAddress(&pCustomer->address);
	printf("Credits Available: %d\n", pCustomer->credits);
}

void changeCredits(Customer* pCustomer, int changeNumber)
{
	pCustomer->credits += changeNumber;
	
}

void changeAddress(Customer* pCustomer, Address* pAddress)
{
	pCustomer->address = *pAddress;
}

int initCustomerFromTextFile(FILE* fp, Customer* pCustomer)
{
	if (!initPersonFromTextFile(fp, &pCustomer->person))
		return 0;
	if (!initAddressFromTextFile(fp, &pCustomer->address))
		return 0;
	if(fscanf(fp, "%d", &pCustomer->credits) < 0)
		return 0;
	return 1;
}

int initCustomerFromBinaryFile(FILE* fp, Customer* pCustomer)
{
	if (!initPersonFromBinaryFile(fp, &pCustomer->person))
		return 0;
	if (!initAddressFromBinaryFile(fp, &pCustomer->address))
		return 0;
	if (fread(&pCustomer->credits, sizeof(int), 1, fp) != 1)
		return 0;	
	return 1;
}

int writeCustomerToTextFile(FILE* fp, Customer* pCustomer)
{
	if(!writePersonToTextFile(fp, &pCustomer->person))
		return 0;
	writeAddressToTextFile(fp, &pCustomer->address);
	fprintf(fp, "%d\n", pCustomer->credits);
	return 1;
}

int writeCustomerToBinaryFile(FILE* fp, Customer* pCustomer)
{
	if(!writePersonToBinaryFile(fp, &pCustomer->person))
		return 0;
	if (!writeAddressToBinaryFile(fp, &pCustomer->address))
		return 0;
	if (fwrite(&pCustomer->credits, sizeof(int), 1, fp) != 1)
		return 0;
	return 1;
}
