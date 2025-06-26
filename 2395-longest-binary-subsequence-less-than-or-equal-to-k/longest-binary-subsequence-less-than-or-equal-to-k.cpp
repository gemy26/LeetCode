class Solution {
public:
    int longestSubsequence(string s, int k) {
        reverse(s.begin(), s.end());
        long long num = 0; int ans = 0;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '1'){
                if(i <= 29 && num + (int) pow(2, i) <= k){
                    num += (int) pow(2, i);
                    ans ++;
                }
            }
            else{
                ans ++;
            }
        }
        return ans;
    }
};