#include<iostream>
#include<string>

class BIRTH
{
public:
    BIRTH(std::string a):date(a)
    {
        std::cout<<"创建日期："<<date<<"\n";
    }
    BIRTH(const BIRTH& a)
    {
        date=a.date+"1";
        std::cout<<"创建日期："<<date<<"\n";
    }
    ~BIRTH()
    {
        std::cout<<date<<"日期类结束\n";
    }
    inline std::string getstring()
    {
        return date;
    }
private:
    std::string date;
};

class person
{
public:
    person(int a,int b,std::string c,std::string d):number(a),id(b),sex(c),birthday(d)
    {
        std::cout<<"创建了一个人。\n";
        std::cout<<"number为"<<number<<"\n";
        std::cout<<"id为"<<id<<"\n";
        std::cout<<"sex为"<<sex<<"\n";
        std::cout<<"birth为"<<birthday.getstring()<<"\n";
    }
    person(const person& a,const BIRTH& b):birthday(b)
    {
        number=a.number+1;
        id=a.id;
        sex=a.sex;
        std::cout<<"创建了一个人。\n";
        std::cout<<"number为"<<number<<"\n";
        std::cout<<"id为"<<id<<"\n";
        std::cout<<"sex为"<<sex<<"\n";
        std::cout<<"birth为"<<birthday.getstring()<<"\n";
    }
    ~person()
    {
        std::cout<<number<<"人没了\n";
    }
    inline std::string getbirth()
    {
        return birthday.getstring();
    }
private:
    int number;
    std::string sex;
    BIRTH birthday;
    int id;
};

int main()
{
    BIRTH person1date("19451002");
    person boy1(1,123,"male","19451001");
    person boy2(boy1,person1date);
    std::cout<<boy2.getbirth()<<"\n";
    return 0;
}