/*��ˮ��������*/
//����һ������Ϊ n ���������� height ���� n �����ߣ��� i ���ߵ������˵��� (i, 0) �� (i, height[i]) ��
//�ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��
//�����������Դ�������ˮ����
//˵�����㲻����б������
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max = 0;
        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            max = max > area ? max : area;

            if (height[left] > height[right]) {
                right--;
            }
            else {
                left++;
            }
        }
        return max;
    }
};