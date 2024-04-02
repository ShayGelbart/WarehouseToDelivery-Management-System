#pragma once
#ifndef __DELIVERY__
#define __DELIVERY__

#include "Customer.h"
#include "Product.h"
#include "Date.h"
#include "DeliveryCompany.h"
#include "list.h"


typedef struct
{
	Customer* customer;
	LIST* products;//array
	int numberOfProducts;
	Date     deliveryDate;
	DeliveryCompany* deliveryCompany;
	DeliveryPerson* deliveryPerson;
}Delivery;

void		initDelivery(Delivery* pDelivery);
void		printDelivery(Delivery* pDelivery);
void		changeDeliveryDate(Delivery* pDelivery);
void		changeProduct(Delivery* pDelivery, Product* pProduct1, Product* pProduct2);
int			removeProduct(Delivery* pDelivery, Product* pProduct);
int			addProduct(Delivery* pDelivery, Product* pProduct);
void		changeRatingWhenDelivered(Delivery* pDelivery);

#endif