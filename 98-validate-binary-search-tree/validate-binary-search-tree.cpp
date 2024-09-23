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

    bool validate(TreeNode* range_min, TreeNode* root, TreeNode* range_max) {
        if(!root)
            return true;

        if((range_min && root->val <= range_min->val) || (range_max && root->val >= range_max->val))
            return false;
        
        return validate(range_min, root->left, root) && validate(root, root->right, range_max);
    }

public:
    bool isValidBST(TreeNode* root) {
        // if(!root)
        //     return true;
        
        return validate(NULL, root, NULL);
    }
};