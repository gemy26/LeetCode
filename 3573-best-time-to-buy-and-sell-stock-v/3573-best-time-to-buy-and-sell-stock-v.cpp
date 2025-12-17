class Solution {
public:
    vector<int> price;
    long long dp[1001][501][2][2];
    long long calc(int idx, int k, int type, int state) {
        if (idx == price.size()) {
            return state == 0 ? 0 : -1e18;
        }
        long long& ret = dp[idx][k][type][state];
        if (~ret)
            return ret;

        ret = calc(idx + 1, k, type, state);

        if (state == 0) {
            ret = max(ret, -price[idx] + calc(idx + 1, k, 0, 1));
            ret = max(ret, price[idx] + calc(idx + 1, k, 1, 1));
        } else if (k > 0) {
            if (type == 0)
                ret = max(ret, price[idx] + calc(idx + 1, k - 1, 0, 0));
            else
                ret = max(ret, -price[idx] + calc(idx + 1, k - 1, 0, 0));
        }
        return ret;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        // dp[idx][k][transaction_type][state]
        // 1e3 * 2 * 2 * 500
        memset(dp, -1, sizeof dp);
        price = prices;
        return calc(0, k, 0,
                    0); // state = 0 can buy, type == 0 preic[j] else -price[j]
    }
};