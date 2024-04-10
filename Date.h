#pragma once
#ifndef __MYDATE__
#define __MYDATE__

#define MIN_YEAR 2023

typedef struct
{
	int			day;
	int			month;
	int			year;
}Date;

void	getCorrectDate(Date* pDate);
int		checkDate(char* date, Date* pDate);
int		initDateFromTextFile(FILE* fp, Date* pDate);
int		initDateFromBinaryFile(FILE* fp, Date* pDate);
void	writeDateToTextFile(FILE* fp, Date* pDate);
int		writeDateToBinaryFile(FILE* fp, Date* pDate);
void	printDate(const Date* pDate);


#endif
