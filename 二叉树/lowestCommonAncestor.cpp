/*�������������������*/
//����һ��������, �ҵ�����������ָ���ڵ������������ȡ�
//�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T �������ڵ� p��q������������ȱ�ʾΪһ���ڵ� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ���
class Sulotion {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { // dfs
		if (root == nullptr || root == p || root == q) { // �����ǰ�ڵ���Ŀ��ڵ㣬��ǰ�ڵ������LCA����͹������ȣ���ֱ�ӷ���
			return root;
		}

		// �ݹ����������������p��q
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		// �ݹ����������������p��q
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		// �����ǰ�ڵ㲻��Ŀ��ڵ㣬�����ӽ���в���
		// ���������û���ҵ�p��q��˵��p��q�����������У������������Ľ��
		if (left==nullptr) {
			return right;
		}
		// ���������û���ҵ�p��q��˵��p��q�����������У������������Ľ��
		if (right == nullptr) {
			return left;
		}
		// ��������������ҵ���p��q��˵����ǰ�ڵ�root����LCA
		return root;
	}
};