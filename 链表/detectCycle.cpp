/*环形链表Ⅱ*/
//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// 证明：设：头节点到环入口的距离为 A，环入口到相遇点meet的距离为 B，环的剩余部分（从meet到入口）距离为 C，则环长 L = B + C
// 慢指针走了 A + B 步，快指针走了 A + B + nL = 2( A + B )，
// => A = ( n - 1 )L + C
// 则头节点到入口的距离 A 等于 meet点走 C 步后再绕( n − 1 )圈的距离。因此，若两个指针分别从头节点和meet点出发，每次走1步，最终会在入口处相遇。
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head, * slow1 = head, * slow2 = head;
        // 判断是否有环
        while (fast) {
            fast = fast->next;
            if (!fast) {
                break;
            }
            fast = fast->next;
            slow1 = slow1->next;
            if (slow1 == fast) { // 快慢指针相遇后，一个慢指针从meet节点出发，另一个慢指针从头节点出发。
                while (slow1 != slow2) {
                    slow1 = slow1->next;
                    slow2 = slow2->next;
                }
                return slow1;
            }
        }
        return nullptr;
    }
};