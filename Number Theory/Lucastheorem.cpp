#include<bits/stdc++.h>
using namespace std;

int fact(int n,int p)
{
    int f=1;
    for(int i=1;i<=n;i++)
    {
        f=(f*i)%p;
    }

    return f;
}

long long binaryExpo(long long a,long long b,long long mod)
{
    long long res=1;
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

long long modInverse(long long n,long long p)
{
    return binaryExpo(n,p-2,p)%p;
}

int nCr(int n,int r,int p)
{
    if(r>n)
    return 0;

    int factN=fact(n,p);
    int factR=fact(r,p);
    int factN_R=fact(n-r,p);

    return (factN*modInverse(factR,p)*modInverse(factN_R,p))%p;
}

int lucastheorem(int n,int r,int p)
{
    if(r==0)
    return 1;

    int ni=n%p;
    int ri=r%p;

    int lucas=lucastheorem(n/p,r/p,p);
    int nCrValue=nCr(ni,ri,p);

    return (lucas*nCrValue)%p;
}

int nCkmod10(int n,int r)
{
    int mod2=lucastheorem(n,r,2);
    int mod5=lucastheorem(n,r,5);

    //here we can use chinese remainder theorem as well
    for(int i=0;i<10;i++)
    {
        if(i%2==mod2 and i%5==mod5)
        return i;
    }

    return 0;
}



int main(){

}