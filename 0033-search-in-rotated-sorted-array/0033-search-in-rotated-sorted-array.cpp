class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, ans = -1;
        while(r >= l){
            int mid = (l + r) / 2;
            cout << mid << endl;
            if(nums[mid] == target){
                ans = mid;
                break;
            }
            if(nums[mid] >= nums[l]){
                if(nums[l] <= target && target < nums[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
            else{
                if(target > nums[mid] && target <= nums[r]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        }
        return ans;
    }
};