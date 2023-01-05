
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;
class Node{
    public:
    int data;
    Node * next=NULL;
};
Node* add(Node *ptr,int x){
    Node * temp=new(Node);
    temp->data=x;
    ptr->next=temp;
    return temp;
}
void swap(Node * head,int a,int b){
    Node * fi_p,*fi,*se_p,*se;
    Node * ptr=head;
    for(int i=0;i<a-2;i++){
        ptr=ptr->next;
        if(ptr==NULL){cout<<-1;exit(0);}
    }
    fi_p=ptr;
    fi=ptr->next;
    for(int i=0;i<b-2;i++){
        
        ptr=ptr->next;
        if(ptr==NULL){cout<<-1;exit(0);}
    }
    se_p=ptr;
    se=ptr->next;
    ptr=ptr->next;
    if(ptr==NULL){cout<<-1;exit(0);}
    ptr=ptr->next;
    se_p->next=fi;
    fi_p->next=se;
    se->next=fi->next;
    fi->next=ptr;
    
    
}
int main()
{
    int n;cin>>n;
    Node * head=new(Node);
    
    int t;cin>>t;
    
    head->data=t;
    Node* ptr=new(Node);
    ptr=head;
    cout<<t<<" ";
    for(int i=0;i<n-1;i++){
        int z;cin>>z;
        cout<<z<<" ";
        ptr=add(ptr,z);
    }
    cout<<endl;
    int a,b;cin>>a>>b;
    swap(head,a,b);
    Node * trav=head;
    while(trav!=NULL){
        cout<<trav->data<<" ";
        trav=trav->next;
    }
    return 0;
}

