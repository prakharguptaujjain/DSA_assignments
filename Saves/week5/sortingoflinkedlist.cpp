#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next = NULL;
};
void merge(int arr[], int start, int mid, int end)
{

    int *arr1=new int[mid - start + 1];
    int *arr2=new int[end - mid];
    for (int i = 0; i < mid - start + 1; i++)
    {
        arr1[i] = arr[i + start];
    }
    for (int i = 0; i < end - mid; i++)
    {
        arr2[i] = arr[i + mid + 1];
    }

    int ptr = start;
    int ptr1 = 0;
    int ptr2 = 0;
    while (ptr1 < mid - start + 1 && ptr2 < end - mid)
    {
        if (arr1[ptr1] < arr2[ptr2])
        {
            arr[ptr] = arr1[ptr1];
            ptr1++;
            ptr++;
        }
        else
        {
            arr[ptr] = arr2[ptr2];
            ptr2++;
            ptr++;
        }
    }
    while (ptr1 < mid - start + 1)
    {
        arr[ptr] = arr1[ptr1];
        ptr++;
        ptr1++;
    }

    while (ptr2 < end - mid)
    {
        arr[ptr] = arr2[ptr2];
        ptr++;
        ptr2++;
    }
    free (arr1);
    free (arr2);
}
void mergesort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void insert(node *head, int x)
{
    node *temp=new(node);
    temp->data = x;
    head->next = temp;
}
void sortlinkedlist(node* head)
{
    int size=0;
    node *ptr=head;
    while(ptr!=NULL)
    {
size++;
ptr=ptr->next;
    }
    int arr[size];
    node *dataptr=head;
    for (int i = 0; i < size; i++)
    {
        arr[i]=dataptr->data;
        dataptr=dataptr->next;
    }
    mergesort(arr,0,size-1);
    for (int i = 0; i < size; i++)
    {
        head->data=arr[i];
        head=head->next;
    }
    
    
}
int main()
{
    int n;cin>>n;
    int t;
    cin>>t;
    node* head=new(node);
    head->data=t;
    node* ptr=head;
    for (int i = 0; i < n-1; i++)
    {
        cin>>t;
        insert(ptr,t);
        ptr=ptr->next;
    }
    sortlinkedlist(head);
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
