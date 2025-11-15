class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = (int) s.size(), ans = 0;
        vector <int> pre(n + 1, -1);
        for(int i = 0; i < n; i ++){
            if(i == 0 || s[i - 1] == '0'){
                pre[i + 1] = i;
            }
            else{
                pre[i + 1] = pre[i];
            }
        }

        for(int i = 1; i <= n; i ++){
            int cnt0 = (s[i - 1] == '0');
            int j = i;
            while(j > 0 && cnt0 * cnt0 <= n){
                int cnt1 = (i - pre[j]) - cnt0;
                if(cnt0 * cnt0 <= cnt1){
                    ans += min(j - pre[j], cnt1 - cnt0*cnt0 + 1);
                }
                j = pre[j];
                cnt0 ++;
            }
        }

        return ans;

    }
};