class Solution {
public:
    int numRabbits(vector<int>& a) {
        int n = (int)a.size(), ans = 0;
        map <int, int> mp;
        for (int i = 0; i < n; i++)
            mp[a[i]] ++;
        for(auto[f, s] : mp){
            ans += ((ceil((s * 1.0) / (f + 1))) * (f + 1));
        }    
        return ans;
    }
};