#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

//Person* newPerson(char* pName)
//{
//    Person* pPerson = NULL;
//    pPerson = (Person*)malloc(sizeof(Person));
//    if (!pPerson)
//        return NULL;
//    pPerson->name = NULL;
//    pPerson->name = malloc(sizeof(char) * (strlen(pName) + 1));
//    if(pPerson->name)
//        strcpy( pPerson->name, pName);
//
//    return pPerson;
//}

void initPerson(Person* pPerson)
{
    printf("Enter Persons Name: \n");
    myGets(pPerson->name, MAX_STR_LEN);
    
}

int initPersonFromFile(FILE* fp,Person* pPerson)
{
    return 0;
}

void printPerson(Person* pPerson)
{
    printf("Name: %s\n", pPerson->name);
}
