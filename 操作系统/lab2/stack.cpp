
#include <stdio.h>
#include<stdlib.h>
typedef double Elemtype;
typedef struct stack{
 Elemtype a;
 struct  stack *next;
}Stack;
void InitLinkstack(Stack **head){
  *head=(Stack *)malloc(sizeof(Stack));
  ((*head)->next)=NULL;
}
int StackEmpty(Stack *head){
 if(head->next==NULL)
    return 1;
 else
    return 0;
}
void Push(Stack *head,Elemtype c){
Stack *p;
   p=(Stack *)malloc(sizeof(Stack));
   p->a=c;
   p->next=head->next;
   head->next=p;
}
void Pop(Stack *head,Elemtype *c){
Stack *p=head->next;
if(StackEmpty(head))
    printf("Stack is Empty!");
else
    head->next=p->next;
    *c=p->a;
    free(p);
}
void Top(Stack *head,Elemtype *c){
if(StackEmpty(head))
    printf("Stack is Empty!");
else
    *c=head->next->a;
}
void Destroy (Stack *head){
    Stack *p,*q;
    p=head;
    while(p!=NULL)
    {
        q=p;
        free(q);
        p=p->next;
    }
}