class Solution {
public:
    bool isVowel(char ch){
        char c = tolower(ch);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string sortVowels(string s) {
        int idx = 0;
        vector <char> vowels;

        for(auto i : s){
            if(isVowel(i)){
                vowels.push_back(i);
            }
        }

        sort(vowels.begin(), vowels.end());

        for(auto &i : s){
            if(isVowel(i)){
                i = vowels[idx ++];
            }
        }
        return s;
    }
};