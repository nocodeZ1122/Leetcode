class Solution {
public:

    bool dfs(vector<int> adj[], int node, int destination,
             vector<bool>& visited)
    {
        if(node == destination)
            return true;

        visited[node] = true;

        for(int neigh : adj[node])
        {
            if(!visited[neigh])
            {
                if(dfs(adj, neigh, destination, visited))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination)
    {
        vector<int> adj[n];

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        return dfs(adj, source, destination, visited);
    }
};