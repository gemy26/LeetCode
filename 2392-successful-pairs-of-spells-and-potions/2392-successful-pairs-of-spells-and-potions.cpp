class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = (int) spells.size(), m = (int) potions.size();
        sort(potions.begin(), potions.end());
        vector <int> ans(n, 0);
        for(int i = 0; i < n; i ++){
            int l = 0, r = m - 1, res = -1;
            while(r >= l){
                int mid = (l + r) / 2;
                //find first l where spell[i] * potion[l] >= success

                if(1LL * potions[mid] * spells[i] >= success){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                    res = mid;
                }
            }

            ans[i] = m - res - 1;
        }
        return ans;
    }
};