#include <bits/stdc++.h>

/* 
64λ
ָ��ռ8���ֽ� longҲռ8��
���඼��һ����



 */

bool less(float x, float y) { return *(int *)&x < *(int *)&y; }

int main()
{
    char a[] = "hello";
    char b[10];
    char *c = "hello";
    char *d[] = {"hello"};
    std::cout << less(1.1000000000000000,2.000000) << std::endl;

    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(*a) << std::endl;
    
    std::cout << sizeof(b) << std::endl;
    std::cout << sizeof(*b) << std::endl;
    std::cout << sizeof(c) << std::endl;
    std::cout << sizeof(c+1) << std::endl;

    std::cout << sizeof(d) << std::endl;
    std::cout << sizeof(d+1) << std::endl;
    return 0;
}

