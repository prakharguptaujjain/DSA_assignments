#include <iostream>
using namespace std;

int binarysearch(int arr[], int n, int x)
{
    int i = 0;
    int e = n - 1;
    int mid = (i + e) / 2;
    while (i <= e)
    {
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            i = mid + 1;
        }
        else
            e = mid - 1;
        mid = (i + e) / 2;
    }
    return -1;
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

    int s;
    cin >> s;
    cout << binarysearch(arr, n, s) << endl;
}

int main()
{

    int t = 1;
    // cin >> t;                                                     //INPUT TEST CASES
    while (t--)
        solve();
    return 0;
}
