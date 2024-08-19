class A
{
public:
    static A &getInstance() { return a; }
private:
    A();
    A(const A &rhs);
    static A a;
};


class A
{
public:
    static A &getInstance();

private:
    A();
    A(const A &rhs);
};
A& A::getInstance()
{
    static A a;
    return a;
}


