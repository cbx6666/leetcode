/*数据流的中位数*/
//中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。

//例如 arr = [2, 3, 4] 的中位数是 3 。
//例如 arr = [2, 3] 的中位数是(2 + 3) / 2 = 2.5 。
//现 MedianFinder 类 :

//MedianFinder() 初始化 MedianFinder 对象。
//void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
//double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10 - 5 以内的答案将被接受。


// 双堆法，较小的一半：用最大堆存储，可以快速访问这部分的最大值，较大的一半：用最小堆存储，可以快速访问这部分的最小值
class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    MedianFinder() {}

    void addNum(int num) {
        // 将新数字加入最大堆
        max_heap.push(num);
        // 将最大堆的顶部（当前最大值）移到最小堆
        min_heap.push(max_heap.top());
        // 这一步确保最小堆中的数都 >= 最大堆中的数
        max_heap.pop();

        // 平衡两个堆的大小，保持最大堆的大小 >= 最小堆的大小，且最多大1（这样中位数要么是最大堆的顶部，要么是两个堆顶的平均）
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