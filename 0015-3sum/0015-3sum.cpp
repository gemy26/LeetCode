class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector <vector <int>> triplets;
        int n = nums.size();
        for(int i = 0; i < n - 2; i ++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while(k > j) {
                if(-nums[i] == nums[j] + nums[k]) {
                    triplets.push_back({nums[i], nums[j] ,nums[k]});
                    j ++;
                    while(nums[j] == nums[j - 1] && j < k) j ++;
                }else if(-nums[i] > nums[j] + nums[k]) {
                    j ++;
                } else {
                    k --;
                }
            }
        }
        return triplets;
    }
};