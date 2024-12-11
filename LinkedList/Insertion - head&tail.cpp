#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};
void insertAtHead(Node* &head,int d)
{
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertAtTail(Node* &tail,int d)
{
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void print(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* node1=new Node(11);
    Node* head=node1;
    Node* tail=node1;
    insertAtHead(head,12);
    print(head);
      insertAtHead(head,13);
    print(head);
      insertAtHead(head,14);
    print(head);
    insertAtTail(tail,1);
    print(head);
     insertAtTail(tail,2);
    print(head);
     insertAtTail(tail,3);
    print(head);
    
    return 0;
}
