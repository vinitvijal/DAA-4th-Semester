// Write a program to sort the elements of an array using Quick Sort (The program should report the number of comparisons).

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high, int &comparisons)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int &comparisons)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
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
    int arr1[] = {10, 7, 8, 9, 1, 5};
    int comparisons = 0;
    quickSort(arr1, 0, 5, comparisons);
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr1[i] << " ";
    }
    return 0;
}