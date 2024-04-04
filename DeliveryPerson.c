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

	srand((unsigned) time(NULL));
	pDelPer->deliveryTime = generateRandom(UPPER_BORDER_TIME , LOWER_BORDER_TIME);
	pDelPer->id = generateRandom(UPPER_BORDER_ID, LOWER_BORDER_ID);
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
	double* temp = (double*)realloc(pDelPer->ratingArr, (pDelPer->numOfDeliveries + 1) * sizeof(double));
	if (!temp)
		return 0;
	
	pDelPer->ratingArr = temp;
	pDelPer->ratingArr[pDelPer->numOfDeliveries] = rating;
	pDelPer->numOfDeliveries++;
	return 1;
}

double calcAverageRating(DeliveryPerson* pDelPer)
{
	double sum = 0, avr = 0;
	for (int i = 0; i < pDelPer->numOfDeliveries; i++)
		sum += pDelPer->ratingArr[i];
	avr = sum / pDelPer->numOfDeliveries;
	return avr;
}

void printDeliveryPerson(DeliveryPerson* pDelPer)
{
	printPerson(pDelPer->person);
	printf("Number of successful deliveries: %d\tAverage rating by %d customers: %lf\tEstimated delivery time: %d hours\n", pDelPer->numOfDeliveries, pDelPer->numOfDeliveries, pDelPer->averageRating, pDelPer->deliveryTime);
}
