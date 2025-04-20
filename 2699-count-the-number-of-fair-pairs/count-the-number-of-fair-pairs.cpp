class Solution {
public:
    long long countFairPairs(vector<int>& v, int lower, int upper) {
        long long ans = 0, n = v.size();
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i ++){
            int R = upper_bound(v.begin() + i + 1, v.end(), upper - v[i]) - v.begin();
            int L = lower_bound(v.begin() + i + 1, v.end(), lower - v[i])
             - v.begin();
            ans += (R - L);
        }
        return ans;
    }
};

