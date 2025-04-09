/*��תͼ��*/
//����һ�� n �� n �Ķ�ά���� matrix ��ʾһ��ͼ�����㽫ͼ��˳ʱ����ת 90 �ȡ�
//������� ԭ�� ��תͼ������ζ������Ҫֱ���޸�����Ķ�ά�����벻Ҫ ʹ����һ����������תͼ��
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