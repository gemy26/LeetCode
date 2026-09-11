class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set <int> st;
        int n = digits.size();
        for(int i = 0; i < n; i ++){
            if(digits[i] == 0) continue;
            for(int j = 0; j < n; j ++){
                if (j == i) continue;
                for(int k = 0; k < n; k ++){
                    if(i != k && j != k && digits[k] % 2 == 0) {
                        int num = digits[i];
                        num *= 10;
                        num += digits[j];
                        num *= 10;
                        num += digits[k];
                        st.insert(num);
                    }
                }
            }
        }
        return st.size();
    }
};