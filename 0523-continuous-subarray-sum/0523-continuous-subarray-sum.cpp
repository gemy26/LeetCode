class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // a = 6 * c1 + r1, b = 6 * c2 + r2
        // a + b = 6 * (c1 + c2) + (r1 + r2)
        // a + b == r1 + r2 when: mod 6
        // a - b = r1 - r2 -> r1 - r2 can be divisible by k if r1 = r2
        int n = nums.size();
        map<int, int> mp;
        mp[0] = -1;
        int prefix = 0;
        for (int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % k;
            if (mp.find(prefix) != mp.end()) {
                if (i - mp[prefix] > 1) {
                    return true;
                }
            } else {
                mp[prefix] = i;
            }
        }
        return false;
    }
};