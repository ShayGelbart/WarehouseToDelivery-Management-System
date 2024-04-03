#include <stdio.h>
#include <stdlib.h>
#include "DeliveryCompany.h"
#include "DeliveryPerson.h"
#include "General.h"

void initDeliveryCompany(DeliveryCompany* delComp)
{
	delComp->name = getStrExactName("Enter Name:\n");
	delComp->delPerArray = NULL;
	delComp->deliveryPersonCount = 0;
	delComp->region = getRegion();
}

int	addDeliveryPerson(DeliveryCompany* pDelComp)
{
	DeliveryPerson* newPer = (DeliveryPerson*)malloc(sizeof(DeliveryPerson));
	if (!newPer)
		return 0;
	DeliveryPerson** temp = (DeliveryPerson**)realloc(pDelComp->delPerArray, (pDelComp->deliveryPersonCount + 1) * sizeof(DeliveryPerson*));
	if (!temp)
	{
		free(newPer);
		return 0;
	}

	pDelComp->delPerArray = temp;
	initDeliveryPerson(newPer);
	pDelComp->delPerArray[pDelComp->deliveryPersonCount] = newPer;
	pDelComp->deliveryPersonCount++;
	return 1;
}

int findDeliveryPersonInArr(DeliveryCompany* pDelComp, DeliveryPerson* pDelPer)
{
	for (int i = 0; i < pDelComp->deliveryPersonCount; i++)
	{
		if (compareTwoDeliveryPerson(pDelComp->delPerArray[i], pDelPer) == 0)
			return i;
	}
	return -1;
}

int	fireDeliveryPerson(DeliveryCompany* pDelComp, DeliveryPerson* pDelPer)
{
	int index = findDeliveryPersonInArr(pDelComp, pDelPer);
	pDelComp->delPerArray[index] = NULL;
	for (int i = index; i < (pDelComp->deliveryPersonCount - index - 1); i++)
	{
		pDelComp->delPerArray[i] = pDelComp->delPerArray[i + 1];
	}

	DeliveryPerson** newDelPerArray = (DeliveryPerson**)realloc(pDelComp->delPerArray, (pDelComp->deliveryPersonCount - 1) * sizeof(DeliveryPerson*));
	if (!newDelPerArray)
	{
		free(pDelComp->delPerArray);
		return 0;
	}

	pDelComp->delPerArray = newDelPerArray;
	pDelComp->deliveryPersonCount--;
	return 1;
}

int	compareTwoDeliveryPerson(DeliveryPerson* p1, DeliveryPerson* p2)
{
	return (p1->id - p2->id);
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
	printf("In company: %s located in %s there are %d delivery persons:\n", pDelComp->name, regionTypeStr[pDelComp->region], pDelComp->deliveryPersonCount);
	printDeliveryPersonArrayWithIndex(pDelComp);
}