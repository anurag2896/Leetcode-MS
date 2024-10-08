/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    bool find(TreeNode* root, TreeNode* p) {
        if(!root)
            return false;
        
        if(root->val == p->val)
            return true;
        
        return find(root->left, p) || find(root->right, p);
    }

    TreeNode* getLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;

        if(root==p || root==q)
            return root;
        
        TreeNode* l = getLCA(root->left, p, q);
        TreeNode* r = getLCA(root->right, p, q);

        if(l && r)
            return root;
        else if(l)
            return l;
        else if(r)
            return r;
        
        return NULL;

    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!(find(root, p) && find(root, q)))
            return NULL;

        return getLCA(root, p, q);
    }
};