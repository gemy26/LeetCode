class Solution {
public:
    bool reorderedPowerOf2(int n) {
        bool ans = false;
        vector <string> powers;
        for(int i = 0; i < 32; i++){
            int x = (1 << i);
            string s = to_string(x);
            sort(s.begin(), s.end());
            powers.push_back(s);
        }

        string s = to_string(n);
        sort(s.begin(), s.end());
        for(int i = 0; i < 32; i++){
            if(s == powers[i])
                ans = true;
        }
        return ans;
    }
};