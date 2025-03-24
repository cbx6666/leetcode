/*合并区间*/
//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
//请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
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