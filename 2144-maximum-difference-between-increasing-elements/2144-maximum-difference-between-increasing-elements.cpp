class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1, pmin = nums[0];
        for(int i = 1; i < (int) nums.size(); i ++){
            if(nums[i] > pmin){
                ans = max(ans, nums[i] - pmin);
            }
            else{
                pmin = min(pmin, nums[i]);
            }
        }
        return ans;
    }
};