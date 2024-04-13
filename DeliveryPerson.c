#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DeliveryPerson.h"

void initDeliveryPerson(DeliveryPerson* pDelPer)
{
	printf("Adding Delivery Person:\n");
	pDelPer->person = (Person*)malloc(sizeof(Person));
	if (!pDelPer->person)
		return;
	initPerson(pDelPer->person);
	pDelPer->ratingArr = NULL;
	pDelPer->averageRating = 0;
	pDelPer->numOfDeliveries = 0;

	srand((unsigned)time(NULL));
	pDelPer->deliveryTime = generateRandom(UPPER_BORDER_TIME , LOWER_BORDER_TIME);
	pDelPer->id = generateRandom(UPPER_BORDER_ID, LOWER_BORDER_ID);
}

int	initDeliveryPersonFromTextFile(FILE* fp, DeliveryPerson* pDelPer)
{
	pDelPer->person = (Person*)malloc(sizeof(Person));
	if(!initPersonFromTextFile(fp, pDelPer->person))
		return 0;
	if (fscanf(fp, "%d", &pDelPer->numOfDeliveries) < 0)
		return 0;

	pDelPer->ratingArr = (double*)malloc(pDelPer->numOfDeliveries * sizeof(double));
	if (!pDelPer->ratingArr)
		return 0;
	
	for (int i = 0; i < pDelPer->numOfDeliveries; i++)
		if (fscanf(fp, "%lf", &pDelPer->ratingArr[i]) < 0)
			return 0;

	if (fscanf(fp, "%lf", &pDelPer->averageRating) < 0)
		return 0;
	if (fscanf(fp, "%d", &pDelPer->deliveryTime) < 0)
		return 0;
	if (fscanf(fp, "%d", &pDelPer->id) < 0)
		return 0;
	return 1;
}

int	initDeliveryPersonFromBinaryFile(FILE* fp, DeliveryPerson* pDelPer)
{
	if(!initPersonFromBinaryFile(fp, pDelPer->person))
		return 0;
	if (fread(&pDelPer->numOfDeliveries, sizeof(int), 1, fp) != 1)
		return 0;
	
	pDelPer->ratingArr = (double*)malloc(pDelPer->numOfDeliveries * sizeof(double));
	if (!pDelPer->ratingArr)
		return 0;

	for (int i = 0; i < pDelPer->numOfDeliveries; i++)
		if (fread(&pDelPer->ratingArr[i], sizeof(int), 1, fp) != 1)
			return 0;

	if (fread(&pDelPer->averageRating, sizeof(int), 1, fp) != 1)
		return 0;
	if (fread(&pDelPer->deliveryTime, sizeof(int), 1, fp) != 1)
		return 0;
	if (fread(&pDelPer->id, sizeof(int), 1, fp) != 1)
		return 0;
	return 1;
}

int	writeDeliveryPersonToTextFile(FILE* fp, DeliveryPerson* pDelPer)
{
	if(!writePersonToTextFile(fp, pDelPer->person))
		return 0;
	fprintf(fp, "%d\n", pDelPer->numOfDeliveries);
	for (int i = 0; i < pDelPer->numOfDeliveries; i++)
		fprintf(fp, "%lf\n", pDelPer->ratingArr[i]);
	fprintf(fp, "%lf\n%d\n%d\n", pDelPer->averageRating, pDelPer->deliveryTime, pDelPer->id);
	return 1;
}

int	writeDeliveryPersonToBinaryFile(FILE* fp, DeliveryPerson* pDelPer)
{
	if(!writePersonToBinaryFile(fp, pDelPer->person))
		return 0;
	if (fwrite(&pDelPer->numOfDeliveries, sizeof(int), 1, fp) != 1)
		return 0;
	
	for (int i = 0; i < pDelPer->numOfDeliveries; i++)
		if (fwrite(&pDelPer->ratingArr[i], sizeof(double), 1, fp) != 1)
			return 0;
	
	if (fwrite(&pDelPer->averageRating, sizeof(double), 1, fp) != 1)
		return 0;
	if (fwrite(&pDelPer->deliveryTime, sizeof(int), 1, fp) != 1)
		return 0;
	if (fwrite(&pDelPer->id, sizeof(int), 1, fp) != 1)
		return 0;
	return 1;
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
	printf("Deliveries: %d\tAverage rating: %.2f(%d)\tEstimated delivery time: %d hours\n", pDelPer->numOfDeliveries, pDelPer->averageRating, pDelPer->numOfDeliveries, pDelPer->deliveryTime);
}
