class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        int dp[101][101];
        memset(dp, -1, sizeof dp);
        function<int(int, int, int)> calc = [&](int i, int j, int k) {
            if(s1.size() + s2.size() != s3.size()) return false;
            if(i == n && j == m) return true;
            int &ret = dp[i][j];
            if(~ret) return ret ? true : false;
            ret = 0;
            bool check1 = false, check2 = false;
            if(i < s1.size() && s1[i] == s3[k]) check1 = calc(i + 1, j, k + 1);
            if(j < s2.size() && s2[j] == s3[k]) check2 = calc(i, j + 1, k + 1);
            return check1 || check2;
        };
        return calc(0, 0, 0);
    }
};