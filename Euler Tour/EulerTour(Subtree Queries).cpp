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
const ll infLL = 9000000000000000000; //9e18

const int mx = 2e5+123;

ll arr[mx];
ll value[mx];
vector<ll> adj[mx];
ll seg[4*mx];
int in[mx];
int out[mx];
int tym=0;

void dfs(int u,int p)
{
    in[u] = tym;
    for(auto i:adj[u])
    {
        if(i!=p)
        {
            tym++;
            dfs(i,u);
        }
    }
    out[u] = tym;
}

void build(int node,int low,int high)
{
    if (low == high)
    {
        seg[node] = arr[low];
        return;
    }

    int mid = (low+high)/2;
    build((2*node)+1,low,mid);
    build((2*node)+2,mid+1,high);

    seg[node] = seg[(2*node)+1]+seg[(2*node)+2];
}

ll query(int node,int low,int high,int l,int r)
{
    if (low>r || high<l)
    {
        return 0;
    }
    if (low>=l && r>=high)
    {
        return seg[node];
    }
    
    int mid = (low+high)/2;
    ll left = query((2*node)+1,low,mid,l,r);
    ll right = query((2*node)+2,mid+1,high,l,r);

    return left+right;
}

void update(int node,int low,int high,int pos,ll val)
{
    if (low == high)
    {
        seg[node] = val;
        return;
    }

    int mid = (low+high)/2;
    if (mid>=pos)
    {
        update((2*node)+1,low,mid,pos,val);
    }
    else
    {
        update((2*node)+2,mid+1,high,pos,val);
    }

    seg[node] = seg[(2*node)+1]+seg[(2*node)+2];

}

int main()
{
    optimize();
    memset(seg,0,sizeof(seg));
    memset(arr,0,sizeof(arr));
    memset(value,0,sizeof(value));

    int n,q;
    cin>>n>>q;

    for (int i = 0; i < n; ++i)
    {
        cin>>value[i];
    }

    for (int i = 1; i < n; ++i)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0,-1);

    for (int i = 0; i < n; ++i)
    {
        arr[in[i]] = value[i];
    }

    build(0,0,n-1);

    while(q--)
    {
        int type;
        cin>>type;

        if (type==2)
        {
            int pos;
            cin>>pos;
            pos--;
            cout<<query(0,0,n-1,in[pos],out[pos])<<"\n";
        }
        else
        {
            int pos;
            ll val;
            cin>>pos>>val;
            pos--;
            update(0,0,n-1,in[pos],val);  
            arr[in[pos]] = val;          
        }

    }
  
    return 0;
}
