/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int max_lvl = -1;
     int res = 0;
     void traverse(TreeNode *node,int lvl=0){
         if(max_lvl < lvl){
             res = node->val;
             max_lvl = lvl;
         }
         if(node->left != NULL){
             traverse(node->left,lvl+1);
         }
         if(node -> right != NULL){
             traverse(node->right,lvl+1);
         }
         
     }
    int findBottomLeftValue(TreeNode* root) {
        traverse(root);
        return res;
    }
};