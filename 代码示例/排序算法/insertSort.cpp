#include <iostream>

using namespace std;

void showUnderLine();
void showArrayElement(int *arrPtr, int arrLen);
// void swap(int *, int *);
void insertSort(int *arrPtr, int arrLen);

int main()
{
    int arr[]{1, 9, 2, 6, 8, 0, 7};
    showArrayElement(arr, 7);
    insertSort(arr, 7);
    showArrayElement(arr, 7);

    cin.get();
    return 0;
}

void showUnderLine()
{
    cout << "\n---------------\n";
}

void showArrayElement(int *arrPtr, int arrLen)
{
    for (int i = 0; i < arrLen; i++)
        cout << arrPtr[i] << " ";

    showUnderLine();
}

// 第一种: 可以理解为逆序冒泡
// void swap(int *aPtr, int *bPtr) {
//     int temp = *aPtr;
//     *aPtr = *bPtr;
//     *bPtr = temp;
// }

// void insertSort(int *arrPtr, int arrLen) {
//     for(int left = 1; left < arrLen; left++)
//         for(int right = left; right >= 1 && arrPtr[right] < arrPtr[right-1]; right--)
//             swap(&arrPtr[right], &arrPtr[right-1]);
// }

// 第二种
void insertSort(int *arrPtr, int arrLen)
{
    int left, right, temp;
    for (left = 1; left < arrLen; left++)
    {
        temp = arrPtr[left];
        for (right = left; right > 0 && temp < arrPtr[right - 1]; right--)
            arrPtr[right] = arrPtr[right - 1];
        arrPtr[right] = temp;
    }
}