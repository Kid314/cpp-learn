#include<iostream>


class point
{
public:
    static int a;
    point();
    void eat(int a)
    {
        this->a=a;
        std::cout<<a<<"hhh\n";
    }
};
class pointt : public point
{
public:
    pointt();
};
int point::a=3;
point::point()
{
    
}
pointt::pointt() : point()
{

}
class point2
{
public:
    point2();
    static void eat(int b)
    {
        point::a=b;
        std::cout<<point::a<<"hhh\n"<<std::endl;
    }
};
point2::point2()
{

}
int main()
{
    point(c);
    pointt(b);
    std::cout<<c.a<<std::endl;

    point::a=4;
    std::cout<<c.a<<std::endl;
    b.eat(2);
    std::cout<<c.a<<std::endl;
    point2(d);
    d.eat(6);
    std::cout<<c.a<<std::endl;
    point2::eat(7);
    std::cout<<c.a<<std::endl;

    return 0;
}