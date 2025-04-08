/*将二叉树转为链表*/
//给你二叉树的根结点 root ，请你将它展开为一个单链表：
//展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
//展开后的单链表应该与二叉树 先序遍历 顺序相同。
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) { // 对于当前节点，如果存在左子树，则左子树最右侧的节点是当前节点右子树的前驱节点
            if (curr->left != nullptr) {
                TreeNode* next = curr->left;
                TreeNode* pre = next;
                while (pre->right != nullptr) { // 找到左子树最右侧的节点，作为前驱节点
                    pre = pre->right;
                }
                pre->right = curr->right; // 将当前节点的右节点作为前驱节点的右节点
                curr->left = nullptr; // 将左子树移到右子树的位置
                curr->right = next;
            }
            curr = curr->right; // 迭代更新当前节点
        }
    }
};