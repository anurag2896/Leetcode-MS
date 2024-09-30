/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {

    string serializeUtil(TreeNode* root) {
        if(!root)
            return "#";
        
        return to_string(root->val) + "," + serializeUtil(root->left) + "," + serializeUtil(root->right);
    }

    TreeNode* deserializeUtil(stringstream& ss, string temp) {
        getline(ss, temp, ',');
        if(temp=="#")
            return NULL;

        TreeNode* root = new TreeNode(stoi(temp));
        root->left = deserializeUtil(ss, temp);
        root->right = deserializeUtil(ss, temp);
        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return serializeUtil(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root;
        
        stringstream ss(data);
        string temp;
        return deserializeUtil(ss, temp);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));