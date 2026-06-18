class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                if (ans.size() >= 1) {
                    ans.pop_back();
                }
            } else if (s[i] == '#') {
                ans += ans;
            } else if (s[i] == '%') {
                reverse(ans.begin(), ans.end());
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};