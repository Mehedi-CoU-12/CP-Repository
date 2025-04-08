/*
    problem: you are given two string s and t. you have to convert string s into t.
    you have the following operation,
    
    1.insert (insert any character in any position)
    2.replace (replace any character with any character)
    3.remove (remove any character)

    you have to tell minimum number of opertation need to convert string s to t;

    ex: s="horse" and t="ros"

    1->rorse (replace h with r)
    2->rose (remove r)
    3->ros (remove e)

    so the answer for the testcase is 3
*/

#include<bits/stdc++.h>
using namespace std;

int minimumNumberOfOpertation(int i,int j,string s,string t,vector<vector<int>>dp)
{
    if(i<0)
    return j+1;

    if(j<0)
    return i+1;

    if(dp[i][j]!=-1)
    return dp[i][j];

    if(s[i]==t[j])
    return dp[i][j]= minimumNumberOfOpertation(i-1,j-1,s,t,dp);
    else
    {
        int insrt=1+minimumNumberOfOpertation(i,j-1,s,t,dp);
        int replace=1+minimumNumberOfOpertation(i-1,j-1,s,t,dp);
        int remove=1+minimumNumberOfOpertation(i-1,j,s,t,dp);

        return dp[i][j]= min({insrt,replace,remove});
    }
}

int main()
{
    string s,t;
    cin>>s>>t;

    int n=s.size();
    int m=t.size();

    vector<vector<int>>dp(n,vector<int>(m,-1));

    cout<<minimumNumberOfOpertation(n-1,m-1,s,t,dp)<<endl;
}