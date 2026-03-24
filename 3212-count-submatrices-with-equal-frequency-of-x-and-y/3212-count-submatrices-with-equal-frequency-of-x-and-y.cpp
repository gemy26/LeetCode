class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        // 2d prefix
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair<int, int>>> prefix(n, vector<pair<int, int>>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i][j] = {grid[i][j] == 'X', grid[i][j] == 'Y'};
                if (i > 0) {
                    prefix[i][j].first += prefix[i - 1][j].first;
                    prefix[i][j].second += prefix[i - 1][j].second;
                }
                if (j > 0) {
                    prefix[i][j].second += prefix[i][j - 1].second;
                    prefix[i][j].first += prefix[i][j - 1].first;
                }
                if (i > 0 && j > 0) {
                    prefix[i][j].first -= prefix[i - 1][j - 1].first;
                    prefix[i][j].second -= prefix[i - 1][j - 1].second;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (prefix[i][j].first == prefix[i][j].second && prefix[i][j].first != 0)
                    ans++;
            }
        }
        return ans;
    }
};