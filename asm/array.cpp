
#include <stdio.h>
int main()
{
    int array []={};
    int array []={12,4, 168,122,-33,56,78,99,345, 66,-5};
    int n = sizeof(array)/sizeof(array[0]);
    int tmp;
    for(int i=0;i<(n/2);i++)
    {
        tmp=array[i];
        array[i]=array[n-i-1];
        array[n-i-1]=tmp;
    }
    for(int i=0;i<n;i++)
    {m
         printf("%d ",array[i]);
    }
    return 0;
}