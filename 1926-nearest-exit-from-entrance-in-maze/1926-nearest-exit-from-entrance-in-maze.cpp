 class Solution {
public:

    vector<vector<int>> directions{
        {1,0},
        {0,1},
        {-1,0},
        {0,-1}
    };

    int nearestExit(vector<vector<char>>& maze,
                    vector<int>& entrance) {

        int m = maze.size();
        int n = maze[0].size();

        vector<vector<bool>> vis(
            m,
            vector<bool>(n, false)
        );

        queue<pair<int,int>> q;

        q.push({entrance[0], entrance[1]});

        vis[entrance[0]][entrance[1]] = true;

        int steps = 0;

        while(!q.empty())
        {
            int size = q.size();

            steps++;

            for(int i = 0; i < size; i++)
            {
                int row = q.front().first;
                int col = q.front().second;

                q.pop();

                for(auto dir : directions)
                {
                    int row_ = row + dir[0];
                    int col_ = col + dir[1];

                    // boundary check
                    if(row_ < 0 || row_ >= m ||
                       col_ < 0 || col_ >= n)
                    {
                        continue;
                    }

                    // valid empty and unvisited
                    if(maze[row_][col_] == '.' &&
                       !vis[row_][col_])
                    {
                        // if boundary -> exit
                        if(row_ == 0 || row_ == m-1 ||
                           col_ == 0 || col_ == n-1)
                        {
                            return steps;
                        }

                        vis[row_][col_] = true;

                        q.push({row_, col_});
                    }
                }
            }
        }

        return -1;
    }
};