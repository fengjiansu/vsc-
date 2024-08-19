#include <iostream>
using namespace std;

// 二分查找（双闭区间）
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid; // 找到目标值，返回索引
        } else if (arr[mid] < target) {
            left = mid + 1; // 继续搜索右半部分
        } else {
            right = mid - 1; // 继续搜索左半部分
        }
    }
    
    return -1; // 没有找到目标值
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    
    int result = binarySearch(arr, size, target);
    
    if (result != -1) {
        cout << "目标值 " << target << " 在数组中的索引是 " << result << endl;
    } else {
        cout << "目标值 " << target << " 不在数组中" << endl;
    }
    
    return 0;
}
