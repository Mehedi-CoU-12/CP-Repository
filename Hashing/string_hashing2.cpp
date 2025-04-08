#include<bits/stdc++.h>
using namespace std;


const int p=31;
const int N=1e5+6;
const long long mod=1e9+7;

vector<long long>power(N),hash_string;

long long binary_expo(long a,long b)
{
    long long res=1;
    while(b)
    {
        if(b%2)
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

    return res;
}

void powerFunction()
{   
    power[0]=1;
    for(long long i=1;i<N;i++)
    power[i]=(power[i-1]*i*1LL)%mod;
}

//calculate the hash_value for every substring  from 0 to n;
void hashing(string s)
{
    int n=s.size();

    long long hash_value=0;
    hash_string.push_back(0);

    for(int i=0;i<n;i++)
    {
        long long value=((s[i]-'a'+1)*power[i]%mod);
        hash_value=(hash_value+value)%mod;

        hash_string.push_back(hash_value);
    }
}

int main()
{
    /*
        Determine the number of different substrings in a string

        
    */


   string s="abcdeabcdea";
   int n=s.size();

   //======generate all the substrings  of a string;

    //i.======brute-force approach; 
    // set<string>st;
    // for(int i=0;i<n;i++)
    // {
    //     string subs;

    //     for(int j=i;j<n;j++)
    //     {
    //         subs+=s[j];
    //         st.insert(subs);
    //     }
    // }

    // cout<<st.size()<<endl;
   
    //ii.======hashing================
    
    powerFunction();
    hashing(s);

    int cnt=0;

    for(int l=1;l<=n;l++)
    {
        set<long long>st;
        for(int i=0;i<=n-l;i++)
        {
            long long value=(hash_string[i+l]-hash_string[i])%mod;

            value=(value*1LL*binary_expo(power[i],mod-2))%mod;
            st.insert(value);
        }

        cnt+=st.size();
    }

    cout<<cnt<<endl;
}