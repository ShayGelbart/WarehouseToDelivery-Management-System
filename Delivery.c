#include <stdio.h>
#include "Delivery.h"

void initDelivery(Delivery* pDelivery)
{
	
	initCustomer(pDelivery->customer);
	if (!L_init(pDelivery->products))
		return;
	pDelivery->numberOfProducts = 0;
	getCorrectDate(&pDelivery->deliveryDate);
	initDeliveryCompany(pDelivery->deliveryCompany);
	initDeliveryPerson(pDelivery->deliveryPerson);


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
	/*for(int i=0;i<pDelivery->numberOfProducts;i++)
		if(!compareProducts(pProduct,&pDelivery->products[i])
			return 999999;*/

	return 0;
}



int addProduct(Delivery* pDelivery, Product* pProduct)
{
	return 0;
}

void changeRatingWhenDelivered(Delivery* pDelivery)
{
}

void printDelivery(Delivery* pDelivery)
{
	printf("");
}
