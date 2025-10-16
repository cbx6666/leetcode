/*全排列*/
//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> answer;
        backtrack(nums, answer);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& answer) { 
        int n = nums.size();
        // 终止条件：当没有数字可选时
        if (n == 0) {
            ans.push_back(answer); // 将当前完整排列加入结果集
        }

        for (int i = 0; i < n; i++) {  // 遍历所有可选数字
            int temp = nums[i];
            nums.erase(nums.begin() + i); // 从可选数字中移除当前数字
            answer.push_back(temp);  // 将当前数字加入排列

            backtrack(nums, answer); // 递归处理剩余数字

            nums.insert(nums.begin() + i, temp); // 将数字放回原位置
            answer.pop_back(); // 从排列中移除当前数字
        }
    }
};