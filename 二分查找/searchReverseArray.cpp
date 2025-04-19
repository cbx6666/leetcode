/*������ת��������*/
//�������� nums ���������У������е�ֵ ������ͬ ��
//�ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length���Ͻ����� ��ת��ʹ�����Ϊ[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]]���±� �� 0 ��ʼ ��������
// ���磬[0, 1, 2, 4, 5, 6, 7] ���±� 3 ������ת����ܱ�Ϊ[4, 5, 6, 7, 0, 1, 2] ��
//���� ��ת�� ������ nums ��һ������ target ����� nums �д������Ŀ��ֵ target ���򷵻������±꣬���򷵻� - 1 ��
//��������һ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣
class Solution { // �ҵ��м�ֵ��һ�벿��������ģ���һ�벿���������
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) { // ͨ�⣬�ȿ��Դ����������Ķ����������ֿ��Դ�����ת����
            int mid = left + (right - left) / 2; 

            // ֱ���ҵ�Ŀ��ֵ
            if (nums[mid] == target) {
                return mid;
            }

            // �ж���벿���Ƿ�����
            if (nums[left] <= nums[mid]) {
                // ���Ŀ��ֵ���������벿�ַ�Χ��
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // ����벿�ּ��������������Ķ���������
                }
                else {
                    left = mid + 1;  // ����ȥ�Ұ벿������
                }
            }
            // �Ұ벿������
            else {
                // ���Ŀ��ֵ��������Ұ벿�ַ�Χ��
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // ���Ұ벿�ּ��������������Ķ���������
                }
                else {
                    right = mid - 1; // ����ȥ��벿������
                }
            }
        }

        // δ�ҵ�Ŀ��ֵ
        return -1;
    }
};