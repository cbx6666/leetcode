/*环形链表*/
//给你一个链表的头节点 head ，判断链表中是否有环。
class Solution {
public:
    bool hasCycle(ListNode* head) { // 利用快慢指针，如果链表有环，则快慢指针会相遇
        ListNode* fast = head, * slow = head;
        while (fast) {
            fast = fast->next;
            if (!fast) {
                break;
            }
            fast = fast->next;
            slow = slow->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};