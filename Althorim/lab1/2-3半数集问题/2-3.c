#include <stdio.h>
int fun(int n)
{
    int num=1;
       if(n>1)
              for(int i=1;i<=n/2;i++)
                     num+=fun(i);
       return num;
}
int main()
{
    int n,n1,num=0;
    FILE *fp = NULL;
     if((fp=fopen("E:\\vsC++\\Althorim\\lab1\\2-3����������\\input.txt","r"))==NULL)
    {
    printf("\\nerror on open E:\\vsC++\\Althorim\\lab1\\2-3����������\\input.txt\n");
    }   
   fscanf(fp,"%d",&n);
   //printf("%d",n); //�����Ƿ����N
   fclose(fp);
   num=fun(n);
    //printf("%d",num); //�������
   FILE *fp1 = NULL;
      fp1=fopen("E:\\vsC++\\Althorim\\lab1\\2-3����������\\output.txt","w");
   fprintf(fp1,"%d",num);
   fclose(fp1);
    return 0;
}