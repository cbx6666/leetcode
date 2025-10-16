/*二叉树中的最大路径和*/
// 二叉树中的路径 被定义为一条节点序列，其中序列中每对相邻节点之间都存在一条边。
// 同一个节点在一条路径序列中 至多出现一次。该路径 至少包含一个 节点，且不一定经过根节点。
// 路径和 是路径中各节点值之和。
// 给你一个二叉树的根节点 root ，返回其 最大路径和 。
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxValue = INT_MIN;
        maxSum(root, maxValue);
        return maxValue;
    }

    // 返回以当前节点为起点向下的最大贡献值，同时更新全局最大路径和
    int maxSum(TreeNode* root, int& maxValue) {
        if (root) {
            int left = root->left ? maxSum(root->left, maxValue) : 0; // 左子树贡献
            int right = root->right ? maxSum(root->right, maxValue) : 0; // 右子树贡献
            maxValue = max(maxValue, root->val + left + right);
            return max(root->val + max(left, right), 0);
        }

        return 0;
    }
};