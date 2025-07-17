class Solution {
public:
    int maximumLength(vector<int>& v, int k) {
        int n = (int) v.size();
        vector <vector <int>> dp(n + 1, vector <int>(k + 1, 1));
        int ans = 0;
        for(int i = 0; i < n ; i ++){
            for(int j = i + 1; j < n ; j ++){
                int mod = (v[i] + v[j]) % k;
                dp[j][mod] = max(dp[j][mod], 1 + dp[i][mod]);
                ans = max(ans, dp[j][mod]);
            }
        }

        return ans;
    }
};