#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[150];
    for (int i = 0; i < 150; i++)
    {
        arr[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[x] = 1;
    }
    int curr;
    cin >> curr;
    arr[curr] = 1;
    string s;
    cin >> s;
    if (s == "UP")
    {
        for (int i = curr; i < 150; i++)
        {
            if (arr[i] != 0)
                cout << i << " ";
        }
        for (int i = curr - 1; i >= 0; i--)
        {
            if (arr[i] != 0)
            {
                cout << i << " ";
            }
        }
    }
    else
    {
        for (int i = curr; i >= 0; i--)
        {
            if (arr[i] != 0)
            {
                cout << i << " ";
            }
        }
        for (int i = curr+1; i < 150; i++)
        {
            if (arr[i] != 0)
                cout << i << " ";
        }
        
    }
    cout << endl;

    return 0;
}