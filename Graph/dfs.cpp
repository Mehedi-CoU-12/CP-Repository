#include<bits/stdc++.h>
using namespace std;

/*
7 16

1 2 
1 6
2 1
2 3
2 4
2 5
3 2
3 6
4 2
4 5
5 2 
5 4
6 1
6 3
6 7
7 6


*/

void dfs(int vertex,vector<int>g[],vector<int>&vis)
{
    vis[vertex]=true;
    for(auto child:g[vertex])
    {
        if(vis[child])
        continue;
        
        dfs(child,g,vis);
    }
}

void solve(){
    int node,edge;
    cin>>node;

    edge=node-1;

    vector<int>vis(node+10,0),g[node+10];
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0,g,vis);
}
int main(){
    int t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}