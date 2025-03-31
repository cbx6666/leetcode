/*�ַ�������*/
//����һ������������ַ������������������ַ�����
//�������Ϊ: k[encoded_string]����ʾ���з������ڲ��� encoded_string �����ظ� k �Ρ�ע�� k ��֤Ϊ��������
//�������Ϊ�����ַ���������Ч�ģ������ַ�����û�ж���Ŀո�������ķ��������Ƿ��ϸ�ʽҪ��ġ�
//���⣬�������Ϊԭʼ���ݲ��������֣����е�����ֻ��ʾ�ظ��Ĵ��� k �����粻������� 3a �� 2[4] �����롣
class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return decode(s, index);
    }

    string decode(string s, int& index) { // �ݹ�ⷨ������'['��ʼ�ݹ飬����']'�����ݹ飬����[ ]�ڵ��ַ���
        string result;
        while (index < s.size() && s[index] != ']') {
            if (s[index] >= '0' && s[index] <= '9') { // ����ѭ������
                int time = 0;
                while (index < s.size() && s[index] >= '0' && s[index] <= '9') {
                    time = time * 10 + (s[index] - '0');
                    index++;
                }
                index++; // ���ֺ�һ����'['������
                string sub = decode(s, index);
                index++; // ����']'
                while (time-- > 0) {
                    result += sub; // ѭ�����[ ]�ڵ��Ӵ�
                }
            }
            else { // ������ͨ��ĸ
                result += s[index];
                index++;
            }
        }
        return result;
    }

    // ��ջ�Ľⷨ
    /*string decodeString(string s) {
        vector<string> stk;  // ʹ��vectorģ��ջ�ṹ���洢���֡���ĸ������
        size_t ptr = 0;     // �ַ�������ָ��

        while (ptr < s.size()) {
            char cur = s[ptr];  // ��ǰ�ַ�
            
            // ���1����ǰ�ַ�������
            if (isdigit(cur)) {
                // ��ȡ�����������ַ����������ж�λ����
                string digits = getDigits(s, ptr);
                stk.push_back(digits);  // �������ַ���ѹջ
            } 
            // ���2����ǰ�ַ�����ĸ��������'['
            else if (isalpha(cur) || cur == '[') {
                // �������ַ�תΪ�ַ�����ѹջ
                stk.push_back(string(1, s[ptr++])); 
            } 
            // ���3����ǰ�ַ���������']'
            else {
                ++ptr;  // ����������
                
                vector<string> sub;  // �洢���ַ�������ʱ����
                // ����ջ��Ԫ��ֱ������������'['
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                // ��Ϊջ�Ǻ���ȳ���������Ҫ��ת���ַ���
                reverse(sub.begin(), sub.end());
                
                stk.pop_back();  // ����������'['
                
                // ջ����ʱ���ظ������������ַ�����
                int repTime = stoi(stk.back()); 
                stk.pop_back();  // ��������
                
                string t, o = getString(sub);  // ��ȡ���ַ���
                // �����ظ������������ַ���
                while (repTime--) t += o; 
                
                // ������õ��ַ���ѹ��ջ��
                stk.push_back(t);
            }
        }

        // ���ջ������Ԫ�غϲ��������ս��
        return getString(stk);
    }

private:
    // �������������ַ���s��ptrλ�ÿ�ʼ��ȡ�����������ַ�
    string getDigits(string &s, size_t &ptr) {
        string ret;
        while (ptr < s.size() && isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    // �������������ַ��������ϲ�Ϊһ���ַ���
    string getString(vector<string> &v) {
        string ret;
        for (const auto &s : v) {
            ret += s;
        }
        return ret;
    }*/
};