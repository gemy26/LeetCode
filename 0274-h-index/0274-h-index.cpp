class Solution {
public:
    int hIndex(vector<int>& c) {
        // citations[i] <= n - i => maximize
        int ans = 0;
        int n = c.size();
        sort(c.rbegin(), c.rend());
        for(int i = 0; i < n; i ++){
            // cout << i + 1  << "  " << c[i] << endl;
            if(c[i] >= i + 1){
                ans = i + 1;
            }
        }
        return ans;
    }
};