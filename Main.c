#pragma once
#include <stdio.h>
#include "Storage.h"

#define EXIT -1
#define READ_TXT "Storage.txt"
#define WRITE_TEXT "WriteStorage.txt"
#define READ_BIN "Storage.bin"
#define WRITE_BIN "WriteStorage.bin"

int menu();

typedef enum
{
	eUploadSystem, ePrintSystem, ePrintSpecificElement, eAddElements, eProductSort, eFindProduct,
	eCreative1, eCreative2, eNofOptions
} eMenuOptions;

const char* str[eNofOptions] = { "Upload System","Print System", "Print Specific Element", "Add Elements",  "Product Sort",
								"Find Product", "Rate Delivery", "Edit Delivery" };


int main()
{
	int option, stop = 0, check = 0;
	Storage storage;
	initStorage(&storage);
	do
	{
		option = menu();
		switch (option)
		{
		case eUploadSystem:
			uploadSystemFromFile(READ_TXT, WRITE_BIN, &storage);
			break;
		case ePrintSystem:
			printStorage(&storage);
			break;
		case ePrintSpecificElement:
			menuPrintSpecificElement(&storage);
			break;
		case eAddElements:
			addSpecificElement(&storage);
			break;
		case eProductSort:
			check = sortMenuProductArray(&storage);
			break;
		case eFindProduct:
			bsearchProductArray(&storage, check);
			break;
		case eCreative1:
			returnRating(&storage);
			break;
		case eCreative2:
			editProductsOfDelivery(&storage);
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

	writeStorageToTextFile(WRITE_BIN, &storage);
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