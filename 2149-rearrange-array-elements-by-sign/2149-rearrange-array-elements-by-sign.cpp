class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> pos, neg;
        for(auto i : nums){
            if(i > 0) pos.push_back(i);
            else neg.push_back(i);
        }  
        int l = 0, r = 0, i = 0;
        while(i < nums.size()){
            if(l < pos.size())nums[i ++] = pos[l ++];
            if(r < neg.size())nums[i ++] = neg[r ++];
        }
        return nums;
    }
};