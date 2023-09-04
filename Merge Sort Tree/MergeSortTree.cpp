#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int llu;
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

#define MOD 1000000007
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
ll arr[mxan];
vector<ll> seg[4*mxan];

void build(int node,int l,int r)
{
    if(l==r)
    {
        seg[node].pb(arr[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);

    int i=0,j=0;

    while(i<seg[2*node+1].size() && j<seg[2*node+2].size())
    {
        if(seg[2*node+1][i]<seg[2*node+2][j])
        {
            seg[node].pb(seg[2*node+1][i]);
            i++;
        }
        else
        {
            seg[node].pb(seg[2*node+2][j]);
            j++;
        }
    }

    while(i<seg[2*node+1].size())
    {
        seg[node].pb(seg[2*node+1][i]);
        i++;
    }

    while(j<seg[2*node+2].size())
    {
        seg[node].pb(seg[2*node+2][j]);
        j++;
    }
}


vector<int> query(int node,int l,int r,int low,int high,int p,int q)
{
    if(r<low || high<l) return {0,-1,-1};

    if(low<=l && r<=high) 
    {
        // int ind = upper_bound(seg[node].begin(),seg[node].end(),val)-seg[node].begin();
        // return seg[node].size()-ind;
        int l1=0,r1=seg[node].size()-1,x=-1,y=-1;
        while(l1<=r1)
        {
            int m = (l1+r1)/2;

            if (seg[node][m]>=p)
            {
                x=m;
                r1=m-1;
            }
            else
            {
                l1=m+1;
            }
        }

        l1=0;
        r1=seg[node].size()-1;
        while(l1<=r1)
        {
            int m = (l1+r1)/2;

            if (seg[node][m]<=q)
            {
                y=m;
                l1=m+1;
                
            }
            else
            {
                r1=m-1;
            }
        }

        vector<int> v;
        if (x==-1 || y==-1)
        {
            v.pb(0); 
            v.pb(-1); 
            v.pb(-1);  
        }
        else
        {
            v.pb(y-x+1);
            v.pb(seg[node][x]);
            v.pb(seg[node][y]);
        }
        return v;

    }
    int mid = (l+r)/2;
    vector<int> left = query(2*node+1,l,mid,low,high,p,q);
    vector<int> right = query(2*node+2,mid+1,r,low,high,p,q);

    int x=0,y=-1,z=-1;
    if (left[0]!=0)
    {
        x+=left[0];
        y = left[1];
        z = left[2];
    }

    if (right[0]!=0)
    {
        x+=right[0];
        if(right[1]!=-1)
        {
            y = min(y,right[1]);
        }
        z = max(z,right[2]);
    }

    return {x,y,z};

    // if (left[0]!=0 && right[0]!=0)
    // {
    //     int tot = left[0]+right[0];
    //     vector<int> v;
    //     v.pb(tot);
    //     v.pb(left[1]);
    //     v.pb(right[2]);
    //     return v;
        
    // }
    // else if (right[0]==0)
    // {
    //     return left;
    // }
    // else
    // {
    //     return right;
    // }
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
        int l,r,x,y;
        cin>>l>>r>>x>>y;
        vector<int> v = query(0,0,n-1,l-1,r-1,x,y);
        if(v[0]==0) v[1]=v[2]=-1;
        cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
    }
}



int main()
{
    optimize();

    // int t;
    // cin>>t;

    // for(int i =1;i<=t;i++)
    // {
    //     solve(i);
    // }
    solve(0);



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