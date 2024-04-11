#pragma once
#ifndef __DELIVERY_COMPANY__
#define __DELIVERY_COMPANY__

#include "DeliveryPerson.h"
#include "Address.h"
typedef struct
{
	char* name;
	int deliveryPersonCount;
	DeliveryPerson** delPerArray;
	eRegionType region;
}DeliveryCompany;

int		initDeliveryCompany(DeliveryCompany* pDelComp, DeliveryCompany* delCompArr, int size);
int		initDeliveryCompanyFromTextFile(FILE* fp, DeliveryCompany* pDelComp);
int		initDeliveryCompanyFromBinaryFile(FILE* fp, DeliveryCompany* pDelComp);
int		writeDeliveryCompanyToTextFile(FILE* fp, DeliveryCompany* pDelComp);
int		writeDeliveryCompanyToBinaryFile(FILE* fp, DeliveryCompany* pDelComp);
int		addDeliveryPerson(DeliveryCompany* pDelComp);
int		findDeliveryPersonInArr(DeliveryCompany* pDelComp, DeliveryPerson* pDelPer);
int		fireDeliveryPerson(DeliveryCompany* pDelComp, DeliveryPerson* pDelPer);
int		compareTwoDeliveryPerson(DeliveryPerson* p1, DeliveryPerson* p2);
void	printDeliveryPersonArrayWithIndex(DeliveryCompany* pDelComp);
void	printDeliveryCompany(DeliveryCompany* pDelComp);

#endif