#include<bits/stdc++.h>
const int N =(int)1e7+10;
#define ll long long int
using namespace std;

//upto 10^8
bool notPrime[100000005];
void sieve2(){

    for (int i = 3; i <= 10000; i += 2)
    {
        if (notPrime[i] == 0)
        {
            for (int j = i * i; j <= 10000000; j += i + i)
            notPrime[j]=1;
        }
    }
    prime.push_back(2);
    for (int i = 3; i <= 10000000; i += 2)
        if (notPrime[i] == 0)
            prime.push_back(i);

    // cout<<prime.back()<<endl;
    // cout<<prime.size()<<endl;
}

//sieve algorithm;
vector<int>isPrime(N,1),prime,primeDivisor;
void sieve()
{
    for(int i=2;i<N;i++)
    {
        if(isPrime[i])
        {
            prime.push_back(i);    //find all the prime number between 10^6;

            for(int j=2*i;j<N;j+=i)
            isPrime[j]=false;
        }
    }
}


vector<ll> primeFactorization(int n)  //divide any number with prime number;
{                               // such as 180 =2 2 3 3 5
    //prime factorization;
    vector<ll>prime_divisor;
    for(int i=0;prime[i]<=sqrt(n);i++)
    {
        if(n%prime[i]==0)
        {
            // primeDivisor.push_back(prime[i]);

            while(n%prime[i]==0){
                prime_divisor.push_back(prime[i]);
                n/=prime[i];
            }
        }
    }

    if(n!=1){
        prime_divisor.push_back(n);
    }

    return prime_divisor;
}

int main()
{
    sieve2();

}