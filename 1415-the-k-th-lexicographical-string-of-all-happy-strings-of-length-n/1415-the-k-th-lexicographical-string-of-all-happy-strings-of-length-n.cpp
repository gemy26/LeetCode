class Solution {
public:
    int N;
    vector <string> happy_string;
    void generate(int idx, string s){
        if(idx >= N){
            happy_string.push_back(s);
            return;
        }
        for(char ch = 'a'; ch <= 'c'; ch ++){
            if(s.size() > 0 && ch == s.back()) continue;
            generate(idx + 1, s + ch);
        }
    }
    string getHappyString(int n, int k) {
        N = n;
        generate(0, "");
        sort(happy_string.begin(), happy_string.end());
        if(k - 1 >= happy_string.size()){
            return "";
        }
        return happy_string[k - 1];
    }
};