class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map <int, int> vis;
        int ans = 0;
        for(int i = 0; i < nums.size(); i ++){
            if(i) nums[i] += nums[i - 1];
            int x = nums[i] - k;
            if(nums[i] == k) ans ++;
            if(vis.find(x) != vis.end()){
                ans += vis[x];
            }
            vis[nums[i]] ++;
        }
        return ans;
    }
};