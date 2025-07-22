class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map <int, int> mp;
        int ans = 0, i = 0, j = 0, n = (int) nums.size(), sum = 0;
        while(i < n && j < n){
            sum += nums[j];
            mp[nums[j]] ++;
            while(mp[nums[j]] > 1){
                sum -= nums[i];
                mp[nums[i]] --;
                i ++;
            }
            ans = max(ans, sum);
            j ++;
        }
        return ans;
    }
};