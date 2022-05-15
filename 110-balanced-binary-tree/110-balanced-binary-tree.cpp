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
    int helper(TreeNode* root, bool &flag) {
        int l, r;
        if(!root)
            return 0;
        else {
            l=helper(root->left, flag);
            r=helper(root->right, flag);
            if(abs(l-r)>1)
                flag=false;
        }
        return 1+max(l,r);
    }
    
    bool isBalanced(TreeNode* root) {
        bool flag=true;
        if(!root)
            return true;
        helper(root, flag);
        if(flag)
            return true;
        return false;
    }
};