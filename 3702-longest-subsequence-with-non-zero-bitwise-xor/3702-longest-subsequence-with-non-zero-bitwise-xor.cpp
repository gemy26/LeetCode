class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // zeros, ones => odd, odd or even odd
        // try to execlude to convrt 
        // at least one true in all 32 bit
        // i think removing one element is enough 
        // so its easier to get XOR of the full array then check 
        // which element could be removed to get non-zero XOR
        // but the element itself does not matter so if the answer not n its n - 1

        int XOR = 0; int allZero = 0; int n = nums.size();
        for(auto i : nums) {
            // cout << i << endl;
            allZero += ( i == 0 );
            XOR ^= i;
        }
        if(XOR > 0) return n;
        return allZero == n ? 0 : n - 1;
    }
};