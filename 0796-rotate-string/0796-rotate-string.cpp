class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        for(int i = 0; i < s.size(); i ++){ //start position
            int j = i, k = 0;
            while(k < goal.size()){
                if(s[j] == goal[k]) k ++, j ++;
                else break;
                j %= s.size();
            }
            if(k == goal.size()) return true;
        }
        return false;
    }
};