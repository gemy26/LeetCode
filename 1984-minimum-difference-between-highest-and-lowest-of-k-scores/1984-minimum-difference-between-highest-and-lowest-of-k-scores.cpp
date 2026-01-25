class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = 1e9;
        sort(nums.begin(), nums.end());
        for(int i = 0; i + k - 1 < nums.size(); i ++){
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans == 1e9 ? 0 : ans;
    }
};