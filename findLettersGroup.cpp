/*�ҵ��ַ�����������ĸ��λ��*/
//���������ַ��� s �� p���ҵ� s ������ p �� ��λ�� ���Ӵ���������Щ�Ӵ�����ʼ�����������Ǵ������˳��
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> answer;
        int n = s.size(), m = p.size();

        if (n < m) {
            return answer;  
        }

        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);
        for (char c : p) {
            pCount[c - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            if (i > m - 1) { // ���ڳ��ȴﵽp�ַ�������
                sCount[s[i - m] - 'a']--; // ��߽�����
            }
            sCount[s[i] - 'a']++; // �ұ߽�����
            if (sCount == pCount) {
                answer.push_back(i - m + 1);
            }
        }

        return answer;
    }
};