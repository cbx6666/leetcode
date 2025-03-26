/*��ΪK��������*/
//����һ���������� nums ��һ������ k ������ͳ�Ʋ����� �������к�Ϊ k ��������ĸ��� ��
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) { // ����ǰ׺�ͣ�����i > j�����i��ǰ׺�ͼ�j��ǰ׺�͵���k����˵������j + 1 ~ i�ĺ�Ϊk��
        unordered_map<int, int> mp; // ��¼ÿ��ǰ׺�ͼ������
        mp[0] = 1; // ����ǰ׺������Ϊk
        int count = 0, pre = 0;
        for (int num : nums) {
            pre += num; // ����ǰ׺��
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }

        return count;
    }
};