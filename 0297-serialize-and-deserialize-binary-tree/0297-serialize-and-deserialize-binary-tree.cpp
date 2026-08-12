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
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (!temp) {
                ans += "N,";
            } else {
                ans += to_string(temp->val) + ",";
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;

        stringstream ss(data);
        string str;

       if (!getline(ss, str, ',') || str == "N" || str.empty()) return NULL;

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (getline(ss, str, ',') && str != "N" && !str.empty()){
                temp->left = new TreeNode(stoi(str));
                q.push(temp->left);
            }

         if (getline(ss, str, ',') && str != "N" && !str.empty()){
                temp->right = new TreeNode(stoi(str));
                q.push(temp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));