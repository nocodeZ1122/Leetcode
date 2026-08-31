class Solution {
public:

    int ans = -1;

    void dfs(vector<vector<int>>& adj,
             int node,
             vector<bool>& visited,
             vector<bool>& inRecursion,
             vector<int>& depth,
             int count)
    {
        visited[node] = true;
        inRecursion[node] = true;

        depth[node] = count;

        for(int neigh : adj[node])
        {
            if(!visited[neigh])
            {
                dfs(adj, neigh, visited, inRecursion, depth, count + 1);
            }
            else if(inRecursion[neigh])
            {
               
                int cycleLength = count - depth[neigh] + 1;

                ans = max(ans, cycleLength);
            }
        }

        inRecursion[node] = false;
    }

    int longestCycle(vector<int>& edges)
    {
        int n = edges.size();

        vector<vector<int>> adj(n);

        
        for(int i = 0; i < n; i++)
        {
            if(edges[i] != -1)
            {
                adj[i].push_back(edges[i]);
            }
        }

        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);
        vector<int> depth(n, 0);

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(adj, i, visited, inRecursion, depth, 0);
            }
        }

        return ans;
    }
};