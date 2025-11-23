class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        map<int, vector<int>> mp;
        int sum = 0, r;
        for(auto i : nums){
            mp[i % 3].push_back(i);
            sum += i;
        }

        r = sum % 3;

        sort(mp[1].begin(), mp[1].end());
        sort(mp[2].begin(), mp[2].end());

        if(r == 0) return sum;
        if(r == 1){
            // remove two elements from group rem 2 or one from group rem 1
            int ch1 = 0, ch2 = 0;
            if(!mp[1].empty()){
                ch1 = sum - mp[1][0];
            }
            if(mp[2].size() >= 2){
                ch2 = sum - (mp[2][0] + mp[2][1]);
            }
            sum = max(ch1, ch2);
        }
        else if(r == 2){
            // remove one element from group rem 2 or two from group rem 1
            int ch1 = 0, ch2 = 0;
            if(!mp[2].empty()){
                ch1 = sum - mp[2][0];
            }
            if(mp[1].size() >= 2){
                ch2 = sum - (mp[1][0] + mp[1][1]);
            }
            sum = max(ch1, ch2);
        }
        return sum;
    }
};