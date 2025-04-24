class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set <int> distinct(nums.begin(), nums.end());
        unordered_map <int, int> mp;
        int k = distinct.size(), n = nums.size();
        int ans = 0;
        int l = 0, r = 0;
        while(r < n){
            if(r < n && mp.size() < k){
                mp[nums[r]] ++;
            }
            while(l <= r && mp.size() == k){
                ans += (n - r);
                mp[nums[l]] --;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l ++;
            }
            r ++;
        }
        return ans;
    }
};