 #include <stdio.h>
 int count=0;
void swap(char *m,char *n)
{
    char tmp=*m;
    *m=*n;
    *n=tmp;
}
int Findsame(char list[], int k, int m){
    
    // list[m]�Ƿ�����list[k, m-1]���ֹ�
    for (int i = k; i < m; i++) {
        if (list[m] == list[i]) {
            // ������
            return 1;
        }
    }
    return 0;
}
void Perm(FILE *fp,char list[], int k, int m)
{
    if (k == m) {
        // �������
        for (int i = 0; i <= m; i++) {
            fprintf(fp,"%c",list[i]);
        }
        count++;// ������+1
        fprintf(fp,"\n");
    }else{
        
        for (int i = k; i <= m; i++) {
            if (Findsame(list, k, i)) {
                continue;//ȥ���ѳ��ֹ�������
            }
            swap(&list[k], &list[i]);
            Perm(fp,list, k + 1, m);// �ݹ�
            swap(&list[k], &list[i]);
        }
    }
}
 int main()
 {
int n;
    char list[100];
    FILE *fp,*fpOut;
     if((fp=fopen("E:\\vsC++\\Althorim\\lab1\\2-5\\input.txt","r"))==NULL){
        printf("\nCannot open input file strike any key exit!");
        getchar();
        return -1;
    }
    if((fpOut=fopen("E:\\vsC++\\Althorim\\lab1\\2-5\\output.txt","w"))==NULL){
        printf("\nCannot open output file strike any key exit!");
        getchar();
        return -1;
    }
    fscanf(fp,"%d",&n);
    fscanf(fp,"%s" ,list);
    Perm(fpOut,list,0,n-1);
    fprintf(fpOut,"%d",count);
    printf("%d",count);
    fclose(fp);
    fclose(fpOut);
    return 0;
 }
 