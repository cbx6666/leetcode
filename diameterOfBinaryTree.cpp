/*二叉树的直径*/
//给你一棵二叉树的根节点，返回该树的直径 。
//二叉树的直径是指树中任意两个节点之间最长路径的长度 。这条路径可能经过也可能不经过根节点 root 。
//两节点之间路径的长度由它们之间边数表示。
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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxLength = 0;
        maxDepth(root, maxLength);
        return maxLength;
    }

    int maxDepth(TreeNode* root, int& maxLength) {
        if (root) {
            int left = root->left ? maxDepth(root->left, maxLength) + 1 : 0;
            int right = root->right ? maxDepth(root->right, maxLength) + 1 : 0;
            
            maxLength = maxLength > left + right ? maxLength : left + right;
            return max(left, right);
        }
        return 0;
    }
};
