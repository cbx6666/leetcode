/*��������*/
//����һ�� m x n �ľ������һ��Ԫ��Ϊ 0 �����������к��е�����Ԫ�ض���Ϊ 0 ����ʹ�� ԭ�� �㷨��
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) { // ���ĳ��Ԫ��Ϊ�㣬�ͽ���Ԫ�����ڵ��к��еĵ�һ��Ԫ������
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

                    if (i == 0) { // ��Ϊ��һ��Ԫ���ǵ�һ�����һ���ཻ��Ԫ�أ�������Ҫ����
                        firstRow = true;
                    }
                    if (j == 0) {
                        firstColumn = true;
                    }
                }
            }
        }

        for (int i = 1; i < row; i++) { // ������һ�У����һ�еĵ�һ��Ԫ��Ϊ0���ͽ���������Ԫ������
            if (matrix[i][0] == 0) {
                for (int j = 1; j < col; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < col; i++) { // ������һ�У����һ�еĵ�һ��Ԫ��Ϊ0���ͽ���������Ԫ������
            if (matrix[0][i] == 0) {
                for (int j = 1; j < row; j++) {
                    matrix[j][i] = 0;
                }
            }
        }

        // ����һ�л��һ�е�Ԫ������
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