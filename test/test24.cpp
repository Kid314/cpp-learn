#include<iostream>
#include<vector>
/**
 * 思路：同时遍历两个数组，比较各个位置的大小，选择小的数添加到答案数组。
 * 比如 第一次比较vec1[i]和vec2[j]，如果vec1[i]小，
 * 则第二次比较vec[i+1]和vec2[j]。
 * 一直到某个数组到底了，另一个数组的剩余部分直接依次填充；
 * 或者两个数组一起到底。
 */

std::vector<int> vec1;
std::vector<int> vec2;
std::vector<int> answer;
int n,m;//n代表vec1有几个数，m代表vec2有几个数
void print()//打印排列后的数组
{
    for(int i:answer)
    {
        std::cout<<i<<" ";
    }
}
void sort_vec()
{
    int i=0,j=0;//遍历的计数变量
    while(i<=n&&j<=m)//数组不能越界
    {
        /**
         * 因为不知道vec12哪个长，所以需要判断
         * 当一个数组到头时，另一个数组的剩余部分直接可以依次添加进answer数组
         */
        if(i==n)
        {
            for(j;j<m;++j)
            {
                answer.push_back(vec2[j]);
            }
            break;
        }
        if(j==m)
        {
            for(i;i<n;++i)
            {
                answer.push_back(vec1[i]);
            }
            break;
        }
        if(vec1[i]==vec2[j])//处理相同的数字
        {
            answer.push_back(vec1[i]);
            i++;
            j++;
            continue;
        }
        if(vec1[i]<vec2[j])
        {
            answer.push_back(vec1[i]);
            i++;
            continue;
        }
        answer.push_back(vec2[j]);
        j++;
    }
    print();
}
void solve()
{
    //将vec12分别填充完整
    int temp;
    std::cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        std::cin>>temp;
        vec1.push_back(temp);
    }
    for(int j=0;j<m;++j)
    {
        std::cin>>temp;
        vec2.push_back(temp);
    }

    sort_vec();
}
int main()
{
    solve();
    return 0;
}