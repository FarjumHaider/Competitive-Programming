/*
https://lightoj.com/problem/jane-and-the-frost-giants
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

const int mxan = 2e2+123;
int lvlF[mxan][mxan];
int lvlJ[mxan][mxan];
char adj[mxan][mxan];
int n,m,mn;

int dx[] = { +1, -1, 0, 0};
int dy[] = { 0, 0, -1, +1};

void bfsF(int a,int b)
{
    lvlF[a][b]=1;
    queue<pair<int,int>> q;
    q.push({a,b});

    while(!q.empty())
    {
        int x = q.front().ff;
        int y = q.front().ss;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if (xx>=1 && xx<=n && yy>=1 && yy<=m  && adj[xx][yy]!='#' && (lvlF[xx][yy]==-1 || lvlF[xx][yy]>lvlF[x][y]+1))
            {
                lvlF[xx][yy] = lvlF[x][y]+1;
                q.push({xx,yy});
            }
        }
    }
}


void bfsJ(int a,int b)
{
    lvlJ[a][b]=1;
    queue<pair<int,int>> q;
    q.push({a,b});

    while(!q.empty())
    {
        int x = q.front().ff;
        int y = q.front().ss;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if (xx>=1 && xx<=n && yy>=1 && yy<=m  && adj[xx][yy]=='.' && lvlJ[xx][yy]==-1 && lvlF[xx][yy]>lvlJ[x][y]+1)
            {
                lvlJ[xx][yy] = lvlJ[x][y]+1;
                q.push({xx,yy});

                // if (xx==1 || yy==1 || xx==n || yy==m)
                // {
                //     mn = min(mn,lvlJ[xx][yy]);
                // }
            }
        }  
    }
}


int main()
{
    optimize();

    int t;
    cin>> t;
    for (int i = 1; i <= t; ++i)
    {
        memset(lvlF,-1,sizeof(lvlF));
        memset(lvlJ,-1,sizeof(lvlJ));
        memset(adj,'\0',sizeof(adj));
        mn=INT_MAX;

        int x,y;
        cin>>n>>m;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                char ch;
                cin>>ch;
                adj[i][j]=ch;
                if(ch=='J')
                {
                    x=i;
                    y=j;
                }
            }
        }


        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if(adj[i][j]=='F')
                {
                    bfsF(i,j);
                }
            }
        }

        bfsJ(x,y);

        for (int i = 1; i <= n; ++i)
        {
            if (lvlJ[i][1]!=-1) mn = min(mn,lvlJ[i][1]);
            if (lvlJ[i][m]!=-1) mn = min(mn,lvlJ[i][m]);
        }

        for (int i = 1; i <= m; ++i)
        {
            if (lvlJ[1][i]!=-1) mn = min(mn,lvlJ[1][i]);
            if (lvlJ[n][i]!=-1) mn = min(mn,lvlJ[n][i]);
        }

        cout<<"Case "<<i<<": ";
        if (mn==INT_MAX)
        {
            cout<<"IMPOSSIBLE"<<"\n";
        }
        else
        {
            cout<<mn<<"\n";
        }
    }

    return 0;
}