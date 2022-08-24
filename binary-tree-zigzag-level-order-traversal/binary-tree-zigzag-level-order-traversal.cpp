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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int level=0;
        vector<vector<int>> result;
        if(!root)
            return result;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> temp;
            int len=q.size();
            for(int i=0; i<len; i++) {
                auto front=q.front();
                q.pop();
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
                temp.push_back(front->val);
            }
            if(level%2==1)
                reverse(temp.begin(), temp.end());
            
            level++;
            result.push_back(temp);
        }
        return result;
    }
};