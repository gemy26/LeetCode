class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> profit(n + 1);
        vector<long long> prefix(n + 1);

        for(int i = 0; i < n; i ++){
            profit[i + 1] = profit[i] + strategy[i] * prices[i];
            prefix[i + 1] = prices[i] + prefix[i];
        }
         
        long long ans = profit[n];
        for(int i = k - 1; i < n; i ++){
            long long l = profit[i - k + 1];
            long long r = profit[n] - profit[i + 1];
            long long change = prefix[i + 1] - prefix[i - k / 2 + 1];
            ans = max(ans, l + r + change);
        }

        return ans;
    }
};