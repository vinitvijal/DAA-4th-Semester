#include <iostream>
using namespace std;

void countSort(int arr[], int size) {
    int maxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (maxElement < arr[i]) {
            maxElement = arr[i];
        }
    }

    int n = maxElement + 1;
    int countArr[n];
    // int countArr[n] = {0};

    for (int i = 0; i < n; i++) {
        countArr[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        countArr[arr[i]]++;
    }

    for (int i = 1; i < n; i++) {
        countArr[i] += countArr[i - 1];
    }

    int sortedArr[size];
    for (int i = size - 1; i >= 0; i--) {
        sortedArr[countArr[arr[i]] - 1] = arr[i];
        countArr[arr[i]]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = sortedArr[i];
    }
}

int main() {
    int arr[5] = {2, 4, 1, 3, 2};

    countSort(arr, 5);

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
