class Solution {
public:
    vector<string> wordSubsets(vector<string>& a, vector<string>& b) {
        vector<string> ans;
        vector<vector<int>> frq_a((int)a.size(), vector<int>(30, 0));
        vector<int> frq_b(30, 0), frq((int)a.size(), 0);
        for (int i = 0; i < (int)a.size(); i++) {
            for (auto ch : a[i]) {
                frq_a[i][ch - 'a'] ++;
            }
        }

        for (int i = 0; i < (int)b.size(); i++) {
            vector <int> tmp_frq(30, 0);
            for (auto ch : b[i]) {
                tmp_frq[ch - 'a'] ++;
            }
            for (char c = 'a'; c <= 'z'; c++){
                frq_b[c - 'a'] = max(frq_b[c - 'a'], tmp_frq[c - 'a']);
            }

        }

        for (int j = 0; j < (int)a.size(); j++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (frq_a[j][c - 'a'] < frq_b[c - 'a']) {
                    frq[j] = -1;
                }
            }
        }

        for (int i = 0; i < (int)a.size(); i++) {
            if (frq[i] != -1) {
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};