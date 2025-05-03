/*����������λ��*/
//��λ�������������б��е��м�ֵ������б�Ĵ�С��ż������û���м�ֵ����λ���������м�ֵ��ƽ��ֵ��

//���� arr = [2, 3, 4] ����λ���� 3 ��
//���� arr = [2, 3] ����λ����(2 + 3) / 2 = 2.5 ��
//�� MedianFinder �� :

//MedianFinder() ��ʼ�� MedianFinder ����
//void addNum(int num) ���������е����� num ��ӵ����ݽṹ�С�
//double findMedian() ���ص�ĿǰΪֹ����Ԫ�ص���λ������ʵ�ʴ���� 10 - 5 ���ڵĴ𰸽������ܡ�


// ˫�ѷ�����С��һ�룺�����Ѵ洢�����Կ��ٷ����ⲿ�ֵ����ֵ���ϴ��һ�룺����С�Ѵ洢�����Կ��ٷ����ⲿ�ֵ���Сֵ
class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    MedianFinder() {}

    void addNum(int num) {
        // �������ּ�������
        max_heap.push(num);
        // �����ѵĶ�������ǰ���ֵ���Ƶ���С��
        min_heap.push(max_heap.top());
        // ��һ��ȷ����С���е����� >= �����е���
        max_heap.pop();

        // ƽ�������ѵĴ�С���������ѵĴ�С >= ��С�ѵĴ�С��������1��������λ��Ҫô�����ѵĶ�����Ҫô�������Ѷ���ƽ����
        if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
        else {
            return max_heap.top();
        }
    }
};