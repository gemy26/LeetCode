class Solution {
public:
    vector<pair<int, int>> dir = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> d(1001, vector<int>(1001, 1e9));
        d[0][0] = 0;
        int n = grid.size(), m = grid[0].size();
        set<pair<int, pair<int, int>>> q;
        q.insert({0, {0, 0}});
        while (!q.empty()) {
            auto [x, y] = q.begin()->second;
            q.erase(q.begin());
            //        if (x >= n || y >= m || x < 0 || y < 0)
            //            continue;

            for (int i = 1; i <= 4; i++) {
                int w;
                if (grid[x][y] == i) {
                    w = 0;
                } else {
                    w = 1;
                }
                int new_x = x + dir[i].first;
                int new_y = y + dir[i].second;
                if (new_x >= n || new_y >= m || new_x < 0 || new_y < 0)
                    continue;
                if (d[x][y] + w < d[new_x][new_y]) {
                    q.erase({d[new_x][new_y], {new_x, new_y}});
                    d[new_x][new_y] = d[x][y] + w;
                    q.insert({d[new_x][new_y], {new_x, new_y}});
                }
            }
        }

        return d[n - 1][m - 1];
    }
};