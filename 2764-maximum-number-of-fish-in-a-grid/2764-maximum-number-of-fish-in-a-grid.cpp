class Solution {
public:
    vector <vector <bool>> vis;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int N, M;
    bool isValid(int i, int j) { return i < N && j < M && i >= 0 && j >= 0; }
    int rec(int i, int j, vector<vector<int>>& grid) {

        if (!isValid(i, j) || vis[i][j] || grid[i][j] == 0)
            return 0;
        vis[i][j] = true;
        return grid[i][j] + rec(i + 1, j, grid) + rec(i - 1, j, grid) + rec(i, j - 1, grid) + rec(i, j + 1, grid);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        N = grid.size(), M = grid[0].size();
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] > 0) {
                    vis = vector <vector <bool>>(N, vector <bool>(M, false));
                    ans = max(ans, rec(i, j, grid));
                }
            }
        }
        return ans;
    }
};