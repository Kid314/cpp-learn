#include<iostream>
#include<string>

/*int *newInt(int value)
{
    int *myInt=new int;
    *myInt=value;

    return myInt;
}*/

void swap(int *x,int *y)
{
#if 0
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
#endif
    *x^=*y;
    *y^=*x;
    *x^=*y;
}

int main()
{
    int a,b;
    a=3;
    b=5;
    std::cout<<a<<"+"<<b<<std::endl;
    swap(&a,&b);
    std::cout<<a<<"+"<<b<<std::endl;
    return 0;
}