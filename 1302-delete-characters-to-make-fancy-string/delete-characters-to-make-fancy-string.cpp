class Solution {
public:
    string makeFancyString(string s) {
        for(int i = 0; i + 2 < s.size(); i ++){
            if(s[i] == s[i + 1] && s[i] == s[i + 2]){
                s[i] = '*';
            }
        }
        string t;
        for(auto i : s){
            if(i != '*'){
                t += i;
            }
        }
        return t;
    }
};