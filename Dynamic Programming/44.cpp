/*
    problem: you are given an array. find the longest divisible subset

    divisible subset means- any two element in the subset must be divisible by one 
    another a[i]%a[j]==0 or a[j]%a[i]==0

    caution: we can not do it in using binary search
*/

#include<bits/stdc++.h>
using namespace std;

int lds(int i,int prev,vector<int>&v)
{
    if(i<0)
    return 0;

    int notTake=0+lds(i-1,prev,v);

    int take=0;
    if(prev==-1 or v[prev]%v[i]==0)
    take=1+lds(i-1,i,v);

    return max(take,notTake);
}

int main()
{
    int n;
    cin>>n;

    vector<int>v(n);
    for(auto &it:v)
    cin>>it;

    sort(v.begin(),v.end());

    cout<<lds(n-1,-1,v)<<endl;
}