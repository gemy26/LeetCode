class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = (int) nums.size();
        map <int, int> frq; //frq of each number
        long long ans = 0, pairs_cnt = 0;
        int l = 0, r = 0;
        while(r < n){
            
            pairs_cnt += frq[nums[r]];
            frq[nums[r]] ++;
            
            while(pairs_cnt >= k && l <= r){
                ans += n - r;
                frq[nums[l]] --;
                pairs_cnt -= frq[nums[l]];
                l ++;
            }

            r ++;
        }
        return ans;
    }
};