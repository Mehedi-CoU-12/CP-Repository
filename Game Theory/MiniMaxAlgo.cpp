/*
                12           ----maximizer

         5            12       ---->minimizer

      5     9     12     23     ---->maximizer

    3, 5, 2, 9, 12, 5, 23, 23
*/

#include<bits/stdc++.h>
using namespace std;

int miniMaxAlgo(int depth,int nodeIndex,bool turn,vector<int>&v,int height)
{
    if(height==depth)
    return v[nodeIndex];

    //maximizer turn's
    if(turn)
    {
        int left=miniMaxAlgo(depth+1,2*nodeIndex,false,v,height);
        int right=miniMaxAlgo(depth+1,2*nodeIndex+1,false,v,height);

        return max(left,right);
    }
    else
    {
        int left=miniMaxAlgo(depth+1,2*nodeIndex,true,v,height);
        int right=miniMaxAlgo(depth+1,2*nodeIndex+1,true,v,height);

        return min(left,right);
    }
}

int log2(int n)
{
    if(n==1)
    return 0;
    else
    return 1+log2(n/2);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &it:v)
    cin>>it;

    int height=log2(n);

    // cout<<height<<endl;

    cout<<miniMaxAlgo(0,0,true,v,height)<<endl;
}