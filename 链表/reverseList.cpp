/*��ת����*/
//���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
class Solution {
public:
    ListNode* reverseList(ListNode* head) { // ������
        ListNode* pre = nullptr; // ��¼��ǰ�ڵ��ǰһ���ڵ�
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next; // ���浱ǰ�ڵ����һ���ڵ�
            cur->next = pre; // ��ǰ�ڵ����һ���ڵ�ָ��ǰ�ڵ�
            pre = cur; // ���е���
            cur = next;
        }

        return pre;
    }
};