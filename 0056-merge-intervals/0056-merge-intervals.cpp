class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> ans;
        sort(v.begin(), v.end());
        int l = v[0][0], r = v[0][1];
        for (int i = 1; i < v.size(); i++) {
            if (v[i][0] > r) {
                cout << l << " " << r << endl;
                vector<int> tmp;
                tmp.push_back(l);
                tmp.push_back(r);
                ans.push_back(tmp);
                l = v[i][0], r = v[i][1];
            }
            else{
                r = max(r, v[i][1]);
            }
        }
        cout << l << " " << r;
        vector<int> tmp;
        tmp.push_back(l);
        tmp.push_back(r);
        ans.push_back(tmp);

        return ans;
    }
};