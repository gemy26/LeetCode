class Solution {
public:
    int N;
    vector <string> happy_string;
    void generate(int idx, string s){
        if(idx >= N){
            happy_string.push_back(s);
            return;
        }
        if(idx){
            if(s[idx - 1] == 'a'){
                generate(idx + 1, s + 'b');
                generate(idx + 1, s + 'c');
            }
            else if(s[idx - 1] == 'b'){
                generate(idx + 1, s + 'a');
                generate(idx + 1, s + 'c');
            }
            else{
                generate(idx + 1, s + 'a');
                generate(idx + 1, s + 'b');
            }
        }
        else{
            generate(idx + 1, "a");
            generate(idx + 1, "b");
            generate(idx + 1, "c");
        }
    }
    string getHappyString(int n, int k) {
        N = n;
        generate(0, "");
        if(k - 1 >= happy_string.size()){
            return "";
        }
        return happy_string[k - 1];
    }
};