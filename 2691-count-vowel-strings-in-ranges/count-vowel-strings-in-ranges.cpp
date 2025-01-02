class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector <int> prefix(words.size(), 0);
        vector <int> ans (queries.size());
        cout << "here 1\n";
        for(int i = 0; i < words.size(); i++){
            if(isVowel(words[i][0]) && isVowel(words[i][words[i].size()-1])){
                prefix[i] ++;
            }
            if(i){
                prefix[i] += prefix[i - 1];
            }
        }

        cout << "here 2\n";

        for(int i = 0; i < queries.size(); i ++){
            cout << i << " ";
            ans[i] = prefix[queries[i][1]] - ( queries[i][0] - 1 >= 0 ? prefix[queries[i][0] - 1] : 0 );
        }

        return ans;
    }
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};