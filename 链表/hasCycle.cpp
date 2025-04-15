/*��������*/
//����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
class Solution {
public:
    bool hasCycle(ListNode* head) { // ���ÿ���ָ�룬��������л��������ָ�������
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
