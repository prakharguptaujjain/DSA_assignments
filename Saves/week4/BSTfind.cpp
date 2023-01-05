
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include <iostream>
#include <climits>

using namespace std;
class Queue{

public:
    int arr[INT_MAX];
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
            cout<<"queueisempty"<<endl;
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
class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;
};
void insert(node *head, int x)
{
    node *ptr = head;
    while (true)
    {
        if ((ptr->data) > (x))
        {
            if (ptr->left == NULL)
                break;
            ptr = ptr->left;
        }

        else
        {
            if (ptr->right == NULL)
                break;

            ptr = ptr->right;
        }
    }

    node *temp = new (node);
    temp->data = x;
    if (ptr->data > x)
        ptr->left = temp;
    else
        ptr->right = temp;
}
Queue find(node *head, int x)
{
    node *ptr = head;
    Queue que;
    while (ptr!=NULL)
    {
        if ((ptr->data) > (x))
        {
            que.push(ptr->data);
            ptr = ptr->left;
        }
        else if(ptr->data==x){
            que.push(x);
            break;
        }
        else
        {
            que.push(ptr->data);

            ptr = ptr->right;
        }
    }
    if (ptr==NULL)
    {
        cout << -1 << endl;
        return;
    }
    if (ptr->data == x)
        {return que;
        
        // cout<<endl;
        // cout << x << endl;
        }
    else
        cout << -1 << endl;
}
void ca(node*head)
{
Queue q1=find()
}
int main()
{
    node *head = new (node);
    int n, m;
    cin >> n >> m;
    int d;
    cin >> d;
    head->data = d;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> d;
        insert(head, d);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> d;
        find(head, d);
    }
    return 0;
}
