class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            int x = i;
            int status = 0;
            while (x) {
                int lastDig = x % 10;
                x /= 10;
                if (lastDig == 4 || lastDig == 7 || lastDig == 3) {
                    status = -1;
                    break;
                } else if (lastDig == 6 || lastDig == 9 || lastDig == 2 ||
                           lastDig == 5) {
                    status = 1;
                }
            }
            if (status == 1) {
                cnt++;
            }
        }
        return cnt;
    }
};