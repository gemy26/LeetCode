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
    
    int res = 0;
    void solve(TreeNode* p, int mini, int maxi) {
        if (p == nullptr)
            return;

        maxi = max(maxi,p->val);
        mini = min(mini,p->val);
        res = max({res, abs(mini - p->val), abs(maxi - p->val)});
        solve(p->left,mini,maxi);
        solve(p->right,mini,maxi);
    }
    int maxAncestorDiff(TreeNode* root) {

        // pair<int,int>right = make_pair(root->val, root->val);
        solve(root,root->val,root->val);

        return res;
    };
};