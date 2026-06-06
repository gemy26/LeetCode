class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int>v;
 map<int,int>mp;
       for(int i =0 ;i < nums.size();i++){
           int x = target-nums[i];
           if(mp.find(x) != mp.end()){
               v.push_back(mp[x]), v.push_back(i); break;
           }
           else
           {
               mp.insert({nums[i],i});
           }
       }
       return v;
    }
};