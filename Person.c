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
    pPerson->name = getStrExactName("Enter Persons Name:");    
}

int initPersonFromTextFile(FILE* fp,Person* pPerson)
{
    char name[MAX_STR_LEN] = { 0 };
    fgetc(fp);
    if (fgets(name, MAX_STR_LEN, fp) == NULL)
        return 0;
    //pPerson->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
    //IF_NULL_RETURN_ZERO(pPerson->name)
    name[strlen(name) - 1] = '\0';
    pPerson->name = _strdup(name);
    
    if (!pPerson->name)
        return 0;
    return 1;
}

int initPersonFromBinaryFile(FILE* fp, Person* pPerson)
{
    int len;
    if(fread(&len , sizeof(int) , 1 , fp) != 1)
        return 0;
    pPerson->name = (char*)malloc(sizeof(char) * len);
    if (!pPerson->name)
        return 0;
    if (len >= sizeof(pPerson->name))
        return 0;
    if (fread(pPerson->name, sizeof(char), len, fp) != len)
        return 0;
    return 1;
}

int	writePersonToTextFile(FILE* fp, Person* pPerson)
{
    if (fprintf(fp, "%s\n", pPerson->name) < 0)
        return 0;
    return 1;
}

int writePersonToBinaryFile(FILE* fp, Person* pPerson)
{
    int len = (int)strlen(pPerson->name) + 1;
    if (fwrite(&len, sizeof(int), 1, fp) != 1)
        return 0;
    if (fwrite(pPerson->name, sizeof(char), len, fp) != len)
        return 0;
    return 1;
}

void printPerson(Person* pPerson)
{
    printf("Name: %s\t", pPerson->name);
}
