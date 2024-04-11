#pragma once
#ifndef __GENERAL__
#define __GENERAL__

#define MAX_STR_LEN 255

#define FREE_RETURN_ZERO(object) {free(object); return 0;}
#define IF_NULL_RETURN_ZERO(object) {if(!object) return 0;}

typedef enum {
	eToys, eBooks, eElectronics, eSports, eFurniture, eClothing, eBeauty, eNofProductTypes
} eProductType;

static const char* productTypeStr[eNofProductTypes]
= { "Toys", "Books", "Electronics", "Sports", "Furniture" , "Clothing", "Beauty" };

char* getStrExactName(const char* msg);
char* myGets(char* buffer, int size);
char* getDynStr(char* str);
char** splitCharsToWords(char* str, int* pCount, int* pTotalLength);
int generateRandom(int upperBorder, int lowerBorder);
void generalArrFunction(void* arr, int numOfElements, int size, void(*func)(void* element));




#endif

