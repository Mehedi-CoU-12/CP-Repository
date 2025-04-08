#include <bits/stdc++.h>
using namespace std;

/*
    this algorithm is used for finding the kth ancestor of any node in 
    log(n) time.

    bruteForce:
    while(k--)
    v=parent[v];

    let's say you want to find the 19th ancestor of a node.
    now instead of going 19 times you can do as follows

    k=19=16+2+1     go for 16th parent then 2nd then 1st.
*/

const int MAXN = 100005; // Adjust as necessary
const int LOG = 22; // log2(MAXN) ~ 17 for 100000 nodes

vector<vector<int>> g(MAXN); // Adjacency list of the tree
vector<vector<int>> up(MAXN, vector<int>(LOG)); // up[i][j] stores the 2^j-th ancestor of node i
vector<int> depth(MAXN); // Depth of each node

// DFS to compute depth and direct parent relationships
void dfs(int v, int parent) {
    up[v][0] = parent; // The 2^0-th ancestor (direct parent)
    for (int i = 1; i < LOG; ++i) {
        if (up[v][i-1] != -1)
            up[v][i] = up[up[v][i-1]][i-1]; // Binary lifting: 2^i-th ancestor
        else
            up[v][i] = -1; // No ancestor exists at this level
    }

    for (int u : g[v]) {
        if (u != parent) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

// Function to lift a node `u` to a given depth
int lift_node(int u, int d) {
    for (int i = LOG - 1; i >= 0; --i) {
        if (d & (1 << i)) {
            u = up[u][i];
        }
    }
    return u;
}

// LCA function using Binary Lifting
int lca(int u, int v) {
    // Step 1: Ensure u and v are at the same depth
    if (depth[u] < depth[v]) swap(u, v); // Ensure u is deeper
    u = lift_node(u, depth[u] - depth[v]); // Bring u to the same depth as v

    // Step 2: If v is the ancestor of u
    if (u == v) return u;

    // Step 3: Lift u and v together until they meet at the LCA
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    // Step 4: The parent of u (or v) is the LCA
    return up[u][0];
}

int main() {
    int n; // Number of nodes
    cin >> n;

    // Read the tree (1-based input)
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Initialize the depth and up table
    depth[1] = 0;
    dfs(1, -1); // Assuming 1 is the root

    // Example LCA queries:
    int u, v;
    cin >> u >> v;
    cout << "LCA of " << u << " and " << v << " is: " << lca(u, v) << endl;

    return 0;
}
