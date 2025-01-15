class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ones = 0, ans = 0;
        for (int bit = 0; bit <= 31; bit++) {
            if ((num2 >> bit) & 1) {
                ones++;
            }
        }

        for (int bit = 31; bit >= 0 && ones; bit--) {
            if ((num1 >> bit) & 1) {
                ans |= (1 << bit);
                ones --;
            }
        }

        for (int bit = 0; bit <= 31 && ones; bit ++) {
            if (!((num1 >> bit)&1)) {
                ans |= (1 << bit);
                ones --;
            }
        }

        return ans;
    }
};