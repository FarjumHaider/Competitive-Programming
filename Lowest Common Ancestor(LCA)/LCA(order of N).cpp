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

const int mx = 1e4+123;
int lvl[mx];
vector<int> adj[mx];
int subTree[mx];
int parent[mx];

void dfs(int v,int p)
{
    for(int u:adj[v])
    {
        if(u!=p)
        {
            dfs(u,v);
            parent[u] = v;
            //subTree[v]+=subTree[u];
        }
    }
}

vector<int> path(int x)
{
    //cout<<parent[x]<<" ***\n";
    vector<int> ans;
    ans.pb(x);
    while(parent[x]!=-1)
    {
        x = parent[x];
        ans.pb(x);
    }
    reverse(all(ans));
    return ans;
}

int main()
{
    optimize();
    //memset(subTree,1,sizeof(subTree));
    //memset(adj,0,sizeof(adj));

    for (int i = 0; i < mx; ++i) subTree[i] = 1;

    int n,m;
    cin>>n;

    for (int i = 0; i < n-1; ++i)
    {
        int u,v;
        cin>>u>>v;

        adj[u].pb(v);
        adj[v].pb(u);
    }


    parent[1]=-1;
    dfs(1,-1);

    int a,b;
    cin>>a>>b;

    vector<int> aa = path(a);
    vector<int> bb = path(b);

    int sz = min(aa.size(),bb.size());

    int lca=0;
    while(aa[lca]==bb[lca])
    {
        lca++;
    }

    cout<<aa[--lca]<<"\n";

    // for (int u:aa)
    // {
    //     cout<<u<<" ";
    // }
    // endl

    // for (int u:bb)
    // {
    //     cout<<u<<" ";
    // }

    // endl

    // parent[1]=-1;
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout<<i<<" "<<parent[i]<<" **\n";
    // }

    // int a;
    // cin>>a;
    // cout<<subTree[a]<<"\n";

    return 0;
}