class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int ans = 0, i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (j >= i && nums1[i] <= nums2[j]) {
                ans = max(j - i, ans);
                j ++;
            } else if (j >= i)
                i ++;
            else
                j ++;
        }

        return ans;
    }
};