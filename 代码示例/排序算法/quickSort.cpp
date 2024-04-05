#include <iostream>

using namespace std;

void swap(int *, int *);
int devide(int *, int, int);
void quickSort(int *, int, int);

int main() {
    int arr[] {1, 9, 2, 6, 8, 0, 7};
    for( auto i : arr) 
        cout << i << endl;

    cout << "----------\n";
    
    quickSort(arr, 0, 6);    
    for( auto i : arr) 
        cout << i << endl;

    cin.get();
    return 0;
}

void swap(int *aPtr, int *bPtr) {
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}

int devide(int *arrPtr, int left, int right) {
    int temp = arrPtr[right];
    int ptr = left - 1;

    for(int i = left; i < right; i ++)
        if(arrPtr[i] < temp)
            swap(&arrPtr[++ptr], &arrPtr[i]);
    swap(&arrPtr[++ptr], &arrPtr[right]);
    return ptr;
}

void quickSort(int *arrPtr, int left, int right) {
    if(left < right) {
        int mid = devide(arrPtr, left, right);

        quickSort(arrPtr, left, mid - 1);
        quickSort(arrPtr, mid + 1, right);
    }
}