#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
const int N = (int)1e6 + 5;
#define yes cout<<'Y'<<'E'<<'S'<<endl
#define no cout<<'N'<<'O'<<endl
#define tst int t;cin>>t;while(t--)
using namespace std;
bool plndrm=true;
vector<int>temp;
int k,sum=4,p=0,n;

// //check a string is palindrome or not;
bool check(string s,int i)
{
    int n=s.size();

        // base case;
    if(i>=n/2)
    return true;

    if(s[i]==s[n-i-1])
    return check(s,i+1);

    return false;
}

//print all the subsequence of an array
void print_subsequence(vector<int>v,int i)
{   
    int n=v.size();

    if(i==n)
    {
        for(auto it:temp)
        cout<<it<<" ";
        cout<<endl;

        return ;
    }
    //pick the index value
    temp.push_back(v[i]);
    print_subsequence(v,i+1);

    //not picking up the index value
    temp.pop_back();
    print_subsequence(v,i+1);
}

int main()
{
    // string s;
    // cin>>s;

    // bool ok=check(s,0);
    // if(ok)
    // yes;
    // else
    // no;

    cin>>n>>k;
    vector<int>v(n);

    for(auto &it:v)
    cin>>it;

    //generating subsequence using bit manipulation;

    // ll len=pow(2,n);

    // for(int i=1;i<=len;i++)
    // {
    //     // cout<<"{ ";
    //     for(int j=0;j<n;j++)
    //     {
    //         if((1<<j)& i)
    //         cout<<v[j]<<' ';
    //     }
    //     cout<<" }"<<endl;
    // }


    print_subsequence(v,0);
}