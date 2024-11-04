class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = (int) word.size();
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && word[j] == word[i] && j - i + 1 <= 9) {
                j++;
            }
            comp += to_string(j - i );
            comp += word[i];
            i = j;
        }
        return comp;
    }
};