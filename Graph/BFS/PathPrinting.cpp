/*
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=703
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

const int mxan = 1e5+123;

map<string,vector<string>> adj;
map<string,int> lvl;
map<string,string> p;

void bfs(string s)
{
    lvl[s]=1;
    queue<string> q;
    q.push(s);

    while(!q.empty())
    {
        string u = q.front();
        q.pop();

        for (string v:adj[u])
        {
            if (lvl[v]==0)
            {
                q.push(v);
                lvl[v] = lvl[u]+1;
                p[v] = u;
            }
        }
    }


}


int main()
{
    optimize();

    int n;
    bool b = false;

    while(cin>>n)
    {
        adj.clear();
        lvl.clear();
        p.clear();

        if (b) cout<<"\n";
        b=true;

        for (int i = 1; i <= n; ++i)
        {
            string u,v;
            cin>>u>>v;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        string s,d;
        cin>>s>>d;

        bfs(s);

        if (lvl[d]==0)
        {
            cout<<"No route"<<"\n";
        }
        else
        {
            vector<pair<string,string>>city;
            string child = d;
            while(!p[child].empty())
            {
                city.push_back({p[child],child});
                child=p[child];
            }

            reverse(city.begin(),city.end());

            for (auto x:city)
            {
                cout<<x.first<<" "<<x.second<<"\n";
            }
        }

        
      
    }

    return 0;
}