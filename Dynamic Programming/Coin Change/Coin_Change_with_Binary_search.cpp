/*
https://leetcode.com/problems/minimum-cost-for-tickets/
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

int const mxan=365+123;
int check[mxan];

ll dp[mxan];
ll cost[5];
ll day[365];
int pass[]={1,7,30};

int n;
ll com=0;

ll fun(int pos)
{
    if(pos==n) return 0; 
    if(dp[pos]!=-1) return dp[pos];
    ll mn=INT_MAX;
    for (int k = 0; k < 3; ++k)  
    {
        ll d =  day[pos]+pass[k]-1;
        int m = upper_bound(day, day + n, d)-day;
        ll c = cost[k]+fun(m);
        mn = min(mn, c);
    }
    return dp[pos] = mn;
}


void solve()
{
    memset(dp,-1,sizeof(dp));

    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>day[i];
    }

    for (int i = 0; i < 3; ++i)
    {
        cin>>cost[i];
    }

    cout<< fun(0) <<"\n";
}



int main()
{
    optimize();

    // int t;
    // cin>>t;

    // while(t--)
    // {
    //     solve();
    // }
    solve();



    return 0;
}