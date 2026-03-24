class Solution {
public:
    int findMin(vector<int>& nums) {
        // if(nums[mid] > nums[l]) l = mid + 1
        // if(nums[mid] < nums[r]) r = mid - 1
        // ans = min(ans, nums[mid])
        int ans = INT_MAX;
        int l = 0, r = nums.size() - 1;
        while(r >= l){
            int mid = (l + r) / 2;
            ans = min(ans, nums[mid]);
            if(nums[mid] < nums[r]){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};