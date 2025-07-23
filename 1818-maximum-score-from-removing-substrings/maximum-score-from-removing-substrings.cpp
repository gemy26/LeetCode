class Solution {
public:
    int process(string pattern, string& s, int val){
        int sum = 0;
        stack <pair <char, int>> stk;
        string new_s = "";
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == pattern[1]) {
                if(!stk.empty() && stk.top().first == pattern[0]){
                    sum += val;
                    s[stk.top().second] = '*';
                    s[i] = '*';
                    stk.pop();
                }
            }
            else if(s[i] == pattern[0]){
                stk.push({s[i], i});
            }
            else{
                while(!stk.empty()) stk.pop();
            }
        }

        for(auto i : s){
            if(i != '*')
                new_s += i;
        }
        // cout << new_s << endl;
        s = new_s;
        return sum;
    }
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        if(y > x){
            ans += process("ba", s, y);
            // cout << "after :"  << s << endl;
            ans += process("ab", s, x);
        }
        else{
            ans += process("ab", s, x);
            ans += process("ba", s, y);
        }
        return ans;
    }
};