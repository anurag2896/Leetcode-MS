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
    int dfs(TreeNode* root, int& ans) {
        if(!root)
            return 0;
        
        int l = dfs(root->left, ans);
        if(l<0)
            l=0;
        
        int r = dfs(root->right, ans);
        if(r<0)
            r=0;
        
        // sum = max(0, root->val + l + r)
        ans = max(ans, root->val + l + r);

        return root->val + max(l, r);
    }

public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        dfs(root, ans);
        return ans;
    }
};