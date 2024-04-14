#include <iostream>

using namespace std;

void showUnderLine();
void showArrayElement(int *arrPtr, int arrLen);
void merge(int *arrPtr, int left, int mid, int right, int *temp);
void devide(int *arrPtr, int left, int right, int *temp);
void mergeSort(int *arrPtr, int arrLen);

int main()
{
    int arr[]{1, 9, 2, 6, 8, 0, 7};
    showArrayElement(arr, 7);
    mergeSort(arr, 7);
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

void merge(int *arrPtr, int left, int mid, int right, int *temp)
{
    int fir = left, sec = mid + 1, thr = left;
    while (fir <= mid && sec <= right)
        temp[thr++] = arrPtr[fir] < arrPtr[sec] ? arrPtr[fir++] : arrPtr[sec++];
    while (fir <= mid)
        temp[thr++] = arrPtr[fir++];
    while (sec <= right)
        temp[thr++] = arrPtr[sec++];
    for (fir = left; fir <= right; fir++)
        arrPtr[fir] = temp[fir];
}

void devide(int *arrPtr, int left, int right, int *temp)
{
    if (left >= right)
        return;

    int mid = left + ((right - left) >> 1);
    devide(arrPtr, left, mid, temp);
    devide(arrPtr, mid + 1, right, temp);
    merge(arrPtr, left, mid, right, temp);
}

void mergeSort(int *arrPtr, int arrLen)
{
    int *temp = (int *)malloc(sizeof(int) * arrLen);
    devide(arrPtr, 0, arrLen - 1, temp);
    free(temp);
}