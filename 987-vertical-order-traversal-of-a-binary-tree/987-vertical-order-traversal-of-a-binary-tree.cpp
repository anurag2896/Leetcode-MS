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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> m;
        queue<pair<int, pair<int, TreeNode*>>> q;
        vector<vector<int>> ans;
        if(root) {
            q.push({0, {0, root}});
            while(!q.empty()) {
                auto p = q.front();
                q.pop();
                int col = p.first;
                int level = p.second.first;
                auto node = p.second.second;
                m[col][level].insert(node->val);
                if(node->left)
                    q.push({col-1, {level+1, node->left}});
                if(node->right)
                    q.push({col+1, {level+1, node->right}});
            }
        }
        for(auto elem:m) {
            vector<int> temp;
            for(auto subelem:elem.second) {
                for(auto e:subelem.second) {
                    temp.push_back(e);
                }
                // ans.push_back(vector<int>(subelem.second.begin(), subelem.second.end()));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};