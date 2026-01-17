class Solution {
public:
    unordered_set<int> calc(int n, vector<int>& v) {
        unordered_set<int> st;
        v.push_back(1);
        v.push_back(n);

        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                st.insert(v[j] - v[i]);
            }
        }
        return st;
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        auto hl = calc(m, hFences);
        auto vl = calc(n, vFences);

        int maxl = -1;

        for (auto i : hl) {
            if (vl.count(i)) {
                maxl = max(maxl, i);
            }
        }

        if (maxl == -1) {
            return -1;
        }

        int ans =  1LL * maxl * maxl % 1000000007;
        return ans;
    }
};