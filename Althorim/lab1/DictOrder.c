#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cnt = 0;
void Print(int A[], int n);
void PERM(int A[], int k, int n);
void Swap(int *p, int *q);

int target[8] = {2, 6, 4, 5, 8, 1, 7, 3};
int flag = 0;
int main(int argc, char *argv[]) {
  // int A[3] = {1, 2, 3};
  // int A[4] = {1, 2, 3, 4};
  int n, i;
  int *A;
  if (argc < 2) {
    printf("Usage: $>DictOrder 3\n");
    exit(0);
  }
  n = atoi(argv[1]);
  A = (int*)malloc(n * sizeof(int));
  for (i = 0; i < n; i++) A[i] = i + 1;
  PERM(A, 0, n);
  return 0;
}

int check(int A[], int B[], int n) {
  for (int i = 0; i < n; i++)
    if (A[i] != B[i]) return 0;
  return 1;
}

void Print(int A[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%3d", A[i]);
  putchar('\n');
  if (flag)              exit(0);
  if (check(A, target, n))  flag = 1;
}

void PERM(int A[], int k, int n) {
  int i;
  if (k == n - 1) {
    printf("%8d: ", ++cnt);
    Print(A, n);
 }
  else {
    for (i = k; i < n; i++) {
      if (i == k) PERM(A, k + 1, n);
      else {
	int j;
	//Swap(&A[i], &A[k]);
	int tmp = A[i];
	for (j = i; j > k; j--) A[j] = A[j - 1];
	A[k] = tmp; 
	PERM(A, k + 1, n);
	//Swap(&A[i], &A[k]);
	tmp = A[k];
	for (j = k; j < i; j++) A[j] = A[j + 1];
	A[j] = tmp;
      }
    }
  }
}

void Swap(int *p, int *q) {
  int tmp;
  tmp = *p;
  *p  = *q;
  *q  = tmp;
}

