class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;
        bool vis[1005][1005] = {};
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    grid[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int X = x + dx[i];
                int Y = y + dy[i];
                if (X >= 0 && X < n && Y >= 0 && Y < m) {
                    if (!vis[X][Y]) {
                        grid[X][Y] = grid[x][y] + 1;
                        vis[X][Y] = 1;
                        q.push({X, Y});
                    }
                }
            }
        }
        return grid;
    }
};