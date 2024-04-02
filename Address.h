#pragma once
#ifndef __ADDRESS__
#define __ADDRESS__

#include "General.h"

typedef enum {
	eNorth, eHaifa, eJudeaAndSamaria , eCenter , eTelAviv , eJerusalem, eSouth, eEilat, eNofRegions
} eRegionType;

static const char* regionTypeStr[eNofRegions]
= {"North", "Haifa", "Judea and Samaria", "Center", "Tel Aviv" , "Jerusalem", "South", "Eilat"};

typedef struct
{
	eRegionType region;
	char city[MAX_STR_LEN];
	char street[MAX_STR_LEN];
	int houseNumber;
}Address;

int initAddressFromFile(Address* pAddress, FILE* fp);
void initAddress(Address* pAddress);
int getRegion();
void printAddress(Address* pAddress);

#endif