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
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int n, levels=0;
        if(!root)
            return ans;
        
        q.push(root);
        vector<int> temp;
        while(!q.empty()) {
            temp.clear();
            n=q.size();
            for(int i=0; i<n; i++) {
                auto t = q.front();
                q.pop(); 
                temp.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            if(levels%2==0)
                ans.push_back(temp);
            else {
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            levels++;
        }
        return ans;
    }
};