/*验证二叉搜索树*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isInSection(root, LONG_MIN, LONG_MAX);
    }

    bool isInSection(TreeNode* root, long min, long max) {
        if (root == nullptr) {
            return true;
        }
        if (root->val >= max || root->val <= min) { // 超出当前允许的区间范围
            return false;
        }

        return isInSection(root->left, min, root->val) &&
            isInSection(root->right, root->val, max);
    }
};