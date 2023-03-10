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
        if(isempty()){
            cout<<"queue is empty"<<endl;
        }
        else start++;
    }
    int front()
    {
        if(isempty()){
            return -1;
        }
        return arr[start];
    }
    int back()
    {if(isempty()){
            return -1;
        }
        return arr[end];
    }
    int size()
    {
        return end-start + 1;
    }
    bool isempty()
    {
        if (end-start + 1)
            return 0;
        else
            return 1;
    }
};
int main()
{
    Queue meta;
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
            meta.push(k);
        }
        else if (s == "pop")
            meta.pop();
        else if (s == "front")
            cout << meta.front() << endl;
        else if (s == "back")
            cout << meta.back() << endl;
        else if (s == "isempty")
            cout << meta.isempty() << endl;
        else
            cout << meta.size() << endl;
    }
    return 0;
}

