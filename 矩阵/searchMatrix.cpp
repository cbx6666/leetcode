/*������ά�����*/
//��дһ����Ч���㷨������ m x n ���� matrix �е�һ��Ŀ��ֵ target ���þ�������������ԣ�
//ÿ�е�Ԫ�ش������������С�
//ÿ�е�Ԫ�ش��ϵ����������С�
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int x = 0, y = col - 1;
        bool isFound = false;
        while (x < row && y >= 0) { // �Ӿ�������Ͻǿ�ʼ����
            if (target > matrix[x][y]) { // ���Ŀ��ֵ���ھ������Ͻǵ�Ԫ�أ��������е�����Ԫ�ض�С��Ŀ��ֵ
                x++;
            }
            else if (target < matrix[x][y]) { // ���Ŀ��ֵС�ھ������Ͻǵ�Ԫ�أ��������е�����Ԫ�ض�����Ŀ��ֵ
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