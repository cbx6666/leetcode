/*单词搜索*/
//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
class Solution {
public:
    vector<vector<bool>> visited; // 记录单元格是否被访问过，避免重复使用

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        // 遍历所有单元格作为起点尝试匹配
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
            return true;  // 完全匹配
        }

        // 边界检查 + 访问标记检查 + 字符匹配检查
        int rows = board.size(), cols = board[0].size();
        if (row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col] || board[row][col] != word[index]) {
            return false;
        }

        visited[row][col] = true;

        // 向四个方向递归搜索（上、下、左、右）
        bool found = backtrack(board, word, index + 1, row - 1, col) ||
            backtrack(board, word, index + 1, row + 1, col) ||
            backtrack(board, word, index + 1, row, col - 1) ||
            backtrack(board, word, index + 1, row, col + 1);

        visited[row][col] = false;  // 回溯

        return found;
    }
};