class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string low = to_string(start), high = to_string(finish);

        low = string(high.size() - low.size(), '0') + low;
        int len = high.size() - s.size();

        auto dp = vector<vector<vector<long long>>>(
            20, vector<vector<long long>>(2, vector<long long>(2, -1)));

        function<long long(int, int, int)> calc = [&](int idx, int ru,
                                                      int rd) -> long long {
            if (idx == low.size())
                return 1;
            long long& ret = dp[idx][ru][rd];
            if (~ret)
                return ret;
            ret = 0;
            int lb = (rd ? low[idx] - '0' : 0);
            int up = (ru ? high[idx] - '0' : 9);

           // cout << lb << " " << up << endl;
            if (idx < len) {
                for (int i = lb; i <= min(limit, up); i++) {
                    ret += calc(idx + 1, ru && (i == up), rd && (i == lb));
                }
            } else {
                int curr_dig = s[idx - len] - '0';
                if ( curr_dig >= lb && curr_dig <= min(limit,up)) {
                    ret = calc(idx + 1, ru && (curr_dig == up), rd && (curr_dig == lb));
                }
            }

            return ret;
        };

        return calc(0, 1, 1);
    }
};