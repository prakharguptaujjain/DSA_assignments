#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int pi = low - 1;
    for (int i = low; i < high; i++)
    {
        if (arr[i] < pivot)
        {
            pi++;
            swap(&arr[pi], &arr[i]);
        }
    }
    pi++;
    swap(&arr[pi], &arr[high]);
    return pi;
}
int partition2(int arr[][2], int low, int high)
{
    int pivot = arr[high][0];
    int pi = low - 1;
    for (int i = low; i < high; i++)
    {
        if (arr[i][0] < pivot)
        {
            pi++;
            swap(&arr[pi][0], &arr[i][0]);
            swap(&arr[pi][1], &arr[i][1]);
        }
    }
    pi++;
    swap(&arr[pi][0], &arr[high][0]);
    swap(&arr[pi][1], &arr[high][1]);

    return pi;
}
void quicksort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);
        quicksort(arr, start, pivot - 1);
        quicksort(arr, pivot + 1, end);
    }
}

void quicksort2(int arr[][2], int start, int end)
{
    if (start < end)
    {
        int pivot = partition2(arr, start, end);
        quicksort2(arr, start, pivot - 1);
        quicksort2(arr, pivot + 1, end);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int arr1[n];

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
        arr1[i] = x;
    }
    int k;
    cin >> k;
    quicksort(arr1, 0, n - 1);

    float median;
    if (n % 2 == 1)
        median = arr1[n / 2];
    else
        median = (arr1[(n / 2) - 1]+arr1[n/2])/2 ;
    int arr2[n][2];
    // median = arr1[n / 2];
        
    for (int i = n-1; i >=0; i--)
    {
        arr2[i][0] = abs(arr[i] - median);
        arr2[i][1] = arr[i];
    }
    quicksort2(arr2, 0, n - 1);
    int itr = n - 1;
    int ar[k];

    for (int i = k - 1; i >= 0; i--)
    {
        ar[i]= arr2[itr][1];
        itr--;
    }
    quicksort(ar,0,k-1);
    for (int i = 0; i < k; i++)
    {
        cout<<ar[i]<<" ";

    }

    return 0;
}