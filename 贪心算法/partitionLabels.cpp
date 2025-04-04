/*������ĸ����*/
//����һ���ַ��� s ������Ҫ������ַ�������Ϊ�����ܶ��Ƭ�Σ�ͬһ��ĸ��������һ��Ƭ���С�
//���磬�ַ��� "ababcc" �ܹ�����Ϊ["abab", "cc"]��������["aba", "bcc"] ��["ab", "ab", "cc"] �Ļ����ǷǷ��ġ�
//ע�⣬���ֽ����Ҫ���㣺�����л��ֽ����˳�����ӣ��õ����ַ�����Ȼ�� s ��
//����һ����ʾÿ���ַ���Ƭ�εĳ��ȵ��б�
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int sIndex = 0, groupIndex = 0;
        vector<int> answer;

        unordered_map<char, int> umap; // ��¼ÿ����ĸ���һ�γ��ֵ�λ��
        for (int i = 0; i < n; i++) {
            umap[s[i]] = i;
        }

        while (sIndex < n) {
            int end = sIndex;
            answer.push_back(0);
            while (sIndex <= end) {
                if (umap[s[sIndex]] != sIndex) { // Ϊ�˽�ͬһ��ĸ����ͬһƬ���У��ҵ�����ĸ�����ֵ�λ�ã����½�β
                    end = max(end, umap[s[sIndex]]);
                }
                answer[groupIndex]++;
                sIndex++;
            }
            groupIndex++;
        }
        return answer;
    }
};