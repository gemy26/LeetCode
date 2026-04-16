class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ones = 0, zeros = 0, ans = 0;
        int l = 0, r = 0;
        while (r < n) {
            ones += (nums[r] == 1);
            zeros += (nums[r] == 0);
            while (l < r && zeros > k) {
                zeros -= (nums[l] == 0);
                l ++;
            }
            if(zeros <= k)
                ans = max(ans, r - l + 1);
            r ++;
        }
        return ans;
    }
};