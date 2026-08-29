 class Solution {
public:

    int dfs(vector<vector<int>>& adj, vector<bool>& vis, int node)
    {
        vis[node] = true;

        int size = 1;

        for(int neigh : adj[node])
        {
            if(!vis[neigh])
            {
                size += dfs(adj, vis, neigh);
            }
        }

        return size;
    }

    long long countPairs(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> adj(n);

        // Build adjacency list
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);

        long long ans = 0;
        long long previous = 0;

        // Find every connected component
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                int size = dfs(adj, vis, i);

                // Every node in this component
                // can pair with every previous node
                ans += (long long)size * previous;

                previous += size;
            }
        }

        return ans;
    }
};