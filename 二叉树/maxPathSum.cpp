/*�����������·����*/
//�������е� ·�� ������Ϊһ���ڵ����У�������ÿ�����ڽڵ�֮�䶼����һ���ߡ�ͬһ���ڵ���һ��·�������� �������һ�� ����·�� ���ٰ���һ�� �ڵ㣬�Ҳ�һ���������ڵ㡣
//·���� ��·���и��ڵ�ֵ���ܺ͡�
//����һ���������ĸ��ڵ� root �������� ���·���� ��
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxValue = INT_MIN;
        maxSum(root, maxValue);
        return maxValue;
    }

    // ����ֵ���ӽڵ�Ϊ���ڵ��ṩ��·���ͣ����ڵ���ӽڵ�������ӳɸ�����·��
    int maxSum(TreeNode* root, int& maxValue) { // ��ǰ�ڵ�������ֵ
        if (root) {
            // ��һ��·���ͣ���ǰ�ڵ�ֵ�����������Ĺ���ֵ
            int left = root->left ? maxSum(root->left, maxValue) : 0; // �����������������ֵ
            int right = root->right ? maxSum(root->right, maxValue) : 0; // �������������������ֵ
            maxValue = max(maxValue, root->val + left + right); // �������ֵ���Ƚϵ�ǰ���ֵ�͵�ǰ·����
            return max(root->val + max(left, right), 0); // ���ص�ǰ�ڵ�������ֵ������ǰ�ڵ�ֵ��������������ֵ�����ֵ��һ���ڵ�������ֵ��С��0
        }

        return 0;
    }
};