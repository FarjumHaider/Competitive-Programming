/*
https://leetcode.com/problems/longest-common-subsequence/
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
string s1,s2;

//T.C: O(n*m)
void solve(int kk)
{
    memset(dp,0,sizeof(dp));
    cin>>s1>>s2;

    int n=s1.size();
    int m=s2.size();
    for (int i = 0; i < n; ++i) dp[i][m]=0;
    for (int j = 0; j < m; ++j) dp[n][j]=0;

    for (int i = n-1; i >= 0; --i)
    {
        for (int j = m-1; j >= 0; --j)
        {
            if(s1[i]==s2[j]) dp[i][j] = 1+dp[i+1][j+1];
            else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
        }
    }
    cout<<dp[0][0]<<"\n";
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