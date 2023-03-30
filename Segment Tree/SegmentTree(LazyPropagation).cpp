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

const int mxan = 2e5+123;
ll arr[mxan];
struct Node{
    ll cost, prop;
}seg[mxan*4];

void build(int node,int low,int high)
{
    if (low==high)
    {
        seg[node].cost = arr[low];
        return;
    }
    int mid = (low+high)/2;
    build((2*node)+1,low,mid);
    build((2*node)+2,mid+1,high);
    seg[node].cost = seg[(2*node)+1].cost+seg[(2*node)+2].cost;
}


ll query(int node,int low,int high,int l,int r)
{
    if (seg[node].prop!=0)
    {
        seg[node].cost+=(high-low+1)*seg[node].prop;
        if (low!=high)
        {
            seg[(2*node)+1].prop+=seg[node].prop;
            seg[(2*node)+2].prop+=seg[node].prop;
        }
        seg[node].prop=0;
    }

    if (r<low || high<l) //no overlap
    {
        return 0;
    } 
    if (l<=low && r>=high) //complete overlap
    {
        return seg[node].cost;
    } 
    //partial overlap
    int mid = (high+low)/2;
    ll left = query((2*node)+1,low,mid,l,r);
    ll right = query((2*node)+2,mid+1,high,l,r);
    return left+right;

}

void update(int node,int low,int high,int l,int r,ll val)
{
    if (seg[node].prop!=0)
    {
        seg[node].cost+=(high-low+1)*seg[node].prop;

        if (low!=high)
        {
            seg[(2*node)+1].prop += seg[node].prop;
            seg[(2*node)+2].prop += seg[node].prop; 
        }
        seg[node].prop=0;
    }

    if (r<low || high<l)
    {
        return;
    }
    if (l<=low && high<=r)
    {
        seg[node].cost += (high-low+1)*val;
        if (low!=high)
        {
            seg[(2*node)+1].prop += val;
            seg[(2*node)+2].prop += val;
        }  
        return;
    }
    int mid = (low+high)/2;
    update((2*node)+1,low,mid,l,r,val);
    update((2*node)+2,mid+1,high,l,r,val);
    seg[node].cost=seg[(2*node)+1].cost+seg[(2*node)+2].cost;
}


ll value(int node,int low,int high,int pos)
{
    if (seg[node].prop!=0)
    {
        seg[node].cost+=(high-low+1)*seg[node].prop;

        if (low!=high)
        {
            seg[(2*node)+1].prop += seg[node].prop;
            seg[(2*node)+2].prop += seg[node].prop; 
        }
        seg[node].prop=0;
    }

    if (low==high)
    {
        return seg[node].cost;
    }
    
    int mid=(low+high)/2;
    if (pos<=mid)
    {
        return value((2*node)+1,low,mid,pos);
    }
    else
    {
        return value((2*node)+2,mid+1,high,pos);
    }
}


void solve(int kk)
{
    memset(seg,0,sizeof(seg));
    memset(arr,0,sizeof(arr));

    int n,q;
    cin>>n>>q;

    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }

    build(0,0,n-1);

    while(q--)
    {
        int type;
        cin>>type;

        if (type==1)
        {
            int l,r;
            ll val;
            cin>>l>>r>>val;
            update(0,0,n-1,l-1,r-1,val);
        }
        else
        {
            int pos;
            cin>>pos;
            cout<<value(0,0,n-1,pos-1)<<"\n";
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