/*回文链表*/
//给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
class Solution {
public:
    bool isPalindrome(ListNode* head) { // 利用快慢指针确定中间节点，需要判断链表节点数的奇偶
        ListNode* fast = head, * slow = head;
        while (fast) {
            fast = fast->next;
            if (!fast) { // 奇数
                slow = slow->next;
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }
        fast = head;

        slow = reverseList(slow); // 翻转后半部分链表
        while (slow) {
            if (slow->val != fast->val) { // 比较前半部分和后半部分的每个节点是否相等
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};