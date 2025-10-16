/*旋转图像*/
//给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
//你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = n; i > 1; i -= 2) {
            for (int j = 0; j < i - 1; j++) {
                int row = (n - i) / 2, col = (n - i) / 2 + j;
                int temp = matrix[row][col];
                matrix[row][col] = matrix[row + i - j - 1][col - j];
                matrix[row + i - j - 1][col - j] = matrix[row + i - 1][col + i - 2 * j - 1];
                matrix[row + i - 1][col + i - 2 * j - 1] = matrix[row + j][col + i - j - 1];
                matrix[row + j][col + i - j - 1] = temp;
            }
        }
    }
};