class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 1000000000, sum = 0, n = nums.size();
        int l = 0, r = 0;
        while (r < n) {
            sum += nums[r];
            while(sum >= target){
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l ++;
            }
            r ++;
        }
        return ans == 1000000000 ? 0 : ans;
    }
};