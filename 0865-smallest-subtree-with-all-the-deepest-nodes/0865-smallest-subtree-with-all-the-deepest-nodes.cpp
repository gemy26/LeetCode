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
    // depth, *node
    pair <int, TreeNode*> calc(TreeNode* root){
        if(!root) return{0, nullptr};

        pair <int, TreeNode*> L = calc(root->left);
        pair <int, TreeNode*> R = calc(root->right);

        if(L.first > R.first){
           return {L.first + 1, L.second};
        }else if(L.first < R.first){
            return {R.first + 1, R.second};
        }else{
            return {L.first + 1, root};
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return calc(root).second;
    }
};