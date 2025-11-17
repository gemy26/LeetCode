class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt0 = 0;
        bool ans = true, f = false;
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] == 0) cnt0 ++;
            else{
                if(f){
                    ans &= (cnt0 >= k);
                }
                cnt0 = 0;
                f = true;
            }
        }
        return ans;
    }
};