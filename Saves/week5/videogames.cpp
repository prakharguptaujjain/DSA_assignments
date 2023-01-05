#include <iostream>
using namespace std;

int binarysearch(int arr[], int n, int x)
{
    int i = 0;
    int end = n;
    int mid = (i + end) / 2;
    // 1 2 3 4 7 8 10
    if (arr[end - 1] < x)
        return n - 1;

    while (i <= end)
    {
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            end = mid - 1;
            mid = (i + end) / 2;
        }
        else
        {
            i = mid + 1;
            mid = (i + end) / 2;
        }
    }
    if (arr[mid] < x)
        return mid;
    else
        return mid - 1;
}
void arrayprint(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int *p = new int[n];
    int mini = 1000000;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    // arrayprint(p,n);
    // arrayprint(p,n);

    int *sum = new int[n];
    sum[0] = p[0];

    for (int i = 1; i < n; i++)
    {

        sum[i] = sum[i - 1] + p[i];
    }
    // arrayprint(sum, n);
    // int *arr=new int[m];
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        cout << binarysearch(sum, n, x) + 1 << " ";
    }
    return 0;
}