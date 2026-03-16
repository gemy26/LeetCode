class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1;
        for(int i = 1; i < nums.size(); i ++){
            if(nums[i] != nums[idx - 1]){
                nums[idx ++] = nums[i];
            }
        }
        return idx;
    }
};