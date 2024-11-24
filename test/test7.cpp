#include<iostream>
#include<string>

class Pet
{
public:
    static int getCount();
    Pet(std::string theNamme);
    ~Pet();
protected:
    std::string name;
private:
    static int count;
};

class Dog : public Pet
{
public:
    Dog(std::string theName);
};

class Cat : public Pet
{
public:
    Cat(std::string theName);
};

int Pet::count=0;

Pet::Pet(std::string theName)
{
    name=theName;
    count++;

    std::cout<<name<<"出生了\n";
}

Pet::~Pet()
{
    count--;
    std::cout<<name<<"挂了\n";
}

int Pet::getCount()
{
    return count;
}

Cat::Cat(std::string theName) : Pet(theName)
{

}

Dog::Dog(std::string theName) : Pet(theName)
{
    std::cout<<"this:"<<this<<"\n";
}

int main()
{
    Dog dog("tom");
    Cat cat("jerry");

    std::cout<<"dog:"<<&dog<<"\n";
    std::cout<<"出生了"<<Pet::getCount()<<std::endl;

    {
        Dog dog_2("tom_2");
        Cat cat_2("jerry_2");

        std::cout<<"出生了"<<Pet::getCount()<<std::endl;
    }

    std::cout <<"剩下"<<Pet::getCount()<<std::endl;
    
    return 0;
}