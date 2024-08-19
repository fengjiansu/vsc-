#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
    printf("Usage: $>GenPerm 3\n");
    exit(0);
  }
  n = atoi(argv[1]);
  A = (int*)malloc(n * sizeof(int));
  for (i = 0; i < n; i++) A[i] = i + 1;
  PERM(A, 0, n);
  return 0;
}

void Print(int A[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%3d", A[i]);
  putchar('\n');
}

void PERM(int A[], int k, int n) {
  int i;
  if (k == n - 1) {
    printf("%8d: ", ++cnt);
    Print(A, n);
  }
    
  else {
    for (i = k; i < n; i++) {
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

