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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root) {
            if(root->right==NULL) {
                ans.push_back(root->val);
                root=root->left;
            } else {
                auto pred = root->right;
                while(pred->left && pred->left!=root) {
                    pred=pred->left;
                }
                if(pred->left==NULL) {
                    ans.push_back(root->val);
                    pred->left=root;
                    root=root->right;
                } else {
                    // ans.push_back(root->val);
                    pred->left=NULL;
                    root=root->left;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};