/*����ܺ�*/
//����һ�����ظ�Ԫ�ص��������� candidates ��һ��Ŀ������ target ���ҳ� candidates �п���ʹ���ֺ�ΪĿ���� target �� ���� ��ͬ��� �������б���ʽ���ء�����԰�����˳�򷵻���Щ��ϡ�
//candidates �е� ͬһ�� ���ֿ��� �������ظ���ѡȡ ���������һ�����ֵı�ѡ������ͬ������������ǲ�ͬ�ġ�
class Solution {
public:
    vector<vector<int>> answer;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // �Ժ�ѡ����������򣬱��ں�����֦����
        sort(candidates.begin(), candidates.end());
        vector<int> sub;

        int n = candidates.size();
        // ����ÿ��Ԫ����Ϊ��ʼ�㣬�������п��ܵ����
        for (int i = 0; i < n; i++) { 
            backTrace(candidates, sub, target, i);
        }

        return answer;
    }

    void backTrace(vector<int>& nums, vector<int>& sub, int target, int start) {
        int n = nums.size();
        // ��֦����ǰԪ���Ѵ���ʣ��Ŀ��ֵ���޷��γ���Ч��ϣ�ֱ�ӷ���
        if (nums[start] > target) {
            return;
        }
        // �ҵ�һ����Ч��ϣ���ǰԪ�����õ���ʣ��Ŀ��ֵ
        if (nums[start] == target) {
            sub.push_back(nums[start]);
            answer.push_back(sub);
            sub.pop_back();
            return;
        }

        // ѡ��ǰԪ�أ����������ʱ���
        sub.push_back(nums[start]);
        // �ݹ鳢�Դӵ�ǰ������ʼ������Ԫ�أ������ظ�ʹ�ã�
        for (int i = start; i < n; i++) {
            backTrace(nums, sub, target - nums[start], i);
        }
        sub.pop_back();
    }
};