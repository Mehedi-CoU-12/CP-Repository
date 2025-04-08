#include<bits/stdc++.h>
using namespace std;


int main()
{
    int node;
    cin>>node;

    int edge=node-1;

    vector<int>tree[node+1];

    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for(auto it:tree)
    {
        for(auto jt:it)
        cout<<jt<<" ";
        cout<<endl;
    }

    auto findingLCA=[&](int a,int b){


    };

}