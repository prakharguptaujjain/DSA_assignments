#include <iostream>
using namespace std;

class stack
{
public:
    int arr[9999];
    int cnt = 0;

    void Pop()
    {
        if (cnt > 0)
        {
            cnt--;
        }
        else
            cout << "stackisempty" << endl;
    }
    void Push(int z)
    {
        arr[cnt] = z;
        cnt++;
    }
    void peek()
    {
        if (cnt > 0)
            cout << arr[cnt - 1] << endl;
        else
            cout << -1 << endl;
    }
    void size()
    {
        cout << cnt << endl;
    }
    void isempty()
    {
        if (cnt <= 0)
        {
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
    }
};

int main()
{
    stack meta;
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;

        if (s == "push")
        {
            int k;
            cin >> k;
            meta.Push(k);
        }
        else if (s == "pop")
            meta.Pop();
        else if (s == "peek")
            meta.peek();
        else if (s == "isempty")
            meta.isempty();
        else
            meta.size();
    }

    return 0;
}
