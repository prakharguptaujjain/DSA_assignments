
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include <iostream>

using namespace std;
class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;
};
class stack
{
    node *arr[9999];
    int count = -1;

public:
    void push(node *head)
    {
        count++;
        arr[count] = head;
    }
    void pop()
    {
        if (isempty())
            cout << "stack is empty";
        else
            count--;
    }
    node* top()
    {
        if (!isempty())
            return arr[count];
        return NULL;
    }

    int isempty()
    {
        if (count < 0)
            return 1;
        else
            return 0;
    }
};

class Queue
{

public:
    int arr[99999];
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
            cout << "queueisempty" << endl;
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
void sumleft(node *head)
{
    stack sta;
    sta.push(NULL);

    int sum=0;
    node* start=head;
    bool first = true;
    while (!sta.isempty() || (first))
    {
        if(head==NULL){
            cout<<sum<<endl;return;
        }
        while ((head->left) != NULL)
        {
            sta.push(head);
        first = false;

            head = head->left;
            sum+=head->data;
        }

        // cout << head->data<<" ";
        if (head->right != NULL)
            head = head->right;
        else
        {
            if(!sta.isempty()){
                if(sta.top()==NULL)
                {cout<<sum<<endl;return;}
                head=sta.top()->right;
            sta.pop();
            }

            else {cout<<sum<<endl;return;}
        }
        

    }
    cout<<sum<<endl;
}
int main()
{
    node *head = new (node);
    int n;
    cin >> n;
    int d;
    cin >> d;
    head->data = d;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> d;
        insert(head, d);
    }
    sumleft(head);

    return 0;
}
