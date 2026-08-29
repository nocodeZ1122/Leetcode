class Solution {
public:

    int dfs(int node, vector<vector<pair<int,int>>>& adj,
            vector<bool>& vis)
    {
        vis[node] = true;

        int ans = INT_MAX;

        for(auto neigh : adj[node])
        {
            int next = neigh.first;
            int wt = neigh.second;

            ans = min(ans, wt);

            if(!vis[next])
            {
                ans = min(ans, dfs(next, adj, vis));
            }
        }

        return ans;
    }

    int minScore(int n, vector<vector<int>>& roads)
    {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<bool> vis(n + 1, false);

        return dfs(1, adj, vis);
    }
};