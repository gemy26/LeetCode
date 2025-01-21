class Solution {
public:
    
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long prefix_up = 0, prefix_bot = 0, ans = 1e18;
        for(int j = 0; j < m; j ++){
            prefix_up += grid[0][j];
        }

        for(int j = 0; j < m; j ++){
            prefix_up -= grid[0][j];
            ans = min(ans, max(prefix_up, prefix_bot));
            prefix_bot += grid[1][j];
        }
        return ans;
    }
};