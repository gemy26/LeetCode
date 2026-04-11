class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        map<int, int>mp;
        int ans = 0;
        for(int i = 0; i < 32; i ++){
            for(int j = 0; j < nums.size(); j ++){
                mp[i] += (nums[j] >> i) & 1;
            }
            ans += mp[i] * (nums.size() - mp[i]);
        }
        return ans;
    }
};