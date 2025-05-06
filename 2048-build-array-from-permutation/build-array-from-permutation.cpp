class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = (int) nums.size();
        vector <int> ans;
        for(int i = 0; i < n; i ++){
            ans.push_back(max(0, nums[nums[i]]));
        }
        return ans;
    }
};