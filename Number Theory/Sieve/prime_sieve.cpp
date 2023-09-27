
#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


const int mx = 1e8+123;
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
int main()
{
    int n = 1e8;
    //cin>>n;
    primeGen(n);

    int sz = prime.size();
    for (int i = 0; i < sz; i+=100)
    {
        cout<<prime[i]<<" ";
    }

   // cout<<sz<<"\n";
    return 0;
}