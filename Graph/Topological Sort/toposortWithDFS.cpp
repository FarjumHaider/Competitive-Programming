/*
https://www.spoj.com/problems/TOPOSORT/en/
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
 //linear order of vertices, u->v , then u appers before v
//only Directed Acyclic graph
const int mxan = 1e4+123;
bool vis[mxan];
vector<int> adj[mxan];
int indegree[mxan];
vector<int> topo;
int In[mxan];
int Out[mxan];
stack<int>st;
int tym=0;

bool dfs(int u)
{
    In[u]=++tym;
    vis[u]=1;
    for (int v:adj[u])
    {
        if(!vis[v])
        {
            if (!dfs(v)) return false;
        } 
        else
        {
            if (Out[v]==0) return false;
        }
    }
    Out[u]=++tym;
    st.push(u);
    return true;
}

void solve()
{
    memset(adj,0,sizeof(adj));
    memset(vis,0,sizeof(vis));
    memset(In,0,sizeof(In));
    memset(Out,0,sizeof(Out));

    int n,m;
    cin>>n>>m;

    for (int i = 0; i < m; ++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }

    for (int i = 1; i <= n ; ++i)
    {
        sort(rall(adj[i]));
    }

    bool bb=true;
    for (int i = n; i >= 1; --i)
    {
        if (!vis[i])
        {
            if (!dfs(i)) bb=false;
        }
    }

    if (!bb)
    {
        cout<<"Sandro fails.\n";
    }
    else
    {
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
        endl        
    }


       
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