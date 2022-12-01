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

const int mx = 1e5+123;

//ll arr[mx];
//ll seg[4*mx];
//vector<ll> seg[4*mx];

class MSTree
{
    vector<vector<ll>> seg;
    public:
        MSTree(int n)
        {
            seg.resize(4*n+1);
        }

    public:

    void build(int node,int low,int high,ll arr[])
    {
        if (low==high)
        {
            seg[node].pb(arr[low]);
            return;
        }

        int mid = (high+low)/2;
        build((2*node)+1,low,mid,arr);
        build((2*node)+2,mid+1,high,arr);

        int i=0,j=0;

        while(i<seg[(2*node)+1].size() && j<seg[(2*node)+2].size())
        {
            if (seg[(2*node)+1][i]<=seg[(2*node)+2][j])
            {
                seg[node].pb(seg[(2*node)+1][i]);
                i++;
            }
            else
            {
                seg[node].pb(seg[(2*node)+2][j]);
                j++; 
            }
        }

        while(i<seg[(2*node)+1].size())
        {
            seg[node].pb(seg[(2*node)+1][i]);
            i++;
        }

        while(j<seg[(2*node)+2].size())
        {
            seg[node].pb(seg[(2*node)+2][j]);
            j++;
        }
    }

    ll query(int node,int low,int high,int l,int r,ll val)
    {
        if (r<low || high<l)
        {
            return 0;
        }

        if (l<=low && high<=r)
        {
            int ind = upper_bound(seg[node].begin(),seg[node].end(),val)-seg[node].begin();
            return seg[node].size()-ind;
        }

        int mid = (high+low)/2;
        ll left = query((2*node)+1,low,mid,l,r,val);
        ll right = query((2*node)+2,mid+1,high,l,r,val);
        return left+right;
    }
    
};


int main()
{
    optimize();
    // memset(seg,0,sizeof(seg));
    // memset(arr,0,sizeof(arr));

    int n,q;
    cin>>n;
    ll arr[n];

    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }

    MSTree sg(n);
    sg.build(0,0,n-1,arr);

    cin>>q;
    while(q--)
    {
        int l,r;
        ll val;
        cin>>l>>r>>val;
        cout<<sg.query(0,0,n-1,l-1,r-1,val)<<"\n";
    }
  
    return 0;
}

//elements greater than k in the subsequence 
// input:
// 5
// 5 1 2 3 4
// 3
// 2 4 1
// 4 4 4
// 1 5 2
// Output
// 2
// 0
// 3
