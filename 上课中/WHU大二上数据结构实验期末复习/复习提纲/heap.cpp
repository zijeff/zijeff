// 复习资料中关于堆的知识，实现了手搓大根堆
#include <bits/stdc++.h>
using namespace std;
void output_nums(vector<int> &nums) {
    for (auto num : nums)
        cout << num << ' ';
    cout << endl;
}
void heapify(vector<int> &a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

// 手动建大根堆函数
void make_maxheap(vector<int> &nums) {
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(nums, n, i);
    }
}
// 往大根堆中加入新的元素
void push(vector<int> &nums, int val) {
    nums.push_back(val);
    int i = nums.size() - 1;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (nums[p] >= nums[i])
            break;
        swap(nums[i], nums[p]);
        i = p;
    }
}
// 输出大根堆中的最大元素
int top(vector<int> &nums) { return nums[0]; }
// 删除大根堆中最大元素
void pop(vector<int> &nums) {
    nums[0] = nums.back();
    nums.pop_back();
    int i = 0;
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < nums.size() && nums[largest] < nums[left])
            largest = left;
        if (right < nums.size() && nums[largest] < nums[right])
            largest = right;
        if (largest == i)
            break;
        swap(nums[i], nums[largest]);
        i = largest;
    }
}
int main() {
    vector<int> nums = {4, 3, 5, 2, 7, 8, 9, 9, 9};
    make_heap(nums.begin(), nums.end(), less<int>()); // 将数组元素排列为大根堆
    output_nums(nums);
    make_heap(nums.begin(), nums.end(), greater<int>()); // 将数组元素排列为小根堆
    output_nums(nums);

    // 使用优先队列建立小根堆
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // priority_queue<int, vector<int>, less<int>> maxHeap;
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(5);
    minHeap.push(5);
    minHeap.push(2);
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
    // 使用自定义函数，也就是手搓堆，显然大根堆与小根堆在算法上只需要改一下符号就行了，所以这里只给出手搓大根堆的代码
    make_maxheap(nums);
    output_nums(nums);
    push(nums, 10);
    output_nums(nums);
    cout << top(nums) << endl;
    pop(nums);
    output_nums(nums);
    return 0;
}
