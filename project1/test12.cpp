#include<iostream>
#include<string>



int main()
{
#if 0
    char str1[40]="i am kid";
    char str2[20]=",i like you";
    char* p1=str1;
    char* p2=str2;
    for(int i=0;i<40;i++)
    {
        if(*p1=='\0')
        {
            break;
        }
        p1++;
    }
    for(int i=0;i<20;i++)
    {
        if(*p2=='\0')
        {
            *p1=*p2;
            break;
        }
        *p1++=*p2++;
    }
    std::cout<<str1<<"\n";
#endif
    std::string a="i am kid";
    std::string b=",i like you";
    std::string c=a+b;
    std::cout<<c<<"\n";
    return 0;
}