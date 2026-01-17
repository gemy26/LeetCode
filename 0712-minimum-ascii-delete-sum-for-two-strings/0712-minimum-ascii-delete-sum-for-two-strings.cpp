class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int total = 0;
        for(auto i : s1) total += int(i);
        for(auto i : s2) total += int(i);
        cout << total << endl;
        int n = s1.size(), m = s2.size();
        vector <vector <int>> dp(n + 1, vector <int>(m + 1, 0));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if (s1[i] == s2[j])
                    dp[i + 1][j + 1] = dp[i][j] + s1[i] + s2[j];
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return total - dp[n][m];
    }
};