class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = 1e9 + 7;
        vector <int> frq(27, 0), temp(27, 0);
        for(auto i : s) frq[i - 'a'] ++;
        for(int i = 0; i < t; i ++){
            for(int j = 0; j < 26; j ++){
                if(frq[j]){
                    if(char(j + 'a') == 'z'){
                        temp[0] = (temp[0] % MOD + frq[j] % MOD) % MOD;
                        temp[1] = (temp[1] % MOD + frq[j] % MOD) % MOD;
                    }
                    else{
                        temp[j + 1] = 
                        (temp[j + 1] % MOD + frq[j] % MOD) % MOD;
                    }
                    frq[j] = 0;
                }
            }
            frq = temp;
            temp.assign(27, 0);
        }
        int ans = 0;
        for(auto i : frq) ans = (ans % MOD + i % MOD) % MOD;
        return ans;
    }
};