/*N�ʺ�*/
//���չ�������Ĺ��򣬻ʺ���Թ�����֮����ͬһ�л�ͬһ�л�ͬһб���ϵ����ӡ�
//n �ʺ����� �о�������ν� n ���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������
//����һ������ n ���������в�ͬ�� n �ʺ����� �Ľ��������
class Solution {
public:
    vector<vector<string>> answer;

    vector<vector<string>> solveNQueens(int n) {
        vector<int> queen(n);
        backTrace(queen, n, 0, 0, 0, 0);
        return answer;
    }

    /**
     * ����λ����Ļ����㷨����ʵ��
     * @param queen   ��ǰ·���Ļʺ�λ�ü�¼
     * @param n       ���̳ߴ�
     * @param row     ��ǰ������к�
     * @param col     ��ռ�õ������루������λ��ʾ��ռ��״̬��
     * @param diag1   ��ռ�õ����ϵ����¶Խ�������
     * @param diag2   ��ռ�õ����ϵ����¶Խ�������
     */
    void backTrace(vector<int>& queen, int n, int row, int col, int diag1, int diag2) {
        // ��ֹ�����������ж��ѳɹ����ûʺ�
        if (row == n) {
            auto board = generateBoard(queen, n);
            answer.push_back(board);
            return;
        }
        // ���㵱ǰ�пɷ��õ�λ�ã�
        // 1. (1 << n) - 1 ����nλ��ȫ1���루��n=4ʱ�õ�0b1111��
        // 2. ~(col | diag1 | diag2) �ϲ����г�ͻλ�ú�ȡ�����õ�����λ��
        int avPositions = ((1 << n) - 1) & (~(col | diag1 | diag2));
        // �޿���λ��ʱ��ǰ����
        if (avPositions == 0) {
            return;
        }
        // �������п���λ��
        while (avPositions != 0) {
            // �Ӷ������� avPositions ����ȡ�����Чλ�����Ҳࣩ��1������λ���㡣
            int position = avPositions & (-avPositions);
            // �Ƴ��Ѵ����λ����ȥ���λ��1��
            avPositions &= (avPositions - 1);
            // ����������������ĩβ0�ĸ������õ�������λλ�ã�
            int column = __builtin_ctz(position);
            queen[row] = column;
            /* �ݹ������һ�㣨�ؼ�λ����״̬���£���
               - col | position: ����ǰ�м���������
               - (diag1 | position) >> 1: ��������-���¶Խ������루��һ��Ӱ������1λ��
               - (diag2 | position) << 1: ��������-���¶Խ������루��һ��Ӱ������1λ�� */
            backTrace(queen, n, row + 1, col | position, (diag1 | position) >> 1, (diag2 | position) << 1);
            queen[row] = -1;
        }
    }

    // ���ʺ�λ��ת��Ϊ���̱�ʾ
    vector<string> generateBoard(vector<int> queen, int n) {
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queen[i]] = 'Q';
            board.push_back(row);
        }

        return board;
    }
};
