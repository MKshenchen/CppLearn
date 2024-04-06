#include <iostream>

using namespace std;

void swap(int *, int *);
void selectSort(int *, int);

int main() {
    int arr[] {1, 9, 2, 6, 8, 0, 7};
    for( auto i : arr) 
        cout << i << " ";

    cout << "\n---------------\n";

    selectSort(arr, 7);
    for( auto i : arr) 
        cout << i << " ";

    cin.get();
    return 0;
}

void swap(int *aPtr, int *bPtr) {
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}

void selectSort(int *arrPtr, int len) {
    for(int ptr = 0; ptr < len; ptr++) {
        int left = ptr;
        for(int right = ptr + 1; right < len; right++) 
            if(arrPtr[left] > arrPtr[right])
                left = right;        
        swap(&arrPtr[ptr], &arrPtr[left]);
    }
}