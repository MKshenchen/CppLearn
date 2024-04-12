#include <iostream>

using namespace std;

// void swap(int *, int *);
void shellSort(int *, int);

int main()
{
    int arr[]{1, 9, 2, 6, 8, 0, 7};
    for (auto i : arr)
        cout << i << " ";

    cout << "\n---------------\n";

    shellSort(arr, 7);
    for (auto i : arr)
        cout << i << " ";

    cin.get();
    return 0;
}

// 第一种
// void swap(int *aPtr, int *bPtr) {
//     int temp = *aPtr;
//     *aPtr = *bPtr;
//     *bPtr = temp;
// }

// void shellSort(int* arrPtr,int len) {
//     int step = 1;
//     while(step < len/3) step = step * 3 + 1;
//     while(step) {
//         for(int left = step; left < len; left++)
//             for(int right = left; right >= step && arrPtr[right] < arrPtr[right-step]; right -= step)
//                 swap(&arrPtr[right], &arrPtr[right-step]);
//         step /= 3;
//     }
// }

// 第二种
void shellSort(int *arrPtr, int len)
{
    int step = 1;
    while (step < len / 3)
        step = step * 3 + 1;
    while (step)
    {
        int left, right, temp;
        for (left = step; left < len; left++)
        {
            temp = arrPtr[left];
            for (right = left; right >= step && temp < arrPtr[right - step]; right -= step)
                arrPtr[right] = arrPtr[right - step];
            arrPtr[right] = temp;
        }
        step /= 3;
    }
}