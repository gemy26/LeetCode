class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int mask = (1 << bit_width(unsigned(n))) - 1;
        return mask ^ n;
    }
};