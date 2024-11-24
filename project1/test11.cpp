#include<iostream>
#include<string>
#include<random>

void trance(int a[3][3])
{
    int copy[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            copy[i][j]=a[j][i];
        }
    }
    std::cout<<"转置前：\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"转置后：\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            std::cout<<copy[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

void treance2(int** a)
{
    int** p=new int*[3];
    for(int i=0;i<3;i++)
    {
        *(p+i)=new int[3];
        for(int j=0;j<3;j++)
        {
            *(*(p+i)+j)=*(*(a+j)+i);
        }
    }
        std::cout<<"转置前：\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"转置后：\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            std::cout<<p[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    for(int i=0;i<3;i++)
    {
        delete[] p[i];
    }
    delete p;
}

int main()
{
    int a[3][3]={0};
    int** p=new int*[3];
    for(int i=0;i<3;i++)
    {
        p[i]=new int[3];
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>dis(0,1000);
    for(int i=0;i<9;i++)
    {
        a[i/3][i%3]=dis(gen);
        p[i/3][i%3]=dis(gen);
    }
    trance(a);
    treance2(p);
    for(int i=0;i<3;i++)
    {
        delete[] p[i];
    }
    delete p;
    return 0;
}