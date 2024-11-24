#include<iostream>
#include<string>
#include<cassert>

unsigned long returnFactorial(unsigned short num) throw(const char*)
{
    unsigned long sum=1;
    unsigned long max=14;

    for(int i=1;i<num;i++)
    {
        sum*=i;
        max/=i;
    }

    if(max<1)
    {
        throw "nnnnnnnnn\n";
    }
    else
    {
        return sum;
    }
}

int main()
{
    unsigned short num=0;

    std::cout<<"请输入一个整数：";
    while(!(std::cin>>num)||(num<1))
    {
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cout<<"请输入一个整数：";
    }
    std::cin.ignore(100,'\n');

    try
    {
        unsigned long factorial=returnFactorial(num);
        std::cout<<num<<"的阶乘数是："<<factorial;
    }
    catch(const char*e)
    {
        std::cout<<e;
    }
    
    return 0;
}