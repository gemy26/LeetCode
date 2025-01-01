class Solution {
public:
    int maxScore(string s) {
        int ones_cnt = 0, zeros_cnt = 0, ans = 0;
        for(int i = 0; i < s.size(); i++){
            ones_cnt += s[i] == '1';
        }
        for(int i = 0; i + 1< s.size(); i++){
            zeros_cnt += s[i] == '0';
            ones_cnt -= s[i] == '1';
            cout << ones_cnt <<" " << zeros_cnt <<  endl;
            ans = max(ones_cnt + zeros_cnt, ans);
        }
        return ans;
    }
};