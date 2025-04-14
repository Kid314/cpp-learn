#include<stdio.h>
#include<stdlib.h>

int fa[105];
int h[105];
int n,m;
int q,x,y;

// int max(int a,int b)
// {
//     return a>b?a:b;
// }
//查找根节点
int find(int x)
{
    if(fa[x]==x)
    {
        return x;
    }
    else
    {
        //return find(fa[x]);
        int f=find(fa[x]);
        fa[x]=f;//查找过程中 就把所有经过的结点都接在根节点上
        return f;
    }
}
// int find2(int x)
// {
//     while(fa[x]!=x)
//     {
//         x=fa[x];
//     }
//     return x;
// }
int main(int argc, char const *argv[])
{
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        h[i]=1;
    }
    int fx,fy;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&q,&x,&y);
        if(q==1)
        {
            fx=find(x);
            fy=find(y);
            //fa[fx]=fy;--one way
            /*if(h[fx]>=h[fy])
            {
                fa[fy]=fx;
                h[fx]=max(h[fx],h[fy]+1);
            }
            else
            {
                fa[fx]=fy;
                h[fy]=max(h[fy],h[fx]+1);
            }*///--one way
        }
        else
        {
            fx=find(x);
            fy=find(y);
            if(fx==fy) printf("yes\n");
            else printf("no\n");
        }
    }
    
    return 0;
}
