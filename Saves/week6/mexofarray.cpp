#include <iostream>
using namespace std;
void merge(int arr[], int start, int mid, int end)
{
    int sarr1 = mid - start + 1;
    int sarr2 = end - mid;
    int arr1[sarr1];
    int arr2[sarr2];
    for (int i = 0; i < sarr1; i++)
    {
        arr1[i] = arr[i+start];
    }
    for (int i = 0; i < sarr2; i++)
    {
        arr2[i] = arr[i + mid + 1];
    }
    int ptr = start;
    int ptr1 = 0, ptr2 = 0;
    while (ptr1 < sarr1 && ptr2 < sarr2)
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
    while (ptr1 < sarr1)
    {
        arr[ptr] = arr1[ptr1];
        ptr1++;
        ptr++;
    }
    while (ptr2 < sarr2)
    {
        arr[ptr] = arr2[ptr2];
        ptr2++;
        ptr++;
    }
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
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);
    int ptr = 0;
    while (arr[ptr] < 0)
    {
        ptr++;
    }
    if(n==1)
    {
        if(arr[0]!=0)
        {
             cout << 0 << endl;
        return;
        }
        else
        
        {
            cout<<1<<endl;
            return;
        }
    }
    if (arr[ptr] != 0)
    {
        cout << 0 << endl;
        return;
    }
    ptr++;
    while (ptr < n)
    {
        if (arr[ptr] - arr[ptr - 1] != 1)
        {
            cout << arr[ptr - 1] + 1 << endl;
            return;
        }
        ptr++;
    }
    cout << arr[ptr-1] + 1 << endl;
}

int main()
{
    int t = 1;
    // cin >> t;                                                     //INPUT TEST CASES
    while (t--)
        solve();
    return 0;
}
