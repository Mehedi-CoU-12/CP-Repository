#include<bits/stdc++.h>
using namespace std;

void dfs(int vertex,vector<vector<int>>&g,vector<int>&vis,vector<int>&path)
{
    vis[vertex]=true;
    for(auto child:g[vertex])
    {
        if(vis[child])
        continue;

        dfs(child,g,vis,path);
    }

    path.push_back(vertex);
}

int main()
{
    /*
        topological sort
        1.graph should be DAG(Directed Acyclic Graph) (means graph should be directed and have no cycle)
        2.run a dfs then store the order
    */
    int node,edge;
    cin>>node>>edge;

    vector<vector<int>>g(node+1);
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
    }

    //find the topological order of the graph;
    vector<int>path,vis(node+5,0);
    for(int i=0;i<node;i++)
    {
        if(vis[i])
        continue;

        dfs(i,g,vis,path);
    }

    reverse(path.begin(),path.end());

    for(auto it:path)
    cout<<it<<" ";
    cout<<endl;
}