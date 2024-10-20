class Solution {
public:
    int compress(vector<char>& chars) {
    int n = (int) chars.size();
    vector <char> res;
    int i = 0;
    for(; i < n;){
        int j = i + 1;
        int cnt = 1;
        while(j < n && chars[i] == chars[j]) j++, cnt++;
        if(cnt > 1){
            res.push_back(chars[i]);
            string s = to_string(cnt);
            for(auto c : s) res.push_back(c);
            // res.push_back(cnt + '0');
        }
        else {
            res.push_back(chars[i]);
        }
        i = j;
    }
    chars.resize((int) res.size());
    chars = res;
    return (int) res.size();
        
    }
};