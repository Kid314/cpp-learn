#include<iostream>
#include<stack>

int Sum(std::stack<std::pair<int,int>> stacks)
{
    int all=0;
    while(!stacks.empty())
    {
        all+=stacks.top().first;
        stacks.pop();
    }
    return all;
}

void show(std::stack<std::pair<int,int>> stacks)
{
    while(!stacks.empty())
    {
        std::cout<<stacks.top().first<<" ";
        stacks.pop();
    }
    std::cout<<"\n";
}

int main()
{
    int weight[]={1,8,4,3,5,2};
    int v=10;
    int j=0;
    int i=j;
    std::stack<std::pair<int,int>> stack;
    while(!stack.empty()||j<5)
    {
        for(i;i<6;i++)
        {
            stack.push({weight[i],i});
            if(Sum(stack)>10)
            {
                stack.pop();
            }
            if(Sum(stack)==10)
            {
                show(stack);
                break;
            }
        }
        i=stack.top().second+1;
        stack.pop();
        if(stack.empty())
        {
            j++;
        }
    }
    return 0;
}