/*螺旋矩阵*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int rowStart = 0, rowEnd = row - 1, colStart = 0, colEnd = col - 1;
        vector<int> answer;
        while (rowStart <= rowEnd && colStart <= colEnd) {
            for (int i = colStart; i <= colEnd; i++) {
                answer.push_back(matrix[rowStart][i]);
            }
            for (int i = rowStart + 1; i <= rowEnd - 1; i++) {
                answer.push_back(matrix[i][colEnd]);
            }
            for (int i = colEnd; i >= colStart && rowStart < rowEnd; i--) {
                answer.push_back(matrix[rowEnd][i]);
            }
            for (int i = rowEnd - 1; i >= rowStart + 1 && colStart < colEnd;
                i--) {
                answer.push_back(matrix[i][colStart]);
            }

            rowStart++, rowEnd--, colStart++, colEnd--;
        }
        return answer;
    }
};
