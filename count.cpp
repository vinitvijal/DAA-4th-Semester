//  Write a program to sort the elements of an array using Count Sort.

#include <iostream>
using namespace std;

void countSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int* count = new int[max + 1];
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    int k = 0;
    for (int i = 0; i <= max; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            arr[k++] = i;
        }
    }
}

int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    countSort(arr, 7);
    cout << "Sorted array: ";
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}