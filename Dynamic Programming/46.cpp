/*
    problem: you are given an array.you have to find the longest bitonic 
    subsequence.

    bitonic subsequence: means it can be contained first increasing then 
    decreasing or just increasing or just decreasing or first decresing 
    then increasing
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &it:v)
    cin>>it;

    vector<int>dp_in(n,1),dp_dec(n,1);

    //for increasing subsequence
    for(int i=0;i<n;i++)
    {
        int len=0;
        for(int prev=0;prev<i;prev++)
        {
            if(v[prev]<v[i])
            len=max(len,dp_in[prev]);
        }

        dp_in[i]+=len;
    }

    //for decreasing subsequence
    for(int i=n-1;i>=0;i--)
    {
        int len=0;
        for(int prev=n-1;prev>i;prev--)
        {
            if(v[prev]<v[i])
            len=max(len,dp_dec[prev]);
        }

        dp_dec[i]+=len;
    }


    int ans=0;
    for(int i=0;i<n;i++)
    ans=max(ans,dp_in[i]+dp_dec[i]-1);

    cout<<ans<<endl;
} 
