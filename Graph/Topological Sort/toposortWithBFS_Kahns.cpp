/*
https://cses.fi/problemset/task/1679
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
const int mxan = 1e5+123;
bool vis[mxan];
vector<int> adj[mxan];
int indegree[mxan];
vector<int> topo;
stack<int>st;
int tym=0;

bool bfs(int n)
{
    //priority_queue<int,vector<int>,greater<int>>pq;
    queue<int> pq;
    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i]==0)
        {
            pq.push(i);
        }
    }

    while(!pq.empty())
    {
        int u = pq.front();
        pq.pop();
        topo.pb(u);

        for (int v:adj[u])
        {
            indegree[v]--;
            if (indegree[v]==0)
            {
                pq.push(v);
            }
        }
    }
 
    if (topo.size()==n) return true;
    else return false;
}

void solve()
{
    memset(adj,0,sizeof(adj));
    memset(vis,0,sizeof(vis));
    memset(indegree,0,sizeof(indegree));
    topo.clear();

    int n,m;
    cin>>n>>m;

    for (int i = 0; i < m; ++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        indegree[v]++;
    }


    if (!bfs(n))
    {
        cout<<"IMPOSSIBLE\n";
    }
    else
    {
        for(auto u:topo)
        {
            cout<<u<<" ";
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