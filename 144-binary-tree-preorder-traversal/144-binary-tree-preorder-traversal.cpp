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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root) {
            if(!root->left) {
                ans.push_back(root->val);
                root=root->right;
            } else {
                auto pred = root->left;
                while(pred->right && pred->right!=root) {
                    pred=pred->right;
                }
                if(pred->right!=root) {
                    ans.push_back(root->val);
                    pred->right = root;
                    root = root->left;
                } else {
                    pred->right = NULL;
                    root = root->right;
                }
            }
        }
        return ans;
    }
};