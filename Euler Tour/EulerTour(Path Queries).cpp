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


// const int inf = 2000000000;  //2e9
// const ll infLL = 9000000000000000000; //9e18

const int mx = 30000+5;

int arr[2*mx];
int value[mx];
vector<int> adj[mx];
int seg[8*mx];
int in[mx];
int out[mx];
int tym=-1;

const int lg=log2(mx)+2;
int T[mx][lg+1];
int n,level[mx],root;

void dfs(int u,int p)
{
    in[u] = ++tym;
    T[u][0]=p; //for sparse table first column
    if(p==-1) level[u]=0;
    else level[u]=level[p]+1;
    for(auto i:adj[u])
    {
        if(i!=p)
        {
            dfs(i,u);
        }
    }
    out[u] = ++tym;
}


//segment tree
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

//lca with sparse table
void buildTable()
{
    memset(T,-1,sizeof(T));
    dfs(root,-1);
    int lg1=log2(n)+1;
 
    for(int j=1;j<=lg1;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(T[i][j-1]!=-1)
            {
                T[i][j]=T[T[i][j-1]][j-1];
            }
        }
    }
}

int lca(int u,int v)
{
    if(level[u]<level[v]) swap(u,v);
        
 
    for(int i=lg;i>=0;i--)
    {
        if(T[u][i]!=-1  && level[u]-(1<<i)>=level[v])
        {
            u=T[u][i];
        }
    }

    if(u==v) return u;
        
    for(int i=lg;i>=0;i--)
    {
        if(T[u][i]!=-1 && T[u][i]!=T[v][i])
        {
            u=T[u][i];
            v=T[v][i];
        }
    }
    return T[u][0];
}

ll distance(int u,int v)
{
    ll d1 = query(0,0,(n*2)-1,in[0],in[u]);
    ll d2 = query(0,0,(n*2)-1,in[0],in[v]); 
    int ind = lca(u,v);
    ll d3 = query(0,0,(n*2)-1,in[0],in[ind]);
    return d1+d2-(2*d3)+arr[in[ind]];
}

void clean()
{
    for(int i=0; i<=n; i++)
    {
        if(adj[i].size()) adj[i].clear();
        in[i] = 0;
        out[i] = 0;
        value[i] = 0;
        level[i] = 0;
    }
    for(int i=1; i<=2*n; i++) arr[i] = 0;
    tym = -1;
    memset(seg,0,sizeof(seg));
    root=0;
}


int main()
{
    //optimize();
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin>>t;

    for (int kk = 1; kk <= t; ++kk)
    {
        clean();
        int q;
        cin>>n;

        for (int i = 0; i < n; ++i)
        {
            cin>>value[i];
        }

        for (int i = 1; i < n; ++i)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        buildTable();

        for (int i = 0; i < n; ++i)
        {
            arr[in[i]] = value[i];
        }

        for (int i = 0; i < n; ++i)
        {
            arr[out[i]] = -value[i];
        }

        build(0,0,(n*2)-1);

        cout<<"Case "<<kk<<":\n";
        cin>>q;
        while(q--)
        {
            int type;
            cin>>type;

            if (type==0)
            {
                int u,v;
                cin>>u>>v;
                cout<< distance(u,v) <<"\n";
            }
            else
            {
                int pos;
                ll val;
                cin>>pos>>val;
                update(0,0,(n*2)-1,in[pos],val);  
                update(0,0,(n*2)-1,out[pos],-val);
                arr[in[pos]] = val; 
                arr[out[pos]] = -val;          
            }

        }
    }

    return 0;
}
