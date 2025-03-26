/*�����������ֵ*/
//����һ���������� nums����һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳࡣ��ֻ���Կ����ڻ��������ڵ� k �����֡���������ÿ��ֻ�����ƶ�һλ��
//���ػ��������е����ֵ ��
// ����i < j����nums[i] < nums[j]������ nums[j] �Ĵ��ڣ�nums[i] һ�������ǻ��������е����ֵ�ˣ����ǿ��Խ� nums[i] ���õ��Ƴ���
// ������ǿ���ʹ��һ�����д洢���л�û�б��Ƴ����±ꡣ
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) { // ���õ������У����е�ֵ�ݼ�����֤ͷ��ֵ���
        int n = nums.size();
        deque<int> dq;
        vector<int> answer;

        for (int i = 0; i < n; i++) {
            if (i < k - 1) {
                while (!dq.empty() && dq.back() < nums[i]) { // ά�����еĵ�����
                    dq.pop_back();
                }
                dq.push_back(nums[i]);
            }
            else {
                while (!dq.empty() && dq.back() < nums[i]) {
                    dq.pop_back();
                }
                dq.push_back(nums[i]);

                answer.push_back(dq.front()); // ��ȡ��ǰ�������ڵ����ֵ

                if (dq.front() == nums[i - k + 1]) { // ����󴰿�������Ȼ���ڣ�����ڶ���ͷ����ɾ�����������
                    dq.pop_front();
                }
            }
        }

        return answer;
    }
};