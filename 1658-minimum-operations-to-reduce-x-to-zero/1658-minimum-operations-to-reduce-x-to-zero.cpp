class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // 3 1 1 2 4    x = 5
        // try to find subarray with sum = total - x
        int maxLen = 0, sum = 0, total = 0, target = 0;
        int n = nums.size();
        for(int i = 0; i < n; i ++){
            total += nums[i];
        }
        target = total - x;
        int l = 0, r = 0;
        for(; r < n; r ++){
            sum += nums[r];
            while(sum > target && r > l){
                sum -= nums[l];
                l ++;
            }
            if(sum == target){
                maxLen = max(maxLen, r - l + 1);
                // cout << l << " " << r << " " << sum << endl;
            }
        }
        // cout << target << " " << total << " " << l << " " << r << " " << maxLen << endl;
        if(target == 0) return n;
        if(maxLen == 0) return -1;
    
        return n - maxLen;
    }
};