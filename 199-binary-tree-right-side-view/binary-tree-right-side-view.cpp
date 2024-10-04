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

    void traverse(TreeNode* root, int index, map<int, int>& m) {
        if(!root)
            return;
        traverse(root->left, index+1, m);
        m[index] = root->val;
        traverse(root->right, index+1, m);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;

        map<int, int> m;
        traverse(root, 0, m);
        
        for(auto ele:m) {
            ans.push_back(ele.second);
        }
        return ans;
    }
};