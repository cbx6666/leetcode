/*相交链表*/
//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点（地址相同）。如果两个链表不存在相交节点，返回 null 。
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) { // 设链表 A 的非公共部分长度为 a，链表 B 的非公共部分长度为 b，公共部分长度为 c。
        ListNode* pA = headA, * pB = headB;
        // 指针 A 的路径：a + c + b
        // 指针 B 的路径：b + c + a
        while (pA != pB) { // 相遇时退出循环
            // 遍历完当前链表后，切换到另一链表头部继续遍历
            pA = (pA == nullptr) ? headB : pA->next; // 如果两个链表不相交，最终两个节点同时为空指针，退出循环
            pB = (pB == nullptr) ? headA : pB->next;
        }
        return pA; // 返回相交节点或 nullptr
    }
};