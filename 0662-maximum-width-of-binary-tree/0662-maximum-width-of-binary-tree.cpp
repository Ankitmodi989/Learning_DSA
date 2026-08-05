/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (!root)
            return 0;

        int width = 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            unsigned long long min_idx = q.front().second;
            unsigned long long left, right;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front().first;
                unsigned long long index = q.front().second - min_idx;
                q.pop();
                if (i == 0)
                    left = index;
                if (i == n - 1)
                    right = index;

                if (node->left) {
                    q.push({node->left, 2 * index + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * index + 2});
                }

                width = max(width, (int)(right - left + 1));
            }
        }
        return width;
    }
};