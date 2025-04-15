/*ȫ����*/
//����һ�������ظ����ֵ����� nums �������� ���п��ܵ�ȫ���� ������� ������˳�� ���ش𰸡�
class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> answer;
        backtrack(nums, answer);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& answer) { 
        int n = nums.size();
        // ��ֹ��������û�����ֿ�ѡʱ
        if (n == 0) {
            ans.push_back(answer); // ����ǰ�������м�������
        }

        for (int i = 0; i < n; i++) {  // �������п�ѡ����
            int temp = nums[i];
            nums.erase(nums.begin() + i); // �ӿ�ѡ�������Ƴ���ǰ����
            answer.push_back(temp);  // ����ǰ���ּ�������

            backtrack(nums, answer); // �ݹ鴦��ʣ������

            nums.insert(nums.begin() + i, temp); // �����ַŻ�ԭλ��
            answer.pop_back(); // ���������Ƴ���ǰ����
        }
    }
};