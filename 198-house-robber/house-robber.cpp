class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int) nums.size();
        vector <int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i < n; i++){
            int take = nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0);
            int leave = dp[i - 1];
            dp[i] = max(take, leave);
        }
        return dp.back();
    }
};