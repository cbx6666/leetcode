/*矩阵置零*/
//给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) { // 如果某个元素为零，就将该元素所在的行和列的第一个元素置零
        int row = matrix.size();
        if (row < 0) {
            return;
        }
        int col = matrix[0].size();
        bool firstRow = false, firstColumn = false;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;

                    if (i == 0) { // 因为第一个元素是第一行与第一列相交的元素，所以需要特判
                        firstRow = true;
                    }
                    if (j == 0) {
                        firstColumn = true;
                    }
                }
            }
        }

        for (int i = 1; i < row; i++) { // 跳过第一行，如果一行的第一个元素为0，就将该行所有元素置零
            if (matrix[i][0] == 0) {
                for (int j = 1; j < col; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < col; i++) { // 跳过第一列，如果一列的第一个元素为0，就将该列所有元素置零
            if (matrix[0][i] == 0) {
                for (int j = 1; j < row; j++) {
                    matrix[j][i] = 0;
                }
            }
        }

        // 将第一行或第一列的元素置零
        if (firstRow) { 
            for (int i = 1; i < col; i++) {
                matrix[0][i] = 0;
            }
        }
        if (firstColumn) {
            for (int i = 1; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};