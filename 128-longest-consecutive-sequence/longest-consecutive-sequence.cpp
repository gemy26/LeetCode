class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = 0, r = 1;
        int ans = 1;
        if(nums.size() == 0){
            return 0;
        }
        map<int,int>mp;
        int n = nums.size();
        int cnt  = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i-1] == 1){
                cnt++;
                ans = max(ans , cnt);
            }
            else if(nums[i] - nums[i-1] == 0){
               
                ans = max(ans , cnt);
            }
        
            else{
                cnt = 1;
                // i++;
            }
        }
        return ans;
    }
};