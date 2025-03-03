/*��������ֱ��*/
//����һ�ö������ĸ��ڵ㣬���ظ�����ֱ�� ��
//��������ֱ����ָ�������������ڵ�֮���·���ĳ��� ������·�����ܾ���Ҳ���ܲ��������ڵ� root ��
//���ڵ�֮��·���ĳ���������֮�������ʾ��
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