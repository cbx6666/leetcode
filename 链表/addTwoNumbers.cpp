/*两数相加*/
// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
// 请你将两个数相加，并以相同形式返回一个表示和的链表。
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode(), *sum = head;
        while (l1 || l2 || carry) {
            int value = carry;
            if (l1) {
                value += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                value += l2->val;
                l2 = l2->next;
            }
            carry = value / 10;
            value %= 10;
            sum->next = new ListNode(value);
            sum = sum->next;
        }
        // 处理尾部空节点
        return head->next;
    }
};