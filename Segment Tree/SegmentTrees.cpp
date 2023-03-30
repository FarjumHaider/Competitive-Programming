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
ll seg[4*mxan];

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
    seg[node] = min(seg[(2*node)+1],seg[(2*node)+2]);
}

ll query(int node,int low,int high,int l,int r)
{
    if (low>r || high<l)
    {
        return INT_MAX;
    }
    if (low>=l && r>=high)
    {
        return seg[node];
    }
    int mid = (low+high)/2;
    ll left = query((2*node)+1,low,mid,l,r);
    ll right = query((2*node)+2,mid+1,high,l,r);
    return min(left,right);
}

void update(int node,int low,int high,int pos,ll val)
{
    if (high<pos || pos<low)
    {
        return;
    }
    if (pos<=low && high<=pos)
    {
        seg[node] = val;
        return;
    }
    int mid = (low+high)/2;
    update((2*node)+1,low,mid,pos,val);
    update((2*node)+2,mid+1,high,pos,val);
    seg[node] = min(seg[(2*node)+1],seg[(2*node)+2]);

}

void solve(int kk)
{
    optimize();
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
            int pos;
            ll val;
            cin>>pos>>val;
            update(0,0,n-1,pos-1,val);
            arr[pos] = val;
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<query(0,0,n-1,l-1,r-1)<<"\n";        
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

// 6
// 1 -2 3 2 4 5
// 5
// 1 3 2 0 5
// 3
// 1 0 3 0 2  
// 2 1 1 2
// 1 0 3 0 2 


// -2 1
// -2
// 1 1
// 1