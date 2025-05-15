/*N皇后*/
//按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
class Solution {
public:
    vector<vector<string>> answer;

    vector<vector<string>> solveNQueens(int n) {
        vector<int> queen(n);
        backTrace(queen, n, 0, 0, 0, 0);
        return answer;
    }

    /**
     * 基于位运算的回溯算法核心实现
     * @param queen   当前路径的皇后位置记录
     * @param n       棋盘尺寸
     * @param row     当前处理的行号
     * @param col     已占用的列掩码（二进制位表示列占用状态）
     * @param diag1   已占用的左上到右下对角线掩码
     * @param diag2   已占用的右上到左下对角线掩码
     */
    void backTrace(vector<int>& queen, int n, int row, int col, int diag1, int diag2) {
        // 终止条件：所有行都已成功放置皇后
        if (row == n) {
            auto board = generateBoard(queen, n);
            answer.push_back(board);
            return;
        }
        // 计算当前行可放置的位置：
        // 1. (1 << n) - 1 生成n位的全1掩码（如n=4时得到0b1111）
        // 2. ~(col | diag1 | diag2) 合并所有冲突位置后取反，得到可用位置
        int avPositions = ((1 << n) - 1) & (~(col | diag1 | diag2));
        // 无可用位置时提前返回
        if (avPositions == 0) {
            return;
        }
        // 遍历所有可用位置
        while (avPositions != 0) {
            // 从二进制数 avPositions 中提取最低有效位（最右侧）的1，其他位清零。
            int position = avPositions & (-avPositions);
            // 移除已处理的位（消去最低位的1）
            avPositions &= (avPositions - 1);
            // 计算列索引（计算末尾0的个数即得到二进制位位置）
            int column = __builtin_ctz(position);
            queen[row] = column;
            /* 递归进入下一层（关键位运算状态更新）：
               - col | position: 将当前列加入列掩码
               - (diag1 | position) >> 1: 更新左上-右下对角线掩码（下一行影响右移1位）
               - (diag2 | position) << 1: 更新右上-左下对角线掩码（下一行影响左移1位） */
            backTrace(queen, n, row + 1, col | position, (diag1 | position) >> 1, (diag2 | position) << 1);
            queen[row] = -1;
        }
    }

    // 将皇后位置转换为棋盘表示
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
