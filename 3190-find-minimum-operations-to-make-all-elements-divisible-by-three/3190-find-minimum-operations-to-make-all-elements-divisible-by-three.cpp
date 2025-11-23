class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(auto i : nums){
            ans += min(i % 3, 3 - (i % 3));
        }
        return ans;
    }
};