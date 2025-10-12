class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        int n = (int) v.size();
        vector <int> ans(n);
        stack <pair <int, int>> stk;

        for(int i = n - 1; i >= 0; i --){
            while(!stk.empty() && v[i] >= stk.top().first){
                stk.pop();
            }
            ans[i] = stk.size() ? stk.top().second - i : 0;
            stk.push({v[i], i});
        }
        return ans;
    }
};