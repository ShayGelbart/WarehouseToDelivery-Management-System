#include <stdio.h>
#include "DeliveryCompany.h"
#include "DeliveryPerson.h"
#include "General.h"

void initDeliveryCompany(DeliveryCompany* delComp)
{
	delComp->name = getStrExactName("Enter Name:\n");
	delComp->delPerArray = NULL;
	delComp->deliveryPersonCount = 0;
	//delComp->region = getRegion();
}

int	addDeliveryPerson(DeliveryCompany* delComp)
{
	return 1;
}

int	removeDeliveryPerson(DeliveryCompany* deComp, DeliveryPerson* pDelPer)
{
	return 1;
}

int	compareTwoDeliveryPerson(DeliveryPerson* p1, DeliveryPerson p2)
{
	return 1;
}

//void assignDeliveryPersonToDelivery(DeliveryCompany* pDelPer, Delivery* pDelivery)
//{
//	int choiceIndex;
//	printDeliveryPersonArrayWithIndex(pDelPer);
//	do {
//		printf("Enter your preferred delivery person\n");
//		scanf("%d", &choiceIndex);
//	} while (choiceIndex <= 0 || choiceIndex > pDelPer->deliveryPersonCount);
//	
//}

void printDeliveryPersonArrayWithIndex(DeliveryCompany* pDelComp)
{
	for (int i = 0; i < pDelComp->deliveryPersonCount; i++)
	{
		printf("%d)", (i + 1));
		printDeliveryPerson(pDelComp->delPerArray[i]);
		printf("\n");
	}
}
void printDeliveryCompany(DeliveryCompany* pDelComp)
{

}