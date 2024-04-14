#include <iostream>

using namespace std;

void showUnderLine();
void showArrayElement(int *arrPtr, int arrLen);
void swap(int *aPtr, int *bPtr);
void selectSort(int *arrPtr, int arrLen);

int main()
{
    int arr[]{1, 9, 2, 6, 8, 0, 7};
    showArrayElement(arr, 7);
    selectSort(arr, 7);
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

void selectSort(int *arrPtr, int arrLen)
{
    for (int ptr = 0; ptr < arrLen; ptr++)
    {
        int left = ptr;
        for (int right = ptr + 1; right < arrLen; right++)
            if (arrPtr[left] > arrPtr[right])
                left = right;
        swap(&arrPtr[ptr], &arrPtr[left]);
    }
}