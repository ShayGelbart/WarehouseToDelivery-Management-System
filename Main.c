#pragma once
#include <stdio.h>
#include "Storage.h"

#define EXIT -1

int menu();

typedef enum
{
	eUploadSystem, ePrintSystem, eAddElements, eProductSort, eFindProduct,
	eCreative1, eCreative2, eNofOptions
} eMenuOptions;

const char* str[eNofOptions] = { "Upload System","Print System","Product Sort",
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
		case 1:
			
			break;

		case 2:
			printStorage(&storage);
			break;

		case 3:
			
			break;

		case 4:
		
			break;

		case 5:
			
			break;

		case 6:
			
			break;

		case 7:
			
			break;

		case 8:
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