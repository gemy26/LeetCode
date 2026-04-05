class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = n - 1, k = i + 1;
            while (j > k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    k ++;
                } else if (sum > 0) {
                    j --;
                } else {
                    ans.push_back({nums[i], nums[k], nums[j]});
                    k ++;
                    while(nums[k] == nums[k - 1] && k < j) k ++;
                }
            }
        }
        return ans;
    }
};