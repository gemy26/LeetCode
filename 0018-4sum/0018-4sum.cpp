class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<vector<int>>ans;
        for(int i = 0; i < n - 3; i ++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n - 2; j ++){
                // if(nums[j] == nums[i]) continue;
                int k = j + 1, m = n - 1;
                long long  curr_tar = (long long)target - (long long)nums[i] - (long long)nums[j];
                while(k < m){
                    if(nums[k] + nums[m] > curr_tar){
                        m --;
                    }
                    else if(nums[k] + nums[m] < curr_tar){
                        k ++;
                    }
                    else{
                        // ans.push_back({nums[i], nums[j], nums[k], nums[m]});
                        st.insert({nums[i], nums[j], nums[k], nums[m]});
                        k ++, m --;
                        //k ++;
                        // while(nums[k] == nums[k - 1]) k++;
                    }
                }
                // cout << i << " " << j << " " << k << " " << m << endl;
            }
        }
        for(auto i : st) ans.push_back(i);
        return ans;
    }
};