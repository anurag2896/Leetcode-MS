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
    int helper(TreeNode* root, bool& bal) {
        if(!root)
            return 0;
        int lh = helper(root->left, bal);
        int rh = helper(root->right, bal);
        if(abs(lh-rh)>1)
            bal=false;
        return 1+max(lh, rh);
    }
    
    bool isBalanced(TreeNode* root) {
        bool bal = true;
        helper(root, bal);
        return bal;
    }
};