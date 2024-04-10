#include <stdio.h>
#include "Delivery.h"
#include "list.h"

int initDelivery(Delivery* pDelivery)
{

	initCustomer(pDelivery->customer);
	if (!L_init(pDelivery->products))
		return 0;
	pDelivery->numberOfProducts = 0;
	getCorrectDate(&pDelivery->deliveryDate);
	initDeliveryCompany(pDelivery->deliveryCompany);
	initDeliveryPerson(pDelivery->deliveryPerson);

	return 1;
}

int readDeliveryFromTextFile(FILE* fp, Delivery* pDel)
{
	
	if(!initCustomerFromTextFile(fp,pDel->customer))
	return 0;

	
}

int writeDeliveryToTextFile(FILE* fp, Delivery* pDel)
{
	if(!writeCustomerToTextFile(fp,pDel->customer))
	return 0;
	fprintf(fp, "%d\n", pDel->numberOfProducts);
	NODE* curr = pDel->products->head.next;
	while (curr != NULL)
	{
		writeProductToText(fp, curr->key);
		curr = curr->next;
	}
	if (!writeDateToTextFile(fp, pDel->deliveryDate))
		return 0;
}

int readDeliveryFromBinaryFile(FILE* fp, Delivery* pDel)
{
	return 0;
}

int writeDeliveryToBinaryFile(FILE* fp, Delivery* pDel)
{
	return 0;
}

void changeDeliveryDate(Delivery* pDelivery)
{
	Date newDate;
	getCorrectDate(&newDate);
	pDelivery->deliveryDate = newDate;
}

void changeProduct(Delivery* pDelivery, Product* pProduct1, Product* pProduct2)
{
	//pProduct1 product that needs to be removed and instead of it needs to be put pProduct2
	removeProduct(pDelivery, pProduct1);
	addProduct(pDelivery, pProduct2);
}

int removeProduct(Delivery* pDelivery, Product* pProduct)
{
	NODE* temp = L_find(&pDelivery->products->head,   pProduct, compareProducts);
	if (!L_delete(temp, NULL))
		return 0;
	return 1;
}


void addProduct(Delivery* pDelivery, Product* pProduct)
{
	L_insert(&pDelivery->products->head, pProduct, compareProducts);
}

void changeRatingWhenDelivered(Delivery* pDelivery)
{
	double rating;
	do
	{
		printf("Please enter a rating for your delivery(0.0-5.0):\n");
		scanf("%lf", &rating);
	} while (rating < 0.0 || rating >5.0);
	changeRating(pDelivery->deliveryPerson, rating);
}

void printDelivery(Delivery* pDelivery)
{
	printCustomer(pDelivery->customer);
	printf("Number of products %d" , pDelivery->numberOfProducts);
	L_print(pDelivery->products, printProduct);
	printDate(&pDelivery->deliveryDate);
	printf("Delivery Company Name: %s \n", pDelivery->deliveryCompany->name);
	printf("Delivery Person: \t ");
	printDeliveryPerson(pDelivery->deliveryPerson);
}
