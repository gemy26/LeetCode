class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        int n = word.size();
        int ans = 0;
        
        vector <int> last_seen(27, -1), first_seen(27, -1);
        
        for(int i = 0; i < n; i ++){
            if(islower(word[i])){
                last_seen[word[i] - 'a'] = i;
            }else{
                if(first_seen[word[i] - 'A'] == -1){
                    first_seen[word[i] - 'A'] = i;
                }
            }
        }

        for(int i = 0; i < 27; i ++){
            if(~last_seen[i] && ~first_seen[i] && first_seen[i] > last_seen[i]) ans ++;
        }

        return ans;
    }
};