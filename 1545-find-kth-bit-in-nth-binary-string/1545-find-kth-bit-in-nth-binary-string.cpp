class Solution {
public:
    char calc(int n, int k){
        if(n == 1) return '0';
        int len = 1 << n;
        if (k < len / 2){
            return calc(n - 1, k);
        }

        if(k == len / 2) return '1';
        
        else{
            char ans = calc(n - 1, len  - k);
            return (ans == '0') ? '1' : '0';
        }
    }
    char findKthBit(int n, int k) {
        return calc(n, k);
    }
};