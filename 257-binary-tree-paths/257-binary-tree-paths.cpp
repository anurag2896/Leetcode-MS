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
    bool isLeaf(TreeNode* root) {
        if(root && !root->left && !root->right)
            return true;
        return false;
    }
    
    void helper(TreeNode* root, vector<string>& ans, string s) {
        if(root) {
            if(isLeaf(root)) {
                s+=to_string(root->val);
                ans.push_back(s);
                return;
            }
            s+=to_string(root->val)+"->";
            helper(root->left, ans, s);
            helper(root->right, ans, s);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root)
            helper(root, ans, "");
        return ans;
    }
};