class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    vector<vector<bool>> vis;
    bool touchBoundry = false;
    void dfs(vector<vector<int>>& grid, int x, int y) {
        int n = grid.size(), m = grid[0].size();
    
        if (x < 0 || y < 0 || x >= n || y >= m) {
            touchBoundry = true;
            return;
        }
        if (vis[x][y] || grid[x][y] == 1)
            return;
        vis[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            cout << x << " " << y << "  -> " << nx << " " << ny << endl; 
            dfs(grid, nx, ny);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        vis = vector<vector<bool>>(101, vector<bool>(101, false)); 
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    touchBoundry = false;
                    dfs(grid, i, j);
                    if (!touchBoundry) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};