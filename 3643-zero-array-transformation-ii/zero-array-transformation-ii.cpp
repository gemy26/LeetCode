class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int l = 0, r = (int)q.size() - 1, ans = -1;
        bool is_zero = true;
        for(auto i : nums)
            if(i > 0)
                is_zero = false;
        if(is_zero)
            return 0;        
        while(r >= l){
            int mid = (l + r) / 2;
            vector <int> a(nums.size() + 5, 0);
            for(int i = 0; i <= mid; i ++){
                a[q[i][0]] -= q[i][2];
                a[q[i][1] + 1] += q[i][2];
            }
            for(int i = 1; i < nums.size(); i ++) a[i] += a[i - 1];
            
            bool ok = 1;
            for (int i = 0; i < nums.size(); ++i) {
                if(a[i] + nums[i] > 0)
                    ok &= 0;
            }
            if(ok){
                r = mid - 1;
               ans = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return (ans >= 0 ? ans + 1 : -1);
    }  
};