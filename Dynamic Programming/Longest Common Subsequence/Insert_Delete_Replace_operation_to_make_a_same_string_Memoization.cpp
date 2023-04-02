/*
https://leetcode.com/problems/edit-distance/
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

//T.C: O(n*m)
//S.C: O(n*m)+O(n+m)
int fun(int i,int j,string &s, string &t)
{
    if(i==s.size() && j==t.size()) return 0;
    if(i==s.size()) return t.size()-j;
    if(j==t.size()) return s.size()-i;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans;
    if(s[i]==t[j]) ans=fun(i+1,j+1,s,t);
    else ans=1+min(fun(i+1,j+1,s,t),min(fun(i+1,j,s,t),fun(i,j+1,s,t)));
    return dp[i][j]=ans;
}

void solve(int kk)
{
    memset(dp,-1,sizeof(dp));
    string s1,s2;
    cin>>s1>>s2;
    cout<<fun(0,0,s1,s2)<<"\n";
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