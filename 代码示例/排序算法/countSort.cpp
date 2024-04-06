#include <iostream>

using namespace std;

void getLimit(int *, int, int &, int &);
void countSort(int *, int);

int main() {
    int arr[] {1, 9, 2, 6, 8, 0, 7};
    for( auto i : arr) 
        cout << i << " ";

    cout << "\n---------------\n";

    countSort(arr, 7);
    for( auto i : arr) 
        cout << i << " ";

    cin.get();
    return 0;
}

void getLimit(int *arrPtr, int len, int &rmax, int &rmin) {
    rmax = rmin = arrPtr[0];
    for(int i = 1; i < len; i++) {
        if(rmax < arrPtr[i]) rmax = arrPtr[i];
        if(rmin > arrPtr[i]) rmin = arrPtr[i];
    }
}

void countSort(int *arrPtr, int len) {
    int max, min;
    getLimit(arrPtr, len, max, min);
    int temp_len = max - min + 1;
    int *temp_arr = new int[temp_len] {0};
    
    for(int i = 0; i < len; i++)
        temp_arr[arrPtr[i]-min]++;
    for(int i = 0, j = 0; i <= max; i++) 
        while(temp_arr[i]--) 
            arrPtr[j++] = i + min;
            
    delete[] temp_arr;
}