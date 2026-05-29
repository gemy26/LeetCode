class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 36;
        for(auto num : nums){
            int sum = 0;
            while(num > 0){
                sum += num % 10;
                num /= 10;
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};