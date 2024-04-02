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
void		printCustomer(Customer* pCustomer);
void		changeCredits(Customer* pCustomer, int changeNumber);
void		changeAddress(Customer* pCustomer, Address* pAddress);

//Person* newCustomer(char* pName, Delivery* pDeliveries, Address* address, int credits, int numberOfDeliveries);

#endif