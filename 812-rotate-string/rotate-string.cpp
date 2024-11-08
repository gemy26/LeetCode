class Solution {
public:
    bool rotateString(string s, string goal) {
        string t = s + s;
        if(goal.size() != s.size()){
            return false;
        }
        return (t.find(goal) != -1);
    }
};