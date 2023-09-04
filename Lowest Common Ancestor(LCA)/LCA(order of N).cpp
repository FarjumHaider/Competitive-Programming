#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int llu;
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

#define MOD 1000000007
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

int const mxan=1e5+123;
int check[mxan];
vector<int> adj[mxan];
int parent[mxan];

void dfs(int u,int p)
{
    parent[u]=p;
    for(int v:adj[u])
    {
        if(v!=p) dfs(v,u);
    }
}


vector<int> path(int u)
{
    vector<int> ans;
    while(u!=-1)
    {
        ans.push_back(u);
        u = parent[u];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    for (int i = 0; i < n-1; ++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1,-1);

    int a,b;
    cin>>a>>b;

    vector<int> p1,p2;
    p1 = path(a);
    p2 = path(b);

    int mn_sz = min(p1.size(),p1.size());
    int lca;
    for (int i = 0; i < mn_sz; ++i)
    {
        if (p1[i]==p2[i]) lca = p1[i];
        else break;
    }

    cout<<lca<<"\n";
}



int main()
{
    optimize();

    // int t;
    // cin>>t;

    // while(t--)
    // {
    //     solve();
    // }
    solve();



    return 0;
}

// 13
// 1 2
// 1 3
// 1 13
// 2 5
// 5 6
// 5 7
// 5 8
// 8 12
// 3 4
// 4 9
// 4 10
// 10 11