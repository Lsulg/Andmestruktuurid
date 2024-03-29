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
void TreeTraversal(Node* pTree);
stack* Push(stack* pStack, void* pNode);
stack* Pop(stack* pStack, void** pResult);
Node* FindParentNode(Node* pTree, Node* childNode);
Node* DeleteTreeNode(Node* pTree, unsigned long int Code);
int main()
{
	HeaderA* pStruct = GetStruct6(9, 10);
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

	/*	printf("Algne\n");
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
	PrintObjects(pStruct);
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

	PrintObjects(pStruct);*/
	Node* tree;
	printf(" Tree\n\n");
	tree = CreateBinaryTree(pStruct);
	TreeTraversal(tree);
	printf("\n\n Deleted\n\n");
	tree = DeleteTreeNode(tree, 64866018);
	TreeTraversal(tree);
	return 0;
}
Node* DeleteTreeNode(Node* pTree, unsigned long int Code)
{
	stack* pStack = 0;
	Node* p1 = pTree;
	Node* previous, *temp, * p2 = NULL;
	if (!pTree)
		return pTree;

	int i = 0;
	do
	{

		while (p1)
		{
			pStack = Push(pStack, p1);
			p1 = p1->pLeft;
		}
		pStack = Pop(pStack, (void**)&p2);
		previous = FindParentNode(pTree, p2);
		//	2. Eemaldataval tipul ei ole t�tartippe.
		if ((((ob9*)p2->pLeft) == NULL) && (((ob9*)p2->pRight) == NULL) && ((((ob9*)p2->pObject)->Code) == Code))
		{
			printf("Eemaldataval tipul ei ole t�tartippe.\n");
			if (previous->pLeft == p2)
			{
				previous->pLeft = NULL;
			}
			else
			{
				previous->pRight = NULL;
			}
			printf("\n vabastan %d \n", ((((ob9*)p2->pObject)->Code)));
			free(p2);
			return pTree;
		}
		//	3. Eemaldataval tipul on ainult parempoolne t�tartipp.
		if ((((ob9*)p2->pLeft) == NULL) && ((((ob9*)p2->pObject)->Code) == Code))
		{
			printf("Eemaldataval tipul on ainult parempoolne t�tartipp.\n");
			if (previous->pLeft == p2) {
				previous->pLeft = p2->pRight;
			}
			else
			{
				previous->pRight = p2->pRight;
			}
			printf("\n vabastan %d \n", ((((ob9*)p2->pObject)->Code)));
			free(p2);
			return pTree;
		}
		//	4. Eemaldataval tipul on ainult vasakpoolne t�tartipp.
		if ((((ob9*)p2->pRight) == NULL) && ((((ob9*)p2->pObject)->Code) == Code))
		{
			printf("Eemaldataval tipul on ainult vasakpoolne t�tartipp.\n");
			if (previous->pLeft == p2)
			{
				previous->pLeft = p2->pLeft;
			}
			else
			{
				previous->pRight = p2->pLeft;
			}
			printf("\n vabastan %d \n", ((((ob9*)p2->pObject)->Code)));
			free(p2);
			return pTree;
		}
		//	5. Eemaldataval tipul on m�lemad t�tartipuud ehk sobib ka juureks.
		if ((((ob9*)p2->pLeft) != NULL) && (((ob9*)p2->pRight) != NULL) && ((((ob9*)p2->pObject)->Code) == Code))
		{
			printf(" Eemaldataval tipul on m�lemad t�tartipuud ehk sobib ka juureks.\n");
			if (p2 == pTree)
			{
				pTree = p2->pRight;
			}
			else
			{
				if (previous->pLeft == p2)
				{
					previous->pLeft = p2->pRight;
				}
				else
				{
					previous->pRight = p2->pRight;
				}
			}
			temp = p2->pRight;
			if (!temp)
				return 0;
			// Leian v�iksima v��rtuse paremast ahelast
			while (1)
			{
				if (temp->pLeft == NULL)
				{
					break;
				}
				else
				{
					temp = temp->pLeft;
				}
			}

			temp->pLeft = p2->pLeft;
			printf("\n vabastan %d \n", ((((ob9*)p2->pObject)->Code)));
			free(p2);
			return pTree;

		}
		p1 = p2->pRight;
	} while (!(!pStack && !p1));
	//	6. Etteantud koodiga kirjet ei olegi
	printf("\n That code did not excist \n");
	return pTree;
}
Node* FindParentNode(Node* pTree, Node* childNode)
{
	stack* pStack = 0;
	Node* p1 = pTree, * p2;
	if (!pTree)
	{
		printf("NULL");
		return NULL;
	}
	do
	{
		while (p1)
		{
			pStack = Push(pStack, p1);
			p1 = p1->pLeft;

		}
		pStack = Pop(pStack, (void**)&p2);

		p1 = p2->pRight;
		if (p2->pLeft == childNode)
		{
			return p2;
		}
		if (p2->pRight == childNode)
		{
			return p2;
		}
	} while (!(!pStack && !p1));
	return NULL;
}
stack* Pop(stack* pStack, void** pResult)
{
	stack* p;
	if (!pStack)
	{
		*pResult = 0;
		return pStack;
	}
	*pResult = pStack->pObject;
	p = pStack->pNext;
	free(pStack);
	return p;
}
stack* Push(stack* pStack, void* pNode)
{
	errno = 0;
	stack* pNew;
	if (!pNode)
	{
		errno = EINVAL;
		return pStack;
	}
	pNew = (stack*)malloc(sizeof(stack));
	if (!pNew)
		return 0;
	pNew->pObject = pNode;
	pNew->pNext = pStack;
	return pNew;
}
Node* CreateBinaryTree(HeaderA* pStruct6)
{
	HeaderA* pHeader = pStruct6;
	Object9* pObjectHeader;
	Object9* temp;
	Node* tree;
	Node* root = NULL;
	while (1) //header loop
	{
		if (pHeader == NULL)
		{
			break;
		}
		else
		{
			pObjectHeader = (Object9*)pHeader->pObject;
			while (pObjectHeader != NULL) // Object loop
			{
				Node* pNew = (Node*)malloc(sizeof(Node));// uus tipp
				if (!pNew)
				{
					break;
				}
				pNew->pObject = pObjectHeader;
				pNew->pLeft = NULL;
				pNew->pRight = NULL;
				tree = root;
				while (1)
				{
					if (!root)
					{
						root = pNew;
						tree = root;
						break;
					}
					if (((ob9*)pNew->pObject)->Code > ((ob9*)(tree->pObject))->Code)
					{
						if (tree->pRight == NULL)
						{
							tree->pRight = pNew;
							break;
						}
						else
						{
							tree = tree->pRight;
						}
					}
					else
					{
						if (tree->pLeft == NULL)
						{
							tree->pLeft = pNew;
							break;

						}
						else
						{
							tree = tree->pLeft;
						}
					}
				}
				temp = (Object9*)pHeader->pObject;
				pObjectHeader = pObjectHeader->pNext;
				if (temp == pObjectHeader)
				{
					break;
				}
			}
			pHeader = pHeader->pNext;

		}

	}

	return root;
}
void TreeTraversal(Node* pTree)
{
	stack* pStack = 0;
	Node* p1 = pTree, * p2;
	int i = 1;
	if (!pTree)
		return;
	do
	{

		while (p1)
		{
			pStack = Push(pStack, p1);
			p1 = p1->pLeft;
		}
		pStack = Pop(pStack, (void**)&p2);
		printf("%d %s %lu %02d %02s %04d\n",i, ((ob9*)p2->pObject)->pID, ((ob9*)p2->pObject)->Code, ((ob9*)p2->pObject)->pDate3->Day, ((ob9*)p2->pObject)->pDate3->pMonth, ((ob9*)p2->pObject)->pDate3->Year);
		p1 = p2->pRight;
		i++;
	} while (!(!pStack && !p1));
}
void PrintObjects(HeaderA* pStruct6)
{
	HeaderA* pHeader = pStruct6;
	Object9* pObject9;
	Object9* pNextObject;
	pNextObject = (Object9*)pHeader->pObject;
	int i = 0;
	while (1) //liikumine j�rgmise headerisse
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
			while (1) // liikumine j�rgmisesse objekti
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
		if ((pHeader->pNext == NULL || (cBeingBuffer > headerAcBegin&& cBeingBuffer < pHeader->cBegin) || cBeingBuffer < pHeader->cBegin && headerCounter == 0) && cBeingBuffer != pHeader->cBegin)
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
			else if (cBeingBuffer > headerAcBegin&& cBeingBuffer < pHeader->cBegin)
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
	while (1) //liikumine j�rgmise headerisse
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