class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        else if(n == 2)
            return "11";    
        string s = "11";
        for(int i = 2; i < n; i ++){
            // cout <<"HERE" << endl;
            string temp = "";
            int cnt = 0;
            //3221
            for(int j = 0; j < s.size(); j ++){
                if(j + 1 < s.size() && s[j] == s[j + 1]){
                    cnt ++;
                }
                else{
                    temp += (char(cnt + 1) + '0');
                    temp += s[j];
                    //cout << i << " " << temp << endl;
                    cnt = 0;
                }
            }
            s = temp;
        }
        return s;
    }
};