/*从先序与中序遍历序列构造二叉树*/
//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
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

        TreeNode* root = new TreeNode(preorder[0]); // 先序遍历的第一个元素为根节点
        int index = 0;
        while (index < n && inorder[index] != preorder[0]) {
            index++;
        }
        vector<int> inorder_left(inorder.begin(), inorder.begin() + index); // 通过根节点分出左子树和右子树的先序遍历和中序遍历
        vector<int> inorder_right(inorder.begin() + index + 1, inorder.end());

        int left_size = inorder_left.size();
        vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + 1 + left_size);
        vector<int> preorder_right(preorder.begin() + 1 + left_size, preorder.end());

        root->left = build(preorder_left, inorder_left); // 递归左子树
        root->right = build(preorder_right, inorder_right); // 递归右子树

        return root;
    }
};
