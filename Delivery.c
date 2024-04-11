#include <stdio.h>
#include <stdlib.h>
#include "Delivery.h"
#include "list.h"

int initDelivery(Delivery* pDelivery)
{

	initCustomer(pDelivery->customer);
	if (!L_init(pDelivery->products))
		return 0;
	pDelivery->numberOfProducts = 0;
	getCorrectDate(&pDelivery->deliveryDate);
	pDelivery->deliveryCompany = NULL;
	initDeliveryPerson(pDelivery->deliveryPerson);

	return 1;
}

int readDeliveryFromTextFile(FILE* fp, Delivery* pDel)
{

	if (!initCustomerFromTextFile(fp, pDel->customer))
		return 0;
	if (fscanf(fp, "%d", &pDel->numberOfProducts) < 0)
		return 0;
	for (int i = 0; i < pDel->numberOfProducts; i++)
	{

		Product* p1 = (Product*)malloc(sizeof(Product));
		if (!p1)
			return 0;
		if (!initProductFromTextFile(fp, p1))
			return 0;
		if (!L_insert(&pDel->products->head, p1))
			return 0;
	}
	initDateFromTextFile(fp, &pDel->deliveryDate);
	if (!initDeliveryCompanyFromTextFile(fp, pDel->deliveryCompany))
		return 0;
	if (!initDeliveryPersonFromTextFile(fp, pDel->deliveryPerson))
		return 0;



	return 1;
}

int writeDeliveryToTextFile(FILE* fp, Delivery* pDel)
{
	if (!writeCustomerToTextFile(fp, pDel->customer))
		return 0;
	fprintf(fp, "%d\n", pDel->numberOfProducts);
	NODE* curr = pDel->products->head.next;
	while (curr != NULL)
	{
		if (!writeProductToTextFile(fp, curr->key))
			return 0;
		curr = curr->next;
	}
	writeDateToTextFile(fp, &pDel->deliveryDate);
	if (!writeDeliveryCompanyToTextFile(fp, pDel->deliveryCompany))
		return 0;
	if (!writeDeliveryPersonToTextFile(fp, pDel->deliveryPerson))
		return 0;

	return 1;

}

int readDeliveryFromBinaryFile(FILE* fp, Delivery* pDel)
{
	if (!initCustomerFromBinaryFile(fp, pDel->customer))
		return 0;
	if (fread(&pDel->numberOfProducts, sizeof(int), 1, fp) != 1)
		return 0;
	for (int i = 0; i < pDel->numberOfProducts; i++)
	{

		Product* p1 = (Product*)malloc(sizeof(Product));
		if (!p1)
			return 0;
		if (!initProductFromBinaryFile(fp, p1))
			return 0;
		if (!L_insert(&pDel->products->head, p1))
			return 0;
	}
	initDateFromBinaryFile(fp, &pDel->deliveryDate);
	if (!initDeliveryCompanyFromBinaryFile(fp, pDel->deliveryCompany))
		return 0;
	if (!initDeliveryPersonFromBinaryFile(fp, pDel->deliveryPerson))
		return 0;
	return 1;
}

int writeDeliveryToBinaryFile(FILE* fp, Delivery* pDel)
{
	if (!writeCustomerToBinaryFile(fp, pDel->customer))
		return 0;
	if (fwrite(&pDel->numberOfProducts, sizeof(int), 1, fp) != 1)
		return 0;
	NODE* curr = pDel->products->head.next;
	while (curr != NULL)
	{
		if (!writeProductToBinaryFile(fp, curr->key))
			return 0;
		curr = curr->next;
	}
	writeDateToBinaryFile(fp, &pDel->deliveryDate);
	if (!writeDeliveryCompanyToBinaryFile(fp, pDel->deliveryCompany))
		return 0;
	if (!writeDeliveryPersonToBinaryFile(fp, pDel->deliveryPerson))
		return 0;

	return 1;
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
	NODE* temp = L_find(&pDelivery->products->head, pProduct, compareProductsByName);
	if (!L_delete(temp, NULL))
		return 0;
	return 1;
}


void addProduct(Delivery* pDelivery, Product* pProduct)
{
	L_insert(&pDelivery->products->head, pProduct);
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
	printf("Number of products %d", pDelivery->numberOfProducts);
	L_print(pDelivery->products, printProduct);
	printDate(&pDelivery->deliveryDate);
	printf("Delivery Company Name: %s \n", pDelivery->deliveryCompany->name);
	printf("Delivery Person: \t ");
	printDeliveryPerson(pDelivery->deliveryPerson);
}
