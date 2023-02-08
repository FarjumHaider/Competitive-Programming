/*
https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
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
        adj[v].pb(u);
    }

    int cnt=0;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i]==0)
        {
            cnt++;
            dfs(i);
        }
    }

    cout<<cnt<<"\n";
    return 0;
}