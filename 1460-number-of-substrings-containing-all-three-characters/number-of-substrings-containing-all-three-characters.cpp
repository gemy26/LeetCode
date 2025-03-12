class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0, n = (int)s.size();
        map<char, int> mp;
        int l = 0, r = 0;
        while (r < n) {
            mp[s[r++]]++;
            while (mp.size() == 3 && l <= r) {
                ans += 1 + (s.size() - r);
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
        }

        return ans;
    }
};