#include<iostream>
#include<string>

class R
{
public:
    void operator+(R &a)
    {
        b=b+a.b;
        std::cout<<b<<std::endl;

    }
    R():b(1)
    {

    }
private:
    int b;
};

int main()
{
    R abc;
    R bcd;
    abc.operator+(bcd);
    return 0;
}