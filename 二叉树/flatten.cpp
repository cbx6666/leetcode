/*二叉树展开为链表*/
// 给你一棵二叉树的根节点 root ，请你将它展开为一个单链表。
// 展开后的单链表应当使用 TreeNode 的 right 指针指向下一个节点，left 指针始终为 null。
// 展开后的单链表应与先序遍历顺序相同。
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) { // 若有左子树，将其接到右侧，再把原右子树接到左子树最右侧
            if (curr->left != nullptr) {
                TreeNode* next = curr->left;
                TreeNode* pre = next;
                while (pre->right != nullptr) { // 找到左子树的最右节点，作为前驱
                    pre = pre->right;
                }
                pre->right = curr->right; // 将当前右子树接到前驱的右侧
                curr->left = nullptr; // 左指针置空
                curr->right = next;
            }
            curr = curr->right; // 移动到下一个节点
        }
    }
};