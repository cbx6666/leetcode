/*对称二叉树*/
//给你一个二叉树的根节点 root ， 检查它是否轴对称。
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
    bool isSymmetric(TreeNode* root) {
        root->right = invertTree(root->right);
        return compareTree(root->left, root->right);
    }

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

    bool compareTree(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr || root2 == nullptr) {
            if (root1 == nullptr && root2 == nullptr) {
                return true;
            }
            else {
                return false;
            }
        }
        if (!compareTree(root1->left, root2->left)) {
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        if (!compareTree(root1->right, root2->right)) {
            return false;
        }
        return true;
    }
};