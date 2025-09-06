class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector <int> ans, vis(101, 0);
        for(auto i : friends) vis[i] = 1;
        for(auto i : order){
            if(vis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};