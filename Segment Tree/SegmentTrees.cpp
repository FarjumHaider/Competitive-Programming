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

const int mx = 1e2+123;

//ll arr[mx];
//ll seg[4*mx];

class SegmentTree
{
    vector<ll> seg;
    public:
        SegmentTree(int n)
        {
            seg.resize(4*n+1);
        }

    void build(int node,int low,int high,ll arr[])
    {
        if (low == high)
        {
            seg[node] = arr[low];
            return;
        }

        int mid = (low+high)/2;
        build((2*node)+1,low,mid,arr);
        build((2*node)+2,mid+1,high,arr);

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

        seg[node] = min(seg[(2*node)+1],seg[(2*node)+2]);

    }
    
};


int main()
{
    optimize();
    // memset(seg,0,sizeof(seg));
    // memset(arr,0,sizeof(arr));

    int n1;
    cin>>n1;
    ll arr1[n1];

    for (int i = 0; i < n1; ++i)
    {
        cin>>arr1[i];
    }

    SegmentTree sg1(n1);
    sg1.build(0,0,n1-1,arr1);

    int n2;
    cin>>n2;
    ll arr2[n2];

    for (int i = 0; i < n2; ++i)
    {
        cin>>arr2[i];
    }

    SegmentTree sg2(n2);
    sg2.build(0,0,n2-1,arr2);

    int q;
    cin>>q;

    while(q--)
    {
        int type;
        cin>>type;

        if (type==1)
        {
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            ll min1 = sg1.query(0,0,n1-1,l1,r1);
            ll min2 = sg2.query(0,0,n2-1,l2,r2);
            cout<<min1<<" "<<min2<<"\n";
            cout<<min(min1,min2)<<"\n";
        }
        else
        {
            int arrNo,pos;
            ll val;
            cin>>arrNo>>pos>>val;
            if (arrNo==1)
            {
                sg1.update(0,0,n1-1,pos,val);
                arr1[pos] = val;  
            }
            else
            {
                sg2.update(0,0,n2-1,pos,val);
                arr2[pos] = val;  
            }       
        }

    }
  
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