class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
       int n = nums.size(); 
       set <int> st;
        for(auto i : nums){
            st.insert(stoi(i, nullptr, 2));
        }
        for(int i = 0; i <= (1 << n); i ++){
            if(st.count(i) == 0){
                ans = bitset<32>(i).to_string();
                return ans.substr(32 - n);
            }
        }
        return "";
    }
};