#include<bits/stdc++.h>
const int N = 2e3+10;
int n,m,sx,sy;
int s[N][N];
bool vis[N][N];
void read()
{
    std::cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            std::cin>>s[i][j];
        }
    }
    std::cin>>sx>>sy;
    sx++,sy++;
}