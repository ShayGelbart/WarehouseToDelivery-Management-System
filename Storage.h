#pragma once
#ifndef __STORAGE__
#define __STORAGE__

#include "Product.h"
#include "DeliveryCompany.h"

typedef struct
{
	int deleteLater;
	DeliveryCompany* DeliveryCompanyArr; // array
}Storage;

int compareManufacturersById(Storage* pStorage, Manufacturer* pMan);

#endif // !__STORAGE__