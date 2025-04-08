#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
const int N = (int)1e6 + 5;
#define yes cout<<'Y'<<'E'<<'S'<<endl
#define no cout<<'N'<<'O'<<endl
#define tst int t;cin>>t;while(t--)
using namespace std;
int n,m;


string dir="RDLU";
int di[]={0,1,0,-1};
int dj[]={1,0,-1,0};

// //given an array find the target sum from the array and you can use any index any time you want;
int number_subsequence(vector<ll>v,int i,int sum)
{
    int n=v.size();

    if(i==n)
    {
        if(sum==0)
        return 1;
        else
        return 0;
    }

    int left=0,right=0;

    //pick the same index more than 1 time;
    if(v[i]<=sum)
    {
        sum-=v[i];
        left=number_subsequence(v,i,sum);
    
        sum+=v[i];
    }
    //goto the next index;
    right=number_subsequence(v,i+1,sum);

    return left+right;
}

//given an 2d array we can move left,right,up and down. print all the possible path to go (n,m )cell;
//don't use same cell twice in the path 
void findThePath(int i,int j,string s,vector<vector<int>>&vis)
{
    if(i>=n or j>=m or i<0 or j<0 or vis[i][j])
    return;

    if(i==n-1 and j==m-1)
    {
        cout<<s<<endl;
        return;
    }

    
    vis[i][j]=1;

    for(int x=0;x<4;x++)
    {
        s+=dir[x];
        findThePath(i+di[x],j+dj[x],s,vis);
        s.pop_back();
    }

    vis[i][j]=0;

}

int main()
{
    
    // int n,sum;
    // cin>>n>>sum;

    // vector<ll>v(n);
    // for(auto &it:v)
    // cin>>it;

    // cout<<number_subsequence(v,0,sum)<<endl;

    cin>>n>>m;

    vector<vector<int>>vis(n,vector<int>(m,0));

    
    string s="";

    findThePath(0,0,s,vis);
}