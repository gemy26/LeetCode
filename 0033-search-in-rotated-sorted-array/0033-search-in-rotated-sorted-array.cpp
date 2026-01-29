class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, ans = -1;
        while(r >= l){
            int mid = (l + r) / 2;
            if(nums[mid] == target){
                ans = mid;
                break;
            }
            if(nums[l] <= nums[mid]){
                if(target < nums[mid] && nums[l] <= target){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else {
                if(target > nums[mid] && nums[r] >= target){
                   l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        return ans;
    }
};