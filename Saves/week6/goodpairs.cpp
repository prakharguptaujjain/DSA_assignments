#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n, k;
    cin >> n >> k;
    long long int arr[n];
    long long int arr1[n];

    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (long long int i = 0; i < n; i++)
    {
        arr1[i] = (k * arr[i]) % n;
        arr[i] = arr[i] % n;
    }
    long long int normalarr[n];
    long long int karr[n];
    for (long long int i = 0; i < n; i++)
    {
        normalarr[i] = 0;
        karr[i] = 0;
    }
    for (long long int i = 0; i < n; i++)
    {
        normalarr[arr[i]]++;
        karr[arr1[i]]++;
    }
    long long int sum = 0;

    sum += (karr[0] * (normalarr[0]));

    for (int i = 1; i < n; i++)
    {
        sum += karr[i] * normalarr[n - i];
    }

    cout << sum << endl;
}

int main()
{

    int t = 1;
    // cin >> t;                                                     //INPUT TEST CASES
    while (t--)
        solve();
    return 0;
}
