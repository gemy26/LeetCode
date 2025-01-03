class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = (int) nums.size(), ans = 0;
        vector <long long > prefix(n), suffix(n);
        for(int i = 0; i < n; i ++){
            prefix[i] += nums[i];
            if(i){
                prefix[i] += prefix[i - 1];
            }
        }

        for(int i = n - 1; i >= 0; i --){
            suffix[i] = nums[i];
            if(i < n - 1){
                suffix[i] += suffix[i + 1]; 
            }
        }

        for(int i = 0; i + 1 < n; i++){
            if(prefix[i] >= suffix[i + 1]){
                ans ++;
            }
        }
        return ans;
    }
};