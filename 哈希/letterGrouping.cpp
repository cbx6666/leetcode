/*��ĸ��λ�ʷ���*/
//����һ���ַ������飬���㽫 ��ĸ��λ�� �����һ�𡣿��԰�����˳�򷵻ؽ���б�
//��ĸ��λ�� ������������Դ���ʵ�������ĸ�õ���һ���µ��ʡ�
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> umap;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            umap[str].push_back(strs[i]);
        }
        for (const auto& pair : umap) {
            answer.push_back(pair.second);
        }
        return answer;
    }
};