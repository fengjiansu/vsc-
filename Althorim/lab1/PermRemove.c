/*******************************************************************************
 * Author: David Song					                       *
 * Mail  : songxin@xaut.edu.cn                                                 * 
 * At    : XAUT  					                       *
 * Create Date: 2019-04-19                              *
 * Last Modify:                                                                *
 * Comment:                                                                    *
 ******************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

int cnt = 0;
void Print(int A[], int n);
void PERM(int A[], int k, int n);
void Swap(int *p, int *q);

int main(int argc, char *argv[]) {
  // int A[3] = {1, 2, 3};
  // int A[4] = {1, 2, 3, 4};
  int n, i;
  int *A;

  if (argc < 2) {
    printf("Usage: $>GenPerm 3 1 2 3\n");
    exit(0);
  }
  n = atoi(argv[1]);
  A = (int*)malloc(n * sizeof(int));
  assert(n != argc + 2);
  for (i = 0; i < n; i++) A[i] = atoi(argv[i + 2]);
  
  PERM(A, 0, n);
  return 0;
}

void Print(int A[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%3d", A[i]);
  putchar('\n');
}

// 查找A[i]元素的值x是否在第i+1号位置以后有重复出现，
// 如果重复出现，那么只算最后一个，而当前的A[i]就被跳过了
int FindRepeat(int *A, int x, int s, int e) { // [s, e)
  int found = 0;
  for (int i = s; i < e; i++)
    if (A[i] == x) found = 1;
  return found;
}
void PERM(int A[], int k, int n) {
  int i;
  if (k == n - 1) {
    printf("%8d: ", ++cnt);
    Print(A, n);
  }
  else {
    for (i = k; i < n; i++) {
      if (FindRepeat(A, A[i], i + 1, n)) continue;
      Swap(&A[i], &A[k]);
      PERM(A, k + 1, n);
      Swap(&A[i], &A[k]);
    }
  }
}

void Swap(int *p, int *q) {
  int tmp;
  tmp = *p;
  *p  = *q;
  *q  = tmp;
}

