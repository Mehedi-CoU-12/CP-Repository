/*
    Problem: you are given two string s and t. you have to tell wheather s and t 
    are matching or not. string s can contain '?' and '*'. here '?' means you can
    match any character of string t with this '?' mark and '*' means you can match 
    0 character or a whole substring with it

    now you have to tell both are equal or not;
*/

#include<bits/stdc++.h>
using namespace std;

bool check(int i,int j,string &s,string &t,vector<vector<int>>&dp)
{
    if(i<0 and j<0)
    return true;

    if(j<0)
    {
        for(int k=i;k>=0;k--)
        {
            if(s[k]!='*')
            return false;
        }

        return true;
    }

    if(i<0)
    return false;

    if(dp[i][j]!=-1)
    return dp[i][j];

    bool ok=false;

    if(s[i]==t[j] or s[i]=='?')
    ok|= check(i-1,j-1,s,t,dp);
    else if(s[i]=='*')
    {
        for(int k=j;k>=0;k--)
        ok|= check(i-1,k,s,t,dp);
    }
    else
    ok|= false;

    return dp[i][j]= ok;
}

int main()
{
    string s,t;
    cin>>s>>t;

    int n=s.size();
    int m=t.size();

    vector<vector<int>>dp(n,vector<int>(m,-1));

    cout<<check(n-1,m-1,s,t,dp)<<endl;
}