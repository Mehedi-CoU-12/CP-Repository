/*
    you're given an array and a target sum . you have to check wheather it is possible to 
    make a subsequence of sum of the target or not;
*/

#include<bits/stdc++.h>
using namespace std;

//recursive way to solve the problem;
// time complexity:O(n*m);
bool subsetSum(int ind,int target,vector<int>&v,vector<vector<int>>&dp){
    if(target==0)
    return true;

    if(ind<0)
    return false;

    if(dp[ind][target]!=-1)
    return dp[ind][target];

    bool not_take=subsetSum(ind-1,target,v,dp);

    bool take=false;
    if(target-v[ind]>=0)
    take=subsetSum(ind-1,target-v[ind],v,dp);

    return dp[ind][target]=(take|not_take);
}

//time complexity: O(n*m/64)
//subset sum using bitset

bool subset_sum_using_bitset(vector<int>v,int target){
    //m could be 1e6 as well.
    const int m=1e5;
    bitset<m>b;

    b[0]=1;
    for(auto it:v){
        b|=(b<<it);
    }

    if(b[target])
    return true;
    else
    return false;
}

int main(){

}