#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define ff first
#define ss second
const int N = (int)1e6 + 5;
const int M=(int)1e8+5;
using namespace std;

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