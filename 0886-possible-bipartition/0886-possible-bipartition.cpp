class Solution {
public:

    bool dfs(vector<int> adj[], int node, vector<int>& color, int currcolor)
    {
        color[node] = currcolor;

        for(int neigh : adj[node])
        {
            // Same group -> impossible
            if(color[neigh] == color[node])
                return false;

            // Not colored yet
            if(color[neigh] == -1)
            {
                if(!dfs(adj, neigh, color, 1 - currcolor))
                    return false;
            }
            else if (color[neigh] == color[node]){
                return false ;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        vector<int> adj[n + 1];

        // Build undirected graph
        for(int i = 0; i < dislikes.size(); i++)
        {
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n + 1, -1);

        // Graph may have multiple components
        for(int i = 1; i <= n; i++)
        {
            if(color[i] == -1)
            {
                if(!dfs(adj, i, color, 0))
                    return false;
            }
        }

        return true;
    }
};