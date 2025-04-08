//*** kosaraju's Algorithms;
//find the strongly connected component of a graph(graph should be directed)
//1.find the finishing time
//2.reverse all edges
//3.run dfs and count or store the connected component

/* 
8 9
0 1
1 2
2 0         
2 3
3 4
4 7
4 5
5 6
6 4
*/

#include<bits/stdc++.h>
using namespace std;
#define output(v) for(auto it:v)cout<<it<<" ";cout<<endl;

void dfs(int vertex,vector<vector<int>>&g,vector<int>&vis,stack<int>&s)
{
    vis[vertex]=true;
    for(auto child:g[vertex])
    {
        if(vis[child])
        continue;

        dfs(child,g,vis,s);
    }

    s.push(vertex);
}

void dfs2(int vertex,vector<vector<int>>&gT,vector<int>&vis,vector<int>&component)
{
    vis[vertex]=true;
    for(auto child:gT[vertex])
    {
        if(vis[child])
        continue;

        dfs2(child,gT,vis,component);
    }

    component.push_back(vertex);
}

int main()
{
    int node,edge;
    cin>>node>>edge;

    vector<vector<int>>g(node),gT(node),ConnectedComponent;
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
    }

    vector<int>vis(node+5,0);
    stack<int>s,temp;

    //here stack s will give the finishing time;
    for(int i=0;i<node;i++)
    {
        if(vis[i])
        continue;

        dfs(i,g,vis,s);
    }

    // temp=s;
    // while(!temp.empty())
    // {
    //     cout<<temp.top()<<" ";
    //     temp.pop();
    // }
    // cout<<endl;


    //reversing all the edge;
    for(int i=0;i<node;i++)
    {
        vis[i]=0;
        for(auto it:g[i])
        gT[it].push_back(i);
    }

    //call the dfs;
    int stronglyConnectedComponent=0;
    while(!s.empty())
    {
        int vertex=s.top();
        s.pop();

        if(vis[vertex])
        continue;

        vector<int>component;
        stronglyConnectedComponent++;

        dfs2(vertex,gT,vis,component);
        ConnectedComponent.push_back(component);
        // output(component);
    }


    //printing the component;
    cout<<stronglyConnectedComponent<<endl;
    for(auto it:ConnectedComponent)
    {
        for(auto jt:it)
        cout<<jt<<" ";
        cout<<endl;
    }
}