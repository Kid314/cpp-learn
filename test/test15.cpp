#include<iostream>
#include<string>

template<class T>
class stack
{
public:
    stack(unsigned int size =100)
    {
        this->size=size;
        data =new T[size];
        sp=0;
    }
    ~stack()
    {
        delete []data;
    }
    void push(T value)
    {
        data[sp++]=value;
    }
    T pop()
    {
        return data[--sp];
    }
private:
    unsigned int size;
    unsigned int sp;
    T *data;
};
int main()
{
    stack<int> intstack(100);

    intstack.push(1);
    intstack.push(2);
    intstack.push(3);

    std::cout<<intstack.pop()<<std::endl;
    std::cout<<intstack.pop()<<std::endl;
    std::cout<<intstack.pop()<<std::endl;

    return 0;
}