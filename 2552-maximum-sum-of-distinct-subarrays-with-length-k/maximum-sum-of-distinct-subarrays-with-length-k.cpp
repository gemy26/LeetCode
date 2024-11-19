class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0, r = 0;
        unordered_map<int, int> mp;
        long long sum = 0;
        long long ans = 0;
        
        while (r < nums.size()) {
            int last = -1 ;
            if(mp.count(nums[r])){
                last = mp[nums[r]];
            }
            while(last >= l || r - l + 1 > k){
                sum -= nums[l];
                l ++;
            }
            mp[nums[r]] = r;
            sum += nums[r];
            if(r - l + 1 == k){
                ans = max(ans, sum);
            }
            r ++;
        }
        return ans;
    }
};