#pragma once
#include <stdio.h>
#include "Storage.h"

#define EXIT -1

int menu();

typedef enum
{
	eUploadSystem, ePrintSystem, eAddElements, ePrintSpecificElement ,eProductSort, eFindProduct,
	eCreative1, eCreative2, eNofOptions
} eMenuOptions;

const char* str[eNofOptions] = { "Upload System","Print System", "Print Specific Element", "Product Sort",
								"Find Product", "Print all Airports",
								"Print all flights with plane type" };


int main()
{
	int option, stop = 0;
	Storage storage;
	do
	{
		option = menu();
		switch (option)
		{
		case eUploadSystem:
			uploadSystemFromFile("CHANGE_LATER", &storage);
			break;
		case ePrintSystem:
			printStorage(&storage);
			break;
		case eAddElements:
			menuPrintSpecificElement(&storage);
			break;
		case ePrintSpecificElement:
			addSpecificElement(&storage);
			break;
		case eProductSort:
			
			break;
		case eFindProduct:
			
			break;
		case eCreative1:
			
			break;
		case eCreative2:
			break;
		case EXIT:
			printf("Bye bye\n");
			stop = 1;
			break;

		default:
			printf("Wrong option\n");
			break;
		}
	} while (!stop);
}


int menu()
{
	int option = 0;
	printf("\n\n");
	printf("Please choose one of the following options\n");
	for (int i = 0; i < eNofOptions; i++)
		printf("%d - %s\n", i, str[i]);
	printf("%d - Quit\n", EXIT);
	scanf("%d", &option);
	//clean buffer
	char tav;
	scanf("%c", &tav);
	return option;
}