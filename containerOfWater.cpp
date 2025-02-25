#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max = 0;
        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            max = max > area ? max : area;

            if (height[left] > height[right]) {
                right--;
            }
            else {
                left++;
            }
        }
        return max;
    }
};

int main()
{
    Solution test;
    vector<int> height = { 1,2,4,3 };
    cout << test.maxArea(height) << endl;
    return 0;
}