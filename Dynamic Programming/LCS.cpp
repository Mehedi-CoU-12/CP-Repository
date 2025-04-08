/*
    this problem can be solved using LIS concept;
    -> we will insert all the index of character in string a to b.
    here is an example->:

    string a="abxy"
       index->1234

    string b="aacbzkly"

    now in string b we will consider such character which is present in both string

    now string b will be reduced to b="aaby" ->remove "czly" from b

    make an array of index-1 1 2 4

    here longest increasing subsequence is 1 2 4 which is refer to "aby";
*/

#include<bits/stdc++.h>
using namespace std;

//lis using binary search
vector<int> longest_increasing_subsequence(vector<int>v)
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
            auto it=lower_bound(lis.begin(),lis.end(),v[i]);
            *it=v[i];
            final_lis[i]=it-lis.begin()+1;
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

    return ans;
}

//LCS using LIS
void LCS_using_LIS(string a,string b)
{
    map<int,char>indexWithChar;
    map<char,vector<int>>charWithIndex;

    int n=a.size();
    int m=b.size();

    for(int i=0;i<n;i++)
    {
        indexWithChar[i]=a[i];
        charWithIndex[a[i]].push_back(i);
    }

    vector<int>v;
    for(auto it:b)
    {
        vector<int>tmp=charWithIndex[it];

        reverse(tmp.begin(),tmp.end());

        for(auto jt:tmp)
        v.push_back(jt);
    }

    vector<int>index=longest_increasing_subsequence(v);

    string ans;
    for(auto it:index)
    ans.push_back(indexWithChar[it]);

    cout<<ans<<endl;
}

//lcs length using recursion
int LCS(int i,int j,string &a,string &b,vector<vector<int>>&dp)
{
    if(i<0 or j<0)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    if(a[i]==b[j])
    return 1+LCS(i-1,j-1,a,b,dp);

    int upString=LCS(i-1,j,a,b,dp);
    int downString=LCS(i,j-1,a,b,dp);

    return dp[i][j]= max(upString,downString);
}

void LCS_Length(string a,string b)
{
    int n=a.size();
    int m=b.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    cout<<LCS(n-1,m-1,a,b,dp)<<endl;
}

//lcs using tabulation technique
void LCS_using_tabulation(string a,string b)
{
    int n=a.size();
    int m=b.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j])
            dp[i+1][j+1]=1+dp[i][j];
            else
            dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        }
    }

    string ans;
    int i=n,j=m;
    while(i>0 and j>0)
    {
        if(a[i-1]==b[j-1])
        {
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
        else if(dp[i][j-1]>dp[i-1][j])
        j--;
        else
        i--;
    }

    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}

int main()
{
    string a,b;
    cin>>a>>b;

    LCS_using_LIS(a,b);
    LCS_Length(a,b);
    LCS_using_tabulation(a,b);
}
