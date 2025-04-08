/*
    you are given an array of stocks.
    
*/

#include<bits/stdc++.h>
using namespace std;

int n;


int maxProfit1(vector<int>v)
{
    int profit=0,mn=INT_MAX;
    for(int i=0;i<n;i++)
    {
        mn=min(mn,v[i]);

        profit=max(profit,v[i]-mn);
    }

    return profit;
}

int maxProfit2(int i,bool buy,vector<int>&v,vector<vector<int>>&dp)
{
    if(i>=n)
    return 0;

    if(dp[i][buy]!=-1)
    return dp[i][buy];

    int profit=INT_MIN;

    if(buy)
    {
        int take=-v[i]+maxProfit2(i+1,false,v,dp);
        int notTake=maxProfit2(i+1,buy,v,dp);

        return dp[i][buy]= max(take,notTake);
    }
    else
    {
        int take=v[i]+maxProfit2(i+1,true,v,dp);
        int notTake=maxProfit2(i+1,buy,v,dp);

        return dp[i][buy]= max(take,notTake);
    }

}

int maxProfit3(int i,bool buy,int cap,vector<int>&v,vector<vector<vector<int>>>&dp)
{
    if(cap==0 or i>=n)
    return 0;

    if(dp[i][buy][cap]!=-1)
    return dp[i][buy][cap];

    if(buy)
    {
        int take=-v[i]+maxProfit3(i+1,0,cap,v,dp);
        int notTake=maxProfit3(i+1,buy,cap,v,dp);

        dp[i][buy][cap]= max(take,notTake);
    }
    else
    {
        int take=v[i]+maxProfit3(i+1,1,cap-1,v,dp);
        int notTake=maxProfit3(i+1,buy,cap,v,dp);

        dp[i][buy][cap]= max(take,notTake);
    }
}

int maxProfit4(int i,bool buy,int cap,vector<int>&v,vector<vector<vector<int>>>&dp)
{
    if(cap==0 or i>=n)
    return 0;

    if(dp[i][buy][cap]!=-1)
    return dp[i][buy][cap];

    if(buy)
    {
        int take=-v[i]+maxProfit4(i+1,0,cap,v,dp);
        int notTake=maxProfit4(i+1,buy,cap,v,dp);

        return dp[i][buy][cap]=max(take,notTake);
    }
    else
    {
        int take=v[i]+maxProfit4(i+1,1,cap-1,v,dp);
        int notTake=maxProfit4(i+1,buy,cap,v,dp);

        return dp[i][buy][cap]=max(take,notTake);
    }
}

int maxProfit5(int i,bool buy,vector<int>&v,vector<vector<int>>&dp)
{
    if(i>=n)
    return 0;

    if(dp[i][buy]!=-1)
    return dp[i][buy];

    if(buy)
    {
        int take=-v[i]+maxProfit5(i+1,0,v,dp);
        int notTake=maxProfit5(i+1,buy,v,dp);

        return dp[i][buy]=max(take,notTake);
    }
    else
    {
        int take=v[i]+maxProfit5(i+2,1,v,dp);
        int notTake=maxProfit5(i+1,buy,v,dp);

        return dp[i][buy]=max(take,notTake);
    }
}

int main()
{
    cin>>n;

    vector<int>v(n);
    for(auto &it:v)
    cin>>it;

    vector<vector<int>>dp2(n,vector<int>(2,-1)),dp5(n,vector<int>(2,-1));
    vector<vector<vector<int>>>dp3(n,vector<vector<int>>(2,vector<int>(3,-1)));

    //for maxProfit4 problem;
    int k;
    cin>>k;
    vector<vector<vector<int>>>dp4(n,vector<vector<int>>(2,vector<int>(k+1,-1)));

    cout<<maxProfit1(v)<<endl;
    cout<<maxProfit2(0,true,v,dp2)<<endl;
    cout<<maxProfit3(0,1,2,v,dp3)<<endl;
    cout<<maxProfit4(0,1,k,v,dp4)<<endl;
    cout<<maxProfit5(0,1,v,dp5)<<endl;
}