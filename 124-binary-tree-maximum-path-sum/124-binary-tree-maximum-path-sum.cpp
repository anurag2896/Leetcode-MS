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
    int helper(TreeNode* root, int &result) {
        if(!root)
            return 0;
        int l = max(helper(root->left, result), 0);
        int r = max(helper(root->right, result), 0);
        result = max(result, l+r+root->val);
        return max(l,r)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int result=INT_MIN;
        if(!root)
            return 0;
        helper(root, result);
        return result;
    }
};