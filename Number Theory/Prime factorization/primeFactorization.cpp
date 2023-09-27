
#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


const int mx = 1e8+10;
bitset<mx> is_prime;
vector<int> prime;

void primeGen(int n)
{
   // memset(is_prime,1,sizeof(is_prime));
    //is_prime[1]= 0;

    for (int i = 3; i <= n; i+=2)
    {
         is_prime[i]= 1;
    }

    for (int i = 3; i*i <= n; i+=2)
    {
        if (is_prime[i]== 1)
        {
            for (int j = i*i; j <= n; j+=i*2)
            {
                is_prime[j]= 0;
            }
        }

    }

    is_prime[2]= 1;
    prime.push_back(2);
    for (int i = 3; i <= n; i+=2)
    {
        if (is_prime[i]==1)
        {    
            prime.push_back(i);
        }
    }

 
}

vector<long long> factorization(long long n)
{
    vector<long long> ret;

    for (auto p:prime)
    {
        if (1LL*p*p > n)
        {
            break;
        }

        if (n%p == 0 )
        {
            while(n%p == 0)
            {
                ret.push_back(p);
                n/=p;
            }
        }
    }
    if (n>1)
    {
        ret.push_back(n);
    }
    return ret;
}


int main()
{
    optimize();
    int lim = 1e7;
    primeGen(lim);

    long long n;  //n=1e14 root(n) = 1e7;
    cin>>n;

    vector<long long> ans;
    ans = factorization(n);

    for (auto p:ans)
    {
        cout<<p<<" ";
    }
    return 0;
}