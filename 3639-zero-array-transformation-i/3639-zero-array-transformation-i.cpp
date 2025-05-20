class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        vector<int> a(nums.size() + 2, 0);
        for (int i = 0; i < q.size(); i++) {
            int l = q[i][0], r = q[i][1];
            a[l] += 1;
            a[r + 1] -= 1;
        }
        for (int i = 1; i < a.size(); i++) {
            a[i] += a[i - 1];
        }
        bool ans = true;
        for (int i = 0; i < nums.size(); i++) {
            ans &= (a[i] >= nums[i]);
        }
        return ans;
    }
};