struct TrieNode{
    TrieNode *child[26];
    bool isEnd;
    TrieNode(){
        memset(child, 0, sizeof(child));
        isEnd = false;
    }
};
class Solution {
public:
    TrieNode* root = new TrieNode();
    void insert(string &word){
        TrieNode *node = root;
        for(char c : word){
            int idx = c - 'a';
            if(!node->child[idx]) node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    bool dfs(string &word, int i, TrieNode* node, int cnt){
        if(!node) return false;
        if(cnt > 2) return false;
        if(i == word.size()){
            return node->isEnd;
        }
        int idx = word[i] - 'a';
        if(node->child[idx]){
            if(dfs(word, i + 1, node->child[idx], cnt)){
                return true;
            }
        }
        if(cnt < 2){
            for(int c= 0; c < 26; c ++){
                if(c == idx) continue;
                if(node->child[c]){
                    if(dfs(word, i + 1, node->child[c], cnt + 1)) return true;
                }
            }
        }
        return false;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        for (auto& w : dictionary) insert(w);
        vector <string> ans;
        for(auto& i : queries){
            if(dfs(i, 0, root, 0)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};