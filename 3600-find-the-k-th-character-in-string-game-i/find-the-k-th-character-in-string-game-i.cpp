class Solution {
public:
    char kthCharacter(int k) {
        string s = "a", t = "a";
        while(s.size() < k){
            // cout << s << " " << t << endl;
            for(auto i : s){
                t += char(((i - 'a'+ 1) % 26) + 'a');
            }
            s = t;
        }
        // cout << s << endl;
        return s[k - 1];
    }

};