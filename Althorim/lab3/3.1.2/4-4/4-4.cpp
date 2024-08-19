
#include<iostream>  
using namespace std;  
  
class A  
{  
public:  
    virtual void fun()  
    {  
        printf("Good!\n");  
    }  
};  
class B : public A  
{  
public:  
    void fun()  //¶àÌ¬¡¢¸²¸Ç
    {  
        printf("Better!\n");  
    }  
};  
class C : public A  
{  
public:  
    void fun()  //¶àÌ¬¡¢¸²¸Ç
    {  
        printf("Best!\n");  
    }  
}; 
class D: public A  
{  
public:  
    void fun()  //¶àÌ¬¡¢¸²¸Ç
    {  
        printf("Exit!\n");  
    }  
}; 
int main(void)  
{  
    A a;  
    B b; 
    C c;
    D d; 
    int n;
    cin>>n;
    if(n==1)
        a.fun();
    else if(n==2) 
      b.fun();
    else if(n==3)
    c.fun();
    else if(n==0)
    d.fun();
    return 0;  
} 