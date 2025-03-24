/*���ظ��ַ�����ִ�*/
// ����һ���ַ��� s �������ҳ����в������ظ��ַ�����Ӵ��ĳ��ȡ�
class solution {
public:
    // ˫ָ��+��ϣ�������ظ�Ԫ�غ󣬴�ǰһ���ظ�Ԫ�ص���һ��Ԫ�ؿ�ʼ��������ֵ��ظ�Ԫ��
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