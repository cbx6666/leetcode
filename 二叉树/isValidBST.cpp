/*��֤����������*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isInSection(root, LONG_MIN, LONG_MAX);
    }

    bool isInSection(TreeNode* root, long min, long max) {
        if (root == nullptr) {
            return true;
        }
        if (root->val >= max || root->val <= min) { // ΪҶ�ڵ��������䣬Ϊ�����������ֵ��Ϊ�Һ���������Сֵ
            return false;
        }

        return isInSection(root->left, min, root->val) &&
            isInSection(root->right, root->val, max);
    }
};