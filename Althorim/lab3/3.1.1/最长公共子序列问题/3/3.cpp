#include<iostream>  
using namespace std;  
  
class A  
{  
public:  
    void foo()  
    {  
        printf("1\n");  
    }  
    virtual void fun()  
    {  
        printf("2\n");  
    }  
};  
class B : public A  
{  
public:  
    void foo()  //���أ�������ĺ�������������ͬ���Ļ��ຯ��
    {  
        printf("3\n");  
    }  
    void fun()  //��̬������
    {  
        printf("4\n");  
    }  
};  
int main(void)  
{  
    A a;  
    B b;  
    //A *p = &a;  
    a.foo();  //���1
    a.fun();  //���2
    //p = &b;  
    b.foo();  //ȡ����ָ�����ͣ����1
   b.fun();  //ȡ���ڶ������ͣ����4�������˶�̬
    return 0;  
}