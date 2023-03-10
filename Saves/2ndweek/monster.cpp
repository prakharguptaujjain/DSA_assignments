#include <iostream>
using namespace std;

class stack
{
public:
    int arr[9999];
    int cnt = -1;
    int mini = 10000;
    void Pop()
    {
        if (cnt >= 0)
        {
            cnt--;
        }
    }
    void Push(int z)
    {
        cnt++;
        arr[cnt] = z;
        mini = min(mini, z);
    }
    int peek()
    {
        if (cnt >= 0)
            return arr[cnt];
        else
            return -1;
    }
    void getmin()
    {
        if (cnt < 0)
        {
            cout << -1 << endl;
        }
        else
            cout << mini << endl;
    }
    int isempty()
    {
        if (cnt < 0)
        {
            return 1;
        }
        else
            return 0;
    }
};
int find(int arr[], int n, int x)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (x == arr[i])
        {
            return i;
        }
    }
}
int main()
{
    stack meta1, meta2;
    int n;
    cin >> n;
    int arr[n];
    int temp[n];
    int res[n];
    for (int i = 0; i < n; i++)
    {
        res[i] = 0;
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[n - 1 - i];
    }

    for (int i = 0; i < n; i++)
    {

        while (meta1.isempty() == 0 && meta1.peek() < arr[i])
        {
            meta1.Pop();
        }
        if (meta1.isempty() == 1)
        {
            res[i] += i;
        }
        else
            res[i] += i - find(arr, i, meta1.peek()) - 1;

        meta1.Push(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {

        while (meta2.isempty() == 0 && meta2.peek() < temp[i])
        {
            meta2.Pop();
        }
        if (meta2.isempty() == 1)
        {
            res[n - 1 - i] += i;
        }
        else
            res[n - 1 - i] += i - find(temp, i, meta2.peek()) - 1;

        meta2.Push(temp[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
