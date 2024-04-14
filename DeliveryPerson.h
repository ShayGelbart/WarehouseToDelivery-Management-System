#pragma once
#ifndef __DELIVERY_PERSON__
#define __DELIVERY_PERSON__

#include "Person.h"

#define UPPER_BORDER_TIME 72
#define LOWER_BORDER_TIME 12


typedef struct
{
	Person* person;
	int numOfDeliveries;
	double* ratingArr;
	double averageRating;
	int deliveryTime;
	int id;
}DeliveryPerson;

void	initDeliveryPerson(DeliveryPerson* pDelPer);
int		initDeliveryPersonFromTextFile(FILE* fp, DeliveryPerson* pDelPer);
int		initDeliveryPersonFromBinaryFile(FILE* fp, DeliveryPerson* pDelPer);
int		writeDeliveryPersonToTextFile(FILE* fp, DeliveryPerson* pDelPer);
int		writeDeliveryPersonToBinaryFile(FILE* fp, DeliveryPerson* pDelPer);
int		changeRating(DeliveryPerson* pDelPer, double Rating); // add rating to the array
int		addRatingToArray(DeliveryPerson* pDelPer, double Rating);
double	calcAverageRating(DeliveryPerson* pDelPer);
void	printDeliveryPerson(DeliveryPerson* pDelPer);
void	freeDeliveryPerson(DeliveryPerson* pDelPer);


#endif // !__DELIVERY_PERSON__
