class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector <int> ans;
        for(int i = 0; i + k - 1< nums.size(); i++){
            //cout << i << "-> ";
            int maxi = nums[i];
            bool f = true;
            for(int j = i + 1; j < i + k; j++ ){
                //cout << j << " ";
                maxi = max(maxi, nums[j]);
                if(nums[j] != nums[j - 1] + 1){
                    f = false;
                    // cout << "here" << " " << j << endl ;
                }
            }
            //cout << endl;
            if(!f){
                maxi = -1;
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};