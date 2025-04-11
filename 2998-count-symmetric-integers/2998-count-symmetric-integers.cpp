class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int i = low; i <= high; i++) {
            string s = to_string(i);
            int n = s.size();
            if (n % 2 == 0) {
                int f = 0, sec = 0;
                for (int j = 0; j < n; j++) {
                    if (j < n / 2)
                        f += (s[j] - '0');
                    else
                        sec += (s[j] - '0');
                }
                if (f == sec) {
                    cnt ++;
                }
            }
        }
        return cnt;
    }
};