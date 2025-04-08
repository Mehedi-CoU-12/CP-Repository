#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
const int N = (int)1e6 + 5;
#define yes cout<<'Y'<<'E'<<'S'<<endl
#define no cout<<'N'<<'O'<<endl
#define tst int t;cin>>t;while(t--)
using namespace std;

//top down operation or backtraking;
int fib(int n,vector<int>&dp)
{
    if(n<=1)
    return n;

    if(dp[n]!=-1)
    return dp[n];

    int left=fib(n-1,dp);
    int right=fib(n-2,dp);

    dp[n]=left+right;

    return dp[n];
}

int main()
{
    int n;
    vector<int>dp(n+5,-1),dp2(n+5);
    cin>>n;
    cout<<fib(n,dp)<<endl;

    //now calculating the same problem with bottom up or tabular form;
    dp2[0]=0;
    dp2[1]=1;

    for(int i=2;i<=n;i++)
    dp2[i]=dp2[i-1]+dp2[i-2];

    cout<<dp2[n]<<endl;
}