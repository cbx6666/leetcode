/*二叉树的最大深度*/
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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int max = 0;
        inorder(root, 1, max);
        return max;
    }

    void inorder(TreeNode* root, int depth, int& max) {
        if (root) {
            inorder(root->left, depth + 1, max);
            max = max > depth ? max : depth;
            inorder(root->right, depth + 1, max);
        }
    }
};