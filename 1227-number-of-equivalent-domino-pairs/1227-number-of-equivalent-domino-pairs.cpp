class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size(), ans = 0;
        vector <int> v;
        for(int i = 0; i < n; i ++){
            sort(dominoes[i].begin(), dominoes[i].end());
            v.push_back(dominoes[i][0] * 10 + dominoes[i][1]);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i ++){
            auto it = upper_bound(v.begin(), v.end(), v[i]) - v.begin() - 1;
            ans +=  (it - i);
           // cout << i << " " << it << endl;
        }
        return ans;
    }
};