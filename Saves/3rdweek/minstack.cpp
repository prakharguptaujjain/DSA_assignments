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
            if (top() < mini)
            {
                mini = 2 * mini - top();
            }
            cnt--;
        }
    }
    void Push(int z)
    {
        if (cnt < 0)
        {
            mini = z;
        cnt++;

            arr[cnt] = z;
        }
        else if (z < mini){
        cnt++;
            
            arr[cnt] = (2 * z - mini);}
        else{
        cnt++;

        
            arr[cnt] = z;}


        // mini = min(mini, z);
    }
    void peek()
    {
        if (cnt >= 0)
            if (top() < mini)
            {
                cout << mini << endl;
            }
            else
                cout << arr[cnt] << endl;
        else
            cout << -1 << endl;
    }
    int top()
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
    void isempty()
    {
        if (cnt < 0)
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

        if (s ==
            "push")
        {
            int k;
            cin >> k;
            meta.Push(k);
        }
        else if (s == "pop")
            meta.Pop();
        else if (s == "top")
            meta.peek();
        else
            meta.getmin();
    }

    return 0;
}
