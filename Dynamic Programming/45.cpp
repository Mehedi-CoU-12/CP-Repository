#include<bits/stdc++.h>
using namespace std;

bool check(string s,string t)
{
    map<char,int>m;
    for(auto it:s)
    m[it]++;

    for(auto it:t)
    m[it]--;

    // cout<<s<<" "<<t<<endl;

    // for(auto it:m)
    // cout<<it.first<<" "<<it.second<<endl;
    // cout<<endl<<endl;

    for(auto it:m)
    {
        if(it.second>=1)
        return false;
    }

    return true;
}

int n;
int lsc(int i,int prev,vector<pair<int,string>>&v,vector<vector<int>>&dp)
{

    if(i>=n)
    return 0;

    if(dp[i][prev+1]!=-1)
    return dp[i][prev+1];


    int notTake=lsc(i+1,prev,v,dp);

    int take=0;
    if(prev==-1)
    {
        take=1+lsc(i+1,i,v,dp);
    }
    else if(v[prev].first+1==v[i].first)
    {
        if(check(v[prev].second,v[i].second))
        take=1+lsc(i+1,i,v,dp);
    }

    return dp[i][prev+1]= max(take,notTake);
}

int main()
{
    cin>>n;

    vector<pair<int,string>>v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i].second;
        v[i].first=v[i].second.size();
    }

    sort(v.begin(),v.end());

    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

    cout<<lsc(0,-1,v,dp)<<endl;

    // for(auto it:dp)
    // {
    //     for(auto i:it)
    //     cout<<i<<" ";
    //     cout<<endl;
    // }
}