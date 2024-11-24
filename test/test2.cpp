#include<iostream>
class Car
{
public:
    std::string color;
    std::string engine;
    float gas_tank;
    unsigned int wheel;

    Car(void);
    ~Car();
    void fill_tank(float liter);
    void running(void);
};

void Car::fill_tank(float liter)
{
    gas_tank+=liter;
}

void Car::running(void)
{
    std::cout<<"好快好快"<<std::endl;
    gas_tank-=0.1;
}

Car::Car(void)
{
    color="white";
    engine="V8";
    wheel=4;
    gas_tank=10.2;
}
Car::~Car()
{
    ;
}
int main()
{
    Car car1;
    while(car1.gas_tank>0.0)
    {
        car1.running();
    }
    std::cout<<"完犊子了"<<std::endl;
    return 0;
}