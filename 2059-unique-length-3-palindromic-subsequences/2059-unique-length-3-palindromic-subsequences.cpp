class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char, vector<int>> mp;
        vector < vector <int> > frq(27, vector <int> (s.size() + 1, 0));
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
            frq[s[i]- 'a'][i] ++;
        }
        for(int i = 0; i < 27; i ++){
            for(int j = 1; j < s.size(); j ++){
                frq[i][j] += frq[i][j - 1];
            }
        }
        for (auto [c, v] : mp) {
            if (v.size() >= 2) {
                int first = v[0], last = v.back();
                for(auto [ch, v2] : mp){
                    ans += ( frq[ch - 'a'][last - 1] - frq[ch - 'a'][first] > 0) ;
                }
            }
        }
        return ans;
    }
};