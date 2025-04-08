#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,0);

        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    //finding ultimate parent
    int findUltimateParent(int node)
    {
        if(node==parent[node])
        return node;
        
        //path compression
        return parent[node]=findUltimateParent(parent[node]);
    }

    //adding two nodes by rank
    void unionByRank(int u,int v)
    {
        int ultimate_u=findUltimateParent(u);
        int ultimate_v=findUltimateParent(v);

        if(rank[ultimate_u]<rank[ultimate_v]){
            parent[ultimate_u]=ultimate_v;
        }
        else if(rank[ultimate_u]>rank[ultimate_v]){
            parent[ultimate_v]=ultimate_u;
        }
        else
        {
            parent[ultimate_v]=ultimate_u;
            rank[ultimate_u]++;
        }
    }

    //adding two nodes by size
    void unionBySize(int u,int v){
        int ultimate_u=findUltimateParent(u);
        int ultimate_v=findUltimateParent(v);

        if(ultimate_u==ultimate_v)
        return ;

        if(size[ultimate_u]<size[ultimate_v]){
            parent[ultimate_u]=ultimate_v;
            size[ultimate_v]+=size[ultimate_u];
        }
        else{
            parent[ultimate_v]=ultimate_u;
            size[ultimate_u]+=size[ultimate_v];
        }
    }
};

/*
    ##union(u,v)
    1.find ultimate parent of u and v, pu,pv
    2.find rank of pu,pv
    3.connect smaller rank to higher rank always
*/

int main()
{
    // int n,edge;
    // cin>>n>>edge;

    DisjointSet ds(7);
    
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"same\n";
    }
    else
    cout<<"Not same\n";

    ds.unionBySize(3,7);

    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"same\n";
    }
    else
    cout<<"Not same\n";

}