#include"global.h"
typedef PCB ElemType;
typedef struct node {
     ElemType elem;
     struct node *next;
   } Node;
typedef struct queue {
     Node * front;
     Node * rear;
   } Que;
void InitQue(Que **p)
{
       *p=(Que *)malloc(sizeof(Que));
       (*p)->front=NULL;
       (*p)->rear=NULL;
}
int QueEmpty(Que *p)
{
    return p->front==NULL;
}
void print(ElemType elem){
  printf("%d\n",elem);
}
void PrintQue(Que *p)
{
    Node *q;
    if (QueEmpty(p)) {printf("the Que is Empty!\n");return;}
    q=p->front;
    while(q!=NULL)
      {print(q->elem);q=q->next;}
}
void EnQue(Que *p, ElemType x)
{
       Node *q;
       q=(Node*)malloc(sizeof(Node));
       q->elem=x;
       q->next=NULL;
       if(p->rear!=NULL)
        p->rear->next=q;
        p->rear=q;
       if(p->front==NULL)
       p->front=q;
}
ElemType DeQue(Que *p)
{
    ElemType q;
    Node *t;
    if (QueEmpty(p))
    {
        puts("error: depart from an empty queue!");
        return 0;
    }
        t=p->front;
       q=p->front->elem;
       p->front=p->front->next;
       free(t);
       return q;
}
ElemType Get(Que *p)
{
    ElemType q;
     if (QueEmpty(p))
    {
        puts("error: Get from an empty queue!");
        return 0;
    }
    else
    {
        q=p->front->elem;
        return q;
    }
}
void QueDestory(Que **p)
{
    free(*p);
    *p = NULL;
}