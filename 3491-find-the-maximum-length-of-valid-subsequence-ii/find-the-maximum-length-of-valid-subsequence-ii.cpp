class Solution {
public:
    int solve(int prevMod, int curr, int n, int k, vector<int> &nums, vector<vector<int>>& dp) {
        if (curr >= n - 1) return 0;

        if (dp[curr][prevMod + 1] != -1) return dp[curr][prevMod + 1];

        int res = 0;

        if (prevMod == -1) {
            res = solve(prevMod, curr + 1, n, k, nums, dp);

            for (int j = curr + 1; j < n; ++j) {
                int mod = (nums[curr] + nums[j]) % k;
                res = max(res, 2 + solve(mod, j, n, k, nums, dp));
            }
        } else {
            for (int j = curr + 1; j < n; ++j) {
                if ((nums[curr] + nums[j]) % k == prevMod) {
                    res = max(res, 1 + solve(prevMod, j, n, k, nums, dp));
                    break; 
                }
            }
        }

        return dp[curr][prevMod + 1] = res;
    }

    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 2, -1)); 
        return solve(-1, 0, n, k, nums, dp);
    }
};
