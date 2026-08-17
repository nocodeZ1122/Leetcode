class Solution {
public:
    vector<int> ans;

    vector<int> dfs(int node, int parent, vector<vector<int>>& adj, string& labels) {
        vector<int> freq(26, 0);

        // Count current node
        freq[labels[node] - 'a']++;

        // Visit children
        for (int child : adj[node]) {
            if (child == parent)
                continue;

            vector<int> childFreq = dfs(child, node, adj, labels);

            // Merge child's frequency into current node
            for (int i = 0; i < 26; i++) {
                freq[i] += childFreq[i];
            }
        }

        // Number of same-label nodes in this subtree
        ans[node] = freq[labels[node] - 'a'];

        return freq;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ans.resize(n);

        dfs(0, -1, adj, labels);

        return ans;
    }
};