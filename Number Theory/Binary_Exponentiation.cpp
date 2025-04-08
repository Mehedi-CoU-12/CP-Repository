#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll pw(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b%2==1)
        {
            res*=a;
            b--;
        }
        else
        {
            a*=a;
            b/=2;
        }
    }

    return res;
}

ll power(ll a,ll b)
{
    if(b==0)
    return 1;

    ll res=power(a,b/2);

    if(b%2)
    return res*res*a;
    else
    return res*res;
}

int main()
{
    ll n;
    cin>>n;

    cout<<power(n,n)<<endl; 
}