class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector <int> ans;

        int n=  nums.size();
        int mask = (1 << maximumBit) - 1;

        for(int i = 1; i < n; i++){
            nums[i] ^= nums[i - 1];
        }

        for(int i = 0; i < n; i++){
            ans.push_back(mask ^ nums[n - i - 1]);
        }
        return ans;
    }
};