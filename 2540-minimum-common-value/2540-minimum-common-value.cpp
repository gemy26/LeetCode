class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int minCommon = INT_MAX;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int l = 0, r = 0;
        while(l < nums1.size() && r < nums2.size()){
            if(nums1[l] < nums2[r]) l ++;
            else if (nums1[l] > nums2[r]) r ++;
            else{
                return nums1[l];
            }
        }
        return -1;
    }
};