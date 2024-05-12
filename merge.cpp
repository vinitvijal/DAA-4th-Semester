// Write a program to sort the elements of an array using Merge Sort (The program should report the number of comparisons).

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r, int &comparisons)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        comparisons++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, int &comparisons)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comparisons);
        mergeSort(arr, m + 1, r, comparisons);
        merge(arr, l, m, r, comparisons);
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
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int comparisons = 0;
    mergeSort(arr1, 0, 5, comparisons);
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr1[i] << " ";
    }
    return 0;
}
