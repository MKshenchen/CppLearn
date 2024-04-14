#include <iostream>

using namespace std;

void showUnderLine();
void showArrayElement(int *arrPtr, int arrLen);
void swap(int *, int *);
int devide(int *, int, int);
void quickSort(int *, int, int);

int main()
{
    int arr[]{1, 9, 2, 6, 8, 0, 7};
    showArrayElement(arr, 7);
    quickSort(arr, 0, 6);
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

void swap(int *aPtr, int *bPtr)
{
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}

int devide(int *arrPtr, int left, int right)
{
    int temp = arrPtr[right];
    int ptr = left - 1;

    for (int i = left; i < right; i++)
        if (arrPtr[i] < temp)
            swap(&arrPtr[++ptr], &arrPtr[i]);
    swap(&arrPtr[++ptr], &arrPtr[right]);
    return ptr;
}

void quickSort(int *arrPtr, int left, int right)
{
    if (left < right)
    {
        int mid = devide(arrPtr, left, right);

        quickSort(arrPtr, left, mid - 1);
        quickSort(arrPtr, mid + 1, right);
    }
}