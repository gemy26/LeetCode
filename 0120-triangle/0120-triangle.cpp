class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);

        for (int i = 0; i < n; ++i) {
            dp[i].resize(i + 1, INT_MAX);
        }

        dp[0][0] = triangle[0][0];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if(i + 1 < n){
                    dp[i + 1][j] = min(triangle[i + 1][j] + dp[i][j], dp[i + 1][j]);
                }
                if(i + 1 < n && j + 1 < triangle[i + 1].size()){
                    dp[i + 1][j + 1] = min(triangle[i + 1][j + 1] + dp[i][j], dp[i + 1][j + 1]);
                }
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};