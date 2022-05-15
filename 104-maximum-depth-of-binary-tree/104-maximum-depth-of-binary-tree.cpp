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
    int help(TreeNode* root, int h) {
        if(!root)
            return 0;
        h=1+max(help(root->left, h), help(root->right, h));
        return h;
    }
    
    int maxDepth(TreeNode* root) {
        int h=0;
        return help(root, h);
    }
};