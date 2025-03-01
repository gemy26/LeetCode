class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
            if (nums[i] != 0)
                ans.push_back(nums[i]);
        }
        int m = ans.size();
        for (int i = 0; i < n - m; i++) {
            ans.push_back(0);
        }
        return ans;
    }
};