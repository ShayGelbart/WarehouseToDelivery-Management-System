#pragma once
#include "General.h"


typedef struct 
{
	char*  name;

}Person ;


//Person*		newPerson(char* pName);
void			initPerson(Person* pPerson);
int				initPersonFromTextFile(FILE* fp, Person* pPerson);
int				initPersonFromBinaryFile(FILE* fp, Person* pPerson);
int				writePersonToTextFile(FILE* fp, Person* pPerson);
int				writePersonToBinaryFile(FILE* fp, Person* pPerson);
void			printPerson(Person* pPerson);