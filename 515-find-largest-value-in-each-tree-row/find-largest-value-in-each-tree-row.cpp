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
    vector<int> largestValues(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<int> ans(100000, INT_MIN);
       // ans[0] = root -> val;
        int lvls = 0;
        q.push({root, 0});
        int maxi = 0;
        while (!q.empty()) {
            auto [node, lvl] = q.front();
            q.pop();
            if(node == nullptr) break;
            ans[lvl + 1] = max(ans[lvl + 1], node -> val);
            lvls = max(lvls, lvl + 1);
            if (node->left != nullptr) {
                q.push({node -> left, lvl + 1});
            }
            if (node->right != nullptr) {
                q.push({node -> right, lvl + 1});
            }
            lvls = max(lvls, lvl + 1);
        }
        vector <int> res(ans.begin() + 1, ans.begin() + lvls + 1);
        return res ;
    }
};