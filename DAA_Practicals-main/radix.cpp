#include <iostream>
#include <vector> // Add this line to include the vector header
#include <algorithm>
using namespace std;

int getMax(vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSort(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    int count[10] = {0};

    for (int i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    int max = getMax(arr);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr;
    arr.push_back(170);
    arr.push_back(45);
    arr.push_back(75);
    arr.push_back(90);
    arr.push_back(802);
    arr.push_back(24);
    arr.push_back(2);
    arr.push_back(66);

    std::cout << "Original array: ";
    printArray(arr);

    radixSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
