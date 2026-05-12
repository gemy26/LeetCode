class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector <int> ans;
        for(auto i : nums){
            int num = i;
            string str = to_string(i);
            for(auto j : str){
                ans.push_back(j - '0');
            }
        }
        return ans;
    }
};