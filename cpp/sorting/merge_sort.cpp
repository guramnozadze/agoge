//
// Created by hebontes on 11/30/24.
//
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &data, int start, int mid, int end) {
    int temp[end-start+1];

    int i =start, j = mid + 1, k = 0;


    while (i <= mid && j <= end) {
        if (data[i] <= data[j]) {
            temp[k] = data[i];
            i++;
            k++;
        }else {
            temp[k] = data[j];
            j++;
            k++;
        }
    }

}


void mergeSort(vector<int> &data, int start, int end) {
    int mid = (start + end) / 2;



    mergeSort(data, start, mid);
    mergeSort(data, mid+1, end);
    merge(data,start,mid,end);
}


int main(){
    cout << 0 /2 << endl;
    vector<int> arr = {8,6,2};
    mergeSort(arr, 0, 2);


    // output arr
    for (int i = 0; i < arr.size(); i++) {
      cout << arr[i] << " ";
    }
    return 0;
}

