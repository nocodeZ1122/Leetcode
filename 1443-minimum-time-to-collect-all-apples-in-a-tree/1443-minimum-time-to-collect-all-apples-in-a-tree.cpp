class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj,
            vector<bool>& hasApple)
    {
        int time = 0;

        for(int neigh : adj[node])
        {
            if(neigh == parent)
                continue;

            int childTime = dfs(neigh, node, adj, hasApple);

            if(childTime > 0 || hasApple[neigh])
            {
                time += childTime + 2;
            }
        }

        return time;
    }

    int minTime(int n, vector<vector<int>>& edges,
                vector<bool>& hasApple)
    {
        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(0, -1, adj, hasApple);
    }
};