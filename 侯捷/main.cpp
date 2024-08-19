#include <bits/stdc++.h>


int main()
{

    char *p1 = nullptr;
    int a[] = {1,2,3};
    int *p3 = a;
    char *p2 = "hello";
    p1 = p2;
    std::cout << p1 << " " << (void*)p1 << " " << p2 << " " << (void*)p2 <<" "<<p3<<" "<<*p3<< std::endl;
    return 0;
}
