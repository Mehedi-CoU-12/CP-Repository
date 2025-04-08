#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter number of Node,Edge and root: "<<endl;
    int n,m,root;
    cin>>n>>m>>root;

    vector<int>g[n+1],vis(n+1,0),bfs;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int>q;
    q.push(root);
    vis[root]=1;

    bfs.push_back(root);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        for(auto child:g[node])
        {
            if(vis[child])
            continue;

            vis[child]=1;
            q.push(child);
            bfs.push_back(child);
        }
    }

    for(auto it:bfs)
    cout<<it<<" ";
    cout<<endl;

}