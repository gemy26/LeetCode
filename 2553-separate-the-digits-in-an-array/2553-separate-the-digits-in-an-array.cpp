class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector <int> ans;
        for(auto i : nums){
            int num = i;
            stack <int> digits;
            while(num > 0){
                int dig = num % 10;
                num /= 10;
                digits.push(dig);
            }
            while(!digits.empty()){
                ans.push_back(digits.top());
                digits.pop();
            }
        }
        return ans;
    }
};