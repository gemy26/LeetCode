class Solution {
public:
    double soupServings(int n) {
        if(n > 5000)
            return 1.0;
    
        int m = ceil(n / 25.0);
        vector <vector <double>> dp(m + 1, vector <double>(m + 1, -1.0));
        function <double(int, int)> calc = [&](int a, int b) -> double{
            if(a <= 0 && b <= 0) return 0.5;
            if(a <= 0) return 1.0;
            if(b <= 0) return 0.0;

            if(dp[a][b] != -1.0)
                return dp[a][b];

            double ret = 0.25 *(
                calc(a - 4, b) +
                calc(a - 3, b - 1) +
                calc(a - 2, b - 2) +
                calc(a - 1, b - 3)
            );

            return dp[a][b] = ret;
        };

        return calc(m, m);
    }
};