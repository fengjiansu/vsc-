#ifndef _SINGLETON_
#define _SINGLETON_
/* 
一个单例模式应该有：
数据: 
私有 静态 类本身 singleton
函数： 
私有构造
共有的 静态 getInstance()


*/

//使用时创建实例，考虑线程安全
class Singleton_lazy
{

public:
    static Singleton_lazy & getInstance()
    {
        static Singleton_lazy singleton;    //  局部静态变量初始化具有线程安全性 这里的线程安全指的是：一个线程在初始化 m 的时候，其他线程执行到 m 的初始化这一行的时候，就会挂起
        return singleton;
    }

private:
    Singleton_lazy()
    {

    }

};

//使用时直接调用
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