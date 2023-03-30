/*
https://leetcode.com/problems/longest-palindromic-subsequence/
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
#define MOD 100000007;

int const mxan=1e3+123;
ll dp[mxan][mxan];
string s;

//T.C: O(n*m)
int fun(int i,int j)
{
    if(i>j) return 0;
    if(i==j) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans;
    if(s[i]==s[j]) ans = 2+fun(i+1,j-1);
    else ans = max(fun(i+1,j),fun(i,j-1));
    return dp[i][j]=ans;
}


void solve(int kk)
{
    memset(dp,-1,sizeof(dp));
    cin>>s;
    cout<<fun(0,s.size()-1)<<"\n";
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