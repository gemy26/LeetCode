class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int l = i, r = nums2.size() - 1;
            int best = -1;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (nums2[mid] >= nums1[i]) {
                    best = mid;     
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (best != -1) {
                ans = max(ans, best - i);
            }
        }

        return ans;
    }
};