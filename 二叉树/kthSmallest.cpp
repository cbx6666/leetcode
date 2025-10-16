/*二叉搜索树中第K小的元素*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        inorderTraversal(root, nums);
        return nums[k - 1];
    }

    void inorderTraversal(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left, nums);
        nums.push_back(root->val);
        inorderTraversal(root->right, nums);
    }
};