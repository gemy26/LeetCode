class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long a = 0, b = 0, cnt_a = 0, cnt_b = 0;
        for(auto i : nums1) a += i, cnt_a += i == 0;
        for(auto i : nums2) b += i, cnt_b += i == 0;
        a += cnt_a;
        b += cnt_b;
        if (!cnt_a && b > a || !cnt_b && a > b) {
            return -1;
        }
        return max(a, b);
    }
};