class Solution {
public:
    bool isVowel(char i){
        i = tolower(i);
        if(i == 'a'|| i == 'e'
            || i == 'i' || i == 'o'
            || i =='u')
            return true;
        return false;    
    }
    bool isValid(string word) {
        bool ans = true;
        int f[4] = {};
        if(word.size() >= 3){
            f[0] ++;
        }
        for(auto i : word){
            if(isVowel(i)){
                f[2] ++;
            }
            if(isalpha(i) && !isVowel(i)){
                f[3] ++;
            }
            if(!isalpha(i) && !isdigit(i)){
                f[1] ++;
            }
            
        }
        cout << f[0] << " "<< f[1] << " " << f[2] <<
         " "<<f[3] << endl;
        if(f[1] || !f[0] || !f[2] || !f[3])
            return false;
        return true;    
    }
};