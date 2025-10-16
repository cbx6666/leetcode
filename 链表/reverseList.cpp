/*反转链表*/
//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
class Solution {
public:
    ListNode* reverseList(ListNode* head) { // 迭代法
        ListNode* pre = nullptr; // 记录当前节点的前一个节点
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next; // 保存当前节点的下一个节点
            cur->next = pre; // 当前节点的下一个节点指向前节点
            pre = cur; // 进行迭代
            cur = next;
        }

        return pre;
    }
};