class TrieNode {
public:
    TrieNode* children[10];
    TrieNode() {
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    void insert(int num) {
        TrieNode* curr_node = root;
        string s = to_string(num);
        for (char dig : s) {
            if (!curr_node->children[dig - '0']) {
                curr_node->children[dig - '0'] = new TrieNode();
            }
            curr_node = curr_node->children[dig - '0'];
        }
    }

    int findLongestPrefix(int num) {
        TrieNode* node = root;
        string s = to_string(num);
        int len = 0;
        for (char dig : s) {
            if (node->children[dig - '0']) {
                len++;
                node = node->children[dig - '0'];
            } else {
                break;
            }
        }
        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        int ans = 0;
        for (auto i : arr1) {
            trie.insert(i);
        }
        for (int i : arr2) {
            ans = max(ans, trie.findLongestPrefix(i));
        }
        return ans;
    }
};