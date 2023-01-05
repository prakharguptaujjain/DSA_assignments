#include <iostream>
using namespace std;

void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
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
            swap(arr, pi, i);
        }
    }
    pi++;
    swap(arr, pi, high);
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

int main()
{int n;cin>>n;
int arr[n];
for (int i = 0; i < n; i++)
{
    cin>>arr[i];

}

quicksort(arr,0,n-1);
for (int i = 0; i < n; i++)
{
    cout<<arr[i]<<" ";

}


    return 0;
}