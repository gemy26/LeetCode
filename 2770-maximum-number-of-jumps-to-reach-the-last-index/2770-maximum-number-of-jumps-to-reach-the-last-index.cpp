class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector <int> dp(n, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i ++){
            if(dp[i] == -1) continue;
            for (int j = i + 1; j < n; j ++){
                int diff = abs(nums[j] - nums[i]);
                if(diff <= target) dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        return (dp[n - 1] == 0 ? -1 : dp[n - 1]);
    }
};