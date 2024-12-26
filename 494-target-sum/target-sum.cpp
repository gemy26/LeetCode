class Solution {
public:
    int calc(vector <int> &nums, int idx, int target, int sum){
        if(idx == nums.size()){
            if(sum == target)
                return 1;
            else 
                return 0;    
        }
        return calc(nums, idx + 1, target, sum + nums[idx]) + calc(nums, idx + 1, target, sum - nums[idx]) ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = calc(nums, 0, target, 0);
        return res;
    }
};