class Solution {
public:
    int minimumLength(string s) {
        int frq[27] = {};
        int ans = 0;
        for(auto c : s){
            frq[c - 'a'] ++;
        }
        
        for(int i = 0; i <= 26; i ++){
            if(frq[i]&1){
                ans += 1;
            }
            else if(frq[i] > 0 && frq[i] % 2 == 0){
                ans += 2;
            }
        }
        return ans;
    }
};