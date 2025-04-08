#include<bits/stdc++.h>
using namespace std;

vector<int>v;
vector<vector<int>>dp;

int minCoinChange(int ind,int target)
{
    if(ind==0)
    {
        if(target%v[ind]==0)
        return target/v[ind];
        else
        return 1e9;
    }
    //not Take
    int notTake=minCoinChange(ind-1,target);
    //take

    int take=INT_MAX;

    if(v[ind]<=target)
    take=1+minCoinChange(ind,target-v[ind]);

    return min(take,notTake);
}

int main()
{

}