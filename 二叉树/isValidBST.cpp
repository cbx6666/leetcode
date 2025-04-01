/*验证搜索二叉树*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isInSection(root, LONG_MIN, LONG_MAX);
    }

    bool isInSection(TreeNode* root, long min, long max) {
        if (root == nullptr) {
            return true;
        }
        if (root->val >= max || root->val <= min) { // 为叶节点设置区间，为左孩子设置最大值，为右孩子设置最小值
            return false;
        }

        return isInSection(root->left, min, root->val) &&
            isInSection(root->right, root->val, max);
    }
};