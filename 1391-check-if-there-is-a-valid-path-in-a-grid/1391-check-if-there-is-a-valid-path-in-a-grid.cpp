class Solution {
public:
    vector<vector<bool>> vis;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool canConnect(int from, int to, int dir) {
        if (dir == 0) { // right
            return (from == 1 || from == 4 || from == 6) &&
                   (to == 1 || to == 3 || to == 5);
        }
        if (dir == 1) { // left
            return (from == 1 || from == 3 || from == 5) &&
                   (to == 1 || to == 6 || to == 4);
        }
        if (dir == 2)
            return (from == 2 || from == 3 || from == 4) &&
                   (to == 2 || to == 5 || to == 6);
        if (dir == 3)
            return (from == 2 || from == 5 || from == 6) &&
                   (to == 2 || to == 3 || to == 4);

        return false;
    }

    bool dfs(int i, int j, vector<vector<int>>& grid) {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)
            return false;
        if (vis[i][j])
            return false;
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return true;
        vis[i][j] = true;
        for (int d = 0; d < 4; d++) {
            int ni = i + dirs[d].first;
            int nj = j + dirs[d].second;
            if (ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size() &&
                !vis[ni][nj])
                if (canConnect(grid[i][j], grid[ni][nj], d)) {
                    if (dfs(ni, nj, grid))
                        return true;
                }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        return dfs(0, 0, grid);
    }
};