class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        // [2, a]                  -> 2 ops
        // [a+1, a+b-1]            -> 1 op
        // [a+b]                   -> 0 ops
        // [a+b+1, b+limit]        -> 1 op
        // [b+limit+1, 2*limit]    -> 2 ops
        
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);
        for (int i = 0; i < n / 2; i++) {
            int a = nums[i], b = nums[n - i - 1];
            if (a > b)
                swap(a, b);
            diff[2] += 2;
            diff[a + 1] -= 1;
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
            diff[b + limit + 1] += 1;
        }
        int ans = n, prefix = 0;
        for (int i = 2; i <= 2 * limit; i++) {
            prefix += diff[i];
            ans = min(ans, prefix);
        }
        return ans;
    }
};