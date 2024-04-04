#pragma once
#ifndef __DELIVERY_PERSON__
#define __DELIVERY_PERSON__

#include "Person.h"

#define UPPER_BORDER_TIME 72
#define LOWER_BORDER_TIME 12

#define UPPER_BORDER_ID 1
#define LOWER_BORDER_ID 9999

typedef struct
{
	Person* person;
	double* ratingArr;
	int numOfDeliveries;
	double averageRating;
	int deliveryTime;
	int id;
}DeliveryPerson;

void initDeliveryPerson(DeliveryPerson* pDelPer);
int changeRating(DeliveryPerson* pDelPer, double Rating); // add rating to the array
int addRatingToArray(DeliveryPerson* pDelPer, double Rating);
double calcAverageRating(DeliveryPerson* pDelPer);
void printDeliveryPerson(DeliveryPerson* pDelPer);

#endif // !__DELIVERY_PERSON__
