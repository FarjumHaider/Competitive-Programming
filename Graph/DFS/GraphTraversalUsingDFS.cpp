#include<bits/stdc++.h>
using namespace std;
 
#define YES cout<<"YES"<<"\n";
#define Yes cout<<"Yes"<<"\n";
#define NO cout<<"NO"<<"\n";
#define No cout<<"No"<<"\n";
#define yes cout<<"yes"<<"\n";
#define no cout<<"no"<<"\n";
#define all(x) x.begin(), x.end()
#define fst first
#define snd second
#define inf INT_MAX
#define pb push_back
#define ll long long
#define end cout<<"\n";
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield);cout.precision(10);cout.setf(ios::fixed,ios::floatfield);

const int mxan = 1e5+123;
bool vis[mxan];
vector<int> adj[mxan];

void dfs(int u)
{
    vis[u]=1;

    for (int v:adj[u])
    {
        if (vis[v]==0) dfs(v);
    }
}

int main()
{
    optimize();

    int n,m;
    cin>>n>>m;

    for (int i = 0; i < m; ++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }

    dfs(1);


    return 0;
}