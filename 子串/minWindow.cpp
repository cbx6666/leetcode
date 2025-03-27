/*��С�����ִ�*/
//����һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ������ s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��
class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.size(), tSize = t.size();
        unordered_map<char, int> need; // ���t���ַ��������
        unordered_map<char, int> window; // �����ڵ��ַ��������
        for (char c : t) {
            need[c]++;
        }

        int left = 0, right = 0, length = INT_MAX, start = 0;
        int valid = 0; // ��¼���������� need �������ַ�������

        while (right < sSize) {
            if (need.find(s[right]) != need.end()) {
                window[s[right]]++;
                if (need[s[right]] == window[s[right]]) {
                    valid++;
                }
            }
            right++;

            while (valid == need.size()) { // ��ʾ�������ַ���
                int currentLength = right - left;
                if (currentLength < length) {
                    length = currentLength;
                    start = left;
                }
                
                // ������߽�
                if (need.find(s[left]) != need.end()) {
                    if (window[s[left]] == need[s[left]]) { // �ƶ����ٸ����ַ���t
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