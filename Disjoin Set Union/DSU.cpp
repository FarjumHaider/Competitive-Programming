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

int const mxan=1e5+123;
int parent[mxan];
int sz[mxan];

void make(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        parent[i]=i;
        sz[i]=1;
    }
}

int find(int v)
{
    if(parent[v]==v) return v;
    return parent[v]=find(parent[v]);
}

void Union(int a,int b)
{
    a = find(a);
    b = find(b);
    if (a!=b)
    {
        if (sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;

    make(n);

    while(m--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }

    int cnt=0;
    for (int i = 1; i <= n; ++i)
    {
        if(parent[i]==i) cnt++;
    }

    cout<<cnt<<"\n";
}



int main()
{
    optimize();

    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }
    //solve();



    return 0;
}