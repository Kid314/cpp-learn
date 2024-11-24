#include<iostream>
#include<vector>
/**
 * 思路：去除头和尾的1，中间在位置i的数是上一次位置i和i+1的数的和。
 * 所以每次可以先将数组初始化为只有一个“1”
 * 然后填充计算完的数，
 * 最后加上1
 * 即可
 */
std::vector<int> vec={1};
void solve()
{
    for(int i=0;i<vec.size();++i)//输出想要的结果
    {
        std::cout<<vec[i]<<" ";
    }
    std::cout<<"\n";

    std::vector<int> temp={1};//开头置1
    for(int i=0;i<vec.size()-1;++i)
    {
        temp.push_back(vec[i]+vec[i+1]);//计算中间的数
    }
    temp.push_back(1);//结尾再加上1
    vec.clear();
    vec=temp;
}
int main()
{
    int count;//次数
    std::cin>>count;

    while(count--)
    solve();
    return 0;
}