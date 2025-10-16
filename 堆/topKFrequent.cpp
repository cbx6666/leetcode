/*前k个高频元素*/
// 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计每个数字出现的频率
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }

        // 存储(数字,频率)对
        vector<pair<int, int>> elements;
        for (auto pair : mp) {
            elements.push_back({ pair.first, pair.second });
        }

        // 构建最大堆
        int size = elements.size();
        buildHeap(elements, size);

        vector<int> answer;
        for (int i = 0; i < k; i++) {
            // 每次取堆顶元素（当前频率最高的）
            answer.push_back(elements[0].first);
            // 将堆顶元素与最后一个元素交换，并缩小堆范围
            elements[0] = elements[size-- - 1];
            // 调整堆，维持最大堆性质
            heapifyDown(elements, 0, size);
        }

        return answer;
    }

    // 堆调整函数（下沉操作）
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

    // 建堆函数
    void buildHeap(vector<pair<int, int>>& nums, int heapSize) {
        for (int i = heapSize / 2 - 1; i >= 0; i--) {
            heapifyDown(nums, i, heapSize);
        }
    }
};