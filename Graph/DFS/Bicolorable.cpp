/*
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=945

https://vjudge.net/problem/UVA-10004
*/

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

const int mxan = 2e2+123;
vector<int> adj[mxan];
bool vis[mxan];
int col[mxan];
int n;

bool dfs(int u,int cl)
{
    vis[u]=1;
    col[u]=cl;

    for (int v:adj[u])
    {
        if (vis[v]==0)
        {
            if (dfs(v,!cl)==false) return false;
        }
        else
        {
            if (col[v]==col[u]) return false;
        }
    }

    return true;
}

void clean()
{
    for (int i = 0; i <= n; ++i)
    {
        adj[i].clear();
        vis[i]=0;
        col[i]=0;
    }  
}

int main()
{
    optimize();
    
    while(cin>>n)
    {
        // memset(vis,0,sizeof(vis));
        // memset(adj,0,sizeof(adj));
        clean();

        if(n==0) exit(0);

        int m;
        cin>>m;

        for (int i = 1; i <= m; ++i)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        if (dfs(0,0)) cout<<"BICOLORABLE."<<"\n";
        else cout<<"NOT BICOLORABLE."<<"\n";
        
    }

    return 0;
}