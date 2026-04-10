class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int ans = 0;
        int vowels = 0;
        for(int i = 0; i < k; i ++){
            vowels += isVowel(s[i]);
        }
        int l = 0, r = k;
        while(r < s.size()){
            ans = max(ans, vowels);
            vowels -= isVowel(s[l]);
            vowels += isVowel(s[r]);
            r ++;
            l ++;
        }
        ans = max(ans, vowels);
        return ans;
    }
};