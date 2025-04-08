#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>v;

//using recursion print only one statement-:
//given an array and k. find a sum where sum can be 
//divisible by k and the print the subsequence and retrun;
//arr[]={1,3,4} and k=3 ouput:{3}

bool find_subsequence(int i,vector<int>&ds,int sum)
{
    if(i==n)
    {
        if(sum%k==0)
        {
            for(auto it:ds)
            cout<<it<<" ";
            cout<<endl;

            return true;
        }

        return false;
    }

    sum+=v[i];
    ds.push_back(v[i]);

    // if(find_subsequence(i+1,ds,sum)==true)
    // return true;

    bool pick=find_subsequence(i+1,ds,sum);

    if(pick)
    return true;

    sum-=v[i];
    ds.pop_back();

    bool notPick=find_subsequence(i+1,ds,sum);
    if(notPick)
    return true;

    // if(find_subsequence(i+1,ds,sum)==true)
    // return true;
}

int main(){

}