/*Ѱ���������������е���λ��*/
//����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ���������������������� ��λ�� ��
//�㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log(m + n)) ��
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) % 2 != 0) {
            // ���������ֱ�ӷ����м�ֵ
            return getKthElement(nums1, nums2, (m + n) / 2 + 1);
        }
        else {
            // ż������������м���������ƽ��ֵ
            return (getKthElement(nums1, nums2, (m + n) / 2) + getKthElement(nums1, nums2, (m + n) / 2 + 1)) / 2.0;
        }
    }

    // ���ַ����kСԪ�أ������㷨��
    double getKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int offset1 = 0, offset2 = 0; // ��ǰ�������Ч��ʼƫ����
        while (true) {
            // �߽��������
            if (offset1 == m) { // nums1��ȫ���ų�
                return nums2[offset2 + k - 1];
            }
            if (offset2 == n) { // nums2��ȫ���ų�
                return nums1[offset1 + k - 1];
            }
            if (k == 1) { // �ҵ�1С��Ԫ��ʱֱ�ӱȽϵ�ǰͷ��
                return min(nums1[offset1], nums2[offset2]);
            }

            /* ���ֺ����߼� */
            // ����Ƚϲ�����ȡk/2��ʣ�೤�ȵĽ�Сֵ��
            int p1 = min(k / 2, m - offset1); // nums1��̽�ⳤ��
            int p2 = min(k / 2, n - offset2); // nums2��̽�ⳤ��
            int index1 = offset1 + p1 - 1; // nums1�ıȽ�λ��
            int index2 = offset2 + p2 - 1; // nums2�ıȽ�λ��
            // �ų������ܰ�����kԪ�ص�����
            if (nums1[index1] <= nums2[index2]) {
                offset1 += p1;  // �ų�nums1��ǰp1��Ԫ��
                k -= p1; // ����ʣ����Ҫ�ҵ�Ԫ�����
            }
            else {
                offset2 += p2; // �ų�nums2��ǰp2��Ԫ��
                k -= p2;
            }
        }
    }
};