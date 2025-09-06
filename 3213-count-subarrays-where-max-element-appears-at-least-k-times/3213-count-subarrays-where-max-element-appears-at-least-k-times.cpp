class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int maxi = *max_element(nums.begin(), nums.end()), frq = 0;
        vector<int> pos;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxi) {
                pos.push_back(i + 1);
                frq++;
            }
            if (frq >= k) {
                ans += (pos[frq - k]);
            }
        }
        return ans;
    }
};