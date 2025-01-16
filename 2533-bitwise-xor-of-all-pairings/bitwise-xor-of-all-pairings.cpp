class Solution {
public:
    int xorAllNums(vector<int>& a, vector<int>& b) {
        map<int, long long > mp;
        int ans = 0;

        for (auto i : a) {
            mp[i]++;
        }

        for (auto& [key, val] : mp) {
            val *= (int) b.size();
        }

        for (auto i : b) {
            mp[i] += (int) a.size();
        }

        for (auto& [key, val] : mp) {
            if(val&1){
                ans ^= key;
            }
        }

        return ans;
    }
};