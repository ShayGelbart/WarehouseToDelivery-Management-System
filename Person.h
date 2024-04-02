#pragma once
#include "General.h"


typedef struct 
{
	char*  name;

}Person ;


//Person*		newPerson(char* pName);
void			initPerson(Person* pPerson);
int				initPersonFromFile(FILE* fp, Person* pPerson);
void			printPerson(Person* pPerson);