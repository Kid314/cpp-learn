#include<iostream>
#include<string>

class Animal
{
public:
    std::string mouth;
    std::string name;

    Animal(std::string theName);
    void eat();
    void sleep();
};

class Pig: public Animal
{
public:
    void climb();
    Pig(std::string theName);
};

class Turtle: public Animal
{
public:
    void swim();
    Turtle(std::string theName);
};

void Animal::eat()
{
    std::cout<<"i am eating"<<std::endl;
}

void Animal::sleep()
{
    std::cout<<"i am sleeping"<<std::endl;
}

Animal::Animal(std::string theName)
{
    name=theName;
}

Pig::Pig(std::string theName):Animal(theName)
{

}

Turtle::Turtle(std::string theName):Animal(theName)
{

}
void Pig::climb()
{
    std::cout<<"i am climbing"<<std::endl;
}

void Turtle::swim()
{
    std::cout<<"i am swimming"<<std::endl;
}

int main()
{
    Pig pig("pig");
    Turtle turtle("turtle");

    pig.eat();
    pig.climb();
    turtle.eat();
    turtle.swim();

    return 0;
}