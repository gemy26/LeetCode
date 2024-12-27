class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int n = (int) v.size();
        vector <int> a(n), b(n), suf(n, INT_MIN);
        for(int i = 0; i < n; i++){
            a[i] = v[i] + i;
            b[i] = v[i] - i;
        }
        suf.back() = b.back();
        for(int i = n - 2; i >= 0; i --){
            suf[i] = max(suf[i + 1], b[i]);
        }
        int ans = INT_MIN;
        for(int i = 0; i + 1 < n; i ++){
            ans = max(ans, a[i] + suf[i + 1]);
        }

        return ans;
    }
};