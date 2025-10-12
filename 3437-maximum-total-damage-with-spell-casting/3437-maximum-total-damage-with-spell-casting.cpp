class Solution {
public:
    long long solve(int idx, vector<pair<long long,long long>> &v, vector<long long> &dp)
    {
        if(idx>=v.size()){
            return 0;
        }
        
        if(dp[idx]!=-1) return dp[idx];

        //skip current
        long long skip = solve(idx+1,v,dp);

        //if we consider the current one -> we need to decide what will be the next valid idx
        int j = idx+1;
        while(j<v.size() && v[j].first<=v[idx].first+2) j++;

        long long consider = v[idx].second + solve(j,v,dp);

        return dp[idx]=max(skip,consider);
    }
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        map<long long,long long> mp;
        for(int i=0;i<n;i++)
        {
            mp[power[i]]+=power[i];
        }
        vector<pair<long long,long long>> v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end());
        vector<long long> dp(v.size(), -1);
        return solve(0,v,dp);
    }
};