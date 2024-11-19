class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0, r = k;
        unordered_map<int, int> mp;
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            mp[nums[i]]++;
        }

        if (mp.size() == k) {
            ans = max(sum, ans);
        }
        while (r < nums.size()) {
            mp[nums[l]]--;
            if (mp[nums[l]] == 0) {
                mp.erase(nums[l]);
            }

            sum -= nums[l++];
            mp[nums[r]]++;
            sum += nums[r++];

            if (mp.size() == k) {
                ans = max(sum, ans);
            }
        }
        return ans;
    }
};