class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector <int> dig, ans;
        int n = digits.size();
        for(int i = 0 ; i < n; i ++){
            for(int j = 0; j < n; j ++){
                for(int k = 0; k < n ; k ++){
                    if(digits[k] == 0 || i == j || j == k || i == k) continue;
                    int num = digits[k] * 100 + digits[j] * 10 + digits[i];
                    if(num % 2 == 0){
                        ans.push_back(num);
                    }
                }
            }
        }
        set <int> st(ans.begin(), ans.end());
        vector <int> res(st.begin(), st.end());
        
        return res;
    }
};