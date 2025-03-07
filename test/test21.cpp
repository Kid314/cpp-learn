#include<iostream>
/**
 * 思路：将过程分为三份
 * 1.最开始坠落
 * 2.中间的起落
 *      1）计算时要将算出的弹起高度乘二
 * 3.最后弹起
 *      1）计算时只需计算弹起的高度
 * 
 * 
 * 重点在于是到达指定高度的总路程
 * 也就是说最后一次计算时，只需要计算球飞上去的高度，不用加上下来的高度
 * 即代码中的i!=n就是分离最后一次和中间的计算
 */
double m;
int n;//m是初始高度，n是次数
double s;//s指的是到达指定高度的总路程
void solve()
{
    s=m;//s应该加上最开始坠落的高度
    for(int i=1;i<=n;++i)
    {
        m=m/2;
        if(i!=n)
            s+=m*2;//不是最后一次，计算弹起坠落的路程
        else
            s+=m;//是最后一次，计算弹起的路程
    }
    std::cout<<m<<"\n";
    std::cout<<s<<"\n";
}
int main()
{
    std::cin>>m>>n;
    solve();
    return 0;
}