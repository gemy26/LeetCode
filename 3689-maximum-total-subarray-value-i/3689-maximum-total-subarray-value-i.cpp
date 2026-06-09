class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int minNum = *min_element(nums.begin(), nums.end());
        return 1LL * (maxNum - minNum) * k;
    }
};