#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DeliveryPerson.h"

void initDeliveryPerson(DeliveryPerson* pDelPer)
{
	initPerson(pDelPer->person);
	pDelPer->ratingArr = NULL;
	pDelPer->averageRating = 0;
	pDelPer->numOfDeliveries = 0;

	int range = UPPER_BORDER - LOWER_BORDER + 1;
	srand((unsigned) time(NULL));

	pDelPer->deliveryTime = (rand() % range) + LOWER_BORDER;
}

int changeRating(DeliveryPerson* pDelPer, double rating)
{
	if (!addRatingToArray(pDelPer, rating))
		return 0;
	pDelPer->averageRating = calcAverageRating(pDelPer);
	return 1;
}

int addRatingToArray(DeliveryPerson* pDelPer, double rating)
{
	return 0;
}

int calcAverageRating(DeliveryPerson* pDelPer)
{
	int sum = 0, avr = 0;
	for (int i = 0; i < pDelPer->numOfDeliveries; i++)
		sum += pDelPer->ratingArr[i];
	avr = sum / pDelPer->numOfDeliveries;
	return avr;
}

void printDeliveryPerson(DeliveryPerson* pDelPer)
{
	printPerson(pDelPer->person);
	printf("Number of successful deliveries: %d\tAverage rating by %d customers: %d\tEstimated delivery time: %d hours\n", pDelPer->numOfDeliveries, pDelPer->numOfDeliveries, pDelPer->averageRating, pDelPer->deliveryTime);
}
