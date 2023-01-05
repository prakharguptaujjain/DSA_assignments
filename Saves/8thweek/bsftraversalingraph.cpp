#include <iostream>
using namespace std;
class Queue
{
public:
    int arr[9999];
    int start = 0;
    int end = -1;

    void push(int x)
    {
        end++;
        arr[end] = x;
    }
    void pop()
    {
        if (isempty())
        {
            cout << "queue is empty" << endl;
        }
        else
            start++;
    }
    int front()
    {
        if (isempty())
        {
            return -1;
        }
        return arr[start];
    }
    int back()
    {
        if (isempty())
        {
            return -1;
        }
        return arr[end];
    }
    int size()
    {
        return end - start + 1;
    }
    bool isempty()
    {
        if (end - start + 1)
            return 0;
        else
            return 1;
    }
};
int main()
{
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    Queue q;
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        arr1[i] = 0;
    }
    arr1[0]=1;
    cout << 0 << " ";
    q.push(0);
    while (!q.isempty())
    {
        int z = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (arr[z][i] && arr1[i]==0)
            {
                q.push(i);

                cout << i << " ";
                arr1[i] = 1;
            }
        }
    }
    return 0;
}