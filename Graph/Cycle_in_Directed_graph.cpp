#include<bits/stdc++.h>
using namespace std;

bool dfs(int vertex,vector<vector<int>>&g,vector<int>&vis,vector<int>&pathVis)
{
    vis[vertex]=true;
    pathVis[vertex]=true;

    bool isCycle=false;
    for(auto child:g[vertex])
    {
        if(vis[child])
        {
            if(pathVis[child])
            return true;
            else
            continue;
        }

        isCycle|=dfs(child,g,vis,pathVis);
    }

    pathVis[vertex]=false;

    return isCycle;
}

int main()
{
    int node,edge;
    cin>>node>>edge;

    //directed graph;
    //here the logic part-> we keep two vector
    //vis ->for the visitation and another is 
    //pathVis -> is the path is visited before;

    //undirected graph
    //we need to check if the parent and vis[node] is same or not 
    //if same continue else cycle exist;

    vector<vector<int>>g(node);
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
    }

    vector<int>vis(node+10,0),pathVis(node+10,0);

    bool isCycle=false;

    for(int i=0;i<node;i++)
    {
        if(vis[i])
        continue;

        isCycle|=dfs(i,g,vis,pathVis);
    }

    if(isCycle)
    cout<<"Cycle exist in the graph"<<endl;
    else
    cout<<"Cycle does not exist"<<endl;
}