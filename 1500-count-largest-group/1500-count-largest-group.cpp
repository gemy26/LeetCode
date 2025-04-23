class Solution {
public:
    int countLargestGroup(int n) {
        int ans = 0, maxi = 0;
        map <int, int> mp;
        for(int i = 1; i <= n; i ++){
            string s = to_string(i);
            int curr_sum = 0;
            for(int j = 0; j < (int) s.size(); j ++){
                curr_sum += (s[j] - '0');
            }
            mp[curr_sum] ++;
            maxi = max(maxi, mp[curr_sum]);
        }
        for(auto[_, i] : mp){
            if(i == maxi)
                ans ++;
        }
        return ans;
    }
};