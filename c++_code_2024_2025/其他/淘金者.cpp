//#pragma GCC optimize(1)
//#pragma GCC optimize(2)
//#pragma GCC optimize(3,"Ofast","inline")

#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define int long long
#define ll __int128
#define double long double
#define lowbit(x) (x&(-x))
#define log(x) (31^__builtin_clz(x))
#define endl '\n'

typedef pair<int,int>PII;
typedef pair<double,double>PDD;
typedef tuple<double,double,double>TDDD;
typedef tuple<int,int,int>TIII;

const int N = 2e3+10;
const int mod = 1e9+7 , P = 131;
const double PI = acos(-1);
const double eps = 1e-8;

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());//随机数

int read()
{
    char c=0;
    int res=0;
    int f=1;
    while(!(c>='0'&&c<='9')){
        if(c=='-'){
            f=-f;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        res=(res<<3)+(res<<1)+c-'0';
        c=getchar();
    }
    return res*f;
}

void write(int x)
{
    if(x<0){putchar('-');x=-x;}
    if(x>9) write(x/10);
    putchar(char(x%10+'0'));
}

char s[N][N];
int n,m,sx,sy;
bool vis[N][N];
int dx[]={0,0},dy[]={1,-1};

bool check(int p){
    queue<PII>q;

    memset(vis,false,sizeof vis);

    for(int i=1;i<=m;i++)
    {
        if(s[n][i]=='X')
        {
            q.push({n,i});
            vis[n][i]=true;
        }
    }

    while(q.size())
    {
        PII t=q.front();
        q.pop();

        int tx=t.x,ty=t.y;

        if(tx==sx&&ty==sy)return true;

        for(int i=0;i<2;i++)
        {
            int a=dx[i]+tx,b=dy[i]+ty;
            if(s[a][b]=='X'&&!vis[a][b])
            {
                q.push({a,b});
                vis[a][b]=true;
            }
        }

        for(int i=1;i+tx<=n&&i<=p;i++)
        {
            if(s[i+tx][ty]=='X')
            {
                if(vis[i+tx][ty])break;
                q.push({i+tx,ty});
                vis[i+tx][ty]=true;
                break;
            }
        }

        for(int i=1;tx-i>=1&&i<=p;i++)
        {
            if(s[tx-i][ty]=='X')
            {
                if(vis[tx-i][ty])break;
                q.push({tx-i,ty});
                vis[tx-i][ty]=true;
                break;
            }
        }
    }
    return false;
}

void solve(){
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>s[i][j];
        }
    }
    cin>>sx>>sy;
    sx++,sy++;

    int l=0,r=n+1;

    while(l+1!=r)
    {
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid;
    }
    cout<<r<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    T=1;
    while(T--)solve();

#ifdef PURPLE
    cerr<<fixed<<setprecision(10)<<1.0*clock()/CLOCKS_PER_SEC<<endl;
#endif
    return 0;
}