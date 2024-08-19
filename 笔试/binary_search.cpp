#include <iostream>
using namespace std;

// ���ֲ��ң�˫�����䣩
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid; // �ҵ�Ŀ��ֵ����������
        } else if (arr[mid] < target) {
            left = mid + 1; // ���������Ұ벿��
        } else {
            right = mid - 1; // ����������벿��
        }
    }
    
    return -1; // û���ҵ�Ŀ��ֵ
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    
    int result = binarySearch(arr, size, target);
    
    if (result != -1) {
        cout << "Ŀ��ֵ " << target << " �������е������� " << result << endl;
    } else {
        cout << "Ŀ��ֵ " << target << " ����������" << endl;
    }
    
    return 0;
}
