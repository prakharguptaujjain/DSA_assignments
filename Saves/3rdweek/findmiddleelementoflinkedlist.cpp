#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int d;
        cin >> d;
        Node *head = new (Node);
        head->data = d;
        Node *end = new (Node);
        end = head;
        for (int i = 1; i < n; i++)
        {
            cin >> d;
            Node *temp = new (Node);
            temp->data = d;
            temp->next = NULL;
            end->next = temp;
            end = end->next;
        }
        Node *itr = new (Node);
        itr = head;
        int k = (n / 2)-1;
        while (k--)
        {
            // cout << itr->data <<
            ;
            itr = itr->next;
        }
        itr->next=itr->next->next;

        while(head!=NULL)
        {cout<<head->data<<" ";
        head=head->next;}
    }
    return 0;
}
