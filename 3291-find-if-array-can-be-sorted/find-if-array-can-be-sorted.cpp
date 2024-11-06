class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i].first = nums[i];
            v[i].second = 0;
            for (int j = 0; j <= 8; j++) {
                if ((nums[i] >> j) & 1) {
                    v[i].second++;
                }
            }
        }
        
        int cur_mx = nums[0], cur_mn = nums[0], prev_mx = 0;
        for(int i = 1; i < n; i++){
            if(v[i].second == v[i-1].second){
                cur_mx = max(cur_mx, v[i].first);
                cur_mn = min(cur_mn, v[i].first);
            }
            else if(prev_mx > cur_mn){
                return false;
            }
            else{
                prev_mx = cur_mx;
                cur_mn = nums[i];
                cur_mx = nums[i];
            }
        }
        return prev_mx < cur_mn;
    }
};