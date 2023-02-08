/*
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
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
int lvl[mxan];
vector<int> adj[mxan];

void bfs(int s)
{
    memset(lvl,-1,sizeof(lvl));

    lvl[s]=0;
    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v:adj[u])
        {
            if (lvl[v]==-1)
            {
                q.push(v);
                lvl[v] = lvl[u]+1;
            }
        }        
    }


}

int main()
{
    optimize();

    int t;
    cin>> t;
    for (int i = 1; i <= t; ++i)
    {
        memset(lvl,0,sizeof(lvl));
        memset(adj,0,sizeof(adj));

        int n,m;
        cin>>n>>m;

        for (int i = 1; i <= m; ++i)
        {
            int u,v;
            cin>>u>>v;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        bfs(1);
        cout<<lvl[n]<<"\n";
      
    }

    return 0;
}