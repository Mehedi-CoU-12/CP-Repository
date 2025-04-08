/*
    problem: you are given two string s,t. you have to tell how many time
    string t apear in string s as a subsequence.

    ex:   s=bagbag  t=bag
        here t=bag appear in s=bagbag 3 times
*/

#include<bits/stdc++.h>
using namespace std;

int numberOfWays(int i,int j,string s,string t,vector<vector<int>>&dp)
{
    if(j<0)
    return 1;

    if(i<0)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];


    if(s[i]==t[j])
    {
        int count=numberOfWays(i-1,j-1,s,t,dp);
        int notCount=numberOfWays(i-1,j,s,t,dp);

        return dp[i][j]= count+notCount;
    }
    else
    return dp[i][j]= numberOfWays(i-1,j,s,t,dp);
}

int main()
{
    string s,t;
    cin>>s>>t;

    int n=s.size();
    int m=t.size();

    vector<vector<int>>dp(n,vector<int>(m,-1));

    cout<<numberOfWays(n-1,m-1,s,t,dp)<<endl;
}