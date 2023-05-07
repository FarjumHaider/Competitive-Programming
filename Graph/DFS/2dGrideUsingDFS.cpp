/*
https://lightoj.com/problem/guilty-prince
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

const int mxan = 25;
bool vis[mxan][mxan];
char adj[mxan][mxan];
int n,m,cnt=1;

int dx[] = { +1 , -1 , 0 , 0 };
int dy[] = { 0 , 0 , +1 , -1 };

void dfs(int x,int y)
{
    vis[x][y]=1;
    for (int i = 0; i < 4; ++i)
    {
        int xx = x+dx[i];
        int yy = y+dy[i];

        if (xx>=1 && xx<=n && yy>=1 && yy<=m && vis[xx][yy]==0 && adj[xx][yy]=='.')
        {
            cnt++;
            dfs(xx,yy);
        }
    }
}

void clean()
{
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            adj[i][j]='\0';
            vis[i][j]=0;
        }
    }  
}

int main()
{
    optimize();
    int t;
    cin>> t;
    for (int kk = 1; kk <= t; ++kk)
    {
        // memset(vis,0,sizeof(vis));
        // memset(adj,'\0',sizeof(adj));
        cnt=1;

        int x,y;
        cin>>m>>n;
        
        clean();

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                char ch;
                cin>>ch;
                adj[i][j]=ch;
                if(ch=='@')
                {
                    x=i;
                    y=j;
                }
            }
        }

        dfs(x,y);

        cout<<"Case "<<kk<<": "<<cnt<<"\n";
    }




    return 0;
}