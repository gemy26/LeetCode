class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        reverse(nums1.begin(), nums1.end());
        reverse(nums2.begin(), nums2.end());

        int ans = 0;

        for (int ri = 0; ri < n1; ri++) {

            int l = 0, r = n2 - 1;
            int best = -1;

            while (l <= r) {
                int mid = (l + r) / 2;

                if (nums2[mid] >= nums1[ri]) {
                    best = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if (best != -1) {
                int orig_i = n1 - 1 - ri;
                int orig_j = n2 - 1 - best;

                if (orig_i <= orig_j) {
                    ans = max(ans, orig_j - orig_i);
                }
            }
        }

        return ans;
    }
};