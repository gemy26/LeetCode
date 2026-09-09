class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, ans = 0, n = s.size();
        map<char, int> frq;
        while(r < n) {
            frq[s[r]] ++;
            while(l < r && frq[s[r]] > 1){
                frq[s[l ++]] --;
            }
            ans = max(ans, r - l + 1);
            r ++;
        }
        return ans;
    }
};