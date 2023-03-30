/*
https://codeforces.com/contest/1341/problem/D
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


int const mxan=2e3+123;
ll dp[mxan][mxan];
string arr[mxan];
string digits[]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

ll n,m,k,cnt=0;

struct info
{
    int i,cost,val;
    info(){};
    info(int i,int cost,int val)
    {
        this->i=i;
        this->cost=cost;
        this->val=val;
    }
}dir[mxan][mxan];

int getVal(string s,string s1)
{
    int cnt=0;
    for (int i = 0; i < 7; ++i)
    {
        if(s[i]=='1' && s1[i]=='0') return -1;
        if(s[i]=='0' && s1[i]=='1') cnt++;

    }
    return cnt;
}

ll fun(int i,int stk)
{
    if (stk==0 && i==n) return 1;
    if(stk<0 || i==n) return 0;
    if(dp[i][stk]!=-1) return dp[i][stk];

    int ret=0;
    for (int j = 0; j <= 9; ++j)
    {
        int c = getVal(arr[i],digits[j]);
        if(c==-1)
        {
            continue;
        } 
        else
        {
            if(stk-c>=0)
            {
                if(fun(i+1,stk-c)==1)
                {
                    ret=1;
                    dir[i][stk] = info(i+1,stk-c,j);
                }
            }
                       
        }
    }

    return dp[i][stk]=ret;
}

void print(int i,int cost)
{
    if(dir[i][cost].val==-1) return;
    cout<<dir[i][cost].val;
    print(dir[i][cost].i,dir[i][cost].cost);
}

void solve(int kk)
{
    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));
    cin>>n>>k;
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }

    if (fun(0,k)) print(0,k);
    else cout<<"-1\n";   
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