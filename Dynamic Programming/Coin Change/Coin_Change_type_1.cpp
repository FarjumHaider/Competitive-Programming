/*
https://leetcode.com/problems/coin-change/submissions/910784106/
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

int const mxan=1e4+123;
ll dp[mxan];
// int coin[52];

int n,m;
ll com=0;

long long fun(vector<int>& coins, int amount)
{
    if(amount==0) return 0;
    if(dp[amount]!=-1) return dp[amount];
    long long cnt=INT_MAX;
    for(int i =0;i<coins.size();i++)
    {
        if(amount-coins[i]>=0)
        {
            cnt=min(cnt,1+fun(coins,amount-coins[i]));
        }
    }
    return dp[amount]=cnt;
}

void solve()
{
    memset(dp,-1,sizeof(dp));

    cin>>n;

    vector<int> coins;

    for (int i = 0; i < n; ++i)
    {
        int a;
        cin>>a;
        coins.pb(a);
    }

    int amount;
    cin>>amount;
    cout<<fun(coins,amount)<<"\n";

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