/*从前序与中序遍历序列构造二叉树*/
// 给定一棵二叉树的 preorder 和 inorder 遍历，preorder 是根-左-右，中序 inorder 是左-根-右，重建该二叉树并返回根节点。
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]); // 前序遍历的第一个元素为根节点
        int index = 0;
        while (index < n && inorder[index] != preorder[0]) {
            index++;
        }
        vector<int> inorder_left(inorder.begin(), inorder.begin() + index); // 按根位置划分中序为左、右子树
        vector<int> inorder_right(inorder.begin() + index + 1, inorder.end());

        int left_size = inorder_left.size();
        vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + 1 + left_size);
        vector<int> preorder_right(preorder.begin() + 1 + left_size, preorder.end());

        root->left = build(preorder_left, inorder_left); // 递归构建左子树
        root->right = build(preorder_right, inorder_right); // 递归构建右子树

        return root;
    }
};
