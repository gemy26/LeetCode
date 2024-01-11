class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt  =0;
        int i = 0, j = 0;
        int gsz = g.size();
        int ssz = s.size();
        while(i < gsz && j < ssz){
            if(s[j] >= g[i]){
                i++,j++;
                cnt++;
            }
            else {
                j++;
            }
        }
        return cnt ;
    }
    
};