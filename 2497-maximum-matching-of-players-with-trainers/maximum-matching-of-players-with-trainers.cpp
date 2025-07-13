class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& a, vector<int>& b) {
        int ans = 0, i = 0, j = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        while(i < a.size() && j < b.size()){
            if(a[i] <= b[j]){
                ans ++;
                i ++, j ++;
            }
            else if(b[j] < a[i]){
                j ++;
            }
        }
        return ans;
    }
};