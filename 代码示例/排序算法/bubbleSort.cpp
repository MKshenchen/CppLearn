#include <iostream>

using namespace std;

void showUnderLine();
void showArrayElement(int *arrPtr, int arrLen);
void swap(int *aPtr, int *bPtr);
void bubbleSort(int *arrPtr, int arrLen);

int main()
{
    int arr[]{1, 9, 2, 6, 8, 0, 7};
    showArrayElement(arr, 7);
    bubbleSort(arr, 7);
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

void bubbleSort(int *arrPtr, int arrLen)
{
    int mark = 1;
    while (arrLen-- && mark)
    {
        mark = 0;
        for (int i = 0; i < arrLen; i++)
            if (arrPtr[i] > arrPtr[i + 1])
            {
                swap(&arrPtr[i], &arrPtr[i + 1]);
                mark = 1;
            }
    }
}