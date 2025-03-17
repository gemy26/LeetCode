class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int frq[501] = {};
        for(auto i : nums)
            frq[i] ++;
        bool ans = true;    
        for(auto i : frq){
            ans &= !(i & 1);
        }    
        return ans;
    }
};