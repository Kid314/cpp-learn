#include<iostream>
int main()
{
    int n;//矩阵边长
    std::cin>>n;
    int** vec=new int*[n];//指向指针的指针来代表二维数组
    for(int i=0;i<n;++i)
    {
        vec[i]=new int[n];//将一行一维数组初始化
        for(int j=0;j<n;++j)
        {
            std::cin>>vec[i][j];//接受数据
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            std::cout<<vec[j][i];//转置输出
        }
        std::cout<<"\n";
    }
    return 0;
}