#include<stdio.h>
#include<stdlib.h>

int queen[8]={0};
int lie[8]={1,1,1,1,1,1,1,1};
int f_delta[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};//对角线1 j-i+7来判断
int b_delta[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};//对角线2 i+j来判断
bool isSafe(int i,int j)
{
    
    return (lie[j]&&f_delta[i-j+7]&&b_delta[j+i]);
}

void show()
{
    int i=0;
    for(i;i<8;i++)
    {
        int j=0;
        for(j;j<8;j++)
        {
            if(j==queen[i])
            {
                printf("1|");
            }
            else
            {
                printf("0|");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void solve(int i)
{
    int j;
    for(j=0;j<8;j++)
    {
        if(isSafe(i,j))
        {
            queen[i]=j;
            lie[j]=0;
            f_delta[i-j+7]=0;
            b_delta[i+j]=0;
            if(i<7)
                solve(i+1);
            else
                show();
            lie[j]=1;
            f_delta[i-j+7]=1;
            b_delta[i+j]=1;
        }
    }
}

int main()
{
    solve(0);
    return 0;
}
