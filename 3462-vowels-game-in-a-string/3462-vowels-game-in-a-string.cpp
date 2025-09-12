class Solution {
public:
    bool isVowel(char ch) {
        char c = tolower(ch);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    bool doesAliceWin(string s) {
        int cnt = 0;
        for (auto i : s)
            cnt += isVowel(i);
        if (cnt == 0)
            return false;
        return true;
    }
};