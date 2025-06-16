class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = (int) nums.size();
        int ans = -1;
        for(int i = 0; i < n; i ++){
            for(int j = i + 1 ; j < n; j ++){
                if(nums[j] > nums[i]){
                    ans  = max(ans, nums[j] - nums[i]);
                }
            }
        }
        return ans;
    }
};