/*路径总和 III*/
// 给你一个二叉树的根节点 root 和一个整数 targetSum，返回所有路径中节点值之和等于 targetSum 的路径数目。
// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径必须是向下的（只能从父节点到子节点）。
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> pre; // 前缀和
        pre[0] = 1;
        return dfs(root, 0, pre, targetSum);
    }

    int dfs(TreeNode* root, long long currentSum, unordered_map<long long, int>& pre, int targetSum) { // 深度优先搜索 + 前缀和
        if (root == nullptr) {
            return 0;
        }

        currentSum += root->val;
        int count = pre[currentSum - targetSum]; // 子数组和为 K 的原理相同

        pre[currentSum]++; // 将当前节点的前缀和写入哈希
        count += dfs(root->left, currentSum, pre, targetSum); // 递归处理左右子树，累加有效路径数
        count += dfs(root->right, currentSum, pre, targetSum);  
        pre[currentSum]--; // 回溯：离开当前节点，从哈希中移除当前路径和，避免影响其他分支

        return count;
    }
};