#include<iostream>
/**
 * 思路：二分法。
 * 根据每次的猜测，使得猜测的上限和下限进行排除。
 * 每次可以排除一半的可能
 */
void solve(int n)
{
    int max=99,min=1,count=1;
    int geass=(max+min)/2;
    while(geass!=n)
    {
        std::cout<<geass<<"\n";
        if(geass>n)
            max=geass;//因为猜的比真实的大，所以比猜的大的数可以不用再猜了。
        else
            min=geass;//因为猜的比真实的小，所以比猜的小的数可以不用再猜了。
        geass=(max+min)/2;
        count++;
    }
    std::cout<<geass<<"\n";
    std::cout<<"最终猜了"<<count<<"次\n";
}
int main()
{
    int n;
    std::cin>>n;
    solve(n);
    return 0;
}