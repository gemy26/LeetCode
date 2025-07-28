class Solution {
public:
    int calc(int idx, int val, int max, int n, vector <int> &nums){
        if(idx == n)
            return max == val;
        int take = calc(idx + 1, val | nums[idx], max, n, nums);      
        int leave = calc(idx + 1, val, max, n, nums);
        return take + leave;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for(auto i : nums) max_or |= i;
        return calc(0, 0, max_or, nums.size(), nums);
    }
};