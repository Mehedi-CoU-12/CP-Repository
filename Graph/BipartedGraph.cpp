//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
//check whether a graph is biparted or not

/*
    BipartedNess:
    1.any graph without having cycle
    2.graph having even cycle length
*/


// } Driver Code Ends
class Solution {
public:

    //using dfs
    bool dfs(int vertex,vector<int>g[],vector<int>&vis,int k)
    {
        //if already colored
        if(vis[vertex]!=-1)
        {
            //opposite color according to node;
            if(vis[vertex]==k)
            return true;
            //same color with as the node;
            else
            return false;
        }
        
        vis[vertex]=k;
        bool ok=true;
        
        for(int child:g[vertex])
        {
            //checking self loop
            if(vertex==child)
            return false;
            
            ok&=dfs(child,g,vis,(k+1)%2);
        }
        
        return ok;
    }

    //using bfs
    bool bfs(int n,vector<int>adj[])
    {
        queue<int>q;
        vector<int>color(n,-1);

        color[0]=0;
        q.push(0);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto child:adj[node])
            {
                //if the adjacency node is not yet colored.
                //i will give the opposite color
                if(color[child]==-1){
                    color[child]=!color[node];
                    q.push(child);
                }
                else if(color[child]==color[node])
                return false;
            }
        }

        return true;
    }


	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>vis(V+5,-1);
	    
	   
	    bool ok=true;
	    ok=dfs(0,adj,vis,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==-1)
	        ok&=dfs(i,adj,vis,0);
	    }
	    
	    return ok;
	}



};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends