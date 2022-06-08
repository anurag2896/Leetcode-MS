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
        if(!root->left && !root->right)
            return true;
        return false;
    }
    
    void printLeft(TreeNode* root, vector<int>& ans) {
        if(root) {
            // auto ahead = root->left;
            while(root && !isLeaf(root)) {
                ans.push_back(root->val);
                if(root->left)
                    root=root->left;
                else
                    root=root->right;
            }
        }
        return;
    }
    
    void printRight(TreeNode* root, vector<int>& ans) {
        if(root) {
            vector<int> temp;
            // auto ahead = root->right;
            while(root && !isLeaf(root)) {
                temp.push_back(root->val);
                if(root->right)
                    root=root->right;
                else
                    root=root->left;
            }
            reverse(temp.begin(), temp.end());
            
            int n=temp.size();
            for(int i=0; i<n; i++)
                ans.push_back(temp[i]);
        }
        
        return;
    }
    
    void printLeafs(TreeNode* root, vector<int>& ans) {
        if(root) {
            printLeafs(root->left, ans);
            if(isLeaf(root))
                ans.push_back(root->val);
            printLeafs(root->right, ans);
        }
        return;
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if(root) {
            ans.push_back(root->val);
            printLeft(root->left, ans);
            printLeafs(root->left, ans);
            printLeafs(root->right, ans);
            printRight(root->right, ans);
        }
        return ans;
    }
};