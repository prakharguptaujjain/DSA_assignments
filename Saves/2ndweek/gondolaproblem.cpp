#include <iostream>
using namespace std;
void merge(int arr[], int start, int mid, int end)
{
    int arr1size = mid - start + 1;
    int arr2size = end - mid;
    int *arr1 = new int(arr1size);
    int *arr2 = new int(arr2size);
    for (int i = 0; i < arr1size; i++)
    {
        arr1[i] = arr[start + i];
    }
    for (int i = 0; i < arr2size; i++)
    {
        arr2[i] = arr[mid + i + 1];
    }
    int ptr = start;
    int ptr1 = 0;
    int ptr2 = 0;
    while (ptr1 < arr1size && ptr2 < arr2size)
    {
        if (arr1[ptr1] < arr2[ptr2])
        {
            arr[ptr] = arr1[ptr1];
            ptr1++;
        }
        else

        {
            arr[ptr] = arr2[ptr2];
            ptr2++;
        }
        ptr++;
    }
    while (ptr1 < arr1size)
    {
        arr[ptr] = arr1[ptr1];
        ptr++;
        ptr1++;
    }
    while (ptr2 < arr2size)
    {
        arr[ptr] = arr2[ptr2];
        ptr++;
        ptr2++;
    }
    free(arr1);
    free(arr2);
}

void mergesort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);
    int count = 0;
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        if (arr[s] + arr[e] <= x)
        {
            count ++;
            e--;
            s++;
        }
        else
        {
            e--;
            count++;
        }
    }
    if(s==e)
    {
        count++;
    }
    cout << count<< endl;
    return 0;
}