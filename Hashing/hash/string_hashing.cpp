#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
const long long mod=1e9+7;
const int P=31;

vector<long long >power(N);

void powerFunction(){
    power[0]=1;
    for(long long i=1;i<N;i++)
    power[i]=(power[i-1]*P)%mod;
}

long long hashing(string s)
{
    int n=s.size();
    long long hsh=0;
    
    for(int i=0;i<n;i++)
    {
        hsh=(hsh+(s[i]-'a'+1)*power[i])%mod;
    }

    return hsh;
}

int main(){
    /*
        given  a vector of string. calculate the number of distinct 
        string in the vector

        we can solve this using sorting algo or map. but here we will
        use hash function to do that
    */

   powerFunction();

   vector<string>v={"aa","a","ac","ac","acb","acbe","acde","abc","dd"};
   int n=v.size();

    vector<long long>hashing_string;
    for(auto it:v)
    hashing_string.push_back(hashing(it));

    sort(hashing_string.begin(),hashing_string.end());

    // for(auto it:hashing_string)
    // cout<<it<<" ";
    // cout<<endl;

    int distinct=1;
    for(int i=1;i<n;i++)
    {
        if(hashing_string[i]!=hashing_string[i-1])
        distinct++;
    }

    cout<<distinct<<endl;

    //overall time complexity: n*m + nlog(n) here m is string length
    // and n is vector size();
}