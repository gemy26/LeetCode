class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0, zeros = 0;
        for (auto i : s) {
            if (i == '1')
                ones++;
            else
                zeros++;
        }
        string res = "";
        for (int i = 0; i < ones - 1; i++) {
            res += '1';
        }
        for (int i = ones ; i < s.size(); i++) {
            res += '0';
        }
        if (ones)
            res += '1';

        return res;
    }
};