#pragma once
#ifndef __CUSTOMER__
#define __CUSTOMER__


#include "Person.h"
#include "Address.h"

typedef struct
{
	Person person;
	Address address;
	int credits;
}Customer;


void		initCustomer(Customer* pCustomer);
void		changeCredits(Customer* pCustomer, int changeNumber);
void		changeAddress(Customer* pCustomer, Address* pAddress);
int			initCustomerFromTextFile(FILE* fp, Customer* pCustomer);
int			initCustomerFromBinaryFile(FILE* fp, Customer* pCustomer);
int			writeCustomerToTextFile(FILE* fp, Customer* pCustomer);
int			writeCustomerToBinaryFile(FILE* fp, Customer* pCustomer);
void		printCustomer(Customer* pCustomer);

//Person* newCustomer(char* pName, Delivery* pDeliveries, Address* address, int credits, int numberOfDeliveries);

#endif