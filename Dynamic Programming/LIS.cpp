#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define yes cout<<'Y'<<'E'<<'S'<<endl
#define no cout<<'N'<<'O'<<endl
#define tst int t;cin>>t;while(t--)
const int N = (int)1e6 + 5;
const int M=(int)1e8+5;
using namespace std;

//============================== lis(dp) =============================================
//tc= n*n;
int longest_increasing_subsequence(int i,int prev_i,int n,vector<int>&v,vector<vector<int>>&dp)
{
    if(i==n)
    return 0;

    if(dp[i][prev_i+1]!=-1)
    return dp[i][prev_i+1];

    int pick=0,notPick=0;
    notPick=0+longest_increasing_subsequence(i+1,prev_i,n,v,dp);

    if(prev_i==-1 or v[prev_i]<v[i])
    pick=1+longest_increasing_subsequence(i+1,i,n,v,dp);

    return dp[i][prev_i+1] = max(pick,notPick);
}


//========================== lis(binary search) ===================================== 
    //tc=nlog(n);
    //longest decreasing subsequence just multiplies all elements with -1;
    
int longest_increasing_subsequence(vector<int>v)
{
    
    vector<int>lis,final_lis(v.size()),ans;
    
    for(int i=0;i<v.size();i++)
    {
        if(lis.empty() or lis.back()<v[i])
        {
            lis.push_back(v[i]);
            final_lis[i]=lis.size();
        }
        else
        {
            //use upper bound for equal elements
            int index=lower_bound(lis.begin(),lis.end(),v[i])-lis.begin();

            lis[index]=v[i];
            final_lis[i]=index+1;
        }
    }

   
    int len=lis.size();//length of the subsequence;

    //print the longest increasing subsequence 
    for(int i=final_lis.size()-1;i>=0;i--)
    {
        if(final_lis[i]==len)
        {
            ans.push_back(v[i]);
            len--;
        }
    }

    reverse(ans.begin(),ans.end());

    for(auto it:ans)
    cout<<it<<" ";
    cout<<endl;
}

int main()
{
    ll n;
    cin>>n;

    vector<int>v(n);

    for(auto &it:v)
    cin>>it;

    longest_increasing_subsequence(v);
}