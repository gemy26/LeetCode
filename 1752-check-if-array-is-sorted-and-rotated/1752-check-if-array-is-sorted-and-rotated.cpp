class Solution {
public:
    bool check(vector<int>& nums) {
        if(is_sorted(nums.begin(), nums.end())){
            return true;
        }
        int i = 1, count = 0;
        for(; i < nums.size(); i ++){
            if(nums[i] < nums[i - 1]) {
                count ++;
            }
            if(count > 1) {
                return false;
            }
        }
        return nums.back() <= nums[0];
    }
};