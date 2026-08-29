class Solution {
public:

    int ans = 0;

    void dfs(vector<vector<pair<int,int>>>& adj,
             int u,
             int parent)
    {
        for(auto p : adj[u])
        {
            int v = p.first;
            int check = p.second;

            if(v == parent)
                continue;

            if(check == 1)
                ans++;

            dfs(adj, v, u);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections)
    {
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < connections.size(); i++)
        {
            int a = connections[i][0];
            int b = connections[i][1];

            adj[a].push_back({b, 1});
            adj[b].push_back({a, 0});
        }

        ans = 0;

        dfs(adj, 0, -1);

        return ans;
    }
};