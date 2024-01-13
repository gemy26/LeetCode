class Solution {
public:
    int minSteps(string s, string t) {
       map<char,int>mp;
       map<char,int>mp2;
       for(auto i : s){
           mp[i]++;
       }
       for(auto i : t){
           mp2[i]++;
       }
       int cnt  =0;
       for(auto i : mp){
           if(mp2[i.first] < i.second){
                  cnt += (i.second-mp2[i.first]);
           }
       }
       return cnt;
    }
};