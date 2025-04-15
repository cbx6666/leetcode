/*·���ܺ͢�*/
//����һ���������ĸ��ڵ� root ����һ������ targetSum ����ö�������ڵ�ֵ֮�͵��� targetSum �� ·�� ����Ŀ��
//·�� ����Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����������·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩��
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> pre; // ǰ׺��
        pre[0] = 1;
        return dfs(root, 0, pre, targetSum);
    }

    int dfs(TreeNode* root, long long currentSum, unordered_map<long long, int>& pre, int targetSum) { // ������ȱ���+���ݷ�
        if (root == nullptr) {
            return 0;
        }

        currentSum += root->val;
        int count = pre[currentSum - targetSum]; // ���ΪK���Ӵ�ԭ����ͬ

        pre[currentSum]++; // ����ǰ�ڵ��ǰ׺��д���ϣ��
        count += dfs(root->left, currentSum, pre, targetSum); // �ݹ鴦�������������ۼ����ǵ���Ч·����
        count += dfs(root->right, currentSum, pre, targetSum);  
        pre[currentSum]--; // ���ݣ��뿪��ǰ�ڵ�ǰ���ӹ�ϣ�����Ƴ���ǰ·���ͣ���ΪҪ���ظ��ڵ㣬��ǰ·���Ͳ�Ӧ��Ӱ��������֧�ļ���

        return count;
    }
};