class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        // for each i how many nums[i] * 2 from [0 -> i - 1]  and how many
        // nums[i] * 2 from [i + 1, n] and just multiply
        int ans = 0, mod = 1e9 + 7, n = nums.size();
        map <int, int> frq, par;
        for(auto i : nums){
            frq[i] ++;
        }

        for(auto i : nums){
            int X = i * 2;
            int l = par[X];
            par[i] ++;
            int r = frq[X] - par[X];
            ans = (ans % mod + (l % mod * 1LL * r % mod)) % mod;
        }

        return ans;
    }
};