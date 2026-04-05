class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> s;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                auto it = lower_bound(nums.begin() + j + 1, nums.end(),
                                      -(nums[i] + nums[j]));
                if (it != nums.end() && *it + nums[i] + nums[j] == 0) {
                    s.insert({nums[i], nums[j], *it});
                }
            }
        }
        for(auto i : s) ans.push_back(i);
        return ans;
    }
};