
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include <iostream>
#include <climits>

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
public:
  int arr[9999];
  int cnt = -1;

  void Pop()
  {
    if (cnt >= 0)
    {
      cnt--;
    }
    else
      cout << "stackisempty" << endl;
  }
  void Push(int z)
  {
    cnt++;
    arr[cnt] = z;
  }
  int peek()
  {
    if (cnt >= 0)
      return arr[cnt];
    else
    {
      cout << 0 << endl;
      exit(0);
    }
    return 0;
  }
  int size()
  {
    return cnt + 1;
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
stack sta;
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
void inorder(node *head)
{

    if (head == NULL)
    {
        return;
    }
    inorder(head->left);
    sta.Push(head->data);
    inorder(head->right);
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
int k;
    cin >> k;
    inorder(head);
    for (int i = 0; i < k; i++)
    {
        cout<<sta.peek()<<" ";
        sta.Pop();
    }
    

    return 0;
}
