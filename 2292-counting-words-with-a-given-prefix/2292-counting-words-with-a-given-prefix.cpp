struct Trie {
    Trie* children[26];
    bool endOfWord;
    int cnt;

    Trie() {
        memset(children, 0, sizeof(children));
        endOfWord = false;
        cnt = 0;
    }

    void insert(string &s, int idx = 0) {
        if (idx == s.size()) return;
        auto c = s[idx]-'a';
        if (children[c] == nullptr) children[c] = new Trie();
        if (idx+1 == s.size()) endOfWord = true;
        children[c]->cnt ++;
        children[c]->insert(s, idx+1);
    }

    bool check(string &s, int idx = 0) {
        if (idx == s.size()) return true;
        auto c = s[idx]-'a';
        if (children[c] == nullptr) return false;
        return children[c]->check(s, idx+1);
    }

    int prefix(string &s, int idx = 0){
        if (idx == s.size() - 1) { if(children[s[idx] - 'a'] == nullptr) return 0; else return children[s[idx] - 'a']->cnt; }
        auto c = s[idx]-'a';
        if (children[c] == nullptr) return 0;
        return children[c]->prefix(s, idx+1);
    }
};


class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie ;
        int ans = 0;
        for(int i = 0; i < words.size(); i ++){
            trie.insert(words[i]);
        }
        return trie.prefix(pref);
    }
};