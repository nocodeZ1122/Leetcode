class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for(int i = 0; i < times.size(); i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({v, wt});
        }

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        vector<int> res(n + 1, INT_MAX);

        res[k] = 0;

        pq.push({0, k});

        while(!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto &neigh : adj[node])
            {
                int adjnode = neigh.first;
                int wt = neigh.second;

                if(d + wt < res[adjnode])
                {
                    res[adjnode] = d + wt;

                    pq.push({d + wt, adjnode});
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++)
        {
            if(res[i] == INT_MAX)
            {
                return -1;
            }

            ans = max(ans, res[i]);
        }

        return ans;
    }
};