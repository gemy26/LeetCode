class Solution {
public:
    long long minEnd(int n, int x) {
       long long ans = x;
       while(--n){
        ans = (x | (ans + 1));
       }
       return ans;
    }
};