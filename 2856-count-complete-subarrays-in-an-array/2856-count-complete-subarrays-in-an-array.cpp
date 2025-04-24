class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set <int> distinct(nums.begin(), nums.end());
        map <int, int> mp;
        int k = distinct.size(), n = nums.size();
        int ans = 0;
        int l = 0, r = 0;
        while(r < n){
            if(r < n && mp.size() < k){
                //cout << r << " ";
                mp[nums[r]] ++;
                //cout << mst.size() << endl;
            }
            while(l <= r && mp.size() == k){
                // for(auto i : mst) cout << i << " ";
                // cout << endl;
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