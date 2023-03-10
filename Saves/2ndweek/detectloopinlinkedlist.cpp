#include <iostream>
using namespace std;
/*Driver code starts*/
typedef struct Node
{
    int data;
    Node *next;

} Node;

Node *insert(Node *end, int val)
{
    Node *n = new Node;
    n->data = val;
    n->next = NULL;
    end->next = n;
    return n;
}
Node *tempo = new Node;

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
    {tempo=NULL;
       return;}
    Node *walk = head;
    int i = 0;
    while (i < position - 1)
    {
        walk = walk->next;
        i++;
    }
    // cout<<walk->data<<'\n';
    tail->next = walk;
    tempo = walk;
}
/*Driver code ends*/

Node *solve(Node *head)
{   
    int te = 3;
    // your code goes here
    if(tempo==NULL){
        return head;
    }
    if(head->next==head){
    Node *en_temp = new Node;
    en_temp=head;
        en_temp = insert(en_temp, head->data);
        return head;
    }
    if(tempo==head || tempo==head->next){
te--;
    }
    Node *hea = new Node;
    hea->data = head->data;
    hea->next = NULL;
    Node *ptr = head;
    Node *en = hea;
    ptr = ptr->next;

    while (te)
    {

        en = insert(en, ptr->data);
        ptr = ptr->next;
        if (tempo == ptr)
        {
            te--;
        }
    }
    en->next = NULL;
    return hea;
}

/*Driver code starts*/
int main()
{
    int n;
    cin >> n;
    Node *head = new Node;
    int temp;
    cin >> temp;
    head->data = temp;
    head->next = NULL;
    Node *end = head;

    for (int i = 1; i < n; i++)
    {
        cin >> temp;
        end = insert(end, temp);
    }

    int position;
    cin >> position;
    loopHere(head, end, position);


    head = solve(head);
    Node *ptr = head;
    while (ptr)
    {
        cout << ptr->data << ' ';
        ptr = ptr->next;
    }
    return 0;
}
/*Driver code ends*/
