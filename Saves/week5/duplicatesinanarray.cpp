#include <iostream>
#include <climits>

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

void quicksort(int *arr,int start,int end)
{if(start<end)


{int pivot=partition(arr,start,end);
quicksort(arr,start,pivot-1);
quicksort(arr,pivot+1,end);

}

}

void solve()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        
    }
    quicksort(arr, 0, n - 1);
    int x=INT_MIN;
    for (int i = 0; i < n-2; i++)
    {
        if(x==arr[i])
        continue;
        x=arr[i];
        if (x==arr[i+1] && arr[i+2]==x)
        {
            cout << arr[i] << " ";
            i+=2;
        }
    }
}

int main()
{

    int t = 1;
    // cin >> t;                                                     //INPUT TEST CASES
    while (t--)
        solve();
    return 0;
}