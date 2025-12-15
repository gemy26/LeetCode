class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0, cnt = 1;
        for(int i = 0; i < prices.size(); i ++){
            if(i + 1 < prices.size() && prices[i + 1] == prices[i] - 1){
                cnt ++;
            }
            else{
                if(cnt){
                    ans += (cnt * (cnt + 1)) / 2;
                    cnt = 1;
                }
                else{
                    ans ++;
                }
            }
        }
        return ans;
    }
};