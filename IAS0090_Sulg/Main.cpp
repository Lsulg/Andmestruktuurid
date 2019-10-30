#include "stdio.h"
#include <stdlib.h>
#include <string>
#include "DateTime.h"
#include "Objects.h"
#include "Headers.h"
#include "Structs.h"
#include "time.h"
#include <malloc.h>
#pragma warning ( disable : 4996 )
//Objectn* RemoveExistingObject(HeaderA** pStruct2, char* pExistingID); valmis 11 nädalaks
int InsertNewObject(HeaderA** pStruct6, char* pNewID, int NewCode);
void PrintObjects(HeaderA* pStruct6);
int main()
{
	char str[16] = "Al";
	char* a = str;
	HeaderA* pStruct = GetStruct6(9, 35);
	//PrintObjects(pStruct);
	InsertNewObject(&pStruct, a, 21);



	// O asemel kirjutage juhendaja poolt antud ud objektide arv3.
	// N ei ole kunagi 0objekti indeks.
	// N asemel kirjutage juhendaja poolt ant
	//

	return 0;
}
void PrintObjects(HeaderA* pStruct6)
{
	HeaderA* pHeader = pStruct6;
	Object9* pObject9;
	Object9* pNextObject;
	pNextObject = (Object9*)pHeader->pObject;
	int i = 0;
	while (1) //liikumine järgmise headerisse
	{
		i++;
		if (pHeader == NULL)
		{
			break;
		}
		else
		{
			pObject9 = (Object9*)pHeader->pObject;
			printf("%d %c\n", i, pHeader->cBegin);
			while (1) // liikumine järgmisesse objekti
			{
				printf("%s %lu %02d %s %04d \n", pObject9->pID, pObject9->Code, pObject9->pDate3->Day, pObject9->pDate3->pMonth, pObject9->pDate3->Year);
				pNextObject = (Object9*)pHeader->pObject;
				pObject9 = pObject9->pNext;
				if (pNextObject == pObject9)
				{
					break;
				}
			}
		}
		pHeader = pHeader->pNext;
	}
}
int InsertNewObject(HeaderA** pStruct6, char* pNewID, int NewCode)
{
	HeaderA* pHeader = *pStruct6;
	HeaderA* Headerbuffer = *pStruct6;
	HeaderA* newHeaderAPrev = *pStruct6;
//	Object9* pObject9;
	if (!pHeader)
	{
		return 0;
	}
	int resultCmp = 1;
	int headerCounter = 0;
	int ObjectCounter = 0;
	char pNewIDBuffer[40];
	char cBeingBuffer[16];

	strcpy(pNewIDBuffer, pNewID);
	strncpy(cBeingBuffer, pNewIDBuffer, sizeof(16));
	strncpy(cBeingBuffer, pNewIDBuffer, 1);
	cBeingBuffer[1] = '\0';

	char headerAcBegin;
	headerAcBegin = pHeader->cBegin;
	if (!pNewID)
	{
		return 0;
	}

	int i = 0;
	//kontrollin kas pID vastab formaadile
	while (pNewID != NULL)
	{
		if ('A' <= pNewID[0] && pNewID[0] <= 'Z')
		{
			while (pNewID[i + 1] != '\0')
			{
				if (pNewID[i + 1] >= 'a' && pNewID[i + 1] <= 'z')
				{
					break;
				}
				else
				{
					printf("\n cannot enter given identifier \n");
					return 0;

				}
			}
			break;
		}
		else
		{
			printf("\n cannot enter given identifier \n");
			return 0;
		}
		i++;
	}
	while (1)
	{
		if ((pHeader->pNext == NULL || (*cBeingBuffer > headerAcBegin && *cBeingBuffer < pHeader->cBegin) || *cBeingBuffer < pHeader->cBegin && headerCounter == 0) && *cBeingBuffer != pHeader->cBegin)
		{
			HeaderA* newHeaderA;
			HeaderA* tempNext;
			newHeaderA = (HeaderA*)malloc(sizeof(HeaderA));
			if (newHeaderA == NULL)
			{
				printf("\nnewHeaderA was nullptr\n");
				return 0;
			}
			newHeaderA->cBegin = *cBeingBuffer;
			if (*cBeingBuffer < pHeader->cBegin && headerCounter == 0)
			{
				tempNext = *pStruct6;
				newHeaderA->pNext = tempNext;
				*pStruct6 = newHeaderA;
				pHeader = newHeaderA;
				newHeaderA->pObject = NULL;
			
			}
			else if (*cBeingBuffer > headerAcBegin && *cBeingBuffer < pHeader->cBegin)
			{
				newHeaderA->pNext = newHeaderAPrev->pNext;
				newHeaderAPrev->pNext = newHeaderA;
				pHeader = newHeaderA;
				newHeaderA->pObject = NULL;
				
			}
			else 
			{
				tempNext = pHeader->pNext;
				pHeader->pNext = newHeaderA;
				newHeaderA->pNext = tempNext;
				pHeader = newHeaderA;
				newHeaderA->pObject = NULL;
			}
		}
		if (!pHeader)
		{
			//printf("pheader->pNext was nullptr\n");
			break;
		}
		if (*cBeingBuffer == pHeader->cBegin)
		{
			//uus objekt uues headeris

			if (pHeader->pObject == NULL)
			{
				HeaderA *linkingHeader;
				Object9 *newObject;
			/*	Date3 *newDate3;
				int nMonthBuf = 20;
				char* pMonthBuf;
				time_t newTime;
				newDate3 = (Date3*)malloc(sizeof(Date3));
				pMonthBuf = (char*)malloc(sizeof(char) + 1);
				newTime = (time_t)malloc(sizeof(time_t) + 1);
				
				if (newDate3 == NULL || pMonthBuf == NULL || newTime == NULL)
				{
					printf("GetDate3 memory allocation failed");
					return 0;
				}*/
				//time(&newTime);

				linkingHeader = (HeaderA*)malloc(sizeof(HeaderA));
				newObject = (Object9*)malloc(sizeof(Object9));
				if (newObject == NULL || linkingHeader == NULL)
				{
					return 0;
				}
				
			//	GetDate3(newTime, nMonthBuf, pMonthBuf, newDate3);
				newObject->pID = pNewID;
				newObject->Code = NewCode;
			//	newObject->pDate3 = newDate3;
				linkingHeader->pObject = newObject;
				

				printf("%s %d \n", newObject->pID, newObject->Code);
				//printf("%d \n", newObject->pDate3->Day);
		//		printf("%p\n", newDate3);
				
			}
			/*while (1)
			{
				if (!strcmp(pObject9->pID, pNewID))
				{
					return 0;
				}
				else//lisada objekt
				{
				}

			}*/
			
			break;
		}
		newHeaderAPrev = pHeader;
		pHeader = pHeader->pNext;
		headerCounter++;
	}
	return 1;

}
//Objectn* RemoveExistingObject(HeaderA** pStruct2, char* pExistingID); valmis 11 nädalaks
/*Date3 pDate3;
int nMonthBuf = 1;
char* pMonthBuf = (char*)malloc(sizeof(nMonthBuf) + 1);
if (pMonthBuf == NULL)
{
	printf("\Monthbuffer was nullptr\n");
	return 0;
}
GetDate3(time(0), nMonthBuf, pMonthBuf, &pDate3);*/
/*pNewObject = (Object9*)malloc(sizeof(Object9));
				if (pNewObject == NULL)
				{
					printf("\nnewObject was nullptr\n");
					return 0;
				}
				pNewObject->pID = (char*)malloc(sizeof(*pNewID) + 1);
				if (pNewObject->pID == NULL)
				{
					printf("\nnewObject was nullptr\n");
					return 0;
				}
				strcpy(pNewObject->pID, pNewID);
				printf("Header will be first %s \n", pNewID);
*/

