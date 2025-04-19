/*二叉树的最近公共祖先*/
//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。
class Sulotion {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { // dfs
		if (root == nullptr || root == p || root == q) { // 如果当前节点是目标节点，则当前节点可能是LCA（最低公共祖先），直接返回
			return root;
		}

		// 递归遍历左子树，查找p或q
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		// 递归遍历右子树，查找p或q
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		// 如果当前节点不是目标节点，则在子结点中查找
		// 如果左子树没有找到p或q，说明p和q都在右子树中，返回右子树的结果
		if (left==nullptr) {
			return right;
		}
		// 如果右子树没有找到p或q，说明p和q都在左子树中，返回左子树的结果
		if (right == nullptr) {
			return left;
		}
		// 如果左右子树都找到了p或q，说明当前节点root就是LCA
		return root;
	}
};