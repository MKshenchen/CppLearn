#include <iostream>

using namespace std;

void swap(int *, int *);
void bubbleSort(int *, int);

int main() {
    int arr[] {1, 9, 2, 6, 8, 0, 7};
    for( auto i : arr) 
        cout << i << " ";

    cout << "\n---------------\n";

    bubbleSort(arr, 7);
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

void bubbleSort(int *arrPtr, int len) {
    int mark = 1;
    while(len-- && mark) {     
        mark = 0;
        for(int i = 0; i < len; i++) 
            if(arrPtr[i] > arrPtr[i+1]) {
                swap(&arrPtr[i], &arrPtr[i+1]); 
                mark = 1;
            } 
    }
}