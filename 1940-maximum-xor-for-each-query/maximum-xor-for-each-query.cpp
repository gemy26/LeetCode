class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        // frq for each bit 
        vector <int> frq(31, 0);
        for(int i = 0; i < (int) nums.size(); i++){
            for(int j = 0; j <= 30; j++){
                if( (nums[i] >> j) & 1){
                    frq[j] ++;
                }
            }
        }
        vector <int> ans;
        for(int i = (int) nums.size() - 1; i >= 0 ; i--){
            int k = 0;
             for(int j = 0; j <= 30; j++){
                if(frq[j] % 2 == 0 && j < maximumBit){
                    k += (1 << j);
                }
            }
            for(int j = 0; j <= 30; j++){
                if( (nums[i] >> j) & 1){
                    frq[j] --;
                }
            }
            ans.push_back(k);
        }
        return ans;
    }
};