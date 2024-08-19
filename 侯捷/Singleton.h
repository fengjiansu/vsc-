#ifndef _SINGLETON_
#define _SINGLETON_
/* 
һ������ģʽӦ���У�
����: 
˽�� ��̬ �౾�� singleton
������ 
˽�й���
���е� ��̬ getInstance()


*/

//ʹ��ʱ����ʵ���������̰߳�ȫ
class Singleton_lazy
{

public:
    static Singleton_lazy & getInstance()
    {
        static Singleton_lazy singleton;    //  �ֲ���̬������ʼ�������̰߳�ȫ�� ������̰߳�ȫָ���ǣ�һ���߳��ڳ�ʼ�� m ��ʱ�������߳�ִ�е� m �ĳ�ʼ����һ�е�ʱ�򣬾ͻ����
        return singleton;
    }

private:
    Singleton_lazy()
    {

    }

};

//ʹ��ʱֱ�ӵ���
class Singleton_hurry
{
    public:
        static Singleton_hurry& getInstance()
        {
        return singleton;
        }
    private:
        static Singleton_hurry singleton;
        Singleton_hurry()
        {

        }
};

#endif