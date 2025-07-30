class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, cur = 0, maxi = 0;
        for (auto x : nums) {
            if (x > maxi) {
                maxi = x;
                ans = cur = 0;
            }
            if (x == maxi) {
                cur++;
            } else {
                cur = 0;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};