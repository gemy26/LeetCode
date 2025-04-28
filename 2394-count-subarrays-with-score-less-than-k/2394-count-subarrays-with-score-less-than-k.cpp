class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l = 0, r = 0, n = nums.size();
        long long ans = 0, sum = 0;
        while(r < n){
            if(sum * (r - l) < k){
                sum += nums[r ++];
            }
            while(r >= l && sum * (r - l) >= k){
                sum -= nums[l ++];
            }
            ans += (r - l);
        }
        return ans;
    }
};