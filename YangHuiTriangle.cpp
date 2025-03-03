/*Ñî»ÔÈý½Ç*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int level = 1; level <= numRows; level++) {
            triangle.push_back(vector<int>(level, 1));
            int index = 1;
            while (index < level - 1) {
                triangle[level - 1][index] =
                    triangle[level - 2][index - 1] + triangle[level - 2][index];
                index++;
            }
        }
        return triangle;
    }
};