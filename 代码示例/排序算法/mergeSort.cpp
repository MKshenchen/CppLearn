#include <iostream>

using namespace std;

void merge(int *, int, int, int, int *);
void devide(int *, int, int, int *);
void mergeSort(int *, int);

int main() {
    int arr[] {1, 9, 2, 6, 8, 0, 7};
    for( auto i : arr) 
        cout << i << " ";

    cout << "\n---------------\n";

    mergeSort(arr, 7);
    for( auto i : arr) 
        cout << i << " ";

    cin.get();
    return 0;
}

void merge(int *arrPtr, int left, int mid, int right, int *temp) {
    int fir = left, sec = mid + 1, thr = left;
    while(fir <= mid && sec <= right) 
        temp[thr++] = arrPtr[fir] < arrPtr[sec] ? arrPtr[fir++] : arrPtr[sec++];
    while(fir <= mid) temp[thr++] = arrPtr[fir++];
    while(sec <= right) temp[thr++] = arrPtr[sec++];
    for(fir = left; fir <= right; fir++) arrPtr[fir] = temp[fir];
}

void devide(int *arrPtr, int left, int right, int *temp) {
    if(left >= right) return;
    
    int mid = left + ((right - left) >> 1);
    devide(arrPtr, left, mid, temp);
    devide(arrPtr, mid + 1, right, temp);
    merge(arrPtr, left, mid, right, temp);
}

void mergeSort(int *arrPtr, int len) {
    int *temp = (int*)malloc(sizeof(int) * len);
    devide(arrPtr, 0, len - 1, temp);
    free(temp);
}