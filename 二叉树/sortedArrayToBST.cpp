/*����������ת��Ϊ����������*/
//����һ���������� nums ������Ԫ���Ѿ��� ���� ���У����㽫��ת��Ϊһ�� ƽ�� ������������
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BuildBST(nums, 0, nums.size() - 1);
    }

    TreeNode* BuildBST(vector<int>& nums, int begin, int end) {
        if (begin > end) {
            return nullptr;
        }

        int middle = (begin + end) / 2;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = BuildBST(nums, begin, middle - 1);
        root->right = BuildBST(nums, middle + 1, end);

        return root;
    }
};