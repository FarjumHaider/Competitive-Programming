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

const int mxan = 2e2+123;
int failure[mxan];

void build_failure_function(string pat, int m)
{
    int i=1,len=0;
    failure[0]=0;
    while(i<m)
    {
        if (pat[i]==pat[len])
        {
            len++;
            failure[i]=len;
            i++;
        }
        else
        {
            if (len>0)
            {
                len = failure[len-1];
            }
            else
            {
                failure[i]=0;
                i++;
            }
        }
    }
}

bool kmp_find_substring(string tex, string pat)
{
    int n = tex.size();
    int m = pat.size();

    int i=0,j=0;

    while(i<n)
    {
        if (tex[i]==pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j>0)
            {
                j=failure[j-1];
            } 
            else
            {
                i++;
            }
            
        }

        if (j==m)
        {
            return true;
        }
    }
    return false;
}

ll kmp_count_substring(string tex, string pat)
{
    int n = tex.size();
    int m = pat.size();

    int i=0,j=0,cnt=0;

    while(i<n)
    {
        if (tex[i]==pat[j])
        {
            i++;
            j++;
            if (j==m)
            {
                j=failure[j-1];
                cnt++;
            }
        }
        else
        {
            if (j>0)
            {
                j=failure[j-1];
            } 
            else
            {
                i++;
            }
        }
    }
    return cnt;
}

void solve(int kk)
{
    string tex,pat;
    cin>>tex>>pat;

    build_failure_function(pat,pat.size());

    cout<<"Case "<<kk<<": "<<kmp_count_substring(tex,pat)<<"\n";

}


int main()
{
    optimize();

    int t;
    cin>>t;

    for (int kk = 1; kk <= t; ++kk)
    {
        solve(kk);
    }
    //solve(0);



    return 0;
}