class Solution {
public:
    bool isArraySpecial(vector<int>& v) {
        for(int i = 0; i + 1 < v.size(); i ++){
            if(v[i] % 2 == v[i + 1] % 2 )
                return false;
        }
        return true;
    }
};