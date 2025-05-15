/*��������*/
//����һ�� m x n ��ά�ַ����� board ��һ���ַ������� word ����� word �����������У����� true �����򣬷��� false ��
//���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�
class Solution {
public:
    vector<vector<bool>> visited; // ��¼��Ԫ���Ƿ񱻷��ʹ��������ظ�ʹ��

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        // �������е�Ԫ����Ϊ��㳢��ƥ��
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (backtrack(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, const string& word, int index, int row, int col) {
        if (index == word.size()) {
            return true;  // ��ȫƥ��
        }

        // �߽��� + ���ʱ�Ǽ�� + �ַ�ƥ����
        int rows = board.size(), cols = board[0].size();
        if (row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col] || board[row][col] != word[index]) {
            return false;
        }

        visited[row][col] = true;

        // ���ĸ�����ݹ��������ϡ��¡����ң�
        bool found = backtrack(board, word, index + 1, row - 1, col) ||
            backtrack(board, word, index + 1, row + 1, col) ||
            backtrack(board, word, index + 1, row, col - 1) ||
            backtrack(board, word, index + 1, row, col + 1);

        visited[row][col] = false;  // ����

        return found;
    }
};