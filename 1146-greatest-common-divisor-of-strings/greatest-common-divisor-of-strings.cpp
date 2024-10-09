class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int x = str1.size();
        int y = str2.size();
        int period = gcd(x, y);
        string res = "";
        for(int i = 0; i < period; i++) res += str1[i];
        bool f = true;
        for(int i = 0; i < x; i++){
            if(str1[i] != res[i%period]){
             f = false; 
            } 
        }
        if(!f){
            res = "";
        }
        f = true;
        for(int i = 0; i < y; i++){
            if(str2[i] != res[i%period]){
             f = false; 
            } 
        }
        if(!f){
            res = "";
        }
        return res;
    }
};