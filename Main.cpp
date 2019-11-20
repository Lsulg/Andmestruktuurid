#include "stdio.h"
#include "DateTime.h"
#include "Objects.h"
#include "Headers.h"
#include "Structs.h"
#pragma warning ( disable : 4996 )

void PrintObjects(HeaderA* pStruct6);
int main()
{
	
	 HeaderA *pStruct = GetStruct6(6, 9);
	 PrintObjects(pStruct);
	// PrintObjects(pStruct);
	// O asemel kirjutage juhendaja poolt antud objekti indeks.
	// N asemel kirjutage juhendaja poolt antud objektide arv3.
	// N ei ole kunagi 0
	//
	return 0;
}
void PrintObjects(HeaderA* pStruct6)
{
	HeaderA* pointerLinkList = pStruct6;
	Object9* head;
	head = (Object9*)pointerLinkList->pObject;
	for (int i = 0; i < 10; i++)
	{
		if (head != NULL)	
		{
			printf("%s, %lu,%02d, %s, %04d\n", head->pID, &head->Code, &head->pDate3->Day, head->pDate3->pMonth,&head->pDate3->Year);
		
		}
		
		head = head->pNext;
	}
	
	

}
/*
typedef struct ob9
{  // formatting string for printf is "%d) %s %lu %02d %s %04d\n", the result is for example "1) Abcde 100 01 Detsember 2010"
   // or "10) Abcde Fghij 100 01 Detsember 2010"
	char* pID;
	unsigned long int Code;
	Date3* pDate3; // Declaration of Date3 is in file DateTime.h
	struct ob9* pNext;
} Object9;
typedef struct
{
	int Day;
	char* pMonth; // pointer to full name in Estonian
	int Year;
} Date3;*/