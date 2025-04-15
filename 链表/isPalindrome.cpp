/*��������*/
//����һ���������ͷ�ڵ� head �������жϸ������Ƿ�Ϊ������������ǣ����� true �����򣬷��� false ��
class Solution {
public:
    bool isPalindrome(ListNode* head) { // ���ÿ���ָ��ȷ���м�ڵ㣬��Ҫ�ж�����ڵ�������ż
        ListNode* fast = head, * slow = head;
        while (fast) {
            fast = fast->next;
            if (!fast) { // ����
                slow = slow->next;
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }
        fast = head;

        slow = reverseList(slow); // ��ת��벿������
        while (slow) {
            if (slow->val != fast->val) { // �Ƚ�ǰ�벿�ֺͺ�벿�ֵ�ÿ���ڵ��Ƿ����
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