
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = (int)code.size();
        vector<int> prefix(n), res(n);
        for (int i = 0; i < code.size(); i++) {
            prefix[i] = code[i];
            if (i) {
                prefix[i] += prefix[i - 1];
            }
        }
        if (k >= 0) {
            for (int i = 0; i < code.size(); i++) {
                if (i + k < n) {
                    res[i] = prefix[i + k] - prefix[i];
                } else {
                    res[i] = prefix[k - (n - i - 1) - 1] + prefix.back() - prefix[i];
                }
            }
        }
        else{
             for (int i = 0; i < code.size(); i++) {
                if(i >= abs(k)){
                    res[i] = prefix[i - 1] - (i + k - 1 < 0 ? 0 : prefix[i + k - 1]);
                }
                else{
                    if(i == 0){
                        res[i] = prefix.back() - prefix[n + k - 1];
                    }
                    else{
                        res[i] = prefix[i - 1] + prefix.back() - prefix[n - 1 - abs(k) + i];
                    }
                }
             }
        }

        return res;
    }
};