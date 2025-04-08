/*��������תΪ����*/
//����������ĸ���� root �����㽫��չ��Ϊһ��������
//չ����ĵ�����Ӧ��ͬ��ʹ�� TreeNode ������ right ��ָ��ָ����������һ����㣬������ָ��ʼ��Ϊ null ��
//չ����ĵ�����Ӧ��������� ������� ˳����ͬ��
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) { // ���ڵ�ǰ�ڵ㣬��������������������������Ҳ�Ľڵ��ǵ�ǰ�ڵ���������ǰ���ڵ�
            if (curr->left != nullptr) {
                TreeNode* next = curr->left;
                TreeNode* pre = next;
                while (pre->right != nullptr) { // �ҵ����������Ҳ�Ľڵ㣬��Ϊǰ���ڵ�
                    pre = pre->right;
                }
                pre->right = curr->right; // ����ǰ�ڵ���ҽڵ���Ϊǰ���ڵ���ҽڵ�
                curr->left = nullptr; // ���������Ƶ���������λ��
                curr->right = next;
            }
            curr = curr->right; // �������µ�ǰ�ڵ�
        }
    }
};