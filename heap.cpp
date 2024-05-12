//  Write a program to sort the elements of an array using Heap Sort (The program should report the number of comparisons).

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, int &comparisons)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    comparisons++;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    comparisons++;
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, comparisons);
    }
}

void heapSort(int arr[], int n)
{
    int comparisons = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, comparisons);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, comparisons);
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
    int arr1[] = {12, 11, 13, 5, 6, 7};
    heapSort(arr1, 6);
    cout << "Sorted array: ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr1[i] << " ";
    }
    return 0;
}
