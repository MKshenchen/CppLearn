#include <iostream>

using namespace std;

void showUnderLine();
void showArrayElement(int *arrPtr, int arrLen);
int getLimitLen(int *arrPtr, int arrLen, int &maxElement, int &minElenment);
void countSort(int *arrPtr, int arrLen);

int main()
{
    int arr[]{1, 9, 2, 6, 8, 0, 7};
    showArrayElement(arr, 7);
    countSort(arr, 7);
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

int getLimitLen(int *arrPtr, int arrLen, int &maxElement, int &minElement)
{
    maxElement = minElement = arrPtr[0];
    for (int i = 1; i < arrLen; i++)
    {
        if (maxElement < arrPtr[i])
            maxElement = arrPtr[i];
        if (minElement > arrPtr[i])
            minElement = arrPtr[i];
    }

    return maxElement - minElement + 1;
}

void countSort(int *arrPtr, int arrLen)
{
    int maxElement, minElement;
    int temp_len = getLimitLen(arrPtr, arrLen, maxElement, minElement);
    int *temp_arr = new int[temp_len]{0};

    for (int i = 0; i < arrLen; i++)
        temp_arr[arrPtr[i] - minElement]++;
    for (int i = 0, j = 0; i <= maxElement; i++)
        while (temp_arr[i]--)
            arrPtr[j++] = i + minElement;

    delete[] temp_arr;
}