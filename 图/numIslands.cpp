/*岛屿数量*/
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或垂直方向上相邻的陆地连接形成。
// 此外，你可以假设该网格的四条边均被水包围。
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int island = 0;

        vector<vector<bool>> visit(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visit[i][j]) {
                    dfs(grid, visit, i, j);
                    island++;
                }
            }
        }

        return island;
    }

private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int row,
             int column) {
        int m = grid.size();
        int n = grid[0].size();

        if (row < 0 || row >= m || column < 0 || column >= n ||
            visit[row][column] || grid[row][column] == '0') {
            return;
        }
        visit[row][column] = true;

        dfs(grid, visit, row - 1, column);
        dfs(grid, visit, row + 1, column);
        dfs(grid, visit, row, column - 1);
        dfs(grid, visit, row, column + 1);
    }
};