#include<iostream>
#include<string>

class BaseClass
{
public:
    BaseClass();
    ~BaseClass();

    void doSomething();
};

class SubClass: public BaseClass
{
public:
    SubClass();
    ~SubClass();
};

BaseClass::BaseClass()
{
    std::cout<<"enter BaseClass\n";
}

BaseClass::~BaseClass()
{
    std::cout<<"enter BaseClass again\n";
}

void BaseClass::doSomething()
{
    std::cout<<"i do somthing\n";
}
SubClass::SubClass()
{
    std::cout<<"enter SubClass\n";
}

SubClass::~SubClass()
{
    std::cout<<"enter SubClass again\n";
}

int main()
{
    SubClass subclass;
    subclass.doSomething();

    std::cout <<"stop\n";
    return 0;
}