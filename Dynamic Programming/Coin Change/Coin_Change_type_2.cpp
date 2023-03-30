/*
https://leetcode.com/problems/coin-change-ii/
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

int const mxan=5e3+123;
ll dp[300][mxan];
// int coin[52];

int n,m;
ll com=0;

long long fun(int i,int amount,vector<int>& coins)
{
    if (amount==0) return 1;
    if (i==coins.size()) return 0;
    if (dp[i][amount]!=-1) return dp[i][amount];

    long long total=0;
    for (int j = 0; j <= amount; ++j)
    {
        if (amount-(j*coins[i])>=0)
        {
            total+=fun(i+1,amount-(j*coins[i]),coins);
        }
        else
        {
            break;
        }
    }

    return dp[i][amount]=total;
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

    cout<<fun(0,5,coins)<<"\n";
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