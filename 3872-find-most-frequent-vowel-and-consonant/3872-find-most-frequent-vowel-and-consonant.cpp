class Solution {
public:
    int maxFreqSum(string s) {
        map <char, int> mp;
     for(auto i : s) mp[i] ++;
     int maxi_1 = 0, maxi_2 = 0;
     for(auto[ch, frq] : mp){
        if(ch == 'a' || ch == 'e' || ch == 'i' ||ch == 'o' || ch == 'u' ){
            maxi_1 = max(maxi_1, frq);
        }
        else{
            maxi_2 = max(maxi_2, frq);
        }
     }
     return maxi_1 + maxi_2;   
    }
};