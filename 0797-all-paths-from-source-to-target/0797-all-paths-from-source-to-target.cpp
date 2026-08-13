 class Solution {
public:

    void dfs(vector<vector<int>>& graph,
             int node,
             int target,
             vector<vector<int>>& result,
             vector<int>& temp)
    {
        temp.push_back(node);

        if(node == target)
        {
            result.push_back(temp);
        }
        else
        {
            for(int neigh : graph[node])
            {
                dfs(graph, neigh, target, result, temp);
            }
        }

        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        int n = graph.size();

        vector<vector<int>> result;
        vector<int> temp;

        dfs(graph, 0, n - 1, result, temp);

        return result;
    }
};
 
 