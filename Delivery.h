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

int			initDelivery(Delivery* pDelivery);
int			readDeliveryFromTextFile(FILE* fp, Delivery* pDel);
int			writeDeliveryToTextFile(FILE* fp, Delivery* pDel);
int			readDeliveryFromBinaryFile(FILE* fp, Delivery* pDel);
int			writeDeliveryToBinaryFile(FILE* fp, Delivery* pDel);
void		printDelivery(Delivery** ppDelivery);
void		changeDeliveryDate(Delivery* pDelivery);
void		changeProduct(Delivery* pDelivery, Product* pProduct1, Product* pProduct2);
int			removeProduct(Delivery* pDelivery, Product* pProduct);
void		addProduct(Delivery* pDelivery, Product* pProduct);
void		changeRatingWhenDelivered(Delivery* pDelivery);

#endif