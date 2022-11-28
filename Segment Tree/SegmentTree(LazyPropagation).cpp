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
//ll seg[4*mx];

class SegmentTree
{
    vector<ll> seg,lazy;
public:
    SegmentTree(int n)
    {
        seg.resize(4*n+1);
        lazy.resize(4*n+1);
    }

    void build(int node,int low,int high)
    {
        if (low==high)
        {
            seg[node] = arr[low];
            return;
        }

        int mid = (low+high)/2;
        build((2*node)+1,low,mid);
        build((2*node)+2,mid+1,high);
        seg[node] = seg[(2*node)+1]+seg[(2*node)+2];

    }

    void update(int node,int low,int high,int l,int r,ll val)
    {
        if (lazy[node]!=0)
        {
            seg[node]+=(high-low+1)*lazy[node];

            if (low!=high)
            {
                lazy[(2*node)+1] += lazy[node];
                lazy[(2*node)+2] += lazy[node]; 
            }
            else
            {
                arr[low] = seg[node];
            }
            lazy[node]=0;
        }

        if (r<low || high<l)
        {
            return;
        }

        if (l<=low && high<=r)
        {
            seg[node] += (high-low+1)*val;
            if (low!=high)
            {
                lazy[(2*node)+1] += val;
                lazy[(2*node)+2] += val;
            }  
            else
            {
                arr[low] = seg[node];
            }
            lazy[node]=0;
            return;
        }

        int mid = (low+high)/2;
        update((2*node)+1,low,mid,l,r,val);
        update((2*node)+2,mid+1,high,l,r,val);
        seg[node]=seg[(2*node)+1]+seg[(2*node)+2];

    }

    ll query(int node,int low,int high,int l,int r)
    {
        if (lazy[node]!=0)
        {
            seg[node]+=(high-low+1)*lazy[node];
            if (low!=high)
            {
                lazy[(2*node)+1]+=lazy[node];
                lazy[(2*node)+2]+=lazy[node];
            }
            else
            {
                arr[low]=seg[node];
            }
            lazy[node]=0;
        }


        if (r<low || high<l) //no overlap
        {
            return 0;
        } 
        else if (l<=low && r>=high) //complete overlap
        {
            return seg[node];
        } 
        else //partial overlap
        {
            int mid = (high+low)/2;
            ll left = query((2*node)+1,low,mid,l,r);
            ll right = query((2*node)+2,mid+1,high,l,r);
            return left+right;
        }


    }


    ll value(int node,int low,int high,int pos)
    {
        if (lazy[node]!=0)
        {
            seg[node]+=(high-low+1)*lazy[node];

            if (low!=high)
            {
                lazy[(2*node)+1] += lazy[node];
                lazy[(2*node)+2] += lazy[node]; 
            }
            else
            {
                arr[low] = seg[node];
            }
            lazy[node]=0;
        }


        if (low==high)
        {
            return arr[pos];
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
    
};


int main()
{
    optimize();
    memset(arr,0,sizeof(arr));
    int n,q;
    cin>>n>>q;

    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }

    SegmentTree sg(n);
    sg.build(0,0,n-1);

    while(q--)
    {
        int type;
        cin>>type;

        if (type==1)
        {
            int l,r;
            ll val;
            cin>>l>>r>>val;
            sg.update(0,0,n-1,l-1,r-1,val);
        }
        else
        {
            int pos;
            cin>>pos;
            cout<<sg.value(0,0,n-1,pos-1)<<"\n";
        }

    }

    return 0;
}
