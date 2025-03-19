class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, n = (int) nums.size();
        for(int i = 0; i + 2 < n; i ++){
            if(nums[i] == 0){
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ans ++;
            }
        }

        bool ok = true;
        for(auto i : nums)
            ok &= (i);

        if(ok)
            return ans;
        return -1;        
    }
};