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
    for (int i = n; i >= 0; i--)
    {
        if (x == arr[i])
        {
            return i;
        }
    }
    {
        /* code */
    }
}
int main()
{
    stack meta;
    int n;
    cin>>n;
    int arr[n];
    int res[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        res[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (meta.isempty() == 1)
        {
            res[i] += i;
        }
        else
        {
            while (meta.isempty() == 0 && meta.peek() <= arr[i])
            {
                meta.Pop();
            }
            if (meta.isempty() == 1)
            {
                res[i] += i;
            }
            else
                res[i] += i - find(arr, i, meta.peek()) -1;
        }
        meta.Push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}

