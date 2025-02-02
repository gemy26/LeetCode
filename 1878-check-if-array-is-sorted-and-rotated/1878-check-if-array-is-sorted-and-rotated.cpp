class Solution {
public:
    bool check(vector<int>& a) {
        int l = 0, r = 0;
        for (int i = 0; i + 1 < a.size(); i++) {
            int diff = a[i + 1] - a[i];
            if (diff >= 0) {
                r = i;
            }
            else{
                bool ok = true;
                for(int j = i + 1; j + 1 < a.size(); j ++){
                    ok &= (a[j + 1] - a[j] >= 0);
                }
                if(!ok || a.back() > a[0]){
                    return false;
                }
            }
        }
        return true;
    }
};