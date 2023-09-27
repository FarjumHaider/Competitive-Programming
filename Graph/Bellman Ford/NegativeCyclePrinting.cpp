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


const int inf = 2000000000;  //2e9
const ll infLL = 9000000000000; //9e18

struct info
{
    int u,v,w;
};

const int mx = 3e3+123;
ll dis[mx];
vector<info> adj;
int par[mx];


//time complexity: O(n*m)
vector<int> bellmanford(int s,int n,int m)
{
    vector<int> path;
    for (int i = 0; i <= n; ++i)
    {
        dis[i]=infLL;
    }

    dis[s]=0;

    int x=-1;

    for (int i = 1; i <= n; ++i)
    {
        x=-1;
        for(auto e:adj)
        {
            if (dis[e.v] > dis[e.u]+e.w)
            {
                dis[e.v]= max(-infLL,dis[e.u]+e.w);
                x = e.v;
                par[e.v] = e.u;
            }
        }
    }

    if(x==-1) return path;

    for (int i = 1; i <= n; ++i)
    {
        x = par[x];
    }

    int y=x;

    while(x!=y || path.size()==0)
    {
        path.pb(y);
        y=par[y];
    }

    path.pb(x);
    reverse(all(path));
    return path;
}




int main()
{
    optimize();

    int n,m;
    cin>>n>>m;

    for (int i = 1; i <= m; ++i)
    {
        int u,v,w;
        cin>>u>>v>>w;

        adj.pb({u,v,w});
    }

    vi ans = bellmanford(1,n,m);
    if (ans.size()==0)
    {
        NO
    }
    else
    {
        YES
        for(int u:ans)
        {
            cout<<u<<" ";
        }
        endl
    }

  
    return 0;
}