class Solution {
public:
    string clearStars(string s) {
        map<char, set<int>> mp;
        int idx = 0;
        for(auto c : s){
            if(c == '*'){
                for(auto &[i, j] : mp){
                    if(j.size()){
                        s[*prev(j.end())] = '*';
                        j.erase(prev(j.end()));
                        break;
                    }
                }
            }
            else{
                mp[c].insert(idx);
            }
            idx ++;
        }
        string t = "";
        for(auto c : s) if(c != '*') t += c;
        return t;
    }
};