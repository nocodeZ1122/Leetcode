 class Solution {
public:

    bool bipartite(vector<vector<int>>& graph, int currnode, vector<int>& color, int currcolor)
    {
        color[currnode] = currcolor;

        for(int neigh : graph[currnode])
        {
            if(color[neigh] == color[currnode])
            {
                return false;
            }

            if(color[neigh] == -1)
            {
                if(bipartite(graph, neigh, color, 1 - currcolor) == false)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();

        vector<int> color(n, -1);

        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                if(bipartite(graph, i, color, 0) == false)
                {
                    return false;
                }
            }
        }

        return true;
    }
};