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

const ll infLL = 9000000000000000000; //9e18

int const mxan=1e2+123;
vector<pair<ll,ll>> adj[mxan];
ll dis[mxan];
int n;

void dijkstra(int s)
{
    for (int i = 1; i <= n; ++i)
    {
        dis[i]=infLL;
    }
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    //priority_queue<pll,vpll,greater<pll>> pq;

    pq.push({0,s});
    dis[s]=0;

    while(!pq.empty())
    {
        ll u = pq.top().ss;
        ll w = pq.top().ff;
        pq.pop();

        if(dis[u]<w) continue;

        for(auto v:adj[u])
        {
            if(dis[v.ff]>w+v.ss)
            {
                dis[v.ff]=w+v.ss;
                pq.push({dis[v.ff],v.ff});
            }
        } 
    }
}

void clean()
{
    for (int i = 0; i <= n; ++i)
    {
        adj[i].clear();
    }
}

void solve(int kk)
{
    int m;
    cin>>n>>m;

    for (int i = 0; i < m; ++i)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    dijkstra(1);
    cout<<"Case "<<kk<<": ";
    if (dis[n]!=infLL)
    {
        cout<<dis[n]<<"\n";
    }
    else
    {
        cout<<"Impossible\n";
    }

    clean();
}



int main()
{
    optimize();

    int t;
    cin>>t;

    for (int i = 1; i <= t; ++i)
    {
        solve(i);
    }
    //solve(0);



    return 0;
}