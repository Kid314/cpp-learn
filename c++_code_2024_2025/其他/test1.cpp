#include<bits/stdc++.h>

/*int main()
{
    int** a=new int*[5];
    int* b=new int[5];
    b[1]=2;
    std::cout<<b[1]<<"\n";
    delete b;
    b=new int(6);
    std::cout<<*b<<"\n";
    delete b;
    //int** b=new int*(5);
    //delete a[1];
    delete a;
    return 0;
}*/

/*void func(int a,int b=0)
{
    std::cout<<a+b<<"\n";
}
void func(int a)
{
    std::cout<<a<<"\n";
}

int main()
{
    int a=10;
    func(a);
    func(10);

    return 0;
}*/

class a
{
private:
    int aaa;
    void prt()
    {
        std::cout<<"父类private中的函数\n";
    }
protected:
    int b;
    void ppp()
    {
        std::cout<<"父类protected中的函数\n";
    }
public:
    a(int a,int b):aaa(a),b(b){}
    void show()
    {
        std::cout<<"public函数调用private数据"<<aaa<<"\n";
    }
    typedef void (a::*aa)();
    void wow()
    {
        aa a1;
        a1=prt;
        std::cout<<"这里是普通函数wow:\n";
        (this->*a1)();
    }
    void hhh(aa ptr)
    {
        (this->*ptr)();
        std::cout<<"这里是普通函数hhh:\n";
    }
};
class bb:public a
{
private:
    int bb_aaa;
    void bb_prt()
    {
        std::cout<<"子类的private函数\n";
    }
protected:
    int bb_b;
    void ppp()
    {
        std::cout<<"子类的protected函数\n但是名字和父类一样，是父类的重载\n";
    }
public:
    bb(int a,int b,int c,int d):a(a,b),bb_aaa(c),bb_b(d){};

};
int main()
{
    a a1(1,2);
    bb b1(1,2,3,4);
    a* b2=new bb(1,2,3,4);
    a::aa aptr=&a::ppp;
    (a1.*aa)();
    return 0;
}