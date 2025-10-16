/*二叉树的最近公共祖先*/
// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
// 百度百科对最近公共祖先的定义为：对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
// 满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { // dfs
		if (root == nullptr || root == p || root == q) { // 命中目标或空节点，直接返回
			return root;
		}

		// 递归在左右子树分别寻找 p、q
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		// 递归在右子树寻找 p、q
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		// 当前节点不是目标节点时，检查子树结果
		// 若左子树为空，LCA 在右侧；若右子树为空，LCA 在左侧；都不空则当前即 LCA
		if (left==nullptr) {
			return right;
		}
		if (right == nullptr) {
			return left;
		}
		return root;
	}
};