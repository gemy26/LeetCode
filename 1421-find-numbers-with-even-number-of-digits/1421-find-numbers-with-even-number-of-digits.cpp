class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto i : nums){
            int len = to_string(i).size();
            ans += (len % 2 == 0);
            }
        return ans;    
    }
};