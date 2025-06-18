class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        int l = 0, r = 1e9, ans = 0;
        while(r >= l){
            int mid = (l + r) / 2;
            int cnt = 0;
            for(int i = 0; i  + 1 < n ; i ++){
                if(nums[i + 1] - nums[i] <= mid){
                    cnt ++;
                    i ++;
                }
            }
            if(cnt >= p){
                r = mid - 1;
                ans = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};