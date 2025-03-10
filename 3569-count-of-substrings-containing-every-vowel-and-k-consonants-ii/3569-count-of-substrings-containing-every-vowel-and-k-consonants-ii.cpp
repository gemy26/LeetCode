class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        string vowel = "aeiou";
        long long l = 0, r = 0, ans = 0, n = (int)word.size();
        map<char, int> frq;
        vector<int> next_cons(n);
        int next = n;
        for (int i = n - 1; i >= 0; i--) {
            next_cons[i] = next;
            if (vowel.find(word[i]) == -1)
                next = i;
        }
        int cons = 0;

        while (r < n) {
            if (vowel.find(word[r]) == -1)
                cons++;
            else
                frq[word[r]]++;

            while (cons > k) {
                if (vowel.find(word[l]) == -1)
                    cons--;
                else {
                    frq[word[l]]--;
                    if (frq[word[l]] == 0)
                        frq.erase(word[l]);
                }

                l++;
            }
            while (frq.size() == 5 && l < n && cons == k) {
                ans += next_cons[r] - r;
                if (vowel.find(word[l]) == -1)
                    cons--;
                else {
                    frq[word[l]]--;
                    if (frq[word[l]] == 0)
                        frq.erase(word[l]);
                }

                l++;
            }

            r++;
        }

        return ans;
    }
};