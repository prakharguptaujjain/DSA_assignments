#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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
    int n, r, a;
    cin >> n>>r>>a; // bi then ai
    int arr[n][2];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][1];
        cin >> arr[i][0];
        sum += arr[i][1];
    }
    a*=n;
    quicksort2(arr, 0, n - 1);
    int cnt = 0;
    int counter = 0;
    while (sum != a)
    {
        if (arr[counter][1] != r)
        {
            cnt+=arr[counter][0];
            sum++;
            arr[counter][1]++;
        }
        else

        {
            counter++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}