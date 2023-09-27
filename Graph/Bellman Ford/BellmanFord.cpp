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

const int mx = 1e3+123;
ll dis[mx];
vector<info> adj;

//time complexity: O(n*m)
bool bellmanford(int s,int n,int m)
{
    for (int i = 0; i < n; ++i)
    {
        dis[i] = infLL;
    }

    dis[s] = 0;

    bool isCycle = false;

    for (int i = 1; i <= n; ++i)
    {
        isCycle = false;
        for (auto e:adj)
        {
            if (dis[e.u]<infLL)
            {
                if (dis[e.u]+e.w < dis[e.v])
                {
                    dis[e.v] = max(-infLL,dis[e.u]+e.w);
                    isCycle = true;
                }
            }
        }
    }
    return isCycle;

}




int main()
{
    optimize();

    int t;
    cin >> t;

    while ( t-- )
    {
        adj.clear();
        int n,m;
        cin>>n>>m;

        for (int i = 1; i <= m; ++i)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj.pb({u,v,w});
        }

        if(bellmanford(0,n,m)) cout<<"Negative cycle\n";
        else cout<<"not negative cycle\n";       
    }

  
    return 0;
}