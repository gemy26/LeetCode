class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, ans = INT_MAX;
        while(r >= l){
            int mid = (l + r) / 2;
            ans = min(ans, nums[mid]);
            if(nums[mid] <= nums[r]){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};