/*������������������й��������*/
//���������������� preorder �� inorder ������ preorder �Ƕ���������������� inorder ��ͬһ����������������빹�����������������ڵ㡣
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]); // ��������ĵ�һ��Ԫ��Ϊ���ڵ�
        int index = 0;
        while (index < n && inorder[index] != preorder[0]) {
            index++;
        }
        vector<int> inorder_left(inorder.begin(), inorder.begin() + index); // ͨ�����ڵ�ֳ���������������������������������
        vector<int> inorder_right(inorder.begin() + index + 1, inorder.end());

        int left_size = inorder_left.size();
        vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + 1 + left_size);
        vector<int> preorder_right(preorder.begin() + 1 + left_size, preorder.end());

        root->left = build(preorder_left, inorder_left); // �ݹ�������
        root->right = build(preorder_right, inorder_right); // �ݹ�������

        return root;
    }
};
