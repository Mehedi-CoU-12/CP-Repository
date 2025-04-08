#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,edge,source;
    cin>>n>>edge>>source;
    
    vector<vector<pair<int,int>>>g(n+1);
    for(int i=0;i<edge;i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;

        g[u].push_back({v,weight});
        g[v].push_back({u,weight});
    }
    
    //we can use "set" instead of priority queue as well
    priority_queue<int,vector<pair<int,int>>,greater<pair<int,int>> >pq;
    vector<int>dis(n+1,1e9),par(n+1,0);

    for(int i=0;i<=n;i++)
    par[i]=i;

    //0 is considered as a source node;
    dis[source]=0;
    pq.push({0,source});
    par[source]=0;

    while(!pq.empty())
    {
        int node=pq.top().second;
        int path=pq.top().first;
        pq.pop();

        for(auto it:g[node])
        {
            int curDis=it.second;
            int curNode=it.first;

            if(path+curDis>=dis[curNode])
            continue;

            dis[curNode]=path+curDis;
            pq.push({dis[curNode],curNode});

            //for finding the path from source to destination;
            par[curNode]=node;
        }
    }

    //all shortest path_distance from source vertex 0 ;
    for(int i=0;i<n;i++)
    cout<<dis[i]<<" ";
    cout<<endl;

    //print the path from source to destination ;
    int des=3;
    cin>>des;

    cout<<des<<" ";
    while(source!=par[des])
    {
        cout<<par[des]<<" ";
        des=par[des];
    }
    cout<<endl;
}