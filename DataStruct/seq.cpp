#include<stdio.h>
#include<stdlib.h>

#define INITSIZE 20   //线性表存储数据空间的初始分配量
typedef double ElemType;
typedef struct list
{
    ElemType *elem;
    int length;
    int listSize;
}SeqList;

void InitList(SeqList **ppList);
void IncreaseSize(SeqList *pList, int length);
bool InsertElem(SeqList * pList, int i, ElemType elm);
bool DelElem(SeqList *pList, int i, ElemType *pElm);
void PrintList(SeqList *pList);
bool GetElem(SeqList *plist, int i, ElemType *pElem);
int LocateElem(SeqList *plist, ElemType *pElm);
void PrintList(SeqList *pList);

int main()
{
    return 0;
}

void InitList(SeqList **ppList)
{
    
    (*ppList)->elem = (ElemType *)malloc(INITSIZE*sizeof(ElemType));
    (*ppList)->length = 0;
    (*ppList)->listSize=INITSIZE;
}
void IncreaseSize(SeqList *pList, int increment)
{
    ElemType *temp = pList->elem;
    pList->elem = (ElemType *)malloc((pList->length+increment)*sizeof(ElemType));
    for(int i=0; i<pList->length; i++)
    {
        pList->elem[i] = temp[i];
    }
    pList->listSize += increment;
    free(temp);
}
bool InsertElem(SeqList * pList, int i, ElemType elm)
{
    if(i<1||i>pList->length)
        return false;
    if(pList->length>=pList->listSize)
        return false;
    for(int k=pList->length; k>=i; k--)
        {
            pList->elem[]=pList->elem[];
        }
}


