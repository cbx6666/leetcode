/*最小覆盖字串*/
//给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.size(), tSize = t.size();
        unordered_map<char, int> need; // 组成t的字符及其个数
        unordered_map<char, int> window; // 窗口内的字符及其个数
        for (char c : t) {
            need[c]++;
        }

        int left = 0, right = 0, length = INT_MAX, start = 0;
        int valid = 0; // 记录窗口中满足 need 条件的字符种类数

        while (right < sSize) {
            if (need.find(s[right]) != need.end()) {
                window[s[right]]++;
                if (need[s[right]] == window[s[right]]) {
                    valid++;
                }
            }
            right++;

            while (valid == need.size()) { // 表示覆盖了字符串
                int currentLength = right - left;
                if (currentLength < length) {
                    length = currentLength;
                    start = left;
                }
                
                // 左移左边界
                if (need.find(s[left]) != need.end()) {
                    if (window[s[left]] == need[s[left]]) { // 移动后不再覆盖字符串t
                        valid--;
                    }
                    window[s[left]]--;
                }
                left++;
            }
        }

        return length == INT_MAX ? "" : s.substr(start, length);
    }
};