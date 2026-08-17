 class Solution {
public:

    int res = 1;

    int dfs(vector<vector<int>>& adj, int curr, int parent, string& s)
    {
        int longest = 0;
        int second_longest = 0;

        for(int child : adj[curr])
        {
            if(child == parent)
                continue;

            int childLength = dfs(adj, child, curr, s);

            // Cannot use this child if characters are same
            if(s[child] == s[curr])
                continue;

            if(childLength > longest)
            {
                second_longest = longest;
                longest = childLength;
            }
            else if(childLength > second_longest)
            {
                second_longest = childLength;
            }
        }

        // Path going through current node using two branches
        res = max(res, 1 + longest + second_longest);

        // Only ONE branch can be returned to parent
        return 1 + longest;
    }

    int longestPath(vector<int>& parent, string s)
    {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for(int i = 1; i < n; i++)
        {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }

        dfs(adj, 0, -1, s);

        return res;
    }
};