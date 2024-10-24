class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        int l = 0, r = n - 1;
        int cnt = 0;
        while(r > l){
            if(nums[r] + nums[l] == k){
                cnt ++;
                r --;
                l ++;
            }
            else if(nums[r] + nums[l] > k){
                r --;
            }
            else if(nums[r] + nums[l] < k){
                l ++;
            }
        }
        return cnt;
    }
};