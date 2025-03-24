/*无重复字符的最长字串*/
// 给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。
class solution {
public:
    // 双指针+哈希表，出现重复元素后，从前一个重复元素的下一个元素开始，到后出现的重复元素
    int lengthOfLongestSubstring(string s) {
        int max = 0, currentLength = 0;
        unordered_map<char, int> umap;
        int i = 0, j = 0, n = s.size();
        while (j < n) {
            if (umap.find(s[j]) != umap.end()) {
                while (i <= umap[s[j]]) {
                    umap.erase(s[i]);
                    i++;
                }
                max = max > currentLength ? max : currentLength;
                currentLength = j - i + 1;
            }
            else {
                currentLength++;
            }
            umap[s[j]] = j;
            j++;
        }
        return max > currentLength ? max : currentLength;
    }
};
