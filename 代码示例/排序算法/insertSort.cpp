#include <iostream>

using namespace std;

// void swap(int *, int *);
void insertSort(int *, int);

int main() {
    int arr[] {1, 9, 2, 6, 8, 0, 7};
    for( auto i : arr) 
        cout << i << " ";

    cout << "\n---------------\n";

    insertSort(arr, 7);
    for( auto i : arr) 
        cout << i << " ";

    cin.get();
    return 0;
}

// 第一种: 可以理解为逆序冒泡
// void swap(int *aPtr, int *bPtr) {
//     int temp = *aPtr;
//     *aPtr = *bPtr;
//     *bPtr = temp;
// }

// void insertSort(int *arrPtr, int len) {
//     for(int left = 1; left < len; left++)
//         for(int right = left; right >= 1 && arrPtr[right] < arrPtr[right-1]; right--)
//             swap(&arrPtr[right], &arrPtr[right-1]);
// }

// 第二种
void insertSort(int *arrPtr, int len) {
    int left, right, temp;
    for(left = 1; left < len; left++) {
        temp = arrPtr[left];
        for(right = left; right > 0 && temp < arrPtr[right-1]; right--)
            arrPtr[right] = arrPtr[right-1];
        arrPtr[right] = temp;
    }
}