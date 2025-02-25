#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 复杂度非常高的方法...
    /*vector<vector<int>> threeSum(vector<int>& nums) {
        vector < vector<int>> answer;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) { // 去重
                continue;
            }

            unordered_set<int> uset;
            int target = -nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int complement = target - nums[j];
                if (uset.find(complement) != uset.end()) {
                    answer.push_back({ nums[i],nums[j],complement });

                    while (j + 1 < nums.size() && nums[j] == nums[j + 1]) { // 去重
                        j++;
                    }
                }
                uset.insert(nums[j]);
            }
        }
        return answer;
    }*/

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector < vector<int>> answer;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        if (n < 3) return answer;

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    left++;
                }
                else if (sum > 0) {
                    right--;
                }
                else {
                    answer.push_back({ nums[i],nums[left],nums[right] });
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
            }
        }

        return answer;
    }
};