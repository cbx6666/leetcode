/*�ϲ�����*/
//������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti, endi] ��
//����ϲ������ص������䣬������ һ�����ص����������飬��������ǡ�ø��������е��������� ��
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> answer;
        int index = 1;
        while (index < n) {
            if (intervals[index][0] <= end) {
                end = max(intervals[index][1], end);
            }
            else {
                answer.push_back({ start, end });
                start = intervals[index][0];
                end = intervals[index][1];
            }
            index++;
        }
        answer.push_back({ start, end });
        return answer;
    }
};