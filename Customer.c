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
	initPersonFromTextFile(fp, &pCustomer->person);
	return 0;
}

int initCustomerFromBinaryFile(FILE* fp, Customer* pCustomer)
{
	initPersonFromBinaryFile(fp, &pCustomer->person);
	return 0;
}

int writeCustomerToTextFile(FILE* fp, Customer* pCustomer)
{
	writePersonToTextFile(fp, &pCustomer->person);
	return 0;
}

int writeCustomerToBinaryFile(FILE* fp, Customer* pCustomer)
{
	writePersonToBinaryFile(fp, &pCustomer->person);
	return 0;
}
