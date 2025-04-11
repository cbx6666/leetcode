/*�ཻ����*/
//���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㣨��ַ��ͬ��������������������ཻ�ڵ㣬���� null ��
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) { // ������ A �ķǹ������ֳ���Ϊ a������ B �ķǹ������ֳ���Ϊ b���������ֳ���Ϊ c��
        ListNode* pA = headA, * pB = headB;
        // ָ�� A ��·����a + c + b
        // ָ�� B ��·����b + c + a
        while (pA != pB) { // ����ʱ�˳�ѭ��
            // �����굱ǰ������л�����һ����ͷ����������
            pA = (pA == nullptr) ? headB : pA->next; // ������������ཻ�����������ڵ�ͬʱΪ��ָ�룬�˳�ѭ��
            pB = (pB == nullptr) ? headA : pB->next;
        }
        return pA; // �����ཻ�ڵ�� nullptr
    }
};