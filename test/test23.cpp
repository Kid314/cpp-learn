#include<iostream>
/**
 * 素数的判断是它的因子只有1和它本身
 * 也就是说判断一个是不是质数只需让它和比他小的数相除
 * 但是可以剪枝的地方是，只需要和  平方小于它的数相除就行
 */
void isOdd(int n)
{
    if(n<=2)
    {
        std::cout<<n<<"\n";
        return ;
    }
    for(int i=2;i*i<=n;++i)//大于2的数的判断
    {
        if(n%i==0)
            return ;
    }
    std::cout<<n<<"\n";
}
void solve(int n)
{
    for(int i=1;i<=n;++i)
        isOdd(i);
}
int main()
{
    int n;
    std::cin>>n;
    solve(n);
    return 0;
}