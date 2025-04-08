/*
    1. (A+B)%MOD=(A%MOD+B%MOD)%MOD
    2. (A*B)%MOD=(A%MOD*B%MOD)%MOD

    //but for the division that not work,so that's why we use modular inverse
    3. (A/B)%MOD=(A%MOD*(B^-1)%MOD)%MOD
        here B^-1 can be calculated as
        B^(MOD-2);

    so the final function will be
    (A/B)%MOD=(A%MOD * (B^(MOD-2))%MOD)%MOD;

    #caution:
    i.mod should be prime number
    ii.this function is also call farmatt theorem;
    iii. this function is mostly using for nCr combination
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=(int)1e6;
ll mod=1e9+7;

vector<ll>fact(N);

ll binaryExpo(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b%2==1)
        {
            res=(res*a)%mod;
            b--;
        }
        else
        {
            a=(a*a)%mod;
            b/=2;
        }
    }

    return res%mod;

}

ll modInverse(ll n)
{
    return binaryExpo(n,mod-2)%mod;
}

ll factorial1(ll n) 
{ 
    if (n == 0 || n == 1) 
        return 1; 

    return (n * factorial1(n - 1))%mod; 
}

void factorial()
{
    fact[0]=1;
    for(ll i=1;i<N;i++)
    fact[i]=(fact[i-1]*i)%mod;
}

ll nCr(ll n,ll r)
{
    //calculate the nCr 
    // nCr=n!/((n-r)!*r!);

    ll nn=fact[n]%mod;
    ll rr=(fact[n-r]*1LL*fact[r])%mod;

    ll ans=(nn * modInverse(rr))%mod;

    return ans;
}

int main() 
{
    ll n,r;
    cin>>n>>r;

    
    //factorial
    factorial();

    //binomial co-efficient
    cout<<nCr(n,r)<<endl;
}