/*搜索二维矩阵Ⅱ*/
//编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
//每行的元素从左到右升序排列。
//每列的元素从上到下升序排列。
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int x = 0, y = col - 1;
        bool isFound = false;
        while (x < row && y >= 0) { // 从矩阵的右上角开始搜索
            if (target > matrix[x][y]) { // 如果目标值大于矩阵右上角的元素，则所在行的所有元素都小于目标值
                x++;
            }
            else if (target < matrix[x][y]) { // 如果目标值小于矩阵右上角的元素，则所在列的所有元素都大于目标值
                y--;
            }
            else {
                isFound = true;
                break;
            }
        }

        return isFound;
    }
};