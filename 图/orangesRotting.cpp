/*橘子腐烂*/
// 给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个空单元格、1 表示一个新鲜橘子、2 表示一个腐烂的橘子。
// 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
// 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        // bfs找腐烂的橘子
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;
        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [x, y] = q.front();
                q.pop();

                if (x > 0 && grid[x - 1][y] == 1) {
                    q.push({x - 1, y});
                    fresh--;
                    grid[x - 1][y] = 2;
                }
                if (x < m - 1 && grid[x + 1][y] == 1) {
                    q.push({x + 1, y});
                    fresh--;
                    grid[x + 1][y] = 2;
                }
                if (y > 0 && grid[x][y - 1] == 1) {
                    q.push({x, y - 1});
                    fresh--;
                    grid[x][y - 1] = 2;
                }
                if (y < n - 1 && grid[x][y + 1] == 1) {
                    q.push({x, y + 1});
                    fresh--;
                    grid[x][y + 1] = 2;
                }
            }
            time++;
        }
        return fresh > 0 ? -1 : time;
    }
};