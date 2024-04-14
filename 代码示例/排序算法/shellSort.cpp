#include <iostream>

using namespace std;

// void swap(int *, int *);
void showUnderLine();
void showArrayElement(int *arrPtr, int arrLen);
void shellSort(int *arrPtr, int arrLen);

int main()
{
    int arr[]{1, 9, 2, 6, 8, 0, 7};
    showArrayElement(arr, 7);
    shellSort(arr, 7);
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

// 第一种
// void swap(int *aPtr, int *bPtr) {
//     int temp = *aPtr;
//     *aPtr = *bPtr;
//     *bPtr = temp;
// }

// void shellSort(int* arrPtr,int arrLen) {
//     int step = 1;
//     while(step < arrLen/3) step = step * 3 + 1;
//     while(step) {
//         for(int left = step; left < arrLen; left++)
//             for(int right = left; right >= step && arrPtr[right] < arrPtr[right-step]; right -= step)
//                 swap(&arrPtr[right], &arrPtr[right-step]);
//         step /= 3;
//     }
// }

// 第二种
void shellSort(int *arrPtr, int arrLen)
{
    int step = 1;
    while (step < arrLen / 3)
        step = step * 3 + 1;
    while (step)
    {
        int left, right, temp;
        for (left = step; left < arrLen; left++)
        {
            temp = arrPtr[left];
            for (right = left; right >= step && temp < arrPtr[right - step]; right -= step)
                arrPtr[right] = arrPtr[right - step];
            arrPtr[right] = temp;
        }
        step /= 3;
    }
}