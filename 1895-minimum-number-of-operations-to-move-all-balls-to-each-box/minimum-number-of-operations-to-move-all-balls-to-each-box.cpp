class Solution {
public:
    vector<int> minOperations(string s) {
        vector <int> prefix((int) s.size() + 1, 0), suffix((int) s.size() + 1, 0), frq(3000, 0), ans(s.size(), 0);
    for(int i = 0; i < (int) s.size(); i ++){
        if(s[i] == '1'){
            frq[i] ++;
            prefix[i] = i + 1;
            suffix[i] = i + 1;
        }
        if(i){
            frq[i] += frq[i - 1];
            prefix[i] += prefix[i - 1];
        }
    }
    for(int i = s.size() - 2; ~i; i --){
        suffix[i] += suffix[i + 1];
    }

    for(int i = 0; i < (int) s.size(); i ++ ){
        int pre = abs(( (frq[i]- (s[i] == '1' ? 1 : 0)) * (i + 1) )  - (i ? prefix[i - 1] : 0));
        int suf = abs(suffix[i + 1] - ((frq[s.size() - 1] - frq[i] ) * (i + 1)) );
        ans[i] = pre + suf;
    }

    return ans;
    }
};