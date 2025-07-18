class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector <string> t = s, temp;
        vector<vector<string>> ans;
        int idx = 0;
        map <string, vector <int>> mp;
        for(auto &i : t){
            sort(i.begin(), i.end());
        }

        for(auto i : t){
            mp[i].push_back(idx ++);
        }

        for(auto [i, j] : mp){
            temp.clear();
            for(auto k : j) temp.push_back(s[k]);
            ans.push_back(temp);
        }

        return ans;
    }
};