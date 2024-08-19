/*******************************************************************************
 * Author: David Song					                       *
 * Mail  : songxin@xaut.edu.cn                                                 * 
 * At    : XAUT  					                       *
 * Create Date: 2019-04-19                              *
 * Last Modify:                                                                *
 * Comment:                                                                    *
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int HalfSet(int n) {
  int sum = 0;
  if (n == 1) return 1;
  for (int i = 1; i <= n / 2; i++)
    sum += HalfSet(i);
  return sum + 1;
}

int main(int argc, char **argv) {
  int n;
  if (argc != 2) {
    puts("Usage: $> HalfSet 6");
    exit(0);
  }
  n = atoi(argv[argc - 1]);
  printf("HalfSet number of %d is: %d\n", n, HalfSet(n));
}
