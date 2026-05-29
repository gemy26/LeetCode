class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // at each position i check if i can jump to the next zeros where i + minJump <= j <= i + maxJump
        // mark interval as rechable
        if(s.back() != '0') return false;
        int n = s.size();
        vector <int> dp(n, 0), pre(n, 0);
        for(int i = 0; i < minJump; i ++) pre[i] = 1;
        for(int i = minJump; i < n; i ++){
            if(s[i] == '0'){
                int l = i - maxJump, r = i - minJump;
                if(pre[r] - (l > 0 ? pre[l - 1] : 0) > 0){
                    dp[i] = 1;
                }
            }
            pre[i] = pre[i - 1] + dp[i];
        }
        
        return dp[n - 1];
    }
};