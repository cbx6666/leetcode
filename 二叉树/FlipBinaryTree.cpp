/*翻转二叉树*/
//给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
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
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            invertTree(root->left);
            TreeNode* temp;
            temp = root->left;
            root->left = root->right;
            root->right = temp;
            invertTree(root->left);
        }
        
        return root;
    }
};
