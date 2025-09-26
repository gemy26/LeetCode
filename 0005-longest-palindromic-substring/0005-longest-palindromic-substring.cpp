class Solution {
public:
    string expand(int l, int r, string& s) {
        if (s.length() <= 1) {
            return s;
        }

        string ans = "";
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l --, r ++;
        }
        // cout << l << " " << r << endl;
        return s.substr(l + 1, r - (l + 1));
    }
    string longestPalindrome(string s) {
        string ans = "";
        ans += s[0];

        for (int i = 0; i < s.size(); i ++) {
            string odd = expand(i, i, s);
            string even = expand(i, i + 1, s);
            // cout << odd << " " << even << endl;

            if (odd.length() > ans.length()) {
                ans = odd;
            }
            if (even.length() > ans.length()) {
                ans = even;
            }
        }

        return ans;
    }
};