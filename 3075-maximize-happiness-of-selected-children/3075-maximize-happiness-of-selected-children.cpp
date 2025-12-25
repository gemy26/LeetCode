class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        int cnt = 0;
        multiset <int> s(happiness.begin(), happiness.end());
        sort(happiness.begin(), happiness.end());
        for(int i = 0; i < k; i ++){
            int curr = *s.rbegin();
            if(curr - cnt <= 0) break;
            s.erase(prev(s.end()));
            ans += (curr - cnt);
            cnt ++;
        }
        return ans;
    }
};