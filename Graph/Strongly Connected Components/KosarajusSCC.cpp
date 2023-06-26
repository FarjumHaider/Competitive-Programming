
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
 //linear order of vertices, u->v , then u appers before v
//only Directed Acyclic graph
const int mxan = 1e5+123;
bool vis[mxan];
vector<ll> adj[mxan];
vector<ll> tadj[mxan];
stack<ll> st;
vector<ll> ssc;
// map<string, vector<string>> adj;
// map<string,int> indegree;
// vector<string> topo;

int tym=0;

void dfs(int u)
{
    vis[u]=1;

    for(int v:adj[u])
    {
        if(!vis[v]) dfs(v);
    }

    st.push(u);
}

void kosaraju(int u)
{
    vis[u]=1;
    ssc.pb(u);

    for(int v:tadj[u])
    {
        if(!vis[v]) kosaraju(v);
    }
}

void solve(int kk)
{
    memset(adj,0,sizeof(adj));
    memset(tadj,0,sizeof(tadj));
    memset(vis,0,sizeof(vis));

    int n,m;
    cin>>n>>m;

    for (int i = 0; i < m; ++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        tadj[v].pb(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i]) dfs(i);
    }

    memset(vis,0,sizeof(vis));
    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        if (!vis[u])
        {
            ssc.clear();
            kosaraju(u);
            for(auto v:ssc)
            {
                cout<<v<<" ";
            }
            endl
        }
    }
       
}


int main()
{
    optimize();

    // int t;
    // cin>>t;
    // for (int kk = 1; kk <= t; ++kk)
    // {
    //     solve(kk);
    // }

    solve(0);

    return 0;
}