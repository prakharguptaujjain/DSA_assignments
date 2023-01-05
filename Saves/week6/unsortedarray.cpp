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
    for (int i = low; i <= high; i++)
    {
        if (arr[i] < pivot)
        {
            pi++;
            swap(arr, i, pi);
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

void solve()
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
    quicksort(arr1, 0, n - 1);
    int s = -1;
    bool si = false;
    int e = -1;
    for (int i = 0; i < n; i++)
    {
        if (!si && arr1[i] != arr[i])
        {
            s = i;
            si = true;
        }
        if (arr1[i] != arr[i])
            e = i;
    }
    if (s == -1)
    {
        cout << -1 << endl;
        return;
    }
    if (s == e)
    {
        cout << 1 << endl;
        return;
    }
    cout << e - s + 1 << endl;
}
int main()
{
    int t = 1;
    // cin >> t;                                                     //INPUT TEST CASES
    while (t--)
        solve();
    return 0;
}
