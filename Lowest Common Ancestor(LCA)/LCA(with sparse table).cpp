#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef double dl;


#define YES cout<<"YES"<<"\n";
#define Yes cout<<"Yes"<<"\n";
#define NO cout<<"NO"<<"\n";
#define No cout<<"No"<<"\n";
#define yes cout<<"yes"<<"\n";
#define no cout<<"no"<<"\n";
#define endl cout<<"\n";
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ff first
#define ss second
#define iMax INT_MAX
#define iMin INT_MIN
#define pb push_back
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield);cout.precision(10);cout.setf(ios::fixed,ios::floatfield);

const int maxn=1e5+5;
const int lg=log2(maxn)+2;
vector<int> adj[maxn];
int T[maxn][lg+1];
int n,level[maxn],root;

void dfs(int u,int p)
{
    T[u][0]=p;
    if(p==-1) level[u]=0;
    else level[u]=level[p]+1;
    for(auto i:adj[u])
    {
        if(i!=p)
        {
            dfs(i,u);
        }
    }
}


void build()
{
    memset(T,-1,sizeof(T));
    dfs(root,-1);
    int lg1=log2(n)+1;
 
    for(int j=1;j<=lg1;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(T[i][j-1]!=-1)
            {
                T[i][j]=T[T[i][j-1]][j-1];
            }
        }
    }
}


int kthParent(int u,long long int k)
{
    if(k>n) return -1;
        
    int lg1=log2(k)+1;
 
    for(int i=lg1;i>=0;i--)
    {
        if(u==-1) return -1;
            
        if((1<<i)<=k)
        {
            k-=(1<<i);
            u=T[u][i];
        }
    }
    return u;
}


int lca(int u,int v)
{
    if(level[u]<level[v]) swap(u,v);
        
    int lg1=log2(n)+1;
 
    for(int i=lg1;i>=0;i--)
    {
        if(T[u][i]!=-1  && level[u]-(1<<i)>=level[v])
        {
            u=T[u][i];
        }
    }

    if(u==v) return u;
        
    for(int i=lg1;i>=0;i--)
    {
        if(T[u][i]!=-1 && T[u][i]!=T[v][i])
        {
            u=T[u][i];
            v=T[v][i];
        }
    }
    return T[u][0];
}

int distance(int u,int v)
{
    return level[u]+level[v]-(2*level[lca(u,v)]);
}

int main()
{
    optimize();

    int t;
    cin>>t;
    for (int kk = 1; kk <= t; ++kk)
    {
        memset(adj,0,sizeof(adj));
        memset(T,-1,sizeof(T));
        memset(level,0,sizeof(level));

        int m,q;
        cin>>n;
        for (int i = 1; i <= n; ++i)
        {
            cin>>m;
            while(m--)
            {
                int v;
                cin>>v;
                adj[i].pb(v);
                adj[v].pb(i);
            }
        }

        root=1;
        build();

        cout<<"Case "<<kk<<":\n";
        cin>>q;
        while(q--)
        {
            int u,v;
            cin>>u>>v;
            cout<<lca(u,v)<<"\n";
        }
    }

    return 0;
}