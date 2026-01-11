/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* ans = root;
        int max_depth = 0;
        queue<TreeNode*> q;
        vector<int> depth(501, 0);
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<TreeNode*> max_lvl;
        q.push(root);
        depth[root->val] = 0;
        while (!q.empty()) {
            int size = q.size();
            max_lvl.clear();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                max_lvl.push_back(node);

                auto L = node->left;
                auto R = node->right;

                if (L) {
                    q.push(L);
                    parent[L] = node;
                }
                if (R) {
                    q.push(R);
                    parent[R] = node;
                }
            }
        }

        unordered_set<TreeNode*> deepest(max_lvl.begin(), max_lvl.end());
        while (deepest.size() > 1) {
            unordered_set<TreeNode*> next;
            for (auto i : deepest) {
                next.insert(parent[i]);
            }
            deepest = next;
        }
        ans = *deepest.begin();
        return ans;
    }
};