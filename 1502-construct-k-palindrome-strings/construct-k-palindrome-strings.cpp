class Solution {
public:
    bool canConstruct(string s, int k) {
        int frq[27] = {};
        int odd = 0, even = 0;
        for(auto c : s){
            frq[c - 'a'] ++;
        }

        for(char c = 'a'; c <= 'z'; c ++){
            odd += (frq[c - 'a'] & 1);
            even += (frq[c - 'a'] % 2  == 0 && frq[c - 'a'] > 0);
        }
        if( odd > k || s.size() < k){
            return false;
        }
        return true;
    }
};