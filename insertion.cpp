// Write a program to sort the elements of an array using Insertion Sort (The program should report the number of comparisons).
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j, comparisons = 0;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        comparisons++;
        while (j >= 0 && arr[j] > key)
        {
            comparisons++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout << "Number of comparisons: " << comparisons << endl;
}

int main()
{
    // int n;
    // cout << "Enter the number of elements: ";
    // cin >> n;
    // int arr[n];
    // cout << "Enter the elements: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    int arr1[] = {12, 11, 13, 5, 6};
    insertionSort(arr1, 5);
    cout << "Sorted array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    return 0;
}