#pragma once
#ifndef __STORAGE__
#define __STORAGE__

#include "Product.h"

typedef struct
{
	int deleteLater;
}Storage;

int compareManufacturersById(Storage* pStorage, Manufacturer* pMan);

#endif // !__STORAGE__