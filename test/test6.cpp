#include<iostream>
#include<string>

class lovers
{
public:
    lovers(std::string theName);
    void kiss(lovers *lover);
protected:
    std::string name;

    friend class others;
};

class Boyfriend : public lovers
{
public:
    Boyfriend(std::string theName);
};

class Girlfriend : public lovers
{
public:
    Girlfriend(std::string theName);
};

class others
{
public:
    others(std::string theName);
    void kiss(lovers *lover);

protected:
    std::string name;
};

//方法定义
lovers::lovers(std::string theName)
{
    name=theName;
}

void lovers::kiss(lovers *lover)
{
    std::cout<<"hello"<<lover->name<<std::endl;
}

Boyfriend::Boyfriend(std::string theName) : lovers(theName)
{

}

Girlfriend::Girlfriend(std::string theName) : lovers(theName)
{

}

others::others(std::string theName)
{
    name=theName;
}

void others::kiss(lovers *lover)
{
    std::cout<<name<<" hello "<<lover->name<<std::endl;
}



int main()
{
    Boyfriend Boyfriend("kid");
    Girlfriend Girlfriend("c.c");
    others others("kId");

    Boyfriend.kiss(&Girlfriend);
    Girlfriend.kiss(&Boyfriend);

    others.kiss(&Girlfriend);
    return 0;
}