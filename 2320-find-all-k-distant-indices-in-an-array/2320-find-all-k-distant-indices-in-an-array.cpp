class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> v, ans;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == key)
                v.push_back(i);
        }

        for (int i = 0; i < (int)nums.size(); i++) {
            auto it = lower_bound(v.begin(), v.end(), i);
            if (it != v.end() && abs(*it - i) <= k) {
                ans.push_back(i);
                continue;
            }
            if (it != v.begin()) {
                --it;
                if (abs(*it - i) <= k) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};