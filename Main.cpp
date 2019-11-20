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
Object9* RemoveExistingObject(HeaderA** pStruct6, char* pExistingID);
int InsertNewObject(HeaderA** pStruct6, char* pNewID, int NewCode);
void PrintObjects(HeaderA* pStruct6);
Node* CreateBinaryTree(HeaderA* pStruct6);
/*void TreeTraversal(Node* pTree);
Node* DeleteTreeNode(Node* pTree, unsigned long int Code);*/
int main()
{
	HeaderA* pStruct = GetStruct6(9, 35);
	/* testid Dx, Db, Dz, Dk, Aa, Wu,
Wa, Zw, Za, wk, Wa, WW, W8, W_ */
	char str[16] = "Dx";
	char* a = str;
	char str1[16] = "Db";
	char* b = str1;
	char str2[16] = "Dz";
	char* c = str2;
	char str3[16] = "Dk";
	char* d = str3;
	char str4[16] = "Aa";
	char* e = str4;
	char str5[16] = "Wu";
	char* f = str5;
	char str6[16] = "Wa";
	char* g = str6;
	char str8[16] = "Wb";
	char* h = str8;
	char str7[16] = "Zw";
	char* i = str7;
	char str9[16] = "Wb";
	char* j = str9;
	char str10[16] = "Wa";
	char* k = str10;
	char str11[16] = "WW";
	char* l = str11;
	char str12[16] = "W8";
	char* m = str12;
	char str13[16] = "W_";
	char* n = str13;

	printf("Algne\n");
	PrintObjects(pStruct);


	printf("inserted\n");
	InsertNewObject(&pStruct, a, 21);
	InsertNewObject(&pStruct, b, 21);
	InsertNewObject(&pStruct, c, 21);
	InsertNewObject(&pStruct, d, 21);
	InsertNewObject(&pStruct, e, 21);
	InsertNewObject(&pStruct, f, 21);
	InsertNewObject(&pStruct, g, 21);
	InsertNewObject(&pStruct, h, 21);
	InsertNewObject(&pStruct, i, 21);
	InsertNewObject(&pStruct, j, 21);
	InsertNewObject(&pStruct, k, 21);
	InsertNewObject(&pStruct, l, 21);
	InsertNewObject(&pStruct, m, 21);
	InsertNewObject(&pStruct, n, 21);

	printf("removed\n");
	

	RemoveExistingObject(&pStruct, a);
	RemoveExistingObject(&pStruct, b);
	RemoveExistingObject(&pStruct, c);
	RemoveExistingObject(&pStruct, d);
	RemoveExistingObject(&pStruct, e);
	RemoveExistingObject(&pStruct, f);
	RemoveExistingObject(&pStruct, g);
	RemoveExistingObject(&pStruct, h);
	RemoveExistingObject(&pStruct, i);
	RemoveExistingObject(&pStruct, j);
	RemoveExistingObject(&pStruct, k);
	RemoveExistingObject(&pStruct, l);
	RemoveExistingObject(&pStruct, m);
	RemoveExistingObject(&pStruct, n);

	PrintObjects(pStruct);
	return 0;
}
Node* CreateBinaryTree(HeaderA* pStruct6)
{
	HeaderA* pHeader;
	Object9* pObject9;
	pObject9 = (Object9*)pHeader->pObject;
	Node* pNew = (Node*)malloc(sizeof(Node));
	pNew->pObject = pObject9->Code;
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
			if (pObject9 == NULL)
			{
				printf("pObject9 was nullptr");
				break;
			}
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
Node* CreateBinaryTree(HeaderA* pStruct6)
{
	return nullptr;
}
int InsertNewObject(HeaderA** pStruct6, char* pNewID, int NewCode)
{
	if (!pNewID)
		return 0;
	HeaderA* pHeader = *pStruct6;
	HeaderA* Headerbuffer = *pStruct6;
	HeaderA* newHeaderAPrev = *pStruct6;
	Object9* pObject9;
	if (!pHeader)
	{
		return 0;
	}
	int resultCmp = 1;
	int headerCounter = 0;
	int ObjectCounter = 0;
	char pNewIDBuffer[40];

	strcpy(pNewIDBuffer, pNewID);
	char cBeingBuffer = *pNewIDBuffer;
	char headerAcBegin = pHeader->cBegin;
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
					printf("\n cannot enter %s \n", pNewID);
					return 0;
				}
			}
			break;
		}
		else
		{
			printf("\n cannot enter %s \n", pNewID);
			return 0;
		}
		i++;
	}
	while (1)
	{
		if ((pHeader->pNext == NULL || (cBeingBuffer > headerAcBegin && cBeingBuffer < pHeader->cBegin) || cBeingBuffer < pHeader->cBegin && headerCounter == 0) && cBeingBuffer != pHeader->cBegin)
		{
			HeaderA* newHeaderA;
			HeaderA* tempNext;
			newHeaderA = (HeaderA*)malloc(sizeof(HeaderA));
			if (newHeaderA == NULL)
			{
				printf("\nnewHeaderA was nullptr\n");
				return 0;
			}
			newHeaderA->cBegin = cBeingBuffer;
			if (cBeingBuffer < pHeader->cBegin && headerCounter == 0)
			{
				tempNext = *pStruct6;
				newHeaderA->pNext = tempNext;
				*pStruct6 = newHeaderA;
				pHeader = newHeaderA;
				newHeaderA->pObject = NULL;
			}
			else if (cBeingBuffer > headerAcBegin && cBeingBuffer < pHeader->cBegin)
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
			if (pHeader->pObject == NULL)
			{
				Object9* newObject;
				Date3* newDate3;
				int nMonthBuf = 10;
				char* pMonthBuf;
				time_t newTime;
				newDate3 = (Date3*)malloc(sizeof(Date3));
				pMonthBuf = (char*)malloc(sizeof(char) + 9);
				newTime = NULL;
				if (newDate3 == NULL || pMonthBuf == NULL)
				{
					printf("GetDate3 memory allocation failed");
					return 0;
				}
				time(&newTime);
				newObject = (Object9*)malloc(sizeof(Object9));
				if (newObject == NULL)
				{
					return 0;
				}
				newObject->pID = (char*)malloc(strlen(pNewID) + 1);
				if (newObject->pID == NULL)
				{
					return 0;
				}
				GetDate3(newTime, nMonthBuf, pMonthBuf, newDate3);
				strcpy(newObject->pID, pNewID);
				newObject->Code = NewCode;
				newObject->pDate3 = newDate3;
				newObject->pNext = newObject;
				newHeaderA->pObject = newObject;
				return 1;
			}
		}
		if (!pHeader)
		{
			printf("pheader->pNext was nullptr\n");
			break;
		}
		if (cBeingBuffer == pHeader->cBegin)
		{
			pObject9 = (Object9*)pHeader->pObject;
			while (1)
			{
				if (!strcmp(pObject9->pID, pNewID))
				{
					printf("\n cannot enter %s \n", pNewID);
					return 0;
				}
				else//lisada objekt
				{
					Object9* newObject;
					Date3* newDate3;
					int nMonthBuf = 10;
					char* pMonthBuf;
					time_t newTime;
					newDate3 = (Date3*)malloc(sizeof(Date3));
					pMonthBuf = (char*)malloc(sizeof(char) + 9);
					newTime = NULL;
					if (newDate3 == NULL || pMonthBuf == NULL)
					{
						printf("GetDate3 memory allocation failed");
						return 0;
					}
					time(&newTime);
					newObject = (Object9*)malloc(sizeof(Object9));
					if (newObject == NULL)
					{
						return 0;
					}
					newObject->pID = (char*)malloc(strlen(pNewID) + 1);
					if (newObject->pID == NULL)
					{
						return 0;
					}
					GetDate3(newTime, nMonthBuf, pMonthBuf, newDate3);
					strcpy(newObject->pID, pNewID);
					//newObject->pID = pNewID;
					newObject->Code = NewCode;
					newObject->pDate3 = newDate3;
					Object9* temp;
					Object9* firstObject;
					Object9* prevObject;
					firstObject = pObject9->pNext;
					int swapped, i = 0;
					//sortin objekti
					if (pObject9->pNext != pObject9)
					{
						do
						{
							swapped = 0;
							while (pObject9->pNext == pObject9)
							{
								if (pObject9->pID > pObject9->pNext->pID)
								{
									temp = pObject9;
									temp->pID = pObject9->pID;
									pObject9->pID = pObject9->pNext->pID;
									pObject9->pNext->pID = temp->pID;
									swapped = 1;
								}
							}
						} while (swapped);
					}
					int ObjectCounter = 0;
					temp = pObject9;
					while (1)
					{
						prevObject = pObject9;
						pObject9 = pObject9->pNext;
						int cmpVaule = strcmp(newObject->pID, pObject9->pID);
						int cmpVaule2 = strcmp(newObject->pID, pObject9->pNext->pID);
						if (ObjectCounter == 0 && cmpVaule < 0) // esimene
						{
							newObject->pNext = pObject9;
							while (1)
							{
								pObject9 = pObject9->pNext;
								if (temp == pObject9)
								{
									pObject9->pNext = newObject;
									break;
								}
							}
							pHeader->pObject = newObject;
							break;
						}
						else if (cmpVaule < 0 && cmpVaule2 > 0 && ObjectCounter != 0) //keskmine
						{
							newObject->pNext = pObject9->pNext->pNext;
							pObject9->pNext->pNext = newObject;
							pHeader->pObject = firstObject;
							break;
						}
						else if (temp == pObject9) // end of object viimane objekt
						{
							newObject->pNext = firstObject;
							while (1)
							{
								pObject9 = pObject9->pNext;
								if (temp == pObject9)
								{
									pObject9->pNext = newObject;
									break;
								}
							}
							pHeader->pObject = firstObject;
							break;
						}
						else
						{
							ObjectCounter++;
						}
					}
					return 1;
				}
				break;
			}
			break;
		}
		newHeaderAPrev = pHeader;
		pHeader = pHeader->pNext;
		headerCounter++;
	}
	return 1;
}
Object9* RemoveExistingObject(HeaderA** pStruct6, char* pExistingID)
{
	if (!pExistingID)
	{
		return 0;
	}
	char pNewIDBuffer[40];
	char cBeingBuffer[16];
	strcpy(pNewIDBuffer, pExistingID);
	strncpy(cBeingBuffer, pNewIDBuffer, sizeof(16));
	strncpy(cBeingBuffer, pNewIDBuffer, 1);
	cBeingBuffer[1] = '\0';
	int i = 0;
	HeaderA* pHeader = *pStruct6;
	HeaderA* prevpHeader = *pStruct6;
	HeaderA* pHeaderTemp = NULL;
	Object9* objectHeader;
	Object9* prevObject;
	Object9* pNextObject;
	int HeaderCounter = 0;
	while (1) //liikumine järgmise headerisse
	{
		if (pHeader == NULL)
		{
			break;
		}
		if (*cBeingBuffer == pHeader->cBegin)
		{
			prevObject = (Object9*)pHeader->pObject;
			objectHeader = (Object9*)pHeader->pObject;
			int objectCounter = 0;
			while (1)
			{
				pNextObject = (Object9*)pHeader->pObject;
				int cmpValue = strcmp(pExistingID, objectHeader->pID);
				if (objectHeader->pNext == pNextObject && objectCounter == 0 && cmpValue == 0 && HeaderCounter == 0)//kui objekt on ainust selles headeris ja esimene ta on esimene header
				{
					*pStruct6 = pHeader->pNext;
					free(pHeader);
					return objectHeader;
				}
				else if (objectHeader->pNext == pNextObject && objectCounter == 1 && cmpValue == 0 && HeaderCounter != 0 && pNextObject->pNext == pNextObject)	//kui objekt on ainust selles headeris ja kuskil headri ahelloendi keskel
				{
					prevpHeader->pNext = pHeader->pNext;
					free(pHeader);
					return objectHeader;
				}
				else if (objectHeader->pNext != pNextObject && objectCounter == 0 && cmpValue == 0)		//kui objekt on lihtsalt esimene kuskil keskel 
				{
					Object9* temp;
					temp = objectHeader;
					pHeader->pObject = objectHeader->pNext;
					while (1)
					{
						prevObject = objectHeader;
						objectHeader = objectHeader->pNext;
						if (objectHeader->pNext == temp)
						{
							objectHeader->pNext = temp->pNext;
							return objectHeader;
							break;
						}
					}
				}
				else if (objectHeader->pNext == pNextObject && cmpValue == 0 && objectCounter != 0 && HeaderCounter != 0)		//kui objekt on viimane
				{
					Object9* temp;
					temp = objectHeader;
					pHeader->pObject = objectHeader->pNext;
					while (1)
					{
						prevObject = objectHeader;
						objectHeader = objectHeader->pNext;
						if (objectHeader->pNext == temp)
						{
							objectHeader->pNext = temp->pNext;
							return objectHeader;
						}
					}
					return objectHeader;
				}
				else if (cmpValue == 0 && objectCounter != 0)		//kui objekt on kuskil keskel
				{
					prevObject->pNext = objectHeader->pNext;
					return objectHeader;
				}
				else if (cmpValue != 0 && objectHeader->pNext == pNextObject)				// objekti ei ole
				{
					printf("object was not found \n");
					return 0;
				}
				else
				{
					objectCounter++;
					prevObject = objectHeader;
					objectHeader = objectHeader->pNext;
				}
			}
		}
		prevpHeader = pHeader;
		pHeader = pHeader->pNext;
		HeaderCounter++;
	}
	return 0;
}
/*	while (pExistingID != NULL)	//kontrollin kas pExistingID vastab formaadile
	{
		if ('A' <= pExistingID[0] && pExistingID[0] <= 'Z')
		{
			while (pExistingID[i + 1] != '\0')
			{
				if (pExistingID[i + 1] >= 'a' && pExistingID[i + 1] <= 'z')
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
	}*/
/*esimene
*/