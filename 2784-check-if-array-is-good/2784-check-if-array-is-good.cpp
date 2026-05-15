class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        bool ans = true;
        if(n == 1) return false;
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= n - 1; i ++){
            // cout << i << " " << nums[i - 1] << endl;
            if(nums[i - 1] != i) ans &= false;
        }   
        // cout << nums[n - 1] << " " << nums.back() << " " << n - 1  << endl;
        ans &= (nums[n - 2] == nums[n - 1]);
        return ans;
    }
};