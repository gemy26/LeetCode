class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return xorsum(0, nums, 0);
    }
    int xorsum(int idx, vector<int>& a, int currxor){
        if(idx == a.size()) return currxor;
        int take = xorsum(idx + 1, a, currxor ^ a[idx]);
        int leave = xorsum(idx + 1, a, currxor);
        return take + leave;
    }
};