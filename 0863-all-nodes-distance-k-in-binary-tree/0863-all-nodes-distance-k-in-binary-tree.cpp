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
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void inorder(TreeNode* root) {
        if (!root)
            return;

        if (root->left) {
            parent[root->left] = root;
        }
        inorder(root->left);
        if (root->right) {
            parent[root->right] = root;
        }
        inorder(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inorder(root);
        vector<int> ans;
        queue<TreeNode*> q;
        set<TreeNode*> visited;
        q.push(target);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (level == k)
                break;
            level++;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                visited.insert(node);

                if (node->left && !visited.count(node->left))
                    q.push(node->left);
                if (node->right && !visited.count(node->right))
                    q.push(node->right);

                TreeNode* par = parent[node];
                if (par && !visited.count(par))
                    q.push(par);
            }
        }
        while (!q.empty()) {
            TreeNode* node = q.front();
            ans.push_back(node->val);
            q.pop();
        }
        return ans;
    }
};