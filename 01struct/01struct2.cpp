#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,m;
int f[105];
typedef struct
{
    int u,v;
    int w;
}Edge;

Edge e[10005];
void sortt(int l,int r)
{//m^2---->mlogm
    int minn;
    Edge t;
    for(int i=l;i<r;i++)
    {
        minn=i;
        for(int j=i+1;j<=r;j++)
        {
            if(e[minn].w>e[j].w)
            {
                minn=j;
            }
        }
        t=e[minn];
        e[minn]=e[i];
        e[i]=t;
    }
}
int find(int x)
{
    // return f[x]= (x==f[x]?x:find(f[x]));
    if(x==f[x]) return x;
    else return f[x]=find(f[x]);
}
void Kruskal()
{
    for(int i=0;i<n;i++)
    {
        f[i]=i;
    }
    int cnt=0,sum=0;
    int fv,fu;
    for(int i=1;i<=m;i++)
    {
        fv=find(e[i].v);
        fu=find(e[i].u);
        if(fv!=fu)
        {
            printf("%d %d:%d\n",e[i].u,e[i].v,e[i].w);
            sum+=e[i].w;
            f[fu]=fv;
            cnt++;
        }
        if(cnt==n-1) break;
    }
    printf("%d\n",sum);
}
int main()
{
    scanf("%d %d",&n,&m);
    int x,y,w;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&x,&y,&w);
        e[i].u=x;
        e[i].v=y;
        e[i].w=w;
    }
    sortt(1,m);//mlogm
    Kruskal();//m
    return 0;
}