class Solution {
public:
    int countGoodNumbers(long long n) {
        int mod = 1e9 + 7;
        function<long long(long long, long long)> fast_pow =
            [&](long long base, long long pow) -> long long {
            if (pow == 0)
                return 1;
            long long half = fast_pow(base, pow / 2) % mod;
            long long ans = (half * half) % mod;
            if (pow % 2 == 1) {
                ans = (ans * base) % mod;
            }
            return ans;
        };
        long long ans = (fast_pow(5, (n + 1) / 2) * fast_pow(4, n / 2)) % mod;
        return (int)ans;
    }
};