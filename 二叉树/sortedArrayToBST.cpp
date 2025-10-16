/*将有序数组转换为二叉搜索树*/
// 给你一个整数数组 nums ，元素已经按 升序 排列，请你将其转换为一棵 高度平衡 的二叉搜索树。
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