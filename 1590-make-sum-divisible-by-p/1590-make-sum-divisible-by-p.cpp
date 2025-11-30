class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        map <int, int> mp;
        int sum = 0;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i ++){
            sum = (sum + nums[i]) % p;
        }
        int target = sum % p;
        if(sum % p == 0) return 0;
        sum = 0;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i ++){
            sum = (sum + nums[i]) % p;
            int need = (sum - target + p) % p;
            if(mp.find(need) != mp.end()){
                ans = min(ans, i - mp[need]);
            }
            mp[sum] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};