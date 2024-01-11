class Solution {
public:
    int minOperations(vector<int>& nums) {
        map <int, int> freq;
        for(auto &i: nums)
            freq[i] ++;
        int res = 0, x;
        for(auto &i: freq){
            int j = i.second;
            if(j == 1){
                res = -1;
                break;
            }
            x = j/3;
            if((j&1 && !(x&1)) || (!(j&1) && x&1)){
                x --;
            }
            res += x + (j - x*3) / 2;
        }
        return res;
    }
};