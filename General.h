#pragma once
#ifndef __GENERAL__
#define __GENERAL__

#define MAX_STR_LEN 255
#define UPPER_BORDER_ID 999
#define LOWER_BORDER_ID 1

#define FREE_RETURN_ZERO(object) {free(object); return 0;}
#define IF_NULL_RETURN_ZERO(object) {if(!object) {return 0;}}

typedef enum {
	eBeauty, eBooks, eClothing, eElectronics, eFurniture, eSports, eToys, eNofProductTypes
} eProductType;

static const char* productTypeStr[eNofProductTypes]
= { "Beauty", "Books", "Clothing", "Electronics", "Furniture", "Sports", "Toys"};

char* getStrExactName(const char* msg);
char* myGets(char* buffer, int size);
char* getDynStr(char* str);
char** splitCharsToWords(char* str, int* pCount, int* pTotalLength);
int generateRandom(int upperBorder, int lowerBorder);
void generalArrFunction(void* arr, int numOfElements, int size, void(*func)(void* element));




#endif

