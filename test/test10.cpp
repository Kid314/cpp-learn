#include<iostream>
#include<string>

class person
{
public:
    person(std::string theName)
    {
        name=theName;
    }
    void introduce()
    {
        std::cout<<"hello i am "<<name<<std::endl;
    }
protected:
    std::string name;
};
class teacher : virtual public person
{
public:
    teacher(std::string theName,std::string classTeaching):person(theName)
    {
        classes=classTeaching;
    }
    void teach()
    {
        std::cout<<name<<" 教 "<<classes<<std::endl;
    }
    void introduce()
    {
        std::cout<<"hello i am "<<name<<"我教"<<classes<<std::endl;
    }
protected:
    std::string classes;
};
class student:virtual public person
{
public:
    student(std::string theName,std::string classAttending):person(theName)
    {
        classes=classAttending;
    }
    void attendClass()
    {
        std::cout<<name<<" join "<<classes<<std::endl;
    }
    void introduce()
    {
        std::cout<<"hello i am "<<name<<"who join "<<classes<<std::endl;
    }
protected:
    std::string classes; 
};
class teachingstudent:public student,public teacher
{
public:
    teachingstudent(std::string theName,std::string classTeaching,std::string classAttending):student(theName,classAttending),teacher(theName,classTeaching),person(theName)
    {

    }
    void introduce()
    {
        std::cout<<"hello i am "<<name<<"who teach "<<teacher::classes<<std::endl;
        std::cout<<"i also join "<<student::classes<<std::endl;
    }
};

int main()
{
    teacher a("小甲鱼","c++入门班");
    student b("kid","c++入门班");
    teachingstudent c("KID","c++入门班","c++pro");

    a.introduce();
    a.teach();
    b.introduce();
    b.attendClass();
    c.introduce();
    c.teach();
    c.attendClass();

    return 0;
}