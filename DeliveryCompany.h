#pragma once
#ifndef __DELIVERY_COMPANY__
#define __DELIVERY_COMPANY__

#include "DeliveryPerson.h"
#include "Address.h"
typedef struct
{
	char* name;
	DeliveryPerson** delPerArray;
	int deliveryPersonCount;
	eRegionType region;
}DeliveryCompany;

void			initDeliveryCompany(DeliveryCompany* delComp);
//DeliveryPerson* findDeliveryPerson(DeliveryCompany* delComp);
int				addDeliveryPerson(DeliveryCompany* pDelComp);
int findDeliveryPersonInArr(DeliveryCompany* pDelComp, DeliveryPerson* pDelPer);
int				fireDeliveryPerson(DeliveryCompany* pDelComp, DeliveryPerson* pDelPer);
int				compareTwoDeliveryPerson(DeliveryPerson* p1, DeliveryPerson* p2);
void			printDeliveryPersonArrayWithIndex(DeliveryCompany* pDelComp);
//void			assignDeliveryPersonToDelivery(DeliveryCompany* pDelPer, Delivery* pDel);
// should be in storage 31 errors
void			printDeliveryCompany(DeliveryCompany* pDelComp);

#endif