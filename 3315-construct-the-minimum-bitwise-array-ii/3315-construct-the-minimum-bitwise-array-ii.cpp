class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1e9);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) {
                ans[i] = -1;
                continue;
            }
            int bit = 1;
            int res;
            while(nums[i] & bit){
                res = nums[i] ^ bit;
                bit <<= 1;
            }
            ans[i] = res;
        }
        return ans;
    }
};