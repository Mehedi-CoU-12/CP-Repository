/*
    problem: you are given an array. print the longest increasing subsequence.
*/

#include<bits/stdc++.h>
using namespace std;

// recursion O(n*n)

int lis(int i,int prev,vector<int>&v,vector<vector<int>>&dp)
{
    if(i<0)
    return 0;


    if(prev==-1 or v[i]<v[prev])
    {
        int take=1+lis(i-1,i,v,dp);
        int notTake=lis(i-1,prev,v,dp);

        return max(take,notTake);
    }
    else
    return lis(i-1,prev,v,dp);
}


//binary search O(nlogn)

int lis_using_binary_search(vector<int>v)
{
    vector<int>lis;
    lis.push_back(v[0]);

    for(int i=1;i<v.size();i++)
    {
        if(lis.back()<v[i])
        lis.push_back(v[i]);
        else
        {
            int ind=lower_bound(lis.begin(),lis.end(),v[i])-lis.begin();

            lis[ind]=v[i];
        }
    }

    return lis.size();
}

//tabulation O(n*n)

int lis_tabulation(vector<int>v)
{
    int n=v.size();
    vector<int>dp(n,1);

    int len=1;

    for(int i=0;i<n;i++)
    {
        int mx=0;
        for(int prev=0;prev<i;prev++)
        {
            if(v[prev]<v[i]){
                mx=max(mx,dp[prev]);
            }
        }

        dp[i]+=mx;
        len=max(len,dp[i]);
    }

    return len;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);

    for(auto &it:v)
    cin>>it;

    vector<vector<int>>dp(n,vector<int>(n,-1));

    cout<<lis(n-1,-1,v,dp)<<endl;

    cout<<lis_using_binary_search(v)<<endl;

    cout<<lis_tabulation(v)<<endl;
}