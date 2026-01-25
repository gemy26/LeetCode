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
    long long ans = 1LL;
    int mod = 1000000007;
    long long calc_sum(TreeNode* root){
        if(!root) return 0;
        if(root->left) root->val += calc_sum(root->left);
        if(root->right) root->val += calc_sum(root->right);
        return root->val;
    }

    void calc_prod(TreeNode* root, TreeNode* node){
        if(!node) return;
        if(node->left)  calc_prod(root, node->left);
        if(node->right) calc_prod(root, node->right);
        long long b = root->val - node->val;
        long long a = node->val;
        ans = max(ans, a * b);
    }
    int maxProduct(TreeNode* root) {
        // calc all subtree sum 
        // after that traverse and calc possible answer 
        // sub_tree[a] = sub_tree[root] - sub_tree[b]
        // ans = max(ans, a * b)

        calc_sum(root);
        calc_prod(root, root);
        return ans % mod;
    }
};