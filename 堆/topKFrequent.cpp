/*ǰk����ƵԪ��*/
// ����һ���������� nums ��һ������ k �����㷵�����г���Ƶ��ǰ k �ߵ�Ԫ�ء�����԰� ����˳�� ���ش𰸡�
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // ͳ��ÿ�����ֳ��ֵ�Ƶ��
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }

        // �洢(����,Ƶ��)��
        vector<pair<int, int>> elements;
        for (auto pair : mp) {
            elements.push_back({ pair.first, pair.second });
        }

        // ��������
        int size = elements.size();
        buildHeap(elements, size);

        vector<int> answer;
        for (int i = 0; i < k; i++) {
            // ÿ��ȡ�Ѷ�Ԫ�أ���ǰƵ����ߵģ�
            answer.push_back(elements[0].first);
            // ���Ѷ�Ԫ�������һ��Ԫ�ؽ���������С�ѷ�Χ
            elements[0] = elements[size-- - 1];
            // �����ѣ�ά����������
            heapifyDown(elements, 0, size);
        }

        return answer;
    }

    // �ѵ����������³�������
    void heapifyDown(vector<pair<int, int>>& nums, int index, int heapSize) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int largest = index;
        if (left < heapSize && nums[left].second > nums[largest].second) {
            largest = left;
        }
        if (right < heapSize && nums[right].second > nums[largest].second) {
            largest = right;
        }
        if (largest != index) {
            swap(nums[index], nums[largest]);
            heapifyDown(nums, largest, heapSize);
        }
    }

    // ���Ѻ���
    void buildHeap(vector<pair<int, int>>& nums, int heapSize) {
        for (int i = heapSize / 2 - 1; i >= 0; i--) {
            heapifyDown(nums, i, heapSize);
        }
    }
};