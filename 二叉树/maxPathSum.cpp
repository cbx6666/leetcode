/*二叉树的最大路径和*/
//二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
//路径和 是路径中各节点值的总和。
//给你一个二叉树的根节点 root ，返回其 最大路径和 。
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxValue = INT_MIN;
        maxSum(root, maxValue);
        return maxValue;
    }

    // 贡献值：子节点为父节点提供的路径和，父节点和子节点可以连接成更长的路径
    int maxSum(TreeNode* root, int& maxValue) { // 求当前节点的最大贡献值
        if (root) {
            // 求一条路径和：当前节点值加左右子树的贡献值
            int left = root->left ? maxSum(root->left, maxValue) : 0; // 计算左子树的最大贡献值
            int right = root->right ? maxSum(root->right, maxValue) : 0; // 计算以右子树的最大贡献值
            maxValue = max(maxValue, root->val + left + right); // 更新最大值，比较当前最大值和当前路径和
            return max(root->val + max(left, right), 0); // 返回当前节点的最大贡献值，即当前节点值加左右子树贡献值的最大值，一个节点的最大贡献值不小于0
        }

        return 0;
    }
};