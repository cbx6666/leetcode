/*字符串解码*/
//给定一个经过编码的字符串，返回它解码后的字符串。
//编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
//你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
//此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return decode(s, index);
    }

    string decode(string s, int& index) { // 递归解法，遇到'['开始递归，遇到']'结束递归，处理[ ]内的字符串
        string result;
        while (index < s.size() && s[index] != ']') {
            if (s[index] >= '0' && s[index] <= '9') { // 计算循环次数
                int time = 0;
                while (index < s.size() && s[index] >= '0' && s[index] <= '9') {
                    time = time * 10 + (s[index] - '0');
                    index++;
                }
                index++; // 数字后一定是'['，跳过
                string sub = decode(s, index);
                index++; // 跳过']'
                while (time-- > 0) {
                    result += sub; // 循环添加[ ]内的子串
                }
            }
            else { // 处理普通字母
                result += s[index];
                index++;
            }
        }
        return result;
    }

    // 用栈的解法
    /*string decodeString(string s) {
        vector<string> stk;  // 使用vector模拟栈结构，存储数字、字母和括号
        size_t ptr = 0;     // 字符串遍历指针

        while (ptr < s.size()) {
            char cur = s[ptr];  // 当前字符
            
            // 情况1：当前字符是数字
            if (isdigit(cur)) {
                // 获取连续的数字字符串（可能有多位数）
                string digits = getDigits(s, ptr);
                stk.push_back(digits);  // 将数字字符串压栈
            } 
            // 情况2：当前字符是字母或左括号'['
            else if (isalpha(cur) || cur == '[') {
                // 将单个字符转为字符串并压栈
                stk.push_back(string(1, s[ptr++])); 
            } 
            // 情况3：当前字符是右括号']'
            else {
                ++ptr;  // 跳过右括号
                
                vector<string> sub;  // 存储子字符串的临时容器
                // 弹出栈中元素直到遇到左括号'['
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                // 因为栈是后进先出，所以需要反转子字符串
                reverse(sub.begin(), sub.end());
                
                stk.pop_back();  // 弹出左括号'['
                
                // 栈顶此时是重复次数（数字字符串）
                int repTime = stoi(stk.back()); 
                stk.pop_back();  // 弹出数字
                
                string t, o = getString(sub);  // 获取子字符串
                // 根据重复次数构造新字符串
                while (repTime--) t += o; 
                
                // 将构造好的字符串压回栈中
                stk.push_back(t);
            }
        }

        // 最后栈中所有元素合并就是最终结果
        return getString(stk);
    }

private:
    // 辅助函数：从字符串s的ptr位置开始提取连续的数字字符
    string getDigits(string &s, size_t &ptr) {
        string ret;
        while (ptr < s.size() && isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    // 辅助函数：将字符串向量合并为一个字符串
    string getString(vector<string> &v) {
        string ret;
        for (const auto &s : v) {
            ret += s;
        }
        return ret;
    }*/
};