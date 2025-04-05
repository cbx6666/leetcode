/*������������ͼ*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) { // ʹ�ö������Ĳ����������¼ÿ�����һ��ֵ
        queue<TreeNode*> q;
        q.push(root);
        vector<int> answer;

        if (root == nullptr) {
            return answer;
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* t = q.front();
                if (t->left != nullptr) {
                    q.push(t->left);
                }
                if (t->right != nullptr) {
                    q.push(t->right);
                }
                if (i == size - 1) {
                    answer.push_back(t->val);
                }
                q.pop();
            }
        }

        return answer;
    }
};